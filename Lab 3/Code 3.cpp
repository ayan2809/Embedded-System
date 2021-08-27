int segPins[] = {4,5,7,8,9,11,10,6};
int displayPins[2] = {12, 13};
int displayBuf[2];
int buzzer=3;
int READINPUT;

int segCode[11][8] = {
  { 0, 0, 0, 0, 0, 0, 1, 1},
  { 1, 0, 0, 1, 1, 1, 1, 1},
  { 0, 0, 1, 0, 0, 1, 0, 1},
  { 0, 0, 0, 0, 1, 1, 0, 1},
  { 1, 0, 0, 1, 1, 0, 0, 1},
  { 0, 1, 0, 0, 1, 0, 0, 1},
  { 0, 1, 0, 0, 0, 0, 0, 1},
  { 0, 0, 0, 1, 1, 1, 1, 1},
  { 0, 0, 0, 0, 0, 0, 0, 1},
  { 0, 0, 0, 0, 1, 0, 0, 1},
  { 1, 1, 1, 1, 1, 1, 1, 0},
};
void setup()
{
  for (int i=0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  pinMode(displayPins[0], OUTPUT);
  pinMode(displayPins[1], OUTPUT);
  pinMode(buzzer, INPUT);
 displayBuf[0]=0;
 displayBuf[1]=0;
}
void loop()
{
  READINPUT= Serial.parseInt();
  displayBuf[0]=READINPUT%10;
  displayBuf[1]=READINPUT/10;
  Serial.print("Digit0 : ");
  Serial.println(displayBuf[0]);
  Serial.print("Digit1 :");
  Serial.println(displayBuf[1]);
  digitalWrite(buzzer, HIGH);
  tone(buzzer, 450);
  
  while(Serial.available()==0)
  {
    Display(displayBuf[1], displayBuf[0]);
    digitalWrite(buzzer, LOW);
	noTone(buzzer);
    
  }
  delay(1000);
 
}
  
void Display(int digit1, int digit0)
{
  digitalWrite(displayPins[0], HIGH);
  digitalWrite(displayPins[1],LOW );
  setSegments(digit0);
  delay(5);
  digitalWrite(displayPins[0],LOW);                        
  digitalWrite(displayPins[1], HIGH);
  setSegments(digit1);
  delay(5);                         
}
void setSegments(int n)
{
   for (int i=0; i < 8; i++)
   {
     digitalWrite(segPins[i], segCode[n][i]);
   }
}
