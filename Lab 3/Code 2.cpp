int segPins[] = {4,5,7,8,9,11,10,6};
int displayPins[2] = {12, 13};
int displayBuf[2];
int sw=3;
int i = 0, j = 0;
int startTime = 0;
unsigned long endTime;
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
  pinMode(displayPins[0], OUTPUT);
  pinMode(displayPins[1], OUTPUT);
  pinMode(sw, INPUT);
 displayBuf[0]=0;
 displayBuf[1]=0;
}
void loop()
{
  int swstate=digitalRead(sw);
  if (swstate==HIGH)
  {
    Display(displayBuf[1],displayBuf[0]);
    endTime = millis();
    if ((endTime - startTime) >= 1000)
    {
      if (++i > 9)
      {
        i = 0;
       if (++j > 9)
         j = 0;
      }
      displayBuf[0] = i;
      displayBuf[1] = j;
      startTime = endTime;
    }
  }
  else
  {
    Display(displayBuf[1],displayBuf[0]);
  }
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
