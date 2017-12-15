//Transmisor Variables
const int inputPin = 2;  //pin for pullup resistor
int value = 0;
int ledIR =  13;         //pin for IR led
int lastvalue = 0;     // previous state of the button

//Receptor Variables
#define IRpin_PIN PIND
#define IRpin 2
// the maximum pulse we'll listen for - 65 milliseconds is a long time
#define MAXPULSE 65000
 // what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20
 // we will store up to 100 pulse pairs (this is -a lot-)
uint16_t pulses[100][2]; // pair is high and low pulse
uint16_t highpulse, lowpulse; // temporary storage timing
uint8_t currentpulse = 0; // index for pulses we're storing
int counter;

void setup() 
{
  pinMode(ledIR, OUTPUT);  //Set pin 13 as output
  Serial.begin(9600);      //Start serial communication
}

void loop() 
{
  value = digitalRead(inputPin);  //read the digital input
  PullUp();
  Pulse();

}

void Pulse(void)
{
  highpulse = lowpulse = 0; // start out with no pulse length
 
    // while (digitalRead(IRpin)) { // this is too slow!
    while (IRpin_PIN & (1 << IRpin)) {
     // pin is still HIGH
 
     // count off another few microseconds
     highpulse++;
     delayMicroseconds(RESOLUTION);
 
     // If the pulse is too long, we 'timed out' - either nothing
     // was received or the code is finished, so print what
     // we've grabbed so far, and then reset
     if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
       printpulses();
       currentpulse=0;
       return;
     }
  }
  // we didn't time out so lets stash the reading
  pulses[currentpulse][0] = highpulse;
 
  // same as above
  while (! (IRpin_PIN & _BV(IRpin))) {
     // pin is still LOW
     lowpulse++;
     delayMicroseconds(RESOLUTION);
     if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
       printpulses();
       currentpulse=0;
       return;
     }
  }
  pulses[currentpulse][1] = lowpulse;
 
  // we read one high-low pulse successfully, continue!
  currentpulse++;  
}

//Pulse Generation
void SendPluse()
{  
  //We will send 6 pulses
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
  delayMicroseconds(9325);
}

void pulseIR(long microseg)
{
  /*It generates the 38KHz frequency pulses for x microseconds.
    Parameters: microseg*/
  while (microseg > 0){
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

void PullUp()
{        
  if (value != lastvalue) {
    if (value == HIGH) {
        Serial.println("ON");
        SendPluse(); //I call the function pulse
        Serial.println("Sent!");
        delay(2000);
    }
  }  
  lastvalue = value; //Check the last state 
}

//Receptor

void printpulses(void) 
{
  Serial.println("\n\r\n\rReceived: \n\rOFF \tON");
  for (uint8_t i = 0; i < currentpulse; i++) {
    Serial.print(pulses[i][0] * RESOLUTION, DEC);
    Serial.print(" usec, ");
    Serial.print(pulses[i][1] * RESOLUTION, DEC);
    Serial.println(" usec");
    counter =i;
  }
 
  //Serial.print("\t"); // tab
  Serial.print("pulseIR(");
  Serial.print(pulses[currentpulse-1][1] * RESOLUTION, DEC);
  Serial.print(");");
  counter = counter + 1;
  Serial.print("\n\r\n\rbits: \n\r");
  Serial.print(counter); 
}

