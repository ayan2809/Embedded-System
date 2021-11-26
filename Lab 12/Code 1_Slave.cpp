#include <LiquidCrystal.h>
#define CLK 8
#define SS 9
#define MOSI 10
#define MISO 11
int clkState = LOW;
int prevClkState = LOW;
byte data = 0b00000000;
int bitPos = 7;
unsigned long timerStart;
float temp;
LiquidCrystal lcd(A5, A4, 5, 4, 3, 2);
void setup()
{
    pinMode(CLK, INPUT);
    pinMode(MOSI, INPUT);
    pinMode(MISO, OUTPUT);
    pinMode(SS, INPUT);
    digitalWrite(MISO, LOW);
    lcd.begin(16, 2);
}
void loop()
{
    clkState = digitalRead(CLK);
    if (clkState != prevClkState)
    {
        prevClkState = clkState;
        if (digitalRead(SS) == LOW)
        {
            if (clkState == HIGH)
            {
                if (digitalRead(MOSI) == LOW)
                {
                    data &= ~(0x01 << bitPos);
                    bitPos--;
                }
                else
                {
                    data |= (0x01 << bitPos);
                    bitPos--;
                }
                if (bitPos < 0)
                {
                    delay(500);
                    digitalWrite(MISO, HIGH);
                    delay(1000);
                    digitalWrite(MISO, LOW);
                    bitPos = 7;
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print("Temperature :");
                    lcd.setCursor(0, 1);
                    if (data > 124)
                    {
                        data = data ^ 0b10000000;
                        lcd.print("-");
                        lcd.print(data);
                    }
                    else
                    {
                        lcd.print(data);
                    }
                    lcd.print(" ^C");
                }
            }
        }
    }
    delay(10);
}
