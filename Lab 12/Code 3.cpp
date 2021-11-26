#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(3, 2, A2, A3, A4, A5);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {4, 5, 6, 7};
byte colPins[COLS] = {8, 9, 10, 11};
int LCDRow = 0;
String a;
String last;
float num1 = 0;
float num2 = 0;
float ans;
char op;
String result;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(LCDRow, 0);
}
void loop()
{
    char key = keypad.getKey();
    if (key && key != '#')
    {
        a = a + String(key);
        lcd.setCursor(0, 0);
        lcd.print(a);
    }
    if (key && key == '#')
    {
        last = a;
        char temp;
        for (int i = 0; i < last.length(); i++)
        {
            if (last[i] == 'A')
            {
                temp = 'A';
                op = '+';
                break;
            }
            else if (last[i] == 'B')
            {
                temp = 'B';
                op = '-';
                break;
            }
            else if (last[i] == 'C')
            {
                temp = 'C';
                op = 'x';
                break;
            }
            else if (last[i] == 'D')
            {
                temp = 'D';
                op = '/';
                break;
            }
        }
        int pos = last.indexOf(temp);
        String n1 = last.substring(0, pos);
        String n2 = last.substring(pos + 1);
        if (n1 != "")
            num1 = n1.toFloat();
        if (n2 != "")
            num2 = n2.toFloat();
        if (temp == 'A')
            ans = num1 + num2;
        if (temp == 'B')
            ans = num1 - num2;
        if (temp == 'C')
            ans = num1 * num2;
        if (temp == 'D')
        {
            if (num2 != 0)
                ans = num1 / num2;
        }
        result = String(ans);
        if (num2 == 0 && temp == 'D')
        {
            result = "Not Defined";
        }
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print(n1 + String(op) + n2);
        lcd.setCursor(0, 1);
        lcd.print("Ans = " + result);
    }
    if (key == '*') //Press * to clear the entries
    {
        lcd.clear();
        a = "";
    }
}
