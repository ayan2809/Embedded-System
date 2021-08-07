int LED[4]={0,1,2,3};
int SWITCH=8;
int SWITCHSTATE=0;
int p=0;
void setup()
{
  pinMode (LED[0], OUTPUT);
  pinMode (LED[1], OUTPUT);
  pinMode (LED[2], OUTPUT);
  pinMode (LED[3], OUTPUT);
  pinMode (SWITCH, INPUT);
}
void loop()
{
  SWITCHSTATE = digitalRead(SWITCH);
  if (SWITCHSTATE == HIGH)
 
    {
      p++;
      delay(1000);
    } 
  
  if (p==1)
  {   
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(1000);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(250);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(250);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[3], LOW);
      delay(250);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      delay(250);

  }
  else if(p==0)
  {
     
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(1000);
      digitalWrite(LED[3], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[0], LOW);
      delay(500);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[3], LOW);
      delay(500);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(500);
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      delay(500);
     
  }
  else
  {
    p=0;
  }
}
