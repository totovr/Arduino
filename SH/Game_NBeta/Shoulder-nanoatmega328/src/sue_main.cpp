//By the Super Human Team
//Bluetooth

#include <Arduino.h>
#include <IRremote.h>
#include <SimpleTimer.h>

//Laser receptor
void Laser_Sensor();
const int LSpin = A0;// Pin to read the laser sensor
int points = 0;
int LaserValue = 0;

//EMG Sensor
void repeatEMG();
const int emgPin = A1;// Pin to read the EMG sensor
int emg = 0;
int emgcharging = 7;//led to indicate charging
int emgfullcharge = 8;//led to indicate full charge
int emg_counter = 0;

//IR transmitter
void IR_transmit();
IRsend irsend;
const IRpin = A3;//IR transmitting led
const IRtransmit = A4;//IR transmission
int IRstate = 0;//variable to store IR transmitting ability
int IRon = 9;//led to indicate IR transmission
int IRpinvalue = 0;

//Timer object
SimpleTimer timer;

// IR receptor
void IR_PullUp();
void IR_Receptor();
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
        // initialize serial communication at 38400 bits per second:
        Serial.begin(38400);
        pinMode(IR_Impact, OUTPUT);//Turn on pin 5 if we received an impact of IR
        pinMode(emgcharging, OUTPUT);//Turn on when emg charging takes place
        pinMode(emgfullcharge, OUTPUT);//Turn on when IR gun is fully charged
        pinMode(IRon, OUTPUT);//Turn on when we use IR gun to shoot
        timer.setInterval(1000, repeatEMG);//repeats every 1 second/ can be changed
}

void loop() {
        //Read laser sensors
        LaserValue = analogRead(LSpin);
        Laser_Sensor();
        //EMG sensor reading
        timer.run();
        //IR transmitter
        IR_transmit();
        //IR reading
        IR_Value = digitalRead(IR_PullUPin);
        IR_Receptor();
        //Serial.flush();
        //Serial.write('0');//Avoid errors
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
                        }
                }
        }
        LaserValue = 0;
}

//EMG function to be executed periodically (adjust period accordingly)
void repeatEMG() {
        emg = analogRead(emgPin);
        if(emg > 900) {
                digitalWrite(emgcharging,HIGH);
                delay(500);
                digitalWrite(emgcharging,LOW);

                emg_counter = emg_counter + 1;
                }
                
        else if (emg_counter>10){
                 digitalWrite(emgfullcharge,HIGH);
                 delay(500);
                 digitalWrite(emgfullcharge,LOW);
                 
                 emg_counter = 0;  
                 IRstate = 1;   //when state is 1, IR can be shot
        }
}

//IRtransmitter is enabled if EMG is full charged
void IR_transmit(){
        IRpinvalue = analogRead(IRpin);
        if(IRstate == 1 && IRpinvalue > 1000){
                irsend.sendSony(0x68B90, A4);
                delay(500);
                digitalWrite(IRon, HIGH);
                delay(100);
                digitalWrite(IRon, LOW);
                IRstate = 0;
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
