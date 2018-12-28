const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
unsigned long average = 0;                // the average

int inputPin = A0;

void setupGSR()
{
  // initialize serial communication with computer:
  // initialize all the readings to 0:
  for (int i = 0; i < numReadings; i++)
 {
  readings[i] = 0;     
 }
      
}

unsigned long runGSR() {
  // subtract the last reading:
  total = total - readings[index];        
  // read from the sensor:  
  readings[index] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[index];      
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning:
    index = 0;                          

  // calculate the average:
  average = total / numReadings;        
  // send it to the computer as ASCII digits
  //Serial.println(average);  
  return average;

}
