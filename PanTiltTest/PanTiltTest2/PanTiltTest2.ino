// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo servoPan;
Servo servoTilt;

// Define the servo pin:
int servoPanPin = 9;
int servoTiltPin = 10;

// initialise servo defaults
float pan = 93, tilt = 115;
float panInc = 0.5, tiltInc = 0.5;  // controls the movement speed

// Define the joystick pins
int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 2; // key

// initialise joystick defaults
int x = 0, y = 0, z = 0;

// Controls the direction and speed the servo's are turned
float JoystickDirection(float AValue)
{
  if (AValue > 600) {
    return (panInc);
  }
  else if (AValue < 400) {
    return (-panInc);
  } else return (0);
}

// Returns AValue, but ensure's this is between bounds
float SetBound(float AValue, float AMin, float AMax)
{
  if (AValue <= AMin) {
    return (AMin);
  }
  else if (AValue >= AMax) {
    return (AMax);
  }
  else return (AValue);
}

// Initialise the Arduino
void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);

  Serial.begin (9600); // 9600, 8, N, 1

  // Attach the Servo variable to a pin:
  servoPan.attach(servoPanPin);
  servoTilt.attach(servoTiltPin);
}

// Arduino main loop
void loop ()
{
  // Read the joystick position
  x = analogRead (JoyStick_X);  // 0 to 1023 - default 510 (mid)
  y = analogRead (JoyStick_Y);  // 0 to 1023 - default 510 (mid)
  z = digitalRead (JoyStick_Z); // 0 or 1 - default 1 (up)

  if (z = 1) {
    // if button up: 
    //    move the pan/tilt according to joystick position
    pan += JoystickDirection(x);
    pan = SetBound(pan, 7, 180); // below 7 motor makes a wierd sound

    tilt += JoystickDirection(y);
    tilt = SetBound(tilt, 80, 180);  // not full motion due to assembly
  } else {
    // if button down: 
    //    reset the pan/tilt positions to default
    pan = 93;
    tilt = 115;
  }

  // moves the servo's to the new position (or maintain)
  servoPan.write(pan);
  servoTilt.write(tilt);

  // Debug output
  Serial.print (x, DEC);
  Serial.print (" ");
  Serial.print (y, DEC);
  Serial.print (", ");
  Serial.print (z, DEC);
  Serial.print (", ");
  Serial.print (pan, 1);
  Serial.print (", ");
  Serial.println (tilt, 1);
}
