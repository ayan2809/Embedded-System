#include <Servo.h>  
#include <LiquidCrystal.h>
Servo myservo;  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int potpin = A0; 
int val;
void setup() 
{
  myservo.attach(9);
  lcd.begin(16, 2);
}

void loop() {
  val=analogRead(potpin);
  lcd.print("Voltage : ");
  lcd.print(val);
  val = map(val, 0, 1023, 0, 180);        
  myservo.write(val);   
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("Angle :");
  lcd.print(val);
  delay(1000);
  lcd.clear();
  
}
