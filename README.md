# LEDRunner

##Description
Program for PIC32MX360F512L on EXPLORER 16/32 DevKit that runs 9 LEDs in sequence and can change direction on the press of a button.

##Tools
Microchip XC32 compiler is used to compile the code.

##Compile
Compile the code by using:
```
xc32-gcc –mprocessor=32MX360F512L -o main.o main.c
```
Then convert the object file into .hex
```
xc32-bin2hex main.o
```
