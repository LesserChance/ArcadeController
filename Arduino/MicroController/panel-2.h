#ifndef _PANEL_2_H
#define _PANEL_2_H

#include "pinmap.h"
#include "globals.h"
#include "axis.h"

const float PANEL_2_X_SENSITIVITY = 1;        // 1 tick on the encoder for the X axis is this many ticks on the axis

/**
 * Panel 2: 360 wheel games games
 * Wheel as Mouse on pins X1,X2 (Horizontal)
 * Button pins: 6, 7, 8
 * Buttons LED pins: 9, 10, 11
 */
void panel2_setup() {
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

void panel2_loop() {
  Mouse.move(
    getMouseAxisValue(mouseAxis2.read(), PANEL_2_X_SENSITIVITY, true),
    0,
    0);
  mouseAxis2.write(0);

  // Read button switches
  gamepad.setButton(0, !digitalRead(PIN_B0));
  gamepad.setButton(1, !digitalRead(PIN_B1));
  gamepad.setButton(2, !digitalRead(PIN_B2));
}

void panel2_handleSerialData(boolean controllerIs4Way, int buttonCount) {
  digitalWrite(PIN_B3, buttonCount >= 1);
  digitalWrite(PIN_B4, buttonCount >= 2);
  digitalWrite(PIN_B5, buttonCount >= 3);
}

#endif
