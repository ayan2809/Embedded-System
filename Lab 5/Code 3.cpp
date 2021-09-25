int sensorValue=0;
float volt=0;
int pins[]={6,5,4,3,2};
int conf[5][5]=
{
{0,0,0,0,1},
{0,0,0,1,0},
{0,0,1,0,0},
{0,1,0,0,0},
{1,0,0,0,0},
};
void setup()
{
  Serial.begin(9600);
  for(int i=0;i<5;i++)
  {
  	pinMode(pins[i],OUTPUT);
  }
}
void loop()
{
  sensorValue=analogRead(A0);
  volt=(sensorValue*4.88)/1000;
  Serial.println("Sensor value=");
  Serial.println(sensorValue);
  Serial.println("Voltage=");
  Serial.println(volt);
  delay(1000);
   if(volt>0&&volt<1)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if(volt>1 && volt<2)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if(volt>2 && volt<3)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if(volt>3 && volt<4)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }
  else if(volt>4 && volt<5)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
}
