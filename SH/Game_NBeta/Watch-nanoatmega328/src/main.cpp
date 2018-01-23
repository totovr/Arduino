//By the Super Human Team
//Bluetooth

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremote.h>

//Functions
void TheGame();
void Laser_Points();
void Shoots();
void oled_timer();
void oled_LF();
void shoot_life();
void timer();
void calculateTime();
void Game_Over();

// If using software SPI (the default case):
#define OLED_MOSI  11   //D1
#define OLED_CLK   12   //D0
#define OLED_DC    9
#define OLED_CS    8
#define OLED_RESET 10
char buffer[10];
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//Receptor
int points = 0;
char Laser_Point;
//Emisor
int shoots = 0;
int ShootValue = 0;
const int ShootPin = A1;
int ShootState = 0;
int lastShootState = 0;
//Game_Over
int end = 0;

//Laser shoot
const int Laser_PullUPin = 2;  //pin for pullup resistor D2
int ledLaser =  13;         //pin for laser
int value = 0;
int lastvalue = 0;     // previous state of the button

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 38400 bits per second:
  Serial.begin(38400);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  //delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  //TheGame();
  //Set the pin has input
  pinMode(PointPin, INPUT);
  pinMode(ShootPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //Just will set this display for the first 5 seconds
  oled_timer();
  //Laser Points check if the user was hit by the laser gun
  Laser_Points();
  ShootState = digitalRead(ShootPin);
  //Check how many shoots did the player
  Shoots();
  //delay(300);
}

void TheGame() {
  //Draw a counter of the time to begin the game
  for (int i=0; i < 6; i++) {
    display.clearDisplay();
    display.setCursor(0,0);
    int xy = i;
    display.print("          ");
    display.print("  Ready?      ");
    display.print(xy);
    display.print("               ");
    delay(1000);
    display.display();
  }
}

void Laser_Points() {
  if (Serial.available()) { // If data is available to read,
    Laser_Point = Serial.read(); // read it and store it in val
    if (Laser_Point == '1') {
       if (end > 20) {
         points = points + 1;
         oled_LF();
       }
       else {
         while(1) {
           Game_Over();
         }
       }
    }
  }
}

void Shoots() {
  if (ShootState != lastShootState) {
    if (ShootState == HIGH) {
      shoots = shoots + 1;
      oled_LF();
    }
  }
  lastShootState = ShootState;//Evaluate the last state of the push buttom
}

void oled_timer() {
  display.clearDisplay();
  display.setCursor(0,0);
  timer();
  display.display();
  //delay(500);
}

void oled_LF() {
  display.clearDisplay();
  display.setCursor(0,0);
  shoot_life();
  display.display();
  delay(1000);
}

void shoot_life() {
  display.print("  Shoots  ");
  display.print("    ");
  display.print(shoots);//counter
  display.print("     ");
  display.print(" Impacts  ");
  display.print("    ");
  display.print(points);//counter
  display.print("     ");
}

void timer() {
  display.print("          ");
  display.print("  TIMER    ");
  calculateTime();
  display.print("          ");
  display.display();
}

void calculateTime(){
  long t = millis()/1000 ;
  int horas = t/3600 ;
  int minutos = (t % 3600) / 60;
  int segs = (t - horas*3600 - minutos * 60) % 60 ;
  int n = sprintf(buffer, "%02d:%02d:%02d ", horas, minutos, segs);
  display.print(buffer);
}

void Game_Over() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("GAME OVER");
  display.display();
  delay(1000);
}
