#ifndef _GLOBALS_H
#define _GLOBALS_H

/*
 * NOTE DIFFERENCES FROM PCB:
 * pin 17 is used for the onboard LED and seems to randomly bounce, therefore do not use pin 17
 * Instead:
 * Player Up is 13 instead of 17. Pin 13 is marked as Z2 on the Panel PCB, wire UP to that
 * Pin 13 is used for the rZ axis as well, so you cant have a panel with a z axis and "up" in this case
 */

/**
 * Constants
 */
const int16_t PLAYER = 1;                // switch to 1 for player 2 microcontroller
const int16_t AXIS_MAX = 1024;           // The highest value the controller axis should have
const int16_t AXIS_LIMIT = AXIS_MAX / 2; // The neutral state of the axis (in the middle)
const int16_t ENCODER_LIMIT = 256;       // The highest value an encoder can reach
const byte JOY_UP_PIN = PIN_Z2;
const byte JOY_DOWN_PIN = PIN_DOWN;
const byte JOY_LEFT_PIN = PIN_LEFT;
const byte JOY_RIGHT_PIN = PIN_RIGHT;
const byte JOY_BUTTON_PIN[] = {PIN_B0, PIN_B1, PIN_B2, PIN_B3, PIN_B4, PIN_B5, PIN_Z1, PIN_Y2, PIN_Y1, PIN_X2, PIN_X1, PIN_UP};
const byte CP_BUTTON_PIN[] = {PIN_MAIN_18, PIN_MAIN_19, PIN_MAIN_20, PIN_MAIN_21, PIN_MAIN_22};
const byte CP_BUTTON_KEY[][sizeof(CP_BUTTON_PIN)] = {{'1','5',KEY_F1,KEY_ESC,'p'},{'2','6','l','-','c'}};
const byte PANEL_DIP_PIN[] = {PIN_DIP_0, PIN_DIP_1, PIN_DIP_2};

/**
 * Global Variables
 */
int activePanel = -1;
byte cpButtonActive[][sizeof(CP_BUTTON_PIN)] = {{false,false,false,false,false},{false,false,false,false,false}};

// The Player Joystick, wired to the panel PCB - comprises all possible options that could be connected
Joystick_ gamepad(
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

Encoder mouseX(PIN_Y1, PIN_Y2);
Encoder mouseY(PIN_X1, PIN_X2);
Encoder mouseZ(PIN_Z1, PIN_Z2);

Servo restrictorPlate;

#endif
