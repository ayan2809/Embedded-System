#include <Wire.h>
const int pinTemp = 0;
#define SlaveAdres 8
float valVolt;
float valGradenC;
char tempBuff[7];
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}
float getVolt(int pin)
{
	return (analogRead(pin) * 0.004882814);
}
void loop()
{
  valVolt = getVolt(pinTemp);
  valGradenC = (valVolt - 0.5) * 100.0;
  dtostrf(valGradenC,7,2, tempBuff);
  Serial.print("Temp.: ");
  Serial.print(valGradenC);
  Serial.print(" ");
  Serial.print(char(176));
  Serial.println("C");
  Wire.beginTransmission(SlaveAdres);
  Wire.write(tempBuff);
  Wire.endTransmission();
  delay(200); 
}
