// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo servoPan;
Servo servoTilt;

// Define the servo pin:
int servoPanPin = 9;
int servoTiltPin = 10;

int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 2; // key

// Create a variable to store the servo position:
int pan = 0, tilt=0;
  int x, y, z;

void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);

  Serial.begin (9600); // 9600 bps
  
  // Attach the Servo variable to a pin:
  servoPan.attach(servoPanPin);
  servoTilt.attach(servoTiltPin);
}

void loop ()
{
  x = analogRead (JoyStick_X);  // 0 to 1023 - default 512 (mid)
  y = analogRead (JoyStick_Y);  // 0 to 1023 - default 512 (mid)
  z = digitalRead (JoyStick_Z); // 0 or 1 - default 1 (up)
  pan = map(x, 0, 1023, 7, 180);
  tilt = map(y, 0, 1023, 80, 150);  // not full motion due to assembly

  Serial.print (x, DEC);
  Serial.print (" ");
  Serial.print (y, DEC);
  Serial.print (", ");
  Serial.print (z, DEC);
  Serial.print (", ");
  Serial.print (pan, DEC);
  Serial.print (", ");
  Serial.println (tilt, DEC);

  servoPan.write(pan);
  servoTilt.write(tilt);
}
