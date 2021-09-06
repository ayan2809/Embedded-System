int sensor_pin = 11; 
int relay_pin = 2; 
int output; 
void setup() 
{
  Serial.begin(9600);
  pinMode (sensor_pin, INPUT); 
  pinMode(relay_pin, OUTPUT); 
  digitalWrite (relay_pin, HIGH);
}
void loop() 
{

  output = digitalRead(sensor_pin);
  if (output == 1) 
  {
    digitalWrite(relay_pin, LOW);
    delay(1000);
  }
  else if (output == 0) 
  {
  	digitalWrite (relay_pin, HIGH);
  }
  Serial.println (output);
  delay(100);
}
