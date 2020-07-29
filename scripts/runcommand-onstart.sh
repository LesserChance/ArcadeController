#!/bin/bash

fullromname=$3
romfilename=$(basename "$fullromname")
romname="${romfilename%.*}"
python /home/pi/scripts/sendControls.py $romname