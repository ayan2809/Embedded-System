
#include <Wire.h>
int led = 12;
int button = 13;
void setup()
{
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(receiveButton);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button,INPUT);
}
void loop()
{
  delay(10);
}
void receiveEvent(int howMany)
{
  int x = Wire.read();
  if(x==1){
  	digitalWrite(led,HIGH);
  	delay(10000);
  }
  else
  	digitalWrite(led,LOW);
}
void receiveButton()
{
  int x = digitalRead(button);
  if(x==HIGH)
  	Wire.write(x);
  else
  	Wire.write(0);
}

