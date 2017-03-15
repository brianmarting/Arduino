/*This project requires 2 continous rotation servos connected to pins 9 and 10 of arduino*/ 

#include <Servo.h>
Servo left;//Define left servo
Servo right;//Define right servo
byte val;
int lives = 3;

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
  left.attach(9, 800, 2200); //left servo on digital pin 9 of arduino
  right.attach(10, 800, 2200); //right servo on digital pin 10 of arduino
  //Serial.begin(9600);  
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT);

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
    attachInterrupt(button, fireIR, FALLING);    
  }
  
}

void loop()
{  
 CheckAvailable();
 CalculateDistance();
}


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
    MoveRobot();
    
  }
}

//MotorControls
//----------------------------------------------------------
void forward() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, HIGH);
  digitalWrite(MotorPin4, LOW);

}

void backward() {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, LOW);
  digitalWrite(MotorPin4, HIGH);

}

void turnRight() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  digitalWrite(MotorPin4, HIGH);

}

void turnLeft() {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, HIGH);
  digitalWrite(MotorPin4, LOW);

}

//TODO
void MoveRobot(){
  if(int(val)==49)//Move front
{
  right.write(180);//Rotates servo clockwise
  left.write(0);//Rotates servo anticlockwise
}

if(int(val)==50)//Move back
{
  right.write(0);
  left.write(180);
}

if(int(val)==53)//Stop
{
  right.write(90);//Stops the servos
  left.write(90);//Stops the servos
}

if(int(val)==51)//left
{
  right.write(180);
  left.write(90);
}

if(int(val)==52)//right
{
  right.write(90);
  left.write(0);
}




}


void readIR() {
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
















