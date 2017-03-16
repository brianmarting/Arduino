/*This project requires 2 continous rotation servos connected to pins 9 and 10 of arduino*/ 

byte val;
int lives = 3;
char key = 'KEY_RIGHT_ARROW';

//LiquidCrystal
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define   CONTRAST_PIN   11
#define   BACKLIGHT_PIN  10
#define   CONTRAST       125

//DistanceSensor
float distance;
const int TRIGPIN = 3;
const int ECHOPIN = 4;

//IR 
const byte inputIR = A0;
const byte button = 2;
const byte outputIR = 12;
int signalIR;
int buttonState;

//Motor
const byte Analog1 = 10; //ENABLE Motor1
const byte Analog2 = 11; //ENABLE Motor2

/** 6 -> Input 1
    7 -> Input 2
    8 -> Input 3
    9 -> Input 4*/
const int MotorPin1 = 6; //INPUT 1 Motor1
const int MotorPin2 = 7; //INPUT 2 Motor1
const int MotorPin3 = 8; //INPUT 1 Motor2
const int MotorPin4 = 9; //INPUT 2 Motor2

void setup()
{
  Serial.begin(9600);//Change the baud rate value depending on the default baud rate of your bluetooth module, for Bluesmirf-115200 and for JY-MCU-9600
  Serial1.begin(9600);
  Serial1.println("READY");
  //Serial.begin(9600);  
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT);

  //LiqCrystal
  pinMode(CONTRAST_PIN, OUTPUT);
  pinMode(BACKLIGHT_PIN, OUTPUT);

  digitalWrite(BACKLIGHT_PIN, HIGH);
  analogWrite (CONTRAST_PIN, CONTRAST);
    
  lcd.begin(16,2);               // initialize the lcd 

  lcd.home ();                   // go home
  lcd.print("Hello, ARDUINO ");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print (" WORLD!");      
  
  //Motor
  pinMode(Analog1, OUTPUT);
  pinMode(Analog2, OUTPUT);

  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);

  //IR SENSOR
  pinMode(inputIR, INPUT);
  pinMode(outputIR, OUTPUT);
  pinMode(button, INPUT);
  //If close, shoot
  if (distance < 30){
    
    attachInterrupt(inputIR, readIR, CHANGE);
    
  }
 
}

void loop()
{  
 //CheckAvailable();
 //CalculateDistance();
 
 //backward();
 char incomingChar = 0;   // for incoming serial data
 
 //else {
 // Serial.println("NOT");
// }
 
  if (Serial1.available()) {
    incomingChar = Serial1.read();
    switch (incomingChar) {
      case 'w':
        forward();
        break;
      case 'd':
        turnRight();
        break;
      case 's':
        backward();
        break;
      case 'a':
        turnLeft();
        break;
      case 'z':
        stopp();
        break;  
      case 'r':
        fireIR();
        break;  
      
    }
  }
 //forward();
}



//IR
//----------------------------------------------------------
void readIR() {
  Serial.println("Shot taken...");
  signalIR = analogRead(inputIR);
  Serial.println(signalIR);
  lives--; 
  Serial.println("Lives : ");
  Serial.print(lives);
}

void fireIR() {
  Serial.println("Shooting...");

  digitalWrite(outputIR, HIGH);
  delay(100);
  digitalWrite(outputIR, LOW);

}


//Distancesensor
//----------------------------------------------------------
void CalculateDistance(){
  // Start Ranging -Generating a trigger of 10us burst 
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  // Distance Calculation
  
  distance = pulseIn(ECHOPIN, HIGH); 
  distance= distance/58; 
/* The speed of sound is 340 m/s or 29 us per cm.The Ultrasonic burst travels out & back.So to find the distance of object we divide by 58  */
  
  Serial.print(distance); 
  Serial.println(" cm");
  delay(5000); 
  
}



void CheckAvailable(){
  int a=0;
 if(Serial.available())
  {
    val=Serial.read();
    Serial.println(int(val));
    
    
  }
}

//MotorControls
//----------------------------------------------------------
void forward() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, HIGH);
  digitalWrite(MotorPin4, LOW);
  delay(3000);
  stopp();

}

void backward() {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, LOW);
  digitalWrite(MotorPin4, HIGH);
  delay(3000);
  stopp();

}

void turnRight() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  digitalWrite(MotorPin4, HIGH);
  delay(200);
  stopp();

}

void turnLeft() {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, HIGH);
  digitalWrite(MotorPin4, LOW);
  delay(200);
  stopp();

}

void stopp(){
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  digitalWrite(MotorPin4, LOW);
}


















