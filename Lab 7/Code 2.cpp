#include <Keypad.h>
#include <LiquidCrystal.h>
int pos=0; 
int pin8=8;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte rows=4;
const byte cols=3;
char key[rows][cols]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows]={1,2,3,4};
byte colPins[cols]={5,6,7};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="1872";
int currentposition=0;
int invalidcount=12;
void setup()
{
  displayscreen();
  lcd.begin(16,2);
}
void loop()
{
  if( currentposition==0)
  {
  	displayscreen();
  }
  int l ;
  char code=keypad.getKey();
  if(code!=NO_KEY)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("enter password     ");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
    for(l=0;l<=currentposition;++l)
    {
      lcd.print("*");
    }
    if (code==password[currentposition])
    {
      ++currentposition;
      if(currentposition==4)
      {
        unlockdoor();
        currentposition=0;
      }
    }
    else
    {
      ++invalidcount;
      incorrect();
      currentposition=0;
    }
   }
}
void unlockdoor()
{
  delay(900);
  lcd.setCursor(0,0);
  lcd.println(" ");
  lcd.setCursor(1,0);
  lcd.print("Access Granted      ");
  lcd.setCursor(4,1);
  lcd.println("Welcome  ");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(16,1);
  lcd.println(" ");
  lcd.setCursor(14,1);
  lcd.println(" ");
  lcd.setCursor(13,1);
  lcd.println(" ");
  delay(2000);
  delay(1000);
  delay(1000);
}
void incorrect()
{
  delay(500);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("CODE");
  lcd.setCursor(6,0);
  lcd.print("INCORRECT");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(13,1);
  lcd.println(" ");
  Serial.println("CODE INCORRECT YOU ARE UNAUTHORIZED");
  digitalWrite(pin8, HIGH);
  delay(3000);
  digitalWrite(pin8, LOW);
  lcd.clear();
  displayscreen();
}

void clearscreen()
{
    lcd.setCursor(0,0);
    lcd.println(" ");
    lcd.setCursor(0,1);
    lcd.println(" ");
    lcd.setCursor(0,2);
    lcd.println(" ");
    lcd.setCursor(0,3);
    lcd.println(" ");
}
void displayscreen()
{
  lcd.setCursor(0,0);
  lcd.println(" ENTER THE CODE      ");
  lcd.setCursor(1 ,1);
  lcd.println("TO OPEN          ");
}
