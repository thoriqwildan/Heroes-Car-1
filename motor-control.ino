// Kanan
void rightForward(int PWM) {
  analogWrite(servoIn1, PWM);
  digitalWrite(servoIn2, LOW);
}

void rightBackward(int PWM) {
  digitalWrite(servoIn1, LOW);
  analogWrite(servoIn2, PWM);
}

// Kiri
void leftForward(int PWM) {
  analogWrite(servoIn3, PWM);
  digitalWrite(servoIn4, LOW);
}

void leftBackward(int PWM) {
  digitalWrite(servoIn3, LOW);
  analogWrite(servoIn4, PWM);
}

void rightStop() {
  digitalWrite(servoIn1, LOW);
  digitalWrite(servoIn2, LOW);
}

void leftStop() {
  digitalWrite(servoIn3, LOW);
  digitalWrite(servoIn4, LOW);
}