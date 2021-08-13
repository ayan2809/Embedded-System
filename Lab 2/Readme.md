
# Lab 2 Submissions

Arduino Codes and their respective circuit diagrams on Serial Port and PWMs 


## Description

- **Code 1 -** Program to transmit a message “VIT SCOPE” using serial port (Tx and Rx pins) to PC serial monitor window for every 2 seconds

- **Code 2 -** program to transmit a message on serial window based on the slide switch state. 
    -	Connect the slide switch on one of the digital pins
    -	If the slide switch state is HIGH print your name on serial window
    -	If the slide switch state is LOW print your reg. no. on serial window 

- **Code 3 -** Program to control the LED connected at pin 12 of digital pin based on the input string received from user via serial port
    -	If the string is “ON”, print “ON” on serial window and switch ON the LED for 5 Seconds
    -	If the string is “OFF”, print “OFF” on serial window and switch OFF the LED for 5 Seconds
    -	Otherwise print “BLINK” on serial window and blink the LED with the delay of 1 second

- **Code 4 -** program to control three LEDs (Red, Green, and Blue) connected at digital pins 9, 10 and 11 respectively. Get input string received from user via serial port and control the LED as per following logic.
    -	If “RED”, print “RED” on serial window and switch ON only Red LED for 5 Seconds
    -	If “GREEN”, print “GREEN” on serial window and switch ON only Green LED for 5 Seconds
    -	If “BLUE” print “BLUE” on serial window and switch ON only Blue LED for 5 Seconds
    -	Otherwise print “ALL LEDs OFF” on serial window and make all LEDs in OFF state

- **Code 5 -** Program to control the LED brightness using PWM signal generated on digital pin 6 with different duty cycle. Verify the duty cycle using oscilloscope. 
    -	Case-1: 0% duty cycle
    -	Case-2: 50% duty cycle
    -	Case-3: 100% duty cycle

- **Code 6 -** Program to control the RGB LED state in yellow, cyan, magenta using PWM signal. Find the correct combination value of RGB for different colours and blink each LED with 3 seconds delay between them


Code can be run using the Arduino IDE or TinkerCAD.
    
## Tech Stack

**IDE:** Tinker CAD, Arduino IDE

**Hardware:** Arduino, LEDs, Resistors, Jumper Wires, SliderSwitch, Oscilloscope, RGB LED

  
## Screenshots

### Circuit 1
![1](https://user-images.githubusercontent.com/42286904/129395532-7f0725dc-a10a-4f6e-9e7a-58a067d987df.png)

### Circuit 2
![2](https://user-images.githubusercontent.com/42286904/129395552-d9016eb7-f812-406b-89e4-74365d87b4fb.png)


### Circuit 3
![3](https://user-images.githubusercontent.com/42286904/129395567-41ca4c83-08f0-497c-938a-ac98fe58d52e.png)


### Circuit 4
![4](https://user-images.githubusercontent.com/42286904/129395586-a685fee7-5474-4780-abd3-c61f553fb6f6.png)


### Circuit 5
![5](https://user-images.githubusercontent.com/42286904/129395619-727bfb8a-53d3-4f21-b93c-028d5bdbfde8.png)


### Circuit 6
![6](https://user-images.githubusercontent.com/42286904/129395630-c9390c73-c04a-49de-9292-3251729ec1e0.png)

