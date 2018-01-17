#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RT|TX

int ledPin =  7;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.println("Ready!");
  BTSerial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
  if(BTSerial.available() > 0){ // Checks whether data is comming from the serial port
    state = BTSerial.read(); // Reads the data from the serial port
 }
 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 } 
}
