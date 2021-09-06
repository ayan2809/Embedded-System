int Segpin[] = {9,8,7,6};
int binCode[][4]={
{0,0,0,0},//0
{0,0,0,1},//1
{0,0,1,0},//2
{0,0,1,1},//3
{0,1,0,0},//4
{0,1,0,1},//5
{0,1,1,0},//6
{0,1,1,1},//7
{1,0,0,0},//8
{1,0,0,1}//9
};
int mp = 4;
int mn = 3;
int pir1 = 10;
int pir2 = 11;
int buz = 2;
int count = 0;
int e = 5;
int start = 0;
unsigned long end = 0;
int open = 0;
int open1= 0;
void setup()
{
  for(int i=0;i<4;i++)
  	pinMode(Segpin[i],OUTPUT);
  pinMode(mp,OUTPUT);
  pinMode(mn,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(e,OUTPUT);
}
void displayNum(int num)
{
  for(int i=0;i<4;i++)
  digitalWrite(Segpin[i],binCode[num][i]);
}
void loop()
{
  int readpir1 = digitalRead(pir1);
  int readpir2 = digitalRead(pir2);
  end = millis();
  if(readpir1==HIGH)
  {
    count = count+1;
    if(count>9)
    {
      digitalWrite(buz,HIGH);
      delay(2000);
      digitalWrite(buz,LOW);
      count=9;
    }
    if(open==0)
    {
      digitalWrite(e,HIGH);
      digitalWrite(mp,HIGH);
      digitalWrite(mn,LOW);
      delay(1000);
      digitalWrite(e,LOW);
      open = 1;
    }
    start = end;
  }
  if(readpir2==HIGH)
  {
    count = count-1;
    if(count<0)
      count = 0;
    if(open1==0)
    {
      digitalWrite(e,HIGH);
      digitalWrite(mp,HIGH);
      digitalWrite(mn,LOW);
      delay(1000);
      digitalWrite(e,LOW);
      open1 = 1;
    }
    start = end;
  }
  if((end-start)>=5000&&(open==1||open1==1))
  {
    digitalWrite(e,HIGH);
    digitalWrite(mp,LOW);
    digitalWrite(mn,HIGH);
    delay(1500);
    digitalWrite(e,LOW);
    start = end;
    if(open==1)
    open = 0;
    if(open1==1)
    open1=0;
  }
  displayNum(count);
  delay(500);
}
