int sensorValue = 0;
float volt = 0;
int speed = 0;
void setup()
{
	Serial.begin(9600);
}
void loop()
{
  sensorValue = analogRead(A0);
  volt=(sensorValue*4.88)/1000;
  speed=sensorValue/4;
  analogWrite(9,speed);
  Serial.print("sensorValue=");
  Serial.println(sensorValue);
  Serial.print("Voltage=");
  Serial.println(volt);
  delay(1000);
}
