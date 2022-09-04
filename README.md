# LEDRunner

## Description
Program for PIC32MX360F512L on EXPLORER 16/32 DevKit that runs 9 LEDs in sequence and can change direction on the press of a button.

## Tools
Microchip XC32 compiler is used to compile the code. To flash the project onto the microcontroller ipecmd is used, it comes bundeled with the MPLAB X IDE. MPLAB X IDE was also used while writing the source code to help with debugging.

## Compiling and flashing
Compile the code by using:
```
xc32-gcc –mprocessor=32MX360F512L -o main.o main.c
```
Then convert the object file into .hex
```
xc32-bin2hex main.o
```
You can flash the hex file using this command:
```
java -jar ipecmd.jar -TPPM -32MX360F512L -main.hex -M -OB
```

## Prototype
For testing and debugging a prototype was made also.

Video: https://www.youtube.com/watch?v=uhHO4gy0djo

![Prototype](https://www.youtube.com/watch?v=uhHO4gy0djo)
