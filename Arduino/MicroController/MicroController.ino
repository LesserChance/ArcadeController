
#include <Encoder.h>
#include <Joystick.h>
#include <Mouse.h>
#include <Keyboard.h>

Encoder mouseX(2, 14);
Encoder mouseY(0, 15);
Encoder mouseZ(1, 13);

const int16_t PLAYER = 1;                // switch to 1 for player 2 microcontroller

const int16_t AXIS_MAX = 1024;           // The highest value the controller axis should have
const int16_t AXIS_LIMIT = AXIS_MAX / 2; // The neutral state of the axis (in the middle)

const int16_t ENCODER_LIMIT = 256;       // The highest value an encoder can reach
const int16_t SENSITIVITY_RX = 2;        // 1 tick on the encoder for the X axis is this many ticks on the axis
const int16_t SENSITIVITY_RY = 2;        // 1 tick on the encoder for the Y axis is this many ticks on the axis
const int16_t SENSITIVITY_RZ = 1;        // 1 tick on the encoder for the Z axis is this many ticks on the axis

/*
 * DIFFERENCES FROM PCB
 * pin 17 is used for the onboard LED and seems to randomly bounce, therefore do not use pin 17
 * Instead:
 * Player Up is 11 instead of 17. Pin 11 is marked as BUTTON 5 on the Panel PCB, wire UP to that
 * Button 5 uses pin 13 instead of 11. Button 5 no longer has a dedicated pin
 * - Pin 13 is used for the rZ axis as well, so you cant have a panel with a z axis and the sixth button
 */
const byte JOY_UP_PIN = 13;
const byte JOY_DOWN_PIN = 3;
const byte JOY_LEFT_PIN = 4;
const byte JOY_RIGHT_PIN = 5;
const byte JOY_BUTTON_PIN[] = {6, 7, 8, 9, 10, 11, 1, 14, 2, 15, 0}; 
const byte CP_BUTTON_PIN[] = {18, 19, 20, 21, 22};
const byte CP_BUTTON_KEY[][sizeof(CP_BUTTON_PIN)] = {{'1','5',KEY_F1,KEY_ESC,'p'},{'2','6','l','-','c'}};
const byte PANEL_DIP_PIN[] = {23, 16, 12};

int ACTIVE_PANEL = -1;
byte CP_BUTTON_KEY_ACTIVE[][sizeof(CP_BUTTON_PIN)] = {{false,false,false,false,false},{false,false,false,false,false}};

// The Player Joystick, wired to the panel PCB - comprises all possible options that could be connected
Joystick_ Player(
  ((PLAYER == 0) ? 0x04 : 0x05), // HID ID
  JOYSTICK_TYPE_GAMEPAD, // Joystick type
  sizeof(JOY_BUTTON_PIN), // button count
  0, // hat switch count
  true, // x axis
  true, // y axis
  false, // z axis
  false, // rx axis
  false, // ry axis
  false, // rz axis
  false, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false // steering
);

void setup() {
  // Initialization of Buttons
  pinMode(JOY_UP_PIN, INPUT_PULLUP);
  pinMode(JOY_DOWN_PIN, INPUT_PULLUP);
  pinMode(JOY_LEFT_PIN, INPUT_PULLUP);
  pinMode(JOY_RIGHT_PIN, INPUT_PULLUP);
  for (byte i = 0; i < sizeof(JOY_BUTTON_PIN); i++) {
    pinMode(JOY_BUTTON_PIN[i], INPUT_PULLUP);
  }
  for (byte i = 0; i < sizeof(CP_BUTTON_PIN); i++) {
    pinMode(CP_BUTTON_PIN[i], INPUT_PULLUP);
  }

  Player.begin(false);
  Mouse.begin();
  Keyboard.begin();
}

void loop(){
  // Read DIP state to see if joystick has changed
  setActivePanel();

  // set a neutral state to debounce panel changes
  Player.setXAxis(AXIS_LIMIT);
  Player.setYAxis(AXIS_LIMIT);
  for (byte i = 0; i < sizeof(JOY_BUTTON_PIN); i++) {
    Player.setButton(i, 0);
  }

  // Control Panel
  for (byte i = 0; i < sizeof(CP_BUTTON_PIN); i++) {
    if (!digitalRead(CP_BUTTON_PIN[i])) {
      if (!CP_BUTTON_KEY_ACTIVE[PLAYER][i]) {
        CP_BUTTON_KEY_ACTIVE[PLAYER][i] = true;
        Keyboard.press(CP_BUTTON_KEY[PLAYER][i]);
        delay(40);
      }
    } else if (CP_BUTTON_KEY_ACTIVE[PLAYER][i]) {
      CP_BUTTON_KEY_ACTIVE[PLAYER][i] = false;
      Keyboard.releaseAll();
    }
  }

  switch (ACTIVE_PANEL) {
    
    // Fighter: optical 8 way joysticks, 6 buttons
    case 0:
      setJoystickXAxis();
      setJoystickYAxis();
      setJoystickButtons(6);
      break;

    // Trackball: trackball, 3 buttons
    case 1:
      Mouse.move(
        getMouseAxisValue(mouseX.read(), SENSITIVITY_RX, false),
        getMouseAxisValue(mouseY.read(), SENSITIVITY_RY, false),
        0
       );
      mouseX.write(0);
      mouseY.write(0);
      setJoystickButtons(3);
      break;
      
  }
  
  Player.sendState();
  delay(10);
}

void setJoystickYAxis() {
  if (!digitalRead(JOY_UP_PIN)) {
    Player.setYAxis(AXIS_MAX);
  } else if (!digitalRead(JOY_DOWN_PIN)) {
    Player.setYAxis(0);
  } else {
    Player.setYAxis(AXIS_LIMIT);
  }
}

void setJoystickXAxis() {
  if (!digitalRead(JOY_RIGHT_PIN)) {
    Player.setXAxis(AXIS_MAX);
  } else if (!digitalRead(JOY_LEFT_PIN)) {
    Player.setXAxis(0);
  } else {
    Player.setXAxis(AXIS_LIMIT);
  }
}

void setJoystickButtons(int buttonCount) {
  int maxButton = min(buttonCount, sizeof(JOY_BUTTON_PIN));
  for (byte i = 0; i < maxButton; i++) {
    Player.setButton(i, !digitalRead(JOY_BUTTON_PIN[i]));
  }
}

int getMouseAxisValue(int encoderValue, int sensitivity, bool flip) {
  int newValue = constrain(encoderValue * sensitivity * (flip ? -1 : 1), -ENCODER_LIMIT, ENCODER_LIMIT);
  newValue = map(newValue, -ENCODER_LIMIT, ENCODER_LIMIT, -AXIS_LIMIT, AXIS_LIMIT);
  return newValue;
}

void setActivePanel() {
  int newActivePanel = 0;
  
  bitWrite(newActivePanel, 0, digitalRead(PANEL_DIP_PIN[0]));
  bitWrite(newActivePanel, 1, digitalRead(PANEL_DIP_PIN[1]));
  bitWrite(newActivePanel, 2, digitalRead(PANEL_DIP_PIN[2]));

  if (newActivePanel != ACTIVE_PANEL) {
    ACTIVE_PANEL = newActivePanel;
  }
}
