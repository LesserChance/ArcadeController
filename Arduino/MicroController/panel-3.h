#ifndef _PANEL_3_H
#define _PANEL_3_H

#include "pinmap.h"
#include "globals.h"
#include "axis.h"

const float PANEL_3_X_SENSITIVITY = .5;        // 1 tick on the encoder for the X axis is this many ticks on the axis

/**
 * Panel 3: tron
 * Spinner as Mouse on pins X1,X2 (Horizontal)
 * Joystick as Z2 (Up), Down, Left Right
 * Button pins: B0, B1, B2
 * Buttons LED pins: B3, B4, B5
 */
void panel3_setup() {
  // Joystick switches
  pinMode(PIN_Z2, INPUT_PULLUP); // up is wired to Z2
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
  
  // Button switches
  pinMode(PIN_B0, INPUT_PULLUP);
  pinMode(PIN_B1, INPUT_PULLUP);
  pinMode(PIN_B2, INPUT_PULLUP);
  
  // LED output
  pinMode(PIN_B3, OUTPUT);
  pinMode(PIN_B4, OUTPUT);
  pinMode(PIN_B5, OUTPUT);

  // mouse axis
  pinMode(PIN_X1, INPUT_PULLUP);
  pinMode(PIN_X2, INPUT_PULLUP);
}

void panel3_loop() {
  // Read joystick switches
  setGamepadXAxis(PIN_LEFT, PIN_RIGHT);
  setGamepadYAxis(PIN_Z2, PIN_DOWN);

  // Read Spinner
  Mouse.move(
    getMouseAxisValue(mouseAxis2.read(), PANEL_3_X_SENSITIVITY, true),
    0,
    0);
  mouseAxis2.write(0);

  // Read button switches
  gamepad.setButton(0, !digitalRead(PIN_B0));
  gamepad.setButton(1, !digitalRead(PIN_B1));
  gamepad.setButton(2, !digitalRead(PIN_B2));
}

void panel3_handleSerialData(boolean controllerIs4Way, int buttonCount) {
  digitalWrite(PIN_B3, buttonCount >= 1);
  digitalWrite(PIN_B4, buttonCount >= 2);
  digitalWrite(PIN_B5, buttonCount >= 3);
}

#endif
