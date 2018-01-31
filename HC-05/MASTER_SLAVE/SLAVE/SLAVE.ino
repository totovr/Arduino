#define button 8
int last_value = 0;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 buttonState = digitalRead(button);
 PullUp();
}

void PullUp() {
 //  if(Serial.available() > 0) { // Checks whether data is comming from the serial port
 //    state = Serial.read(); // Reads the data from the serial port
 // }
 // Reading the button
  if(buttonState != last_value) {
    if (buttonState == HIGH) {
      Serial.write('1'); // Sends '1' to the master to turn on LED
    }
    else {
      Serial.write('0');
    }  
  }
  last_value = buttonState;
}
