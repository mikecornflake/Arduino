int LED_PIN = 13;

void setup()          // Runs once when sketch starts
{
  pinMode(LED_PIN, OUTPUT);        // Setting the LED pin as an output
}

void loop()         // Runs repeatedly
{
  digitalWrite(LED_PIN, HIGH);     // Turning the LED on
  delay(1000);                    // Waiting 1 second
  digitalWrite(LED_PIN, LOW);          // Turning the LED off
  delay(3000);                  // Waiting 1 second
}
