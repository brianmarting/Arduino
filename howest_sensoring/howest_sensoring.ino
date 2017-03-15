const byte inputIR = A0;
const byte button = 2;
const byte outputIR = 12;

int signalIR;
int buttonState;

void setup() {

  Serial.begin(9600);
  pinMode(inputIR, INPUT);
  pinMode(outputIR, OUTPUT);
  pinMode(button, INPUT);

  attachInterrupt(inputIR, readIR, CHANGE);
  attachInterrupt(button, fireIR, FALLING);

}

void loop() {

}

void readIR() {
  signalIR = analogRead(inputIR);
  Serial.println(signalIR);
}

void fireIR() {


  digitalWrite(outputIR, HIGH);
  delay(100);
  digitalWrite(outputIR, LOW);

}
