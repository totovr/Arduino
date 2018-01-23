//By the Super Human Team
//Bluetooth

#include <Arduino.h>
#include <IRremote.h>

//Decode values

//Laser receptor
void Laser_Sensor();
const int LSpin = A0;// Pin to read the laser sensor
int points = 0;
int LaserValue = 0;

//EMG Sensor
void EMG();
const int emgPin = A1;// Pin to read the EMG sensor
int emg = 0;
int emg_counter = 0;
int emg_counter1 = 0;

// IR receptor
void IR_PullUp();
void IR_Receptor()
int IR_receptorPin = A2;
IRrecv irrecv(IR_receptorPin);
decode_results results;
const int IR_PullUPin = 3;  //pin for pullup resistor D3
int IR_Value = 0;
int IR_Last_Value = 0;
int IR_Impact = 5;

//Death variable
int end = 0;

void setup() {
  pinMode(IR_Impact, OUTPUT);//Turn on pin 5 if we received an impact of IR
  Serial.begin(38400); // Communication baudio rate of the Bluetooth module
}

void loop() {
  //Read laser sensors
  LaserValue = analogRead(LSpin);
  Laser_Sensor();
  //EMG sensor reading
  emg = analogRead(emgPin);
  EMG();
  //IR reding
  IR_Value = digitalRead(IR_PullUPin);
  IR_Receptor();
  //Serial.flush();
  Serial.write('0');//Avoid errors
 }

//Decode
// Read the laser sensor to count the points
void Laser_Sensor() {
  if(LaserValue > 180) {
    if(end < 20) {
      end=+1;
      Serial.write('1'); // Sends '1' to the master to count as one point
    }//If we detect that the end variable is over 20 we will do a infinite bucle
    else {
      while(1) {
        Serial.write('9'); // Sends '9' to the master to as the player is death
      }
    }
  }
  LaserValue = 0;
}

void EMG() {
  if(emg > 4000) {
    emg_counter=+1;
    if(emg_counter = 500) { //If the count is over 20 we will activate the super arm
      Serial.write('2'); // Sends '2' to the master to activate especial gun
      delay(10);
      emg_counter = 0;
    }
  }
}

void IR_Receptor() {
  digitalWrite(IR_Impact,LOW);
  if (irrecv.decode(&results)) {
    if (results.decode_type == SONY) {
      Serial.write('3'); // Sends '3' to the master to advice that we were shoot by IR
      digitalWrite(IR_Impact,HIGH);//LED will turn on because we were hit
      delay(500);
      digitalWrite(IR_Impact,LOW);
    }
  }
}
