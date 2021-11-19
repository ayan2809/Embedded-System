#define CLK 8
#define SS 9
#define MOSI 10
#define MISO 11
#define FALSE 0
#define TRUE !FALSE
unsigned long prevTick = 0.0;
unsigned long lastTime = 0.0;
int clockState = LOW;
int prevClkState = LOW;
unsigned int clkCounter = 0;
unsigned int pressTime;
int bitNum[8];
int bitSent[] = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
int bitsToSend = 0;
int ii;
const int sensorPin = A3;
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
            if ((clkCounter - pressTime) > (-1 * bitsToSend + 9))
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
        int temp_adc_val;
        float tempC;
        temp_adc_val = analogRead(sensorPin);
        tempC = (temp_adc_val * 4.88);
        tempC = tempC / 10;
        tempC = tempC - 50;
        int t = (int)tempC;
        intToByteset(t);
        pressTime = clkCounter;
        lastTime = millis();
        bitsToSend = 8;
        for (ii = 0; ii < 8; ii++)
        {
            bitSent[ii] = FALSE;
        }
    }
    delay(10);
}
void intToByteset(int n)
{
    int t = n;
    int i = 0;
    while (n != 0)
    {
        bitNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i; j < 8; j++)
    {
        bitNum[i] = 0;
    }
    if (t < 0)
    {
        bitNum[7] = 1;
    }
}
