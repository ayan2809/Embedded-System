int segPins[] = {3,4,5,6,7,8,9,10};
int segCode[11][8]={
  {0,0,0,0,0,0,1,1}, 
  {1,0,0,1,1,1,1,1}, 
  {0,0,1,0,0,1,0,1}, 
  {0,0,0,0,1,1,0,1}, 
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,1,0,0,1}, 
  {0,1,0,0,0,0,0,1}, 
  {0,0,0,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,1}, 
  {0,0,0,0,1,0,0,1},
  {1,1,1,1,1,1,1,0} 
};
int displayBuf[2];
int displayPins[2] = {12,13};
int i = 0, j = 0;
const int TMP36 = A0;
int motor=2;
void setup()
{
  for(int i=0;i<8;i++)
  {
  	pinMode(segPins[i], OUTPUT);
  }
  pinMode(displayPins[0], OUTPUT);
  pinMode(displayPins[1], OUTPUT);
  pinMode(motor,OUTPUT);
  displayBuf[0] = 0;
  displayBuf[1] = 0;
  Serial.begin(9600);
}
void loop()
{
  int temp_adc_val;
  int tempC;
  temp_adc_val = analogRead(TMP36);
  tempC = ((temp_adc_val*4.88)/10) - 50;
  if (tempC > 25)
  {
  	digitalWrite(motor,HIGH);
  }
  else if (tempC < 25)
  {
  	digitalWrite(motor,LOW);
  }
  displayBuf[0] = (tempC%100)/10;
  displayBuf[1] = tempC%10;
  Display(displayBuf[0], displayBuf[1]);
  delay(10); 
  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.println(" Degree Celsius\n");
}
void Display(int d1, int d0)
{
  digitalWrite(displayPins[0],HIGH);
  digitalWrite(displayPins[1],LOW);
  setSegments(d0);
  delay(5);
  digitalWrite(displayPins[1],HIGH);
  digitalWrite(displayPins[0],LOW);
  setSegments(d1);
  delay(5);
}
void setSegments(int n)
{
  for (int l = 0; l < 8; l++)
  	digitalWrite(segPins[l], segCode[n][l]);
}
