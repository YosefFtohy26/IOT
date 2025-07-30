#include <Keypad.h>
#include <ESP32Servo.h>

// Servo setup
Servo myServo;
int servoPin = 13;

// Keypad setup
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {32, 33, 25, 26}; 
byte colPins[COLS] = {27, 14, 12, 23}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int currentAngle = 0;

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.println("ESP32 Keypad Servo Controller Started");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    switch (key) {
      case '1': setServo(30); break;
      case '2': setServo(45); break;
      case '3': setServo(60); break;
      case '4': setServo(90); break;
      case '5': setServo(120); break;
      case '6': setServo(180); break;
      case 'A': stopServo(); break;  // Stop button
      case 'B': resetServo(); break; // Reset button
    }
  }
}

void setServo(int angle) {
  currentAngle = angle;
  myServo.write(angle);
  Serial.print("Moved to angle: ");
  Serial.println(angle);
}

void stopServo() {
  myServo.detach(); // freeze at current position
  Serial.println("Servo stopped at current position");
}

void resetServo() {
  myServo.attach(servoPin);
  setServo(0);
  Serial.println("Servo reset to 0°");
}
