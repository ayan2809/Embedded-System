int PWM = 6;
void setup() 
{
	pinMode(PWM, OUTPUT);
}
void loop() 
{
	// analogWrite (PWM, 0);
	analogWrite (PWM, 127);
	// analogWrite (PWM, 255);
}
