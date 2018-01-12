//Libraries
#include <IRremote.h>
//code values
const int inputPin = 2;  //pin for pullup resistor
int value = 0;
int ledLaser =  13;         //pin for IR led
int lastvalue = 0;     // previous state of the button
//decode
//counter to begin the game
int count = 0;
//Receptor
int points = 0;
const int analogInPin = A0;
int LaserValue = 0;
int PointC = A1;//By this pin we will send the data to the OLED display for points
//EMG Sensor
int emg = 0;
int emgPin = A2;
int emg_counter = 0;
//Infrared
IRsend irsend;
const int analogPin = A3;
int outputvalue = 0;
//Death variable
int end = 0;

void setup() {
  pinMode(ledLaser, OUTPUT);  //Set pin 13 as output
  Serial.begin(9600);      //Start serial communication
  pinMode(PointC, OUTPUT);  //Set pin 11 as output
}

void loop() {
  value = digitalRead(inputPin);  //read the digital input
  PullUp();
  LaserValue = analogRead(analogInPin);
  delay(10);
  //  Serial.print(LaserValue);
  //  Serial.print("\n");
  Points();
  //EMG sensor reading
  emg = analogRead(emgPin);
  EMG();
}
//Encode
void PullUp() {
  if (value != lastvalue) {
    if (value == HIGH) {
        SendPluse(); //I call the function pulse
        delay(10);
    }
  }
  lastvalue = value;//Evaluate the last state of the push buttom
}

void SendPluse() {
  //We will send 1 pulse
  digitalWrite(ledLaser, HIGH);
  delay(1000);
  digitalWrite(ledLaser, LOW);
  delay(2);
}
//decode
void Points() {
  if(LaserValue > 180) {
    if(end < 20) {
      end=+1;
      digitalWrite(PointC, HIGH);
      delay(1000);
      digitalWrite(PointC, LOW);
    }//If we detect that the end variable is over 20 we will do a infinite bucle
    else {
      while(1) {
        digitalWrite(PointC, HIGH);
      }
    }
  }
  LaserValue = 0;
}

void EMG() {
  if(emg > 4000) {
    if(emg_counter = 20) {
      //outputvalue = analogRead(analogPin);
      irsend.sendSony(0x68B90, 20);
      delay(100);
      emg_counter = 0;
    }
  }
}