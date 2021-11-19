
#include <Keypad.h>

#define CLK 10
#define SS 11
#define MOSI 12
#define MISO 13
#define FALSE 0
#define TRUE !FALSE

void setBits(char keypressed);

unsigned long prevTick = 0.0;
unsigned long lastTime = 0.0;
int clockState = LOW;
int prevClkState = LOW;
unsigned int clkCounter = 0;
unsigned int pressTime;
char keypressed;
int bitNum[4];
int bitSent[] = {FALSE, FALSE, FALSE, FALSE};
int bitsToSend = 0;
int ii;

const byte numRows = 4;
const byte numCols = 4;
char keymap[numRows][numCols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins,
                         numRows, numCols);
void setup()
{

    pinMode(CLK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(MISO, INPUT);
    pinMode(SS, OUTPUT);

    digitalWrite(CLK, LOW);
    digitalWrite(MOSI, LOW);
    digitalWrite(SS, HIGH);
}
void loop()
{

    if ((millis() - prevTick) >= 1000)
    {
        clockState = !clockState;
        digitalWrite(CLK, clockState);
        prevTick = millis();
        clkCounter++;
    }

    if (bitsToSend > 0)
    {
        if (!(bitSent[bitsToSend - 1]))
        {
            if ((clkCounter - pressTime) > (-1 * bitsToSend + 5))
            {
                if ((clockState == LOW) && ((millis() - lastTime) > 1000))
                {
                    digitalWrite(SS, LOW);
                    digitalWrite(MOSI, bitNum[bitsToSend - 1]);
                    bitSent[bitsToSend - 1] = TRUE;
                    bitsToSend--;
                    lastTime = millis();
                }
            }
        }
    }
    else
    {
        if (digitalRead(MISO) == HIGH)
        {
            if ((millis() - lastTime) > 2000)
            {
                digitalWrite(SS, HIGH);
                digitalWrite(MOSI, LOW);
            }
        }

        keypressed = myKeypad.getKey();
        if (keypressed != NO_KEY)
        {
            setBits(keypressed);
            pressTime = clkCounter;
            lastTime = millis();
            bitsToSend = 4;
            for (ii = 0; ii < 4; ii++)
            {
                bitSent[ii] = FALSE;
            }
        }
    }
    delay(10);
}

void setBits(char keypressed)
{
    switch (keypressed)
    {
    case '0':
        bitNum[3] = 0;
        bitNum[2] = 0;
        bitNum[1] = 0;
        bitNum[0] = 0;
        break;
    case '1':
        bitNum[3] = 0;
        bitNum[2] = 0;
        bitNum[1] = 0;
        bitNum[0] = 1;
        break;
    case '2':
        bitNum[3] = 0;
        bitNum[2] = 0;
        bitNum[1] = 1;
        bitNum[0] = 0;
        break;
    case '3':
        bitNum[3] = 0;
        bitNum[2] = 0;
        bitNum[1] = 1;
        bitNum[0] = 1;
        break;
    case '4':
        bitNum[3] = 0;
        bitNum[2] = 1;
        bitNum[1] = 0;
        bitNum[0] = 0;
        break;
    case '5':
        bitNum[3] = 0;
        bitNum[2] = 1;
        bitNum[1] = 0;
        bitNum[0] = 1;
        break;
    case '6':
        bitNum[3] = 0;
        bitNum[2] = 1;
        bitNum[1] = 1;
        bitNum[0] = 0;
        break;
    case '7':
        bitNum[3] = 0;
        bitNum[2] = 1;
        bitNum[1] = 1;
        bitNum[0] = 1;
        break;
    case '8':
        bitNum[3] = 1;
        bitNum[2] = 0;
        bitNum[1] = 0;
        bitNum[0] = 0;
        break;
    case '9':
        bitNum[3] = 1;
        bitNum[2] = 0;
        bitNum[1] = 0;
        bitNum[0] = 1;
        break;
    case 'A':
        bitNum[3] = 1;
        bitNum[2] = 0;
        bitNum[1] = 1;
        bitNum[0] = 0;
        break;
    case 'B':
        bitNum[3] = 1;
        bitNum[2] = 0;
        bitNum[1] = 1;
        bitNum[0] = 1;
        break;
    case 'C':
        bitNum[3] = 1;
        bitNum[2] = 1;
        bitNum[1] = 0;
        bitNum[0] = 0;
        break;
    case 'D':
        bitNum[3] = 1;
        bitNum[2] = 1;
        bitNum[1] = 0;
        bitNum[0] = 1;
        break;
    case '*':
        bitNum[3] = 1;
        bitNum[2] = 1;
        bitNum[1] = 1;
        bitNum[0] = 0;
        break;
    case '#':
        bitNum[3] = 1;
        bitNum[2] = 1;
        bitNum[1] = 1;
        bitNum[0] = 1;
        break;
    default:

        break;
    }
}
