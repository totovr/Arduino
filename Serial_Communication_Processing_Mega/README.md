# Serial Communication Processing & Arduino Mega 2560

## Problem

The problem consist in that when you try to communicate processing and Arduino, if processing starts to send information too quickly, the Mega will locked (the LED on pin 13 will turn on and even resetting the card wont work while the board is receiving data).

- This is an example of serial communication with Arduino Uno:

  ```
  import processing.serial.*;

  Serial myPort;  // Create object from Serial class

  void setup() {      
    size(200,200); //make our canvas 200 x 200 pixels big
    String portName = Serial.list()[5]; //change the 0 to a 1 or 2 etc. to match your port
    //println(portName);
    //delay(3000);
    myPort = new Serial(this, portName, 38400);
  }

  void draw() {
    if (mousePressed == true) {                           
      //if we clicked in the window
      myPort.write('1');         //send a 1
      println("1");   
    } else {                           //otherwise
    myPort.write('0');
    println("0");  //send a 0
    }   
  }
  ```

## Solving

- Paste in Processing or Atom the next code:

  ```
  import processing.serial.*;
  float a = 0;

  Serial myPort;  // Create object from Serial class

  void setup() {      
    size(200,200); //make our canvas 200 x 200 pixels big
    String portName = Serial.list()[5]; //change the 0 to a 1 or 2 etc. to match your port
    //println(portName);
    //delay(3000);
    myPort = new Serial(this, portName, 38400);
    while (a < 5000S) {         // cycle of 3 seconds duration, during this time
    a = millis ();}            // you need to press the RESET buttom.
  }

  void draw() {
    if (mousePressed == true) {                           
      //if we clicked in the window
      myPort.write('1');         //send a 1
      println("1");   
    } else {                           //otherwise
    myPort.write('0');
    println("0");  //send a 0
    }   
  }
  ```

- If you see I added the next two lines:

  ```
  while (a < 5000S) {         // cycle of 5 seconds duration, during this time
  a = millis ();}            // you need to press the RESET buttom.
  ```

  This is to to avoid the blocking of the Arduino Mega

- After upload the program in the Mega, you simply need to reset the card after establishing the communication, but before it starts to send the information (before the RX led starts to turn on).


#### LED OFF

<img src="https://github.com/totovr/Arduino/blob/master/Serial_Communication_Processing_Mega/Images/IMG_2444.JPG" width="400">

### LED ON

<img src="https://github.com/totovr/Arduino/blob/master/Serial_Communication_Processing_Mega/Images/IMG_2445.JPG" width="400">

