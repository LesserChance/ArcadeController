
## Panel PCB
### Joystick
| Controller Input | Arduino | Arduino Pin | Function | Note |
|----------|----------|----------|----------|----------|
| UP | 1/2 | SS/D17 | Player Up | Pin 17 is used for the LED, and MUST be a pulldown, wire this button to +5v, in retrospect I shouldn't have used this pin, as it looks like it randomly bounces. Ill probably swap it in the arduino code to the z axis pin or something. |
| DOWN | 1/2 | SCL/D3 | Player Down |  |
| LEFT | 1/2 |  A6/D4 | Player Left |  |
| RIGHT | 1/2 | D5 | Player Right |  |
| BUTTON 0 | 1/2 | A7/D6 | Player Button One |  |
| BUTTON 1 | 1/2 | D7 | Player Button Two |  |
| BUTTON 2 | 1/2 | A8/D8 | Player Button Three |  |
| BUTTON 3 | 1/2 | A9/D9 | Player Button Four |  |
| BUTTON 4 | 1/2 | A10/D10 | Player Button Five |  |
| BUTTON 5 | 1/2 | D11 | Player Button Six |  |
| BUTTON 6 | 1/2 | - | UNUSED |  |
| BUTTON 7 | 1/2 | - | UNUSED |  |

### AXIS
| Controller Input | Arduino | Arduino Pin | Function |
|----------|----------|----------|----------|
| X1 | 1/2 | RX/D0 | Player One Axis X - X1 |
| X2 | 1/2 | D15/SCK | Player One Axis X - X2 |
| Y1 | 1/2 | SDA/D2 | Player One Axis Y - Y1 |
| Y2 | 1/2 | D14/MISO | Player One Axis Y - Y2 |
| Z1 | 1/2 | TX/D1 | Player One Axis Z - Z1 |
| Z2 | 1/2 | D13 | Player One Axis Z - Z2 |

### USB ONE/TWO
| Controller Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| RED | - | - | USB Device - Red |
| WHITE | - | - | USB Device - White |
| GREEN | - | - | USB Device - Green |
| BLACK | - | - | USB Device - Black |

### DIP SWITCH
| Controller Input | Arduino | Arduino Pin | Function | Note |
|----------|----------|----------|----------|----------|
| DIP1 | 1/2 | A5/D23 | Program - Bit 0 |  |
| DIP2 | 1/2 | MOSI/D16 | Program - Bit 1 |  |
| DIP3 | 1/2 | A11/D12 | Program - Bit 2 |  |
| DIP4 | 1/2 | UNUSED | Program - Bit 3 |  |

## Main PCB
### SCREW IN TERMINALS
(analog pins)
| Main Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| A0 | 1/2 | A0/D18 | CP Button One |
| A1 | 1/2 | A1/D19 | CP Button Two |
| A2 | 1/2 | A2/D20 | CP Button Three |
| A3 | 1/2 | A3/D21 | CP Button Four |
| A4 | 1/2 | A4/D22 | CP Button Five |