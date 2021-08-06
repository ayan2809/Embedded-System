int LED[4]={3,2,1,0};
void setup()
{
  pinMode (LED[0], OUTPUT);
  pinMode (LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3],OUTPUT);
}
void loop()
{
  digitalWrite (LED[0], LOW);
  digitalWrite (LED[1], LOW);
  digitalWrite (LED[2], LOW);
  digitalWrite (LED[3], LOW);
  int arr[16][4]={
		{0,0,0,0},
		{0,0,0,1},
		{0,0,1,0},
		{0,0,1,1},
		{0,1,0,0},
		{0,1,0,1},
		{0,1,1,0},
		{0,1,1,1},
		{1,0,0,0},
		{1,0,0,1},
		{1,0,1,0},
		{1,0,1,1},
		{1,1,0,0},
		{1,1,0,1},
		{1,1,1,0},
		{1,1,1,1},
	};
  for(int i=0;i<16;i++)
  {
    for(int j=0;j<4;j++)
    {
      	if(arr[i][j]==0)
        {digitalWrite (LED[j], LOW);}
      	else
        {digitalWrite (LED[j], HIGH);}
    }
    delay(500);
  }
  
}
