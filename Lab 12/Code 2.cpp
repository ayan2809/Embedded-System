int segPins[] = {3, 4, 5, 6, 7, 8, 9, 10};
int displayPins[3] = {12, 13, 11};
int displayBuf[3];
int ss = 2;
int Reset = 1;
int startTime = 0;
int i = 0, j = 0, k = 0;
unsigned long endTime;
int segCode[11][8] = {
    {0, 0, 0, 0, 0, 0, 1, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0, 1}, // 2
    {0, 0, 0, 0, 1, 1, 0, 1}, // 3
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4
    {0, 1, 0, 0, 1, 0, 0, 1}, // 5
    {0, 1, 0, 0, 0, 0, 0, 1}, // 6
    {0, 0, 0, 1, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0, 1}, // 8
    {0, 0, 0, 0, 1, 0, 0, 1}, // 9
    {1, 1, 1, 1, 1, 1, 1, 0}  // .
};
void setup()
{
    for (int n = 0; n < 8; n++)
    {
        pinMode(segPins[n], OUTPUT);
    }
    pinMode(displayPins[0], OUTPUT);
    pinMode(displayPins[1], OUTPUT);
    pinMode(displayPins[2], OUTPUT);
    pinMode(SS, INPUT);
    pinMode(Reset, INPUT);
    displayBuf[0] = 0;
    displayBuf[1] = 0;
    displayBuf[2] = 0;
}
void loop()
{
    int swstate = digitalRead(ss);
    int rs = digitalRead(Reset);
    if (swstate == HIGH)
    {
        Display(displayBuf[2], displayBuf[1], displayBuf[0]);
        endTime = millis();
        if ((endTime - startTime) >= 100)

        {
            if (++i > 9)
            {
                i = 0;
                if (++j > 9)
                {
                    j = 0;
                    if (++k > 5) //To rest to zero after 59th second
                        k = 0;
                }
            }
            displayBuf[0] = i;
            displayBuf[1] = j;
            displayBuf[2] = k;
            startTime = endTime;
        }
    }
    else
    {
        Display(displayBuf[2], displayBuf[1], displayBuf[0]);
    }
    if (rs == HIGH)
    {
        displayBuf[0] = 0;
        displayBuf[1] = 0;
        displayBuf[2] = 0;
        i = 0;
        j = 0;
        k = 0;
        startTime = endTime;
    }
}
void Display(int digit2, int digit1, int digit0)
{
    digitalWrite(displayPins[0], HIGH);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    setSegments(digit0);
    delay(5);
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], HIGH);
    digitalWrite(displayPins[2], LOW);
    setSegments(digit1);
    delay(5);
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], HIGH);
    setSegments(digit2);
    delay(5);
}
void setSegments(int n)
{
    for (int k = 0; k < 8; k++)
    {
        digitalWrite(segPins[k], segCode[n][k]);
    }
}
