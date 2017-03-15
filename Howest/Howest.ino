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



void setup () {

  Serial.begin(9600);
  Serial.print("hello");

  pinMode(Analog1, OUTPUT);
  pinMode(Analog2, OUTPUT);

  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);

}

void loop () {
 /* forward();
  delay(5000);
  backward();
  delay(5000);
  turnRight();
  delay(5000);
  turnLeft();
  delay(5000);*/



}


//MOTOR1 - forward
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





//MOTOR2 - forward



//SPEED
// analogWrite(Analog1, 255);
// analogWrite(Analog2, 255);

/* FIRST TRY
    Serial.print("hello");
  analogWrite(Analog1, 255);
  analogWrite(Analog2, 255);

  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);

  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);


  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);

  digitalWrite(8, HIGH);
  digitalWrite(9, LOW); */

/*delay(5000);

  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);

  delay(5000);*/



