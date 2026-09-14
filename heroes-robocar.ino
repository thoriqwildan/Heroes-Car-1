#include servoIn1 12
#include servoIn2 13
#include servoIn3 14
#include servoIn4 15

void setup() {
  pinMode(servoIn1, OUTPUT);
  pinMode(servoIn2, OUTPUT);
  pinMode(servoIn3, OUTPUT);
  pinMode(servoIn4, OUTPUT);
}

// Kiri
void rightForward() {
  pinMode(servoIn1, HIGH);
  pinMode(servoIn2, LOW);
}

void rightBackward() {
  pinMode(servoIn1, LOW);
  pinMode(servoIn2, HIGH);
}

// Kanan
void leftForward() {
  pinMode(servoIn3, HIGH);
  pinMode(servoIn4, LOW);
}

void leftBackward() {
  pinMode(servoIn3, LOW);
  pinMode(servoIn4, HIGH);
}

void rightBreak() {
  pinMode(servoIn1, HIGH);
  pinMode(servoIn2, HIGH);
}

void leftBreak() {
  pinMode(servoIn3, HIGH);
  pinMode(servoIn4, HIGH);
}

void standBy() {
  pinMode(servoIn1, LOW);
  pinMode(servoIn2, LOW);
  pinMode(servoIn3, LOW);
  pinMode(servoIn4, LOW);
}

// Maju
void allForward() {
  rightForward();
  leftForward();
}

// Mundur
void allBackward() {
  rightBackward();
  leftBackward();
}
 
void loop() {
  allForward();
  delay(1000);
  allBackward();
  delay(1000);
  rightForward();
  leftBreak();
  delay(1000);
  leftForward();
  rightBreak();
  delay(1000);
}
