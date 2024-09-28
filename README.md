# Door-Lock-System-using-Arduino-Uno

# Secure Access System using Servo and Keypad

This project demonstrates a simple security system using an Arduino board, a servo motor, a keypad for entering a passcode, and an LCD display for interaction.

## Summary

The system is built with an Arduino Uno controlling a servo motor that locks and unlocks the door based on user input through a keypad. User instructions and feedback are provided via an I2C LCD.

## Components Needed

- Arduino Uno Board
- Servo Motor
- 4x3 Keypad
- LCD Screen (I2C)
- Breadboard and Wires

## Libraries Required

- Arduino IDE
- Servo.h
- Keypad.h
- Wire.h (for I2C communication)
- LiquidCrystal_I2C.h

## Setup Instructions

1. Attach the servo motor to pin 9 on the Arduino.
2. Connect the keypad to digital pins (columns to pins 2, 3, 4, and rows to pins 5, 6, 7, 8).
3. Attach the LCD screen to the I2C pins.

## Program Flow

The sketch provides the following functionality:

- Initializes the servo, keypad, and LCD.
- Continuously monitors for keypresses on the keypad.
- As keys are pressed, they are displayed on the LCD.
- On pressing `#`, the entered code is checked against a preset code.
- If correct, the servo moves to unlock the door; if incorrect, an error message appears.
- The door is locked after pressing `*`.

## Instructions

1. Upload the sketch to your Arduino Uno.
2. Use the keypad to enter the passcode.
3. Press `#` to submit.
4. If the code is correct, the servo will unlock the door. Press `*` to relock it.

## Customizable Options

You can adjust the passcode by modifying the `secretCode` variable in the sketch. The door lock and unlock positions can also be modified by altering the `openAngle` and `closedAngle` values.
