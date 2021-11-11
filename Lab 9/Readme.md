
# Lab 9 Submissions

Arduino Codes and their respective circuit diagrams on Ultrasonic Distance Sensor


## Description

- **Code 1 -** Program program to read distance value from HC-SR04 ultrasonic sensor module in cm and print it on the serial monitor. 

- **Code 2 -** Program to design a reverse parking sensor module. This module consist of HC-SR04 ultrasonic sensor, LCD and buzzer interfaced with Arduino.  The ultrasonic sensor continuously measure the distance (in cm) between the car and obstacle, then display it on LCD. Whenever the measured distance is lesser than 30cm  generate warning signal to driver using buzzer also display a message “Obstacle !!!” on the first row of the LCD display. 

- **Code 3 -** Program to design smart parking system using HC-SR04 ultrasonic sensor, servo motor, buzzer, LCD and Arduino Uno. 
  - The ultrasonic sensor module place near the gate entrance continuously check for the incoming vehicles. The LCD display “Smart Parking” on the first row and “Avail. slot: XY” in second row of the display. 
  - When a vehicle comes closer to the ultrasonic sensor detection area and parking slot is available then the system open a gate barrier to 90° (close after 10 seconds) to allow the vehicle to the parking slot and decrement parking slot by 1.
  - If no parking slot available then display a message “No Parking slot” on LCD (2nd line) and switch on the buzzer (for 5 Seconds). Have a similar system on the exit and increment the free slot by 1 for every vehicle leaves the parking slot. 



- **Code 4 -** Program to design a Adaptive cruise control (ACC) system to help the vehicle to maintain a safe following distance and stay within the speed limit. This system adjusts a car's speed automatically so drivers don't have to and the detailed function of the system is as follows:
  - This system consists of one slide switch (to select normal or cruise mode), 4 DIP switches (to select different cruise speed), LCD (to display mode and speed of the vehicle), DC motor (to indicate the vehicle speed in rpm), a potentiometer (to control the vehicle speed in normal mode) and a buzzer (to indicate vehicle is very close to others) 
  - Control switch(slide) decide whether the vehicle to be operated in Normal mode (LOW) or cruise mode(HIGH)
  - In normal mode, vehicle speed is controlled by adjusting the potentiometer knob. Also, display a message “Normal mode” in first row and “Speed:XYkmph” on the second row of the LCD. XY is the present vehicle speed.
  - In cruise mode, DIP Switch-1 to 4 select vehicle speed as 40, 60, 80 and 90 kmph respectively. Display the message “Cruising:ABkmph” on the first row and “Speed: XY kmph” on the second row of the LCD. AB is either 40/60/80/90 and XY is the present vehicle speed.
  - Using ultrasonic sensor, map the selected cruise speed with the distance. If other vehicle are not near to the coverage area of the ultrasonic sensor operate the vehicle at its maximum selected cruise speed with high rpm on DC motor. 
  - If other vehicle is detected by ultrasonic sensor vicinity, depends on its distance adjust the speed (DC motor) of the vehicle accordingly.
  - Whenever other vehicle reaches very near to our vehicle (<1m) activate the buzzer to warn the driver. Also display the message “Very close alert” on first row of the LCD.



Code can be run using the Arduino IDE or TinkerCAD.
    
## Tech Stack and Components

**IDE:** Tinker CAD, Arduino IDE

**Hardware:** Arduino, LEDs, Resistors, Jumper Wires, 16x2-LCD Display, Ultrasonic Distance Sensor, Keypad, Buzzer, DC Motor, Potentiometer, Resistors, Switch, Servo Motor

  
## Screenshots

### Circuit 1
![1](https://user-images.githubusercontent.com/42286904/141273008-705ad12d-7c20-48be-8d52-9ddc4f16b73c.png)

### Circuit 2
![2](https://user-images.githubusercontent.com/42286904/141273135-d1b7d885-e54b-4f69-8202-6fee65b31fca.png)


### Circuit 3
![3](https://user-images.githubusercontent.com/42286904/141273318-c4179d40-2469-42c7-b9c8-ac25b7dc1ec3.png)


### Circuit 4
![4](https://user-images.githubusercontent.com/42286904/141273535-f89e4818-81b9-4818-9f3b-1e8c8752a89a.png)
