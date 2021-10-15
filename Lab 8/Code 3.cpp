int ldr = 0;
void setup()
{
  pinMode(A2,INPUT);
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}

void loop()
{
  ldr = analogRead(A2);
  Serial.println(ldr);
  analogWrite(12 , map(ldr,0,1023,0,255));
  delay(100);
}
