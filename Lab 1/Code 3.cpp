int RED=0;
int GREEN=1;
int SWITCH=2;
int SWITCHSTATE;
void setup()
{
  pinMode (RED, OUTPUT);
  pinMode (GREEN, OUTPUT);
  pinMode (SWITCH, INPUT);
}
void loop()
{
  SWITCHSTATE = digitalRead(SWITCH);
  if (SWITCHSTATE==HIGH)
  {
    digitalWrite (RED, LOW);
    digitalWrite(GREEN, HIGH);
    delay(5000); // Wait for 5 seconds
  }
  else
  {
    digitalWrite (RED, HIGH);
    digitalWrite (GREEN, LOW);
  }
}
