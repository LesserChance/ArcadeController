EESchema Schematic File Version 4
LIBS:ArcadePanel-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Arcade Control Panel"
Date "2020-07-14"
Rev "v2.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x08 J4
U 1 1 5F15BF02
P 6850 4200
F 0 "J4" V 6950 4550 50  0000 R CNN
F 1 "Screw_Terminal_01x08" V 6950 4450 50  0000 R CNN
F 2 "TB001-500-08BE:CUI_TB001-500-08BE" H 6850 4200 50  0001 C CNN
F 3 "~" H 6850 4200 50  0001 C CNN
	1    6850 4200
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x10 J5
U 1 1 5F165B1A
P 4750 4150
F 0 "J5" V 4850 3600 50  0000 L CNN
F 1 "Screw_Terminal_01x10" V 4850 3700 50  0000 L CNN
F 2 "TB001-500-10BE:CUI_TB001-500-10BE" H 4750 4150 50  0001 C CNN
F 3 "~" H 4750 4150 50  0001 C CNN
	1    4750 4150
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x10 J2
U 1 1 5F1675AC
P 3750 4150
F 0 "J2" V 3850 3600 50  0000 L CNN
F 1 "Screw_Terminal_01x10" V 3850 3700 50  0000 L CNN
F 2 "TB001-500-10BE:CUI_TB001-500-10BE" H 3750 4150 50  0001 C CNN
F 3 "~" H 3750 4150 50  0001 C CNN
	1    3750 4150
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x10 J1
U 1 1 5F168AF0
P 7750 4200
F 0 "J1" V 7850 4600 50  0000 C CNN
F 1 "Screw_Terminal_01x10" V 7850 4100 50  0000 C CNN
F 2 "TB001-500-10BE:CUI_TB001-500-10BE" H 7750 4200 50  0001 C CNN
F 3 "~" H 7750 4200 50  0001 C CNN
	1    7750 4200
	0    1    1    0   
$EndComp
$Comp
L 2020-07-14_18-22-10:SBH11-PBPC-D25-ST-BK J3
U 1 1 5F168F33
P 3250 3000
F 0 "J3" V 3800 3000 50  0000 L CNN
F 1 "SBH11-PBPC-D25-ST-BK" V 3800 1950 50  0000 L CNN
F 2 "ul_SBH11PBPCD25STBK:SBH11-PBPC-D25-ST-BK" H 3250 3000 50  0001 C CNN
F 3 "~" H 3250 3000 50  0001 C CNN
	1    3250 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3250 3950 3250 3000
Wire Wire Line
	3350 3950 3350 3000
Wire Wire Line
	3450 3950 3450 3000
Wire Wire Line
	3550 3000 3550 3950
Wire Wire Line
	3650 3950 3650 3000
Wire Wire Line
	3750 3000 3750 3950
Wire Wire Line
	3850 3950 3850 3000
Wire Wire Line
	3950 3950 3950 3000
Wire Wire Line
	4050 3950 4050 3000
Wire Wire Line
	4150 3950 4150 3000
Wire Wire Line
	4350 3000 4350 3950
Wire Wire Line
	4450 3950 4450 3000
Wire Wire Line
	4550 3000 4550 3950
Wire Wire Line
	4650 3950 4650 3000
Wire Wire Line
	4750 3000 4750 3950
Wire Wire Line
	4850 3950 4850 3000
Wire Wire Line
	4950 3950 4950 3000
Wire Wire Line
	7150 3000 7150 4000
