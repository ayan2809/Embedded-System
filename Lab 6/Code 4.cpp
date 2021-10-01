#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor = A0;
int sensorValue=0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  
}
void loop () {
  sensorValue=analogRead(sensor);
  delay(100);
  lcd.clear();
  lcd.print("AirQ = ");
  lcd.print(sensorValue);
  lcd.print("ppm");
  Serial.println(sensorValue);
}
