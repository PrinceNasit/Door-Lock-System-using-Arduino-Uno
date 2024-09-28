# Door Lock System using Arduino Uno

This project demonstrates a simple security system using an Arduino board, a servo motor, a keypad for entering a passcode, and an LCD display for interaction.

## Summary

The system is built with an Arduino Uno controlling a servo motor that locks and unlocks the door based on user input through a keypad. User instructions and feedback are provided via an I2C LCD.

## Components Used

- Arduino Uno Board
- Servo Motor
- 4x3 Keypad
- LCD Screen (I2C)
- Breadboard and Wires

## Libraries Used

- Arduino IDE
- Servo.h
- Keypad.h
- Wire.h (for I2C communication)
- LiquidCrystal_I2C.h

## Setup Instructions

1. Attach the servo motor to pin 9 on the Arduino.
2. Connect the keypad to digital pins (columns to pins 2, 3, 4, and rows to pins 5, 6, 7, 8).
3. Attach the LCD screen to the I2C pins.
