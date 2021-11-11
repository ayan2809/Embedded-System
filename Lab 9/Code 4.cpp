#include <LiquidCrystal.h>
LiquidCrystal lcd(A5, A4, 5, 4, 3, 2);
int motor=11;
int mode=6;
int s1=7;
int s2=8;
int s3=9;
int s4=10;
int trig = 13;
int echo = 12;
int speed=0;
int speed1=0;
int sensor=0;
int distance=0;
int select=0;
void setup()
{
  lcd.begin(16, 2);
  pinMode(mode,INPUT);
  pinMode(motor,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(s1, INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  Serial.begin(9600);
}
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void loop()
{
  if(digitalRead(mode)==LOW)
  {
    sensor=analogRead(A3);
    speed= map(sensor,0,1023,0,100);
    analogWrite(motor,sensor);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Normal Mode");
    lcd.setCursor(0,1);
    lcd.print("Speed:");
    lcd.print(speed);
    lcd.print("kmph");
    delay(100);
  }
  else if(digitalRead(mode)==HIGH)
  {
    distance= 0.01723 * readUltrasonicDistance(trig, echo);
    //Serial.println(distance);
    if(digitalRead(s1)==HIGH) select=1;
    else if(digitalRead(s2)==HIGH) select=2;
    else if(digitalRead(s3)==HIGH) select=3;
    else if(digitalRead(s4)==HIGH) select=4;
    switch(select)
    {
    case 1:speed=40;break;
    case 2:speed=60;break;
    case 3:speed=80;break;
    case 4:speed=90;break;
  }
  if(distance==336)
  {
    analogWrite(motor,speed);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Crusing:");
    lcd.print(speed);
    lcd.print("kmph");
    lcd.setCursor(0,1); 
    lcd.print("Speed:");
    lcd.print(speed);
    lcd.print("kmph");
    analogWrite(A0,0);
    delay(100);
  }
  if(distance>100 && distance<336)
  {
    analogWrite(A0,0);
    speed1=map(distance,100,336,0,speed-1);
    analogWrite(motor,speed1);
    lcd.setCursor(0,0);
    lcd.print("Cruising:");
    lcd.print(speed);
    lcd.print("kmph");
    lcd.setCursor(0,1);
    lcd.print("Speed:");
    lcd.print(speed1);
    lcd.print("kmph");
    delay(100);
  }
  if(distance<100)
  {
    analogWrite(motor,speed);
    analogWrite(A0,255);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Very close alert");
    delay(100);
  }
  }
}
