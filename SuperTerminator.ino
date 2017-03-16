const byte inputIR=A0;
const byte outputIR=13;

const int motor1_1=8;
const int motor1_2=9;
const int motor2_1=10;
const int motor2_2=11;
const int enable1=12;
const int enable2=13;

char cmd;
const char up='u';
const char down='d';
const char left='l';
const char right='r';
const char stopD='s';
const char fire='f';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);  
  Serial1.println("Ready for fight!");

  digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
  pinMode(motor1_1,OUTPUT);
  pinMode(motor1_2,OUTPUT);
  pinMode(motor2_1,OUTPUT);
  pinMode(motor2_2,OUTPUT);

  attachInterrupt(inputIR,demanged,FALLING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()){ 
    cmd= Serial1.read()  ;
    Serial.println(cmd);
    if(cmd==up)
      forward();
    else if(cmd==down)
      backward();
    else if(cmd==left)
      turnLeft();
    else if(cmd==right)
      turnRight();
    else if(cmd==stopD)
      stopDriving();
    else if(cmd==fire)
      fireShot();
   }
}

void backward(){
  digitalWrite(motor1_1,LOW);
  digitalWrite(motor1_2,HIGH);
  digitalWrite(motor2_1,LOW);
  digitalWrite(motor2_2,HIGH);
}

void forward(){
  digitalWrite(motor1_1,HIGH);
  digitalWrite(motor1_2,LOW);
  digitalWrite(motor2_1,HIGH);
  digitalWrite(motor2_2,LOW);
}

void turnRight(){
  digitalWrite(motor1_1,HIGH);
  digitalWrite(motor1_2,LOW);
  digitalWrite(motor2_1,LOW);
  digitalWrite(motor2_2,HIGH);
}

void turnLeft(){
  digitalWrite(motor1_1,LOW);
  digitalWrite(motor1_2,HIGH);
  digitalWrite(motor2_1,HIGH);
  digitalWrite(motor2_2,LOW);
}

void stopDriving(){
  digitalWrite(motor1_1,HIGH);
  digitalWrite(motor1_2,HIGH);
  digitalWrite(motor2_1,HIGH);
  digitalWrite(motor2_2,HIGH);
}

void demanged(){  
  Serial1.println("I got hit!");
}

void fireShot(){
  digitalWrite(outputIR,HIGH);
  delay(100);
  digitalWrite(outputIR,LOW);
  Serial.println("Fire!");
  Serial1.println("Fire!");
}

