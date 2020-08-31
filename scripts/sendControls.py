#!/usr/bin/python3
import sys
import time
import serial
import serial.tools.list_ports
import xml.etree.ElementTree as ET
import csv

class SendControls():
    #paths on mac
    GAMELIST_PATH = '/Volumes/share/Media/Arcade/assets/romlist/Arcade.txt'

    #paths on arcade
    # GAMELIST_PATH = '/mnt/share/assets/romlist/Arcade.txt'

    def getSerialDataFromGamelist(self, game):
        with open(self.GAMELIST_PATH) as csvfile:
            reader = csv.reader(csvfile, delimiter=";")
            for row in reader:
                # gamelist format:
                # Name;Title;Emulator;CloneOf;Year;Manufacturer;Category;Players;Rotation;Control;Status;DisplayCount;DisplayType;AltRomname;AltTitle;Extra;Buttons
                # serial data is held in the status column
                romname = row[0]
                if (romname == game):
                    return row[10]

        # Assume the controller is 8 way and all buttons are used
        return "8:6"

    def getSerialData(self, controllerIs4Way, buttonCount):
        return "{}:{}".format(("4" if controllerIs4Way else "8"), str(buttonCount))

    def writeGameSerialData(self, game):
        gameData = self.getSerialDataFromGamelist(game)
        print("writing \"{}\"".format(gameData))
        self.writeSerialData(gameData)

    def writeDefaultSerialData(self):
        output = self.getSerialData(False, 6)
        self.writeSerialData(output)

    def writeSerialData(self, output):
        ports = serial.tools.list_ports.comports()
        for port, desc, hwid in sorted(ports):
            if "Arduino" in desc:
                ser = serial.Serial(port, 115200, write_timeout=0, timeout=2)
                time.sleep(.1)
                ser.flush()
                print("writing \"{}\" to {}".format(output, port))
                try:
                    ser.write(str.encode(output + "\n"))
                except Exception as e:
                    sys.stderr.write('Failed to send serial data: \"{}\"\n'.format(str(e)))

                data = ser.readline()
                print("Received: \"{}\"".format(data));
                ser.close()


sendControls = SendControls()
if len(sys.argv) >= 2:
    sendControls.writeGameSerialData(sys.argv[1])
else:
    output = sendControls.getSerialData(False, 6)
    sendControls.writeSerialData(output)