#!/usr/bin/python3
import sys
import time
import serial
import serial.tools.list_ports
import xml.etree.ElementTree as ET

class SendControls():

    XML_PATH = '/mnt/share/assets/ini/controls.xml'

    def getGameDataFromXML(self, game):
        tree = ET.parse(self.XML_PATH)
        root = tree.getroot()
        game = root.findall("game[@romname='" + game + "']")
        if (len(game) > 0):
            game = game[0];

            player = game.find('player')
            numButtons = '6'
            controlConstant = 'joy8way'

            if player is not None:
                numButtons = player.get('numButtons')
                control = player.find('controls').find('control')
                controlConstant = control.find('constant').get('name')

            return [(controlConstant in {"joy4way", "joy2way", "doublejoy4way", "vdoublejoy2way", "vjoy2way"}), numButtons]

        # Assume the controller is 8 way and all buttons are used
        return [False, 6]

    def getSerialData(self, controllerIs4Way, buttonCount):
        return "{}:{}".format(("4" if controllerIs4Way else "8"), str(buttonCount))

    def writeGameSerialData(self, game):
        gameData = self.getGameDataFromXML(game)
        output = self.getSerialData(gameData[0], gameData[1])
        self.writeSerialData(output)

    def writeDefaultSerialData(self):
        output = self.getSerialData(False, 6)
        self.writeSerialData(output)

    def writeSerialData(self, output):
        ports = serial.tools.list_ports.comports()
        for port, desc, hwid in sorted(ports):
            if "Arduino" in desc:
                ser = serial.Serial(port, 115200, write_timeout=5, timeout=5)
                time.sleep(1)
                ser.flush()
                print("writing \"{}\" to {}".format(output, port))
                try:
                    ser.write(str.encode(output + "\n"))
                except:
                    print("timeout")
                ser.close()


sendControls = SendControls()
if len(sys.argv) >= 2:
    sendControls.writeGameSerialData(sys.argv[1])
else:
    sendControls.writeDefaultSerialData()