Text Label 5150 3800 1    50   ~ 0
+5v
Text Label 5050 3800 1    50   ~ 0
GND
Text Label 3250 3800 1    50   ~ 0
P1-UP
Text Label 3350 3800 1    50   ~ 0
P1-DOWN
Text Label 3450 3800 1    50   ~ 0
P1-LEFT
Text Label 3550 3800 1    50   ~ 0
P1-RIGHT
Text Label 3650 3800 1    50   ~ 0
P1-B0
Text Label 3750 3800 1    50   ~ 0
P1-B1
Text Label 3850 3800 1    50   ~ 0
P1-B2
Text Label 3950 3800 1    50   ~ 0
P1-B3
Text Label 4050 3800 1    50   ~ 0
P1-B4
Text Label 4150 3800 1    50   ~ 0
P1-B5
Text Label 4350 3800 1    50   ~ 0
P1-B7
Text Label 4550 3800 1    50   ~ 0
P1-X2
Text Label 4650 3800 1    50   ~ 0
P1-Y1
Text Label 4750 3800 1    50   ~ 0
P1-Y2
Text Label 4850 3800 1    50   ~ 0
P1-Z1
Text Label 4950 3800 1    50   ~ 0
P1-Z2
Text Label 8150 3800 1    50   ~ 0
P2-UP
Text Label 8050 3800 1    50   ~ 0
P2-DOWN
Text Label 7950 3800 1    50   ~ 0
P2-LEFT
Text Label 7850 3800 1    50   ~ 0
P2-RIGHT
Text Label 7750 3800 1    50   ~ 0
P2-B0
Text Label 7650 3800 1    50   ~ 0
P2-B1
Text Label 7550 3800 1    50   ~ 0
P2-B2
Text Label 7450 3800 1    50   ~ 0
P2-B3
Text Label 7350 3800 1    50   ~ 0
P2-B4
Text Label 7250 3800 1    50   ~ 0
P2-B5
Wire Wire Line
	8150 4000 8150 3000
Wire Wire Line
	8050 4000 8050 3000
Wire Wire Line
	7950 4000 7950 3000
Wire Wire Line
	7850 4000 7850 3000
Wire Wire Line
	7750 4000 7750 3000
Wire Wire Line
	7650 4000 7650 3000
Wire Wire Line
	7550 4000 7550 3000
Wire Wire Line
	7450 4000 7450 3000
Wire Wire Line
	7350 4000 7350 3000
Wire Wire Line
	7250 4000 7250 3000
Text Label 7150 3800 1    50   ~ 0
P2-B6
Text Label 4250 3800 1    50   ~ 0
P1-B6
Text Label 6950 3800 1    50   ~ 0
P2-X1
Text Label 6850 3800 1    50   ~ 0
P2-X2
Text Label 6750 3800 1    50   ~ 0
P2-Y1
Text Label 6650 3800 1    50   ~ 0
P2-Y2
Text Label 6550 3800 1    50   ~ 0
P2-Z1
Text Label 6450 3800 1    50   ~ 0
P2-Z2
Wire Wire Line
	7050 4000 7050 3000
Wire Wire Line
	6950 4000 6950 3000
Wire Wire Line
	6850 4000 6850 3000
Wire Wire Line
	6750 4000 6750 3000
Wire Wire Line
	6650 4000 6650 3000
Wire Wire Line
	6550 4000 6550 3000
Wire Wire Line
	6450 4000 6450 3000
Text Label 7050 3800 1    50   ~ 0
P2-B7
Text Label 4450 3800 1    50   ~ 0
P1-X1
$Comp
L AU-Y1008-2:AU-Y1008-2 J6
U 1 1 5F153A04
P 6350 5250
F 0 "J6" V 6900 5300 60  0000 R CNN
F 1 "AU-Y1008-2" V 6900 5150 60  0000 R CNN
F 2 "AU-Y1008-2:AU-Y1008-2" H 6750 4790 60  0001 C CNN
F 3 "" H 6350 5250 60  0000 C CNN
	1    6350 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 4500 5150 4500
$Comp
L Device:R R1
U 1 1 5F1D1450
P 5000 4500
F 0 "R1" V 5000 4500 50  0000 L CNN
F 1 "10k" V 4950 4600 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4930 4500 50  0001 C CNN
F 3 "~" H 5000 4500 50  0001 C CNN
	1    5000 4500
	0    1    1    0   
$EndComp
Connection ~ 4650 5250
Wire Wire Line
	4650 5250 4650 5350
Connection ~ 4650 5150
Wire Wire Line
	4650 5150 4650 5250
Wire Wire Line
	4650 5050 4650 5150
