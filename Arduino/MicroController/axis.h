#ifndef _AXIS_H
#define _AXIS_H

#include "pinmap.h"
#include "globals.h"

void setGamepadYAxis(byte up_pin, byte down_pin) {
  if (!digitalRead(up_pin)) {
    gamepad.setYAxis(AXIS_MAX);
  } else if (!digitalRead(down_pin)) {
    gamepad.setYAxis(0);
  } else {
    gamepad.setYAxis(AXIS_LIMIT);
  }
}

void setGamepadXAxis(byte left_pin, byte right_pin) {
  if (!digitalRead(right_pin)) {
    gamepad.setXAxis(AXIS_MAX);
  } else if (!digitalRead(left_pin)) {
    gamepad.setXAxis(0);
  } else {
    gamepad.setXAxis(AXIS_LIMIT);
  }
}

int getMouseAxisValue(int encoderValue, int sensitivity, bool flip) {
  int newValue = constrain(encoderValue * sensitivity * (flip ? -1 : 1), -ENCODER_LIMIT, ENCODER_LIMIT);
  newValue = map(newValue, -ENCODER_LIMIT, ENCODER_LIMIT, -AXIS_LIMIT, AXIS_LIMIT);
  return newValue;
}

#endif
