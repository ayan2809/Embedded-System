int sensorValue=0;
float volt=0;
void setup()
{
	Serial.begin(9600);
}
void loop()
{
  sensorValue = analogRead(A0);
  volt= (sensorValue*4.88)/1000;
  Serial.print("SensorValue=");
  Serial.println(sensorValue);
  Serial.print("Voltage=");
  Serial.println(volt);
  delay(1000);
}
