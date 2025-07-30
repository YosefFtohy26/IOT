# IOT

### Problem 2 
Code Explanation
The system uses:

ESP32Servo library to control the servo

Keypad library for keypad handling

Key Mapping:
1 → 30°

2 → 45°

3 → 60°

4 → 90°

5 → 120°

6 → 180°

A → Stop (freeze position)

B → Reset (return to 0°)

Main Functions:
setServo(angle): Moves servo to predefined angle

stopServo(): Detaches servo to freeze position

resetServo(): Returns servo to 0°
