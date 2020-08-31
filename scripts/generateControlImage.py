#!/usr/bin/python3
import xml.etree.ElementTree as ET
import os
import shutil
import csv

class ControlImageGenerator():

    GAMELIST_PATH = '/Volumes/share/Media/Arcade/assets/romlist/Arcade.txt'
    JOYSTICK_IMAGE_PATH = '/Volumes/share/Media/Arcade/media/arcade/launching_joystick/'
    TRACKBALL_IMAGE_PATH = '/Volumes/share/Media/Arcade/media/arcade/launching_trackball/'

    DESTINATION_PATH ='/Volumes/share/Media/Arcade/emulationstation/arcade/images2/'

    IMG_EXT = '.png'

    __trackball_images = []
    __joystick_images = []

    __cur = -1
    __total = 0

    __dry_run = True

    def __init__(self, dry_run = True):
        self.__dry_run = dry_run

        with open(self.GAMELIST_PATH) as csvfile:
            reader = csv.reader(csvfile, delimiter=";")
            self.__total = sum(1 for row in reader) - 1

    def copyImages(self):
        with open(self.GAMELIST_PATH) as csvfile:
            reader = csv.reader(csvfile, delimiter=";")
            for row in reader:
                self.__cur = self.__cur + 1
                romname = row[0]
                controls = row[9]

                if ("trackball" in controls or "Trackball" in controls):
                    self.copyTrackballImage(romname)
                else:
                    self.copyJoystickImage(romname)

    def copyTrackballImage(self, romname):
        if (os.path.isfile(self.TRACKBALL_IMAGE_PATH + romname + self.IMG_EXT)):
            self.__trackball_images.append(romname)
            self.copyImage("Trackball", self.TRACKBALL_IMAGE_PATH + romname + self.IMG_EXT, romname)
        elif (os.path.isfile(self.JOYSTICK_IMAGE_PATH + romname + self.IMG_EXT)):
            self.copyJoystickImage(romname)

    def copyJoystickImage(self, romname):
        if (os.path.isfile(self.JOYSTICK_IMAGE_PATH + romname + self.IMG_EXT)):
            self.__joystick_images.append(romname)
            self.copyImage("Joystick", self.JOYSTICK_IMAGE_PATH + romname + self.IMG_EXT, romname)
        else:
            print("{}/{}, NO IMAGE: {}".format(self.__cur, self.__total, romname))


    def copyImage(self, panelType, source, romname):
        print("{}/{}, {}: {} -> {}".format(self.__cur, self.__total, panelType, source, self.DESTINATION_PATH + romname + '-launching' + self.IMG_EXT))
        if (not self.__dry_run):
            shutil.copy2(source, self.DESTINATION_PATH + romname + '-launching' + self.IMG_EXT)

    def deleteUnnecessaryImages(self):
        for entry in os.listdir(self.TRACKBALL_IMAGE_PATH):
            if (os.path.splitext(entry)[0] not in self.__trackball_images):
                print("DELETE: {}".format(self.TRACKBALL_IMAGE_PATH + entry))
                if (not self.__dry_run):
                    os.remove(self.TRACKBALL_IMAGE_PATH + entry)

        for entry in os.listdir(self.JOYSTICK_IMAGE_PATH):
            if (os.path.splitext(entry)[0] not in self.__joystick_images):
                print("DELETE: {}".format(self.JOYSTICK_IMAGE_PATH + entry))
                if (not self.__dry_run):
                    os.remove(self.JOYSTICK_IMAGE_PATH + entry)

    ## Utility function to remove "-launching" from all files in a directory
    def removeLaunching(self, fromPath):
        for entry in os.listdir(fromPath):
            if "-launching" in entry and entry[0] != ".":
                newEntry = entry.replace("-launching", "")
                print("{} -> {}".format(fromPath + entry, fromPath + newEntry))
                if (not self.__dry_run):
                    os.rename(fromPath + entry, fromPath + newEntry)




imgGenerator = ControlImageGenerator(dry_run = False)
# imgGenerator.removeLaunching('/Volumes/share/Media/Arcade/media/arcade/launching_joystick/')
imgGenerator.copyImages()
imgGenerator.deleteUnnecessaryImages()