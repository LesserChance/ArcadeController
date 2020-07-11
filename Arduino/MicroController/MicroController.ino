
#include <Encoder.h>
#include <Joystick.h>

Encoder axisRx(0, 15);
Encoder axisRy(2, 14);
Encoder axisRz(1, 13);
    
const int16_t AXIS_MAX = 1024;           // The highest value the controller axis should have
const int16_t AXIS_LIMIT = AXIS_MAX / 2; // The neutral state of the axis (in the middle)

const int16_t ENCODER_LIMIT = 512;       // The highest value an encoder can reach
const int16_t SENSITIVITY_RX = 4;        // 1 tick on the encoder for the X axis is this many ticks on the axis
const int16_t SENSITIVITY_RY = 4;        // 1 tick on the encoder for the Y axis is this many ticks on the axis
const int16_t SENSITIVITY_RZ = 1;        // 1 tick on the encoder for the Z axis is this many ticks on the axis

const byte PIN_UP = 17;
const byte PIN_DOWN = 3;
const byte PIN_LEFT = 4;
const byte PIN_RIGHT = 5;
const byte PIN_BUTTON[] = {6, 7, 8, 9, 10, 11, 12, 18, 19, 20, 21, 22, 23};

// Create the Joystick
Joystick_ Joystick(
  0x03, // HID ID
  JOYSTICK_TYPE_MULTI_AXIS, // Joystick type
  13, // button count
  0, // hat switch count
  true, // x axis
  true, // y axis
  false, // z axis
  true, // rx axis
  true, // ry axis
  true, // rz axis
  false, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false // steering
);

void setup() {
  // this pin *needs* to be a pulldown given the wiring on the Micro
  pinMode(PIN_UP, INPUT);

  // Initialization of Buttons with internal pullup resistors
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
  for (byte i = 0; i < sizeof(PIN_BUTTON); i++) {
    pinMode(PIN_BUTTON[i], INPUT_PULLUP);
  }
  
  Joystick.begin(false);
}

void loop(){
  // joystick axes
  if (digitalRead(PIN_UP)) {
    Joystick.setYAxis(AXIS_MAX);
  } else if (!digitalRead(PIN_DOWN)) {
    Joystick.setYAxis(0);
  } else {
    Joystick.setYAxis(AXIS_LIMIT);
  }
  
  if (!digitalRead(PIN_RIGHT)) {
    Joystick.setXAxis(AXIS_MAX);
  } else if (!digitalRead(PIN_LEFT)) {
    Joystick.setXAxis(0);
  } else {
    Joystick.setXAxis(AXIS_LIMIT);
  }

  // buttons
  for (byte i = 0; i < sizeof(PIN_BUTTON); i++) {
    Joystick.setButton(i, !digitalRead(PIN_BUTTON[i]));
  }
  
  // trackballs / spinners
  Joystick.setRxAxis(getAxisValue(axisRx.read(), SENSITIVITY_RX, false));
  Joystick.setRyAxis(getAxisValue(axisRy.read(), SENSITIVITY_RY, true));
  Joystick.setRzAxis(getAxisValue(axisRz.read(), SENSITIVITY_RZ, false));
  
  axisRx.write(0);
  axisRy.write(0);
  axisRz.write(0);

  Joystick.sendState();
  delay(50);
}

int getAxisValue(int encoderValue, int sensitivity, bool flip) {
  int newValue = constrain(encoderValue * sensitivity * (flip ? -1 : 1), -ENCODER_LIMIT, ENCODER_LIMIT);
  newValue = map(newValue, -ENCODER_LIMIT, ENCODER_LIMIT, -AXIS_LIMIT, AXIS_LIMIT);
  return newValue+AXIS_LIMIT;
}
