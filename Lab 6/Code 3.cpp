int pin8=8;
int pin9=9;
int sensor=A0;
int sensorValue=0;

void setup()
{
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue= analogRead(sensor);
  Serial.println(sensorValue);
  if(sensorValue>300)//when the gas sensor value crosses 300 the buzzer will buzz
  {
    digitalWrite(pin8, HIGH);
    digitalWrite(pin9, HIGH);
  }
  else
  {
    digitalWrite(pin8, LOW);
    digitalWrite(pin9, LOW);
  }
}
