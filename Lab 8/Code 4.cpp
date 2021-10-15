#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;             
int initial_position = 90;   
int LDR1 = A0;        
int LDR2 = A1;          
int error = 5;         
int servopin=9;
void setup() 
{
  lcd.begin(16, 2);
  servo.attach(servopin); 
  pinMode(LDR1, INPUT); 
  pinMode(LDR2, INPUT);
  servo.write(initial_position);   
  delay(2000);
  
}

void loop() 
{
  int R1 = analogRead(LDR1); 
  int R2 = analogRead(LDR2);
  // Calculating the difference between the LDR values
  int diff1= abs(R1 - R2);   
  
  int diff2= abs(R2 - R1);
  
  if((diff1 <= error) || (diff2 <= error)) 
  {
    //if the difference is under the error then there is nothing to do
  } 
  else 
  {    
    if(R1 > R2)
    {
      //Move the servo towards 0 degree
      initial_position = --initial_position;  
    }
    if(R1 < R2) 
    {
      //Move the servo towards 180 degree
      initial_position = ++initial_position; 
    }
  }
  servo.write(initial_position);
  delay(100);
  lcd.print("1st:");
  lcd.print(R1);
  lcd.print(" 2nd:");
  lcd.print(R2);
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("Position:");
  lcd.print(initial_position);
  delay(1000);
  lcd.clear();
}
 
