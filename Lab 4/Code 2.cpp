#include <IRremote.h>
#define code1 16615543
#define code2 16582903
#define code3 16580863
int RECV_PIN =12;
IRrecv irrecv(RECV_PIN);
decode_results results;
int BULB =3;
int FAN = 2;
int BULB_STATUS=0;
int FAN_STATUS=0;
void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(BULB,OUTPUT);
  pinMode(FAN,OUTPUT);
}
void loop()
{
  if (irrecv.decode(&results))
  {
  unsigned int value = results.value;
  switch(value) 
  {
    case code1:
      if(BULB_STATUS == 1)
      {
        digitalWrite(BULB,LOW);
        BULB_STATUS=0;
      }
      else 
      {
        digitalWrite(BULB,HIGH);
        BULB_STATUS = 1;
      }
      break;
    case code2:
      if(FAN_STATUS ==1)
      {
        digitalWrite(FAN,LOW);
        FAN_STATUS = 0;
      }
      else 
      {
        digitalWrite(FAN,HIGH);
        FAN_STATUS = 1;
      }
      break;
    case code3:
      if(BULB_STATUS == 1 && FAN_STATUS == 1) 
      {
        digitalWrite(BULB,LOW);
        BULB_STATUS = 0;
        digitalWrite(FAN,LOW);
        FAN_STATUS = 0;
      }
      else 
      {
        digitalWrite(BULB,HIGH);
        BULB_STATUS = 1;
        digitalWrite(FAN,HIGH);
        FAN_STATUS = 1;
      }
  	}
    Serial.println(value);
    irrecv.resume();
  }
}
