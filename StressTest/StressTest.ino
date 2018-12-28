//MASTER 

#define DEBUG 0

//GSR = 32

unsigned long gsr = 0;
float respirationFrequency = 0;
float ppgFrequency = 0;

float newPPG, newR;

void setup()
{
  pinMode(A0, INPUT); 
  Serial.begin(9600);
  setupGSR();
}

void loop()
{
  
  if(DEBUG) Serial.println("4");
  
  gsr = runGSR();
  
  if(DEBUG)
  {  
    Serial.print("GSR: ");
    Serial.println(gsr);
  }
  
  Serial.println(gsr);
  
  delay(100);
    
}
