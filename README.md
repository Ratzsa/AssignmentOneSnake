# Yrkesakademin Trollhättan
# Software Developer Electrical & Autonomous Vehicles

# SV23TR E. Programmering och utveckling av inbyggda system
# YH00260-2020-3

# Assignment 1: Etch-a-sketch & Snake

Using emulation: https://wokwi.com/projects/296234816685212169
Step 1 (G): Rewrite the code to C code. (Completed 2023-06-05)
Step 2 (VG): Implement the game Snake.

This assignment must be done on the Arduino UNO (ATmega328p) to practice programming on low resource hardware.

Joystick controls heavily inspired by and analogRead files from: https://github.com/aspcodenet/avrjoystick/tree/main
Display libraries from: https://github.com/aspcodenet/avrmax72

## TODO
Check libraries for licenses.
If license is GNU change to libraries with MIT licenses.
Implement Snake.

## Start
To understand what the code in max72xx.c does the first thing I did was to make the display light up each LED in order
and then clear the display via a clearScreen function when it was fully lit.
Next I implemented the joystick push button to also clear the screen, and have the LEDs after where I push the button light
up until display is fully lit, when it also cleared the screen.

## Etch-a-sketch 2023-06-04
For the etch-a-sketch (EAS) I kept the clearScreen function for the joystick push button. A setMarker function was also added.
The setMarker function takes pointers to x and y as input\\*1. Not absolutely necessary but probably good practice.
As the example code starts with the marker in the top right corner in every reset the variable x had to start with a
value of 15 and y with a value of 0.

In every loop the following happens:
The joystick button is checked. If pressed, the display is cleared.
The marker coordinates are set via the setMarker function. So even if the display is cleared, the LED where the marker is at
is turned on so the user knows where they are on the display.
If the joystick is moved to a value of within 256 to any max or min value, and the marker does not have an edge in the
direction the joystick is moved, the x or y coordinate is increased or decreased by 1.
There are delays in the setMarker and clearScreen functions as well as whenever the joystick is moved. These delays do
not feel very good at the moment and may need adjustment in the future.
The joystick values were chosen for being 75% of max input in any direction.

## 2023-06-05
Played around with delays. Looked at the code available in the Wokwi project and saw that there was only one delay. Decided to write my code
like that too, and it seems to work pretty well. Step 1 can be considered complete.

\\*1 After further reading and discovering that a pointer is NOT 2 bytes that I thought it was, I decided to start using
stdint.h and uint for small variables. **
