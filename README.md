# ArcadeController
The goal of this project is to make an easily-swappable control panel for a homebuilt arcade. There are two PCBs that are designed to mate through the PCB edge connection. By default, this setup will allow for any control panel to have a maximum of 2 joysticks and 14 buttons (22 total digital inputs), 6 axes (e.g. 6 spinners) and two USB devices. You can easily edit the program on the arduino to assure all of your control panels will work, though, for instance if you need more digital inputs and fewer axes.

As I build out more control panels I'll be adding pictures and diagrams of how everything operates.

## Electronics
### PCB: Panel
One Panel PCB exists for each control panel. The Panel PCB exists as the interface between the controls (joysticks, trackballs, spinners, USB devices) and the Main interface. It is split into various sections. Full wiring diagrams can be found in the docs directory.

![](assets/ArcadeController-PCB.png?raw=true)

**Player One** Four directional wires, 6 button wires. Connected to "Player One" Micro.

**Player Two** Four directional wires, 6 button wires. Connected to "Player Two" Micro.

**USB one** These are used for encoder connections (trackball, spinner) Connected to "Player One" Micro.

**USB two** These are used for encoder connections (trackball, spinner) Connected to "Player Two" Micro.

**USB three, four** These directly wire to USB connection on the main control panel. These can be used to directly connect USB devices to your computer.

**Expansion** These were originally intended as general use/reprogrammable spots, but some gotten taken up in development. These connect to interrupt pins on the arduinos, and are used for encoder connections (trackball, spinner)

### PCB: Main

The Main PCB is what connects to your computer through USB. In total it requires four open USB ports. Only One Main PCB is necessary. The main panels houses two Arduino Micros.

![](assets/ArcadeMain-PCB.png?raw=true)

**Micro Headers** These are the positions where you plug in Arduino Micros.

**Screw in Terminals** These can be used for shared functions e.g. Player 1/2 Start/Coin as well as menu or function buttons. 1-6 are connected to "Player One" Micro, 7-12 are connected to "Player Two" Micro.

### Arduino

The program is built to run on an [Ardunio Micro](https://store.arduino.cc/usa/arduino-micro). Two Arduino Micros are required for two-player functionality. Player One and the two additional USB devices will work fine with just one, though, if you can get away with a maximum of 17 total digital inputs on any control panel.

When plugged in the Arduinos will be treated as a joystick by the computer. The joystick, by default is 5 axis (X/Y, rX/rY/rZ) and 13 button.

---

Schematics were designed in [Kicad](https://kicad-pcb.org/). I print PCBS with [JLCPCB](jlcpcb.com/).

# Documents
### [Pinmap](docs/pinmap.md)
The pinmap outlines how connections are bridged between the PCBs and how they function by default through USB. Panel->Main->Arduino->Function

### [Wiring](docs/wiring.md)
The wiring doc outlines standard wiring for trackballs and spinners directly into the Panel PCB.

# Supplies
_Prices are USD, do not include shipping, and are as of July 2020._

Buy extra screw-in terminals to make more control panels, and buy the Panel PCBs in bulk. Given the below prices you could create 10 easily-swappable control panels for ~$80, and you may be able to find those screw terminals more cheaply, or decide to bypass those, just solder in your connections and have it all for ~$40. Of course the price of buttons/joysticks/trackballs/steering wheels/etc is additional.

| Component | Part | Supply | Cost | Count |
|----------|----------|----------|----------|----------|
| Main | Arduino Micro | [Ardunio Store](https://store.arduino.cc/usa/arduino-micro-without-headers) | $12.30 | 2 |
| Main | PCB | [JLCPCB](jlcpcb.com/) | $7.00 | 1 (price is per 5 though - _minimum order_) |
| Main | Micro USB | [Digikey](https://www.digikey.com/product-detail/en/molex/0475890001/WM17143CT-ND/1832255) | $.87 | 2 |
| Main | Card Edge Connector | [Digikey](https://www.digikey.com/product-detail/en/hirose-electric-co-ltd/CR22A-44D-2.54DSA(70)/H122591-ND/5148616) | $6.10 | 1 |
| Main | Micro Pin Headers | [Digikey](https://www.digikey.com/product-detail/en/sullins-connector-solutions/PREC040SAAN-RC/S1012EC-40-ND/2774814) | $.51 | 2 |
| Main | Micro connection headers | [Digikey](https://www.digikey.com/product-detail/en/adafruit-industries-llc/598/1528-2537-ND/8299908) | $2.95 | 1 (cut each down to 17 pins) |
| Main+Panel | Screw-in Terminal | [Digikey](https://www.digikey.com/products/en?keywords=TB001-500-12BE%20) | $1.73 | 5 (+4 for each additional panel) |
| Panel | PCB | [JLCPCB](jlcpcb.com/) | $12.00 | 1 (price was for 10) |

_Why do the PCBs have the Slurm logo on them? I dont know, I just really like Futurama and happened to have this image handy..._
