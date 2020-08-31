// Library imports
#include <Encoder.h>
#include <Joystick.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <Servo.h>

// Local imports
#include "pinmap.h"
#include "globals.h"
#include "axis.h"
#include "panel-0.h"
#include "panel-1.h"
#include "panel-2.h"
#include "panel-3.h"

void setup() {
  Serial.begin(115200);
  
  for (byte i = 0; i < sizeof(CP_BUTTON_PIN); i++) {
    pinMode(CP_BUTTON_PIN[i], INPUT_PULLUP);
  }

  panel0_setup();
  gamepad.begin(false);
  Mouse.begin();
  Keyboard.begin();
}

void loop(){
  // Read DIP state to see if joystick has changed
  setActivePanel();

  // Read any serial data
  if (Serial.available() > 0) {
    readSerialData();
  }

  // set a neutral state to debounce panel changes
  gamepad.setXAxis(AXIS_LIMIT);
  gamepad.setYAxis(AXIS_LIMIT);
  for (byte i = 0; i < sizeof(JOY_BUTTON_PIN); i++) {
    gamepad.setButton(i, 0);
  }

  // Control Panel
  for (byte i = 0; i < sizeof(CP_BUTTON_PIN); i++) {
    if (!digitalRead(CP_BUTTON_PIN[i])) {
      if (!cpButtonActive[PLAYER][i]) {
        cpButtonActive[PLAYER][i] = true;
        Keyboard.press(CP_BUTTON_KEY[PLAYER][i]);
        delay(40); // need this to get keys to read accurately, would be better to continue to allow execution and use a timer to release the key
      }
    } else if (cpButtonActive[PLAYER][i]) {
      cpButtonActive[PLAYER][i] = false;
      Keyboard.releaseAll();
    }
  }

  switch (activePanel) {
    case 0:
      panel0_loop();
      break;
    case 1:
      panel1_loop();
      break;
    case 2:
      panel2_loop();
      break;
    case 3:
      panel3_loop();
      break;
  }
  
  gamepad.sendState();
  delay(10);
}

void setActivePanel() {
  int newActivePanel = 0;
  
  bitWrite(newActivePanel, 0, digitalRead(PANEL_DIP_PIN[0]));
  bitWrite(newActivePanel, 1, digitalRead(PANEL_DIP_PIN[1]));
  bitWrite(newActivePanel, 2, digitalRead(PANEL_DIP_PIN[2]));

  if (newActivePanel != activePanel) {
    activePanel = newActivePanel;
    
    switch (activePanel) {
      case 0:
        panel0_setup();
        break;
      case 1:
        panel1_setup();
        break;
      case 2:
        panel2_setup();
        break;
      case 3:
        panel3_setup();
        break;
    }
  }
}

void readSerialData() {
  // serial data format x:y (x = 4 or 8 for joystick type, y = number of buttons to light)
  byte ndx = 0;
  char rc;
  char receivedData[3];
  boolean exitRead = false;
  
  while (Serial.available() > 0 && !exitRead && ndx < 3) {
    rc = Serial.read();
  
    if (rc != SERIAL_TERMINATE) {
      receivedData[ndx] = rc;
      ndx++;
    } else {
      boolean controllerIs4Way = (receivedData[0] == CONTROLLER_4_WAY);
      int buttonCount = (int) receivedData[2] - 48; // convert char to int

      Serial.print("ACK");
      
      switch (activePanel) {
        case 0:
          panel0_handleSerialData(controllerIs4Way, buttonCount);
          break;
        case 1:
          panel1_handleSerialData(controllerIs4Way, buttonCount);
          break;
        case 2:
          panel2_handleSerialData(controllerIs4Way, buttonCount);
          break;
        case 3:
          panel3_handleSerialData(controllerIs4Way, buttonCount);
          break;
      }
      exitRead = true;
    }
  }
}
