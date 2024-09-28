#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define constants and objects

Servo servoMotor;
LiquidCrystal_I2C lcdDisplay(0x27, 16, 2);

const int servoPin = 9;
const int rows = 4;
const int columns = 3;

char keys[rows][columns] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[rows] = {8, 7, 6, 5};
byte columnPins[columns] = {4, 3, 2};

char secretCode[] = "1234"; 
char enteredCode[5]; 
int codeIndex = 0;

const int openAngle = 90;
const int closedAngle = 0;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);

void setup() {
  servoMotor.attach(servoPin);
  lcdDisplay.init();
  lcdDisplay.backlight();
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Enter Code:");
  lcdDisplay.setCursor(0, 1);
  lcdDisplay.print(">");
}

void loop() {
  char keyPressed = getKey();

  if (keyPressed != NO_KEY && keyPressed != '#') {
    enteredCode[codeIndex++] = keyPressed;
    lcdDisplay.setCursor(codeIndex, 1);
    lcdDisplay.print('*');
  }

  if (keyPressed == '#') {
    enteredCode[codeIndex] = '\0';
    if (strcmp(enteredCode, secretCode) == 0) {
      openDoor();
      lcdDisplay.clear();
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Access Granted");
      while(getKey() != '*');
      lcdDisplay.clear();
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Locking Door");
      closeDoor();
      lcdDisplay.clear();
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Enter Code:");
    } else {
      lcdDisplay.clear();
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Invalid Code");
      delay(2000);
      lcdDisplay.clear();
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Enter Code:");
      codeIndex = 0;
    }
  }
}

void openDoor() {
  servoMotor.write(openAngle);
}

void closeDoor() {
  servoMotor.write(closedAngle);
}
