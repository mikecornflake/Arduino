int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 2; // key

void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);
  Serial.begin (9600); // 9600 bps
}

void loop ()
{
  int x, y, z;
  x = analogRead (JoyStick_X);  // 0 to 1023 - default 512 (mid)
  y = analogRead (JoyStick_Y);  // 0 to 1023 - default 512 (mid)
  z = digitalRead (JoyStick_Z); // 0 or 1 - default 1 (up)

  Serial.print (x, DEC);
  Serial.print (" ");
  Serial.print (y, DEC);
  Serial.print (", ");
  Serial.println (z, DEC);
}
