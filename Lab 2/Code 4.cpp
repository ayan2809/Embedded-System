// C++ code
//
int RED=8;
int GREEN=9;
int BLUE=10;
String READINPUT;
void setup()
{
  pinMode (RED, OUTPUT);
  pinMode (GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  READINPUT=Serial.readString();
  if (READINPUT=="RED")
  {
    //READINPUT=Serial.readString();
    Serial.println("RED");
    digitalWrite (RED, HIGH);
    digitalWrite (GREEN, LOW);
    digitalWrite (BLUE, LOW);
    delay(5000); 
    
  }
  else if (READINPUT=="GREEN")
  {
    Serial.println("GREEN");
    digitalWrite (RED, LOW);
    digitalWrite (GREEN, HIGH);
    digitalWrite (BLUE, LOW);
    delay(5000); 
  }
  else if (READINPUT=="BLUE")
  {
    Serial.println("BLUE");
    digitalWrite (RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    delay(5000); 
  }
  else
  {
    Serial.println("ALL LEDS OFF");
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}

