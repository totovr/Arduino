
const int inputPin = 2;  //pin for pullup resistor
int value = 0;
int ledIR =  13;         //pin for IR led

void setup() {

    pinMode(ledIR, OUTPUT);  //I set pin 13 as output
    Serial.begin(9600);      //Start serial communication

  }

void loop(){

    PullUp();



  }

//Encode
void SendPluse(){
    pulseIR(80);
    delayMicroseconds(7140);
    pulseIR(60);
    delayMicroseconds(7820);
    pulseIR(80);
    delayMicroseconds(4240);
    pulseIR(100);
    delayMicroseconds(7200);
    pulseIR(80);
    delayMicroseconds(1460);
    pulseIR(80);
  }

void pulseIR(long microseg){
    /*It generates the 38KHz frequency pulses for x microseconds.
        · Parameters: microseg*/

    while (microseg > 0) {
        /*38KHz are approx. 13microseg in HIGH and 13microseg in LOW digital instructionWrite
        late 3microseg in running so we do two delays of 10 instead of 13. In total the cycle
        lasts 26microseg, when it is completed, we subtract the time it has to be sending the pulse*/
      digitalWrite(ledIR, HIGH);
      delayMicroseconds(10);
      digitalWrite(ledIR, LOW);
      delayMicroseconds(10);
      microseg -= 26;
    }
  }

void PullUp(){

    value = digitalRead(inputPin);  //lectura digital de pin
    if (value == HIGH) {
        Serial.println("ON");
        SendPluse(); //Llamo a la función que emite los pulsos
        Serial.println("Sent!");
        delay(2000);
    }

  }
