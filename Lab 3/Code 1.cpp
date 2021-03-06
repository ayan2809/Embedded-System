int segPins[] = {4,5,7,8,9,11,10,6};
int segCode [16][8] = {
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
  { 0, 0, 0, 0, 0, 1, 0, 1}, 
  { 1, 1, 0, 0, 0, 0, 0, 1}, 
  { 0, 1, 1, 0, 0, 0, 1, 1}, 
  { 1, 0, 0, 0, 0, 1, 0, 1}, 
  { 0, 0, 1, 0, 0, 0, 0, 1}, 
  { 0, 1, 1, 1, 0, 0, 0, 1}, 
};
void setup()
{
  for (int i=0; i < 8; i++)
  {
  	pinMode(segPins[i], OUTPUT);
  }
}
void loop()
{
  for (int n= 0; n< 16;n ++) 
  {
    displayDigit(n);
  	delay(1000);
  }
}
void displayDigit(int digit)
{
  for (int i=0; i<8;i++)
  {
  	digitalWrite (segPins[i], segCode [digit][i]);
  }
}
