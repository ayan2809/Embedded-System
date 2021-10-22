#include <LiquidCrystal.h>
int trig = 10;
int echo = 9;
int pin7=7;
float timeduration;
float distance;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  
  lcd.begin(16, 2);
  pinMode(pin7, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  
}

void loop() 
{
  digitalWrite(trig, LOW);
  delayMicroseconds (2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeduration = pulseIn(echo, HIGH);
  distance = 0.034 * timeduration/2;
  if(distance<=30)
  {
    digitalWrite(pin7, HIGH);
    lcd.print("Obstacle!");
  }
  else
  {
    digitalWrite(pin7, LOW);
  }
  //digitalWrite(pin7, LOW);	
  delay(500);
  lcd.clear();
}
 
