#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define SlaveAdres 8
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  Wire.begin(SlaveAdres);
  Wire.onReceive(Temp);
}
void Temp(int howMany)
{
  String dataString = "";
  float valGradenC = 0.0;
  while (Wire.available()) 
  {
    char c = Wire.read();
    dataString = dataString + c;
  }
  valGradenC = dataString.toFloat();
  Serial.println(valGradenC);
  lcd.setCursor(0, 1);
  lcd.print(valGradenC);
  lcd.print(" ");
  lcd.print(char(176));
  lcd.print("C ");
}
void loop()
{
  delay(100);
}

