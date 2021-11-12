#include <Wire.h>
int pushbutton = 13;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(pushbutton, INPUT);
}
void loop()
{
  Wire.beginTransmission(4);
  int x = digitalRead(pushbutton);
  Wire.write(x);
  Serial.println(x);
  Wire.endTransmission();
  delay(500);
}
