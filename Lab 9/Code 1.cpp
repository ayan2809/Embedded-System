int trig = 12;
int echo = 11;
float timeduration;
float distance;
void setup() 
{
  Serial.begin(9600);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}
void loop() 
{
  digitalWrite(trig, LOW);
  delayMicroseconds (2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeduration = pulseIn(echo, HIGH);
  distance = 0.034 * timeduration/2;
  Serial.print("Distance in cm: ");
  Serial.println( distance);
  delay(500);
}
