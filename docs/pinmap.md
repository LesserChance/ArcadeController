
## Panel PCB
### Joystick
| Controller Input | Arduino | Arduino Pin | Function |
|----------|----------|----------|----------|
| UP | 1/2 | SS/D17 | Up |
| DOWN | 1/2 |  SCL/D3 | Down |
| LEFT | 1/2 |  A6/D4 | Left |
| RIGHT | 1/2 |  D5 | Right |
| BUTTON 1 | 1/2 |  A7/D6 | Button One |
| BUTTON 2 | 1/2 |  D7 | Button Two |
| BUTTON 3 | 1/2 |  A8/D8 | Button Three |
| BUTTON 4 | 1/2 |  A9/D9 | Button Four |
| BUTTON 5 | 1/2 |  A10/D10 | Button Five |
| BUTTON 6 | 1/2 |  D11 | Button Six |

### USB ONE
| Controller Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| RED | 1 | A11/D12 | Player One - Button Seven |
| WHITE | 1 | D13 | Player One Axis Z - Z2 |
| GREEN | 1 | D14/MISO | Player One Axis Y - Y2 |
| BLACK | 1 | D15/SCK | Player One Axis X - X2 |

### USB TWO
| Controller Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| RED | 2 | A11/D12 | Player Two - Button Seven |
| WHITE | 2 | D13 | Player Two Axis Z - Z2 |
| GREEN | 2 | D14/MISO | Player Two Axis Y - Y2 |
| BLACK | 2 | D15/SCK | Player Two Axis X - X2 |

### EXPANSION
(interrupt enabled)
| Controller Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| RED | 2 | TX/D1 | Player Two Axis Z - Z1 |
| WHITE | 2 | RX/D0 | Player Two Axis X - X1 |
| GREEN | 2 | SDA/D2 | Player Two Axis Y - Y1 |
| BLACK | 1 | TX/D1 | Player One Axis Z - Z1 |
| BLUE | 1 | RX/D0 | Player One Axis X - X1 |
| YELLOW | 1 | SDA/D2 | Player One Axis Y - Y1 |

### USB THREE/FOUR
| Controller Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| RED | - | - | USB Device - Red |
| WHITE | - | - | USB Device - White |
| GREEN | - | - | USB Device - Green |
| BLACK | - | - | USB Device - Black |

## Main PCB
### SCREW IN TERMINALS
(analog pins)
| Main Input | Arduino |  Arduino Pin | Function |
|----------|----------|----------|----------|
| A0 | 1/2 | A0/D18 | Button Eight |
| A1 | 1/2 | A1/D19 | Button Nine |
| A2 | 1/2 | A2/D20 | Button Ten |
| A3 | 1/2 | A3/D21 | Button Eleven |
| A4 | 1/2 | A4/D22 | Button Twelve |
| A5 | 1/2 | A5/D23 | Button Thirteen |