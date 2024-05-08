/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */

// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

// Create a variable to store the servo position:
int angle = 0;

void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin, 480, 5000);

  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 180; angle += 5) {
    myservo.write(angle);
    delay(100);
  };

  delay(2000);
}

void loop() {
}
