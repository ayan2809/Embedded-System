int SLIDESWITCH;
void setup()
{
  pinMode(12,INPUT);
  Serial.begin(9600);
}
void loop()
{
  SLIDESWITCH = digitalRead(12);
  if (SLIDESWITCH == HIGH)
  {
    Serial.println("Ayan Sadhukhan");
    delay(1000); 				
  }
  else
  {
    Serial.println("19BCE1872");
    delay(1000);
  }
}
