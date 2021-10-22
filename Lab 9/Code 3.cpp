#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo sm1;
Servo sm2;
int trig1 = 10;
int echo1 = 9;
int trig2 = 7;
int echo2 = 6;
float td2,td1;
float distance1;
float distance2;
int count = 15;
unsigned long time1,time2,buztime;
void setup()
{
 Serial.begin(9600);
 lcd.begin(16, 2);
 pinMode(trig1, OUTPUT);
 pinMode(echo1, INPUT);
 pinMode(trig2, OUTPUT);
 pinMode(echo2, INPUT);
 sm1.attach(8);
 sm2.attach(13);
 sm1.write(0);
 sm2.write(0);
 lcd.setCursor(0,0);
 lcd.print("Smart Parking");
 lcd.setCursor(0,1);
 lcd.print("Avail.slot = ");
 if(count<10)
 lcd.print("0");
 lcd.print(count);
}
void loop()
{

 digitalWrite(trig2, LOW);
 delayMicroseconds(2);
 digitalWrite(trig2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig2, LOW);
 td2 = pulseIn(echo2,HIGH);
 distance2 = 0.03446 * td2/2;
 Serial.print("Distance 2 ");
 Serial.println(distance2);
 if(distance2<50&&count>0)
 {
   count--;
   lcd.setCursor(0,1);
   lcd.print("Avail.slot = ");
   if(count<10)
   lcd.print("0");
   lcd.print(count);
   sm1.write(90);
   time1 = millis();
 }
 if(distance2<50&&count==0)
 {
   lcd.setCursor(0,1);
   lcd.print("No parking slot");
   analogWrite(A5,255);
   buztime = millis();
 }
 digitalWrite(trig1,LOW);
 delayMicroseconds(2);
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig1,LOW);
 td1 = pulseIn(echo1,HIGH);
 distance1 = 0.03446 * td1 /2;
  Serial.print("Distance 1 ");
 Serial.println(distance1);
 if(distance1<50&&count<=15)
 {
   if(count<15)
   {
     count++;
     lcd.setCursor(0,1);
     lcd.print("Avail.slot = ");
     if(count<10&&count>0)
     lcd.print("0");
     lcd.print(count);
     sm2.write(90);
     time2 = millis();
   }
 }
 if(millis()-time1>=10000)//10 sec
 {
 	sm1.write(0);
 }
 if(millis()-time2>=10000)//10 sec
 {
 	sm2.write(0);
 }
 if(millis()-buztime>=5000)//5 sec
 {
 	analogWrite(A5,0);
 }
 delay(5000);
}
