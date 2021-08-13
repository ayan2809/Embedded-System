int GREEN=9;
int BLUE=10;
int RED=12;
void setup()
{
  pinMode (GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
}
void loop()
{
  analogWrite (GREEN, 255);
  analogWrite (BLUE, 0);
  analogWrite (RED, 255);
  delay(3000);  // equivalent to 3 sec
  
  analogWrite (GREEN, 255);
  analogWrite (BLUE, 255);
  analogWrite (RED, 0);
  delay(3000);  // equivalent to 3 sec
  
  analogWrite (GREEN, 0);
  analogWrite (BLUE, 255);
  analogWrite (RED, 255);
  delay(3000);  // equivalent to 3 sec
}
