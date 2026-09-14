// Kanan
void rightForward() {
  digitalWrite(servoIn1, HIGH);
  digitalWrite(servoIn2, LOW);
}

void rightBackward() {
  digitalWrite(servoIn1, LOW);
  digitalWrite(servoIn2, HIGH);
}

// Kiri
void leftForward() {
  digitalWrite(servoIn3, HIGH);
  digitalWrite(servoIn4, LOW);
}

void leftBackward() {
  digitalWrite(servoIn3, LOW);
  digitalWrite(servoIn4, HIGH);
}

void rightStop() {
  digitalWrite(servoIn1, LOW);
  digitalWrite(servoIn2, LOW);
}

void leftStop() {
  digitalWrite(servoIn3, LOW);
  digitalWrite(servoIn4, LOW);
}