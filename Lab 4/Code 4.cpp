#include <IRremote.h>
#define UP 16601263
#define DOWN 16584943
#define LEFT 16589023
#define RIGHT 16605343
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
int E1 = 2;//Enable motor 1
int E2 = 3;//Enable motor 2
int m1p = 4;//motor 1 +ve terminal
int m1n = 5;//motor 1 -ve terminal
int m2p = 6;//motor 2 +ve terminal
int m2n = 7;//motor 2 -ve terminal
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(E1,OUTPUT);
  pinMode(E2,OUTPUT);
  pinMode(m1p,OUTPUT);
  pinMode(m1n,OUTPUT);
  pinMode(m2p,OUTPUT);
  pinMode(m2n,OUTPUT);
  pinMode(RECV_PIN,INPUT);
}
void Motor(int n, int of,int d)//motor select,on/off,direction
{
  //0,0,0 for reset
  if(n==1)
  {
    if(of==1)
    {
      if(d==1)
      {
        digitalWrite(m1p,HIGH);
        digitalWrite(m1n,LOW);
        digitalWrite(E1,HIGH);
      }
      else
      {
        digitalWrite(m1n,HIGH);
        digitalWrite(m1p,LOW);
        digitalWrite(E1,HIGH);
      }
    }
    else
    {
    digitalWrite(E1,LOW);
    }
  }
  else
  {
    if(of==1)
    {
      if(d==1)
      {
        digitalWrite(m2p,HIGH);
        digitalWrite(m2n,LOW);
        digitalWrite(E2,HIGH);
      }
      else
      {
        digitalWrite(m2n,HIGH);
        digitalWrite(m2p,LOW);
        digitalWrite(E2,HIGH);
      }
    }
    else
    {
    	digitalWrite(E2,LOW);
    }
  }
  if(n==0&&d==0&&of==0)
  {
    digitalWrite(E1,LOW);
    digitalWrite(E2,LOW);
  }
}
void loop()
{
  if(irrecv.decode(&results))
  {
  unsigned int value = results.value;
  Serial.println(results.value);
  switch(value)
  {
    case UP:
      Motor(1,1,1);
      Motor(2,1,1);
      delay(1000);
      Motor(0,0,0);
      break;
    case DOWN:
      Motor(1,1,-1);
      Motor(2,1,-1);
      delay(1000);
      Motor(0,0,0);
      break;
    case LEFT:
      Motor(1,0,1);
      Motor(2,1,1);
      delay(1000);
      Motor(0,0,0);
      break;
    case RIGHT:
      Motor(1,1,1);
      Motor(2,0,1);
      delay(1000);
      Motor(0,0,0);
      break;
  }
  	irrecv.resume();
  }
}
