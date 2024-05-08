                        // Setting variables which can be easily called to later
int POT_PIN = A0;       // Input pin from the potentiometer
int MOTOR_PIN = 9;        // Output pin to the motor
int motorSpeed = 0;       // A variable to store the motor speed value
int potVal = 0;         // A variable to store the potentiometer value

void setup()          // Runs once when sketch starts
{           // Setting the pin type & defining the I/O
  pinMode(MOTOR_PIN, OUTPUT);     // Setting the motor pin as an output 
}

void loop()         // Runs repeatedly
{
  potVal = analogRead(POT_PIN);     // Setting the potVal variable to the reading from the POT_PIN
  motorSpeed = map(potVal, 0, 1023, 0, 255);  // Setting the motorSpeed variable to an equivalent variable
            // between 0 & 255 based off the potVal which is between 0 & 1023
  analogWrite(MOTOR_PIN, motorSpeed);   // Writing the mapped value to the motorSpeed pin
}
