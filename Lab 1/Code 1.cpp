int GREEN=0;
int YELLOW=1;
int RED=2;
void setup()
{
  pinMode (GREEN, OUTPUT);
  pinMode (YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}
void loop()
{
  digitalWrite (GREEN, HIGH);
  digitalWrite (YELLOW, LOW);
  digitalWrite (RED, LOW);
  delay(15000); // Wait for 15 second(s)
  digitalWrite (GREEN, LOW);
  digitalWrite (YELLOW, HIGH);
  digitalWrite (RED, LOW);
  delay(3000); // Wait for 3 second(s)
  digitalWrite (GREEN, LOW);
  digitalWrite (YELLOW, LOW);
  digitalWrite (RED, HIGH);
  delay(10000); // Wait for 10 second (3)
}
