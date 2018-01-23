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

//Death variable
int end = 0;

void setup() {
  Serial.begin(38400); // Communication baudio rate of the Bluetooth module
}

void loop() {
  //Read laser sensors
  LaserValue = analogRead(LSpin);
  Laser_Sensor();
  //EMG sensor reading
  emg = analogRead(emgPin);
  EMG();
  Serial.flush();
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

}