$Comp
L Switch:SW_DIP_x04 SW1
U 1 1 5F15ACB2
P 4950 5150
F 0 "SW1" H 4950 4900 50  0000 C CNN
F 1 "SW_DIP_x04" V 5350 5200 50  0000 C CNN
F 2 "digikey-footprints:DIP-8_W7.62mm" H 4950 5150 50  0001 C CNN
F 3 "~" H 4950 5150 50  0001 C CNN
	1    4950 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 3000 4250 3950
Wire Wire Line
	5350 3000 5350 4600
Wire Wire Line
	5550 3000 5550 4800
Wire Wire Line
	5450 3000 5450 4700
$Comp
L Device:R R3
U 1 1 5F1A1DCF
P 5000 4700
F 0 "R3" V 5000 4700 50  0000 L CNN
F 1 "10k" V 4950 4800 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4930 4700 50  0001 C CNN
F 3 "~" H 5000 4700 50  0001 C CNN
	1    5000 4700
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 4800 4850 4700
$Comp
L Device:R R4
U 1 1 5F1A4A96
P 5000 4800
F 0 "R4" V 5000 4800 50  0000 L CNN
F 1 "10k" V 4950 4900 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4930 4800 50  0001 C CNN
F 3 "~" H 5000 4800 50  0001 C CNN
	1    5000 4800
	0    1    1    0   
$EndComp
Connection ~ 4850 4700
Connection ~ 4850 4500
Wire Wire Line
	5150 4600 5350 4600
Wire Wire Line
	5150 4700 5450 4700
Wire Wire Line
	5150 4800 5550 4800
Connection ~ 4850 4600
Wire Wire Line
	4850 4500 4850 4600
Wire Wire Line
	4850 4600 4850 4700
$Comp
L Device:R R2
U 1 1 5F19F1EF
P 5000 4600
F 0 "R2" V 5000 4600 50  0000 L CNN
F 1 "10k" V 4950 4700 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4930 4600 50  0001 C CNN
F 3 "~" H 5000 4600 50  0001 C CNN
	1    5000 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 4500 4650 4500
Text Label 4650 4500 0    50   ~ 0
GND
Wire Wire Line
	5050 3000 5050 3950
Wire Wire Line
	4650 5050 4650 4750
Connection ~ 4650 5050
Text Label 4650 4750 3    50   ~ 0
+5v
Wire Wire Line
	5150 3000 5150 3950
Wire Wire Line
	5250 3000 5250 4500
Wire Wire Line
	5250 4500 5250 5050
Connection ~ 5250 4500
Wire Wire Line
	5350 4600 5350 5150
Connection ~ 5350 4600
Wire Wire Line
	5350 5150 5250 5150
Wire Wire Line
	5450 4700 5450 5250
Connection ~ 5450 4700
Wire Wire Line
	5450 5250 5250 5250
Wire Wire Line
	5550 5350 5550 4800
Wire Wire Line
	5250 5350 5550 5350
Connection ~ 5550 4800
Wire Wire Line
	5650 3000 5650 5250
Wire Wire Line
	5750 3000 5750 5250
Wire Wire Line
	5850 3000 5850 5250
Wire Wire Line
	5950 3000 5950 5250
Wire Wire Line
	6050 3000 6050 5250
Wire Wire Line
	6150 3000 6150 5250
Wire Wire Line
	6250 3000 6250 5250
Wire Wire Line
	6350 3000 6350 5250
Text Label 5550 3800 1    50   ~ 0
DIP-1
Text Label 5450 3800 1    50   ~ 0
DIP-2
Text Label 5350 3800 1    50   ~ 0
DIP-3
Text Label 5250 3800 1    50   ~ 0
DIP-4
Text Label 6350 3800 1    50   ~ 0
USB-1
Text Label 6250 3800 1    50   ~ 0
USB-2
Text Label 6150 3800 1    50   ~ 0
USB-3
Text Label 6050 3800 1    50   ~ 0
USB-4
Text Label 5950 3800 1    50   ~ 0
USB-5
Text Label 5850 3800 1    50   ~ 0
USB-6
Text Label 5750 3800 1    50   ~ 0
USB-7
Text Label 5650 3800 1    50   ~ 0
USB-8
$EndSCHEMATC
