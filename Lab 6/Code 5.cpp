#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor = A0;
int sensorValue=0;
const int temp=A1;
const int light=A2;
int lightVal=0;
void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  
}

void loop () {
  
  sensorValue=analogRead(sensor);
  lightVal = analogRead(light);
  int temp_adc_val;
  float tempC;
  temp_adc_val = analogRead(temp);
  tempC = (temp_adc_val * 4.88)-500;
  tempC = (tempC/10);
  
  
  lcd.setCursor(0,0);
  //printing
  lcd.print("Weather Station");
  //printing time
  int t = millis()/1000;
  int m = t/60;
  t = t%60;
  lcd.setCursor(0,1);
  lcd.print("08");
  lcd.print(":");
  if (m < 10)
  lcd.print("0");
  lcd.print(m);
  lcd.print(":");
  if (t < 10)
  lcd.print("0");
  lcd.print(t);
  delay(3000);
  delay(100);
  lcd.clear();
  
  
  lcd.print("Temp:");
  lcd.print(tempC);
  lcd.print(" ");
  lcd.print("Light:");
  lcd.print(lightVal);
  lcd.print(" ");
  lcd.print("CO2:");
  lcd.print(sensorValue);
  for (int i = 0; i <35; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }
  lcd.clear();
  Serial.println(tempC);
  Serial.println(lightVal);
  Serial.println(sensorValue);
 }
