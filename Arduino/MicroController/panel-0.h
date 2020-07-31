#ifndef _PANEL_0_H
#define _PANEL_0_H

#include "pinmap.h"
#include "globals.h"
#include "axis.h"

/**
 * Panel 0: Catch-all 6 buttons
 * Joystick: 4-8 ways switchable (pin X to 0 for 4-way, 1 for 8 way)
 * Button pins:      6,  7, 8,  9, 10, 11
 * Buttons LED pins: 1, 14, 2, 15,  0, 13 (player one only)
 * controller type pins: 1, 14, 2, 15,  0, 13 (player two only)
 */
void panel0_setup() {
  Serial.println("panel0_setup");
  // Joystick switches
  pinMode(PIN_Z2, INPUT_PULLUP);        // up is wired to Z2
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);

  // Button switches
  pinMode(PIN_B0, INPUT_PULLUP);
  pinMode(PIN_B1, INPUT_PULLUP);
  pinMode(PIN_B2, INPUT_PULLUP);
  pinMode(PIN_B3, INPUT_PULLUP);
  pinMode(PIN_B4, INPUT_PULLUP);
  pinMode(PIN_B5, INPUT_PULLUP);
  
  if (PLAYER == 0) {
    // LED output
    pinMode(PIN_X1, OUTPUT);
    pinMode(PIN_X2, OUTPUT);
    pinMode(PIN_Y1, OUTPUT);
    pinMode(PIN_Y2, OUTPUT);
    pinMode(PIN_Z1, OUTPUT);
    pinMode(PIN_UP, OUTPUT);
  
    digitalWrite(PIN_X1, 0);
    digitalWrite(PIN_X2, 0);
    digitalWrite(PIN_Y1, 0);
    digitalWrite(PIN_Y2, 0);
    digitalWrite(PIN_Z1, 0);
    digitalWrite(PIN_UP, 0);
  }
  
  if (PLAYER == 1) {
    // Restrictor plate output
    pinMode(PIN_X2, OUTPUT);
    restrictorPlate.attach(PIN_X2);
  }
}

void panel0_loop() {
  // Read joystick switches
  setGamepadXAxis(PIN_LEFT, PIN_RIGHT);
  setGamepadYAxis(PIN_Z2, PIN_DOWN);

  // Read button switches
  gamepad.setButton(0, !digitalRead(PIN_B0));
  gamepad.setButton(1, !digitalRead(PIN_B1));
  gamepad.setButton(2, !digitalRead(PIN_B2));
  gamepad.setButton(3, !digitalRead(PIN_B3));
  gamepad.setButton(4, !digitalRead(PIN_B4));
  gamepad.setButton(5, !digitalRead(PIN_B5));
}

void setRestictor4Way() {
  restrictorPlate.write(180); 
}

void setRestictor8Way() {
  restrictorPlate.write(0); 
}

void panel0_handleSerialData(boolean controllerIs4Way, int buttonCount) {
  if (PLAYER == 0) {
    // LED output
    digitalWrite(PIN_X1, buttonCount >= 1);
    digitalWrite(PIN_X2, buttonCount >= 2);
    digitalWrite(PIN_Y1, buttonCount >= 3);
    digitalWrite(PIN_Y2, buttonCount >= 4);
    digitalWrite(PIN_Z1, buttonCount >= 5);
    digitalWrite(PIN_UP, buttonCount >= 6);
  }
  
  if (PLAYER == 1) {
    // Restrictor plate output
    if (controllerIs4Way) {
      setRestictor4Way();
    } else {
      setRestictor8Way();
    }
  }
}

#endif
