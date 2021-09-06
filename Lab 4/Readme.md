
# Lab 4 Submissions

Arduino Codes and their respective circuit diagrams on IR sensor and the PIR sensors


## Description

- **Code 1 -** Program to to identify the IR code/values (in decimal) for each key on IR Remote and print it on the serial monitor. The IR receiver is connected one of the digital pin to receive the IR code/value.

- **Code 2 -** Program for IR Remote Controlled Home Automation using Arduino Uno, in which IR remote control two appliances (Blub and Fan) via relay as per following logic.
  - When “power button" is pressed switch ON both appliances, if the same button is pressed again switch OFF both appliances
  - When key "1" is pressed switch ON bulb, if the same key pressed again switch OFF the bulb
  - When key "2" is pressed switch ON fan(DC motor), if the same key pressed again switch OFF the FAN (DC motor)


- **Code 3 -** Program for automatic staircase light using PIR sensor in which this system switch on the staircase lights automatically when someone enters on the stairs and gets off after some time (10 Sec.).

- **Code 4 -** Program for IR Remote Controlled robot using Arduino Uno, in which IR remote control the movement of the robot by controlling its left and right
Wheels (DC motor) as per following logic:
  - When “UP” key is pressed make the robot to move in forward direction with left and right wheel on same rpm (positive). When “DOWN” key is pressed make the robot to move in reverse direction with left and right wheel on same rpm (negative).
  - When “LEFT” key is pressed, stop the left wheel (0 rpm) and maximum positive rpm on right wheel to move towards left direction
  - When “RIGHT" key is pressed, stop the right wheel (0 rpm) and maximum positive rpm on left wheel to move towards right direction


- **Code 5 -** Program to design a bidirectional visitor counter using PIR sensor. This system consist of two PIR sensor, one on the entry another on exit side. For every human detection on entry side increment count value and every human detection on exit side decrement count value. Whenever human presence detected on entry/exit open the automatic door (DC motor) for 5 seconds and close automatically. Use one 7-segment to display number of human inside the room. Also, ensure always maximum number of human present inside the room must be 9. If an whenever any attempt made to enter the room when number of human count is already 9 inside the room then switch On the buzzer. 


Code can be run using the Arduino IDE or TinkerCAD.
    
## Tech Stack and Components

**IDE:** Tinker CAD, Arduino IDE

**Hardware:** Arduino, LEDs, Resistors, Jumper Wires, Power Supply, IR Sensor, PIR Sensor, DC motor, Remote, L293D, CD4511, 7-segment Display

  
## Screenshots

### Circuit 1
![1](https://user-images.githubusercontent.com/42286904/132185794-0026ab21-a5f6-4789-8856-0091c3d68258.png)

### Circuit 2
![2](https://user-images.githubusercontent.com/42286904/132185738-3ac836d9-8381-47cc-9c13-a10a9394f76d.png)


### Circuit 3
![3](https://user-images.githubusercontent.com/42286904/132185677-8aaa9030-2009-434c-a055-e1bf5e57e327.png)

### Circuit 4
![4](https://user-images.githubusercontent.com/42286904/132185631-e7a27320-b42f-410e-b8f6-4a5a092024eb.png)

### Circuit 5
![5](https://user-images.githubusercontent.com/42286904/132185598-6090a479-62f8-46fa-bd61-3ddbd98e4a83.png)
