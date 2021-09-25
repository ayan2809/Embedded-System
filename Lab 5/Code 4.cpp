const int TMP36_pin = A0;
void setup()
{
	Serial.begin(9600);
}
void loop()
{
  int temp_adc_val;
  float tempC;
  temp_adc_val = analogRead(TMP36_pin);
  tempC = (temp_adc_val * 4.88)-500;
  tempC = (tempC/10);
  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.print("Degree Celcius\n");
  float tempF= ((tempC) * 9.0 / 5.0) + 32.0;
  Serial.print("Temperaature = ");
  Serial.print(tempF);
  Serial.print("Degree Fahrenheit\n");
  delay(1000);
}
