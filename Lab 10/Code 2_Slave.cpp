#include <Wire.h>
int button = 13;
int led = 12;
void setup()
{
  Wire.begin();
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{
  if(digitalRead(button)==HIGH)
  {
    Wire.beginTransmission(4);
    Wire.write(1);
    Wire.endTransmission();
    delay(500);
  }
  else
  {
    Wire.beginTransmission(4);
    Wire.write(0);
    Wire.endTransmission();
    delay(500);
  }
  Wire.requestFrom(4,2);
  int x = Wire.read();
  if(x==1)
  {
  	digitalWrite(led,HIGH);
  	delay(1000);
  }
  else
  	digitalWrite(led,LOW);
}

