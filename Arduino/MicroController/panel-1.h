#ifndef _PANEL_1_H
#define _PANEL_1_H

#include "pinmap.h"
#include "globals.h"
#include "axis.h"

const int16_t SENSITIVITY_RX = 2;        // 1 tick on the encoder for the X axis is this many ticks on the axis
const int16_t SENSITIVITY_RY = 2;        // 1 tick on the encoder for the Y axis is this many ticks on the axis

/**
 * Panel 1: Trackball games
 * Trackball as Mouse on pins X1,X2 (Horizontal) and Y1,Y2 (Vertical)
 * Button pins: 6,  7, 8
 */
void panel1_setup() {
  // Button switches
  pinMode(PIN_B0, INPUT_PULLUP);
  pinMode(PIN_B1, INPUT_PULLUP);
  pinMode(PIN_B2, INPUT_PULLUP);

  // mouse axis
  pinMode(PIN_X1, INPUT_PULLUP);
  pinMode(PIN_X2, INPUT_PULLUP);
  pinMode(PIN_Y1, INPUT_PULLUP);
  pinMode(PIN_Y2, INPUT_PULLUP);
}

void panel1_loop() {
  Mouse.move(
    getMouseAxisValue(mouseX.read(), SENSITIVITY_RX, false),
    getMouseAxisValue(mouseY.read(), SENSITIVITY_RY, false),
    0);
  mouseX.write(0);
  mouseY.write(0);

  // Read button switches
  gamepad.setButton(0, !digitalRead(PIN_B0));
  gamepad.setButton(1, !digitalRead(PIN_B1));
  gamepad.setButton(2, !digitalRead(PIN_B2));
}

void panel1_handleSerialData(boolean controllerIs4Way, int buttonCount) {
  // no op
}

#endif
