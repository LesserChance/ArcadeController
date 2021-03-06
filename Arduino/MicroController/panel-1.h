#ifndef _PANEL_1_H
#define _PANEL_1_H

#include "pinmap.h"
#include "globals.h"
#include "axis.h"

const float PANEL_1_SENSITIVITY_X = 2;        // 1 tick on the encoder for the X axis is this many ticks on the axis
const float PANEL_1_SENSITIVITY_Y = 2;        // 1 tick on the encoder for the Y axis is this many ticks on the axis

/**
 * Panel 1: Trackball games
 * Trackball as Mouse on pins X1,X2 (Horizontal) and Y1,Y2 (Vertical)
 * Button pins: 6, 7, 8
 * Buttons LED pins: 9, 10, 11
 */
void panel1_setup() {
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
  pinMode(PIN_Y1, INPUT_PULLUP);
  pinMode(PIN_Y2, INPUT_PULLUP);
}

void panel1_loop() {
  Mouse.move(
    getMouseAxisValue(mouseAxis1.read(), PANEL_1_SENSITIVITY_X, false),
    getMouseAxisValue(mouseAxis2.read(), PANEL_1_SENSITIVITY_Y, false),
    0);
  mouseAxis1.write(0);
  mouseAxis2.write(0);

  // Read button switches
  gamepad.setButton(0, !digitalRead(PIN_B0));
  gamepad.setButton(1, !digitalRead(PIN_B1));
  gamepad.setButton(2, !digitalRead(PIN_B2));
}

void panel1_handleSerialData(boolean controllerIs4Way, int buttonCount) {
  digitalWrite(PIN_B3, buttonCount >= 1);
  digitalWrite(PIN_B4, buttonCount >= 2);
  digitalWrite(PIN_B5, buttonCount >= 3);
}

#endif
