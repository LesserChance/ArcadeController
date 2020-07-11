# Wiring
Using [Ultimarc](https://www.ultimarc.com/) trackballs and spinners, this would be the standard wiring.

Note that these just map to the rX, rY and rZ axes for each controller. You could re-wire or remap these based on your needs, for instance having a control panel with six spinners (sounds fun!) It is important to use at least one EXPANSION pin per axis, as these are interrupt enabled on the Arduino.

## Player One
### Trackball
| Wire | Connection | Function | Controller Input |
|----------|----------|----------|----------|
| Red | A | 5 Volts | +5v |
| Black | A | Ground | GND |
| Purple | A | X1 | EXPANSION - BLUE |
| Blue | A | X2 | USB ONE - BLACK |
| Red | B | 5 Volts | +5v |
| Black | B | Ground | GND |
| Yellow | B | Y1 | EXPANSION - YELLOW |
| Green | B | Y2 | USB ONE - GREEN |

## Spinner
| Wire | Function | Controller Input |
|----------|----------|----------|
| Brown | 5 Volts | +5v |
| White | Ground | GND |
| Yellow | X1 | EXPANSION - BLACK |
| Green | X2 | USB ONE - WHITE |

## Player Two
### Trackball
| Wire | Connection | Function | Controller Input |
|----------|----------|----------|----------|
| Red | A | 5 Volts | +5v |
| Black | A | Ground | GND |
| Purple | A | X1 | EXPANSION - WHITE |
| Blue | A | X2 | USB TWO - BLACK |
| Red | B | 5 Volts | +5v |
| Black | B | Ground | GND |
| Yellow | B | Y1 | EXPANSION - GREEN |
| Green | B | Y2 | USB TWO - GREEN |

## Spinner
| Wire | Function | Controller Input |
|----------|----------|----------|
| Brown | 5 Volts | +5v |
| White | Ground | GND |
| Yellow | X1 | EXPANSION - RED |
| Green | X2 | USB TWO - WHITE |