String READINPUT;
void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  READINPUT=Serial.readString();
  if (READINPUT=="ON")
  {
    Serial.println("ON");
    digitalWrite(12, HIGH);
    delay(5000);
  }
  else if (READINPUT=="OFF")
  {
    Serial.println("OFF");
    digitalWrite(12, LOW);
    delay(5000);
  }
  else
  {
    Serial.println("BLINK");
    digitalWrite(12, HIGH);
    delay(1000); 
    digitalWrite(12, LOW);
    delay(1000); 
  }
}
