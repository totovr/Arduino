#include <Arduino.h>

void PullUp ();

// constants won't change. Used here to set a pin number:
const int ledPin =  13;// the number of the LED pin
const int PullUpin = 5;  //pin for pullup resistor 15
int value = 0;
int last_value = 0;// previous state of the button

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 10;           // interval at which to blink (milliseconds)

void setup() {
        pinMode(ledPin, OUTPUT);
        pinMode(PullUpin, INPUT);
}

void loop() {
        value = digitalRead(PullUpin);
        PullUp ();
        //Serial.write('1');
}

void PullUp() {
        if (value != last_value) {
                if (last_value == HIGH) {
                        unsigned long currentMillis = millis();
                        if (currentMillis - previousMillis >= interval) {
                                // save the last time you blinked the LED
                                previousMillis = currentMillis;
                                // if the LED is off turn it on and vice-versa:
                                if (ledState == LOW) {
                                        digitalWrite(ledPin, HIGH);
                                } else {
                                  digitalWrite(ledPin, LOW);
                                }
                        }
                }
                digitalWrite(ledPin, LOW);
        }
        last_value = value;//Evaluate the last state of the push buttom
}
