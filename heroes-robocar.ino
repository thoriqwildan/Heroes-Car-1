#define servoIn1 12
#define servoIn2 13
#define servoIn3 14
#define servoIn4 15

void setup() {
  Serial.begin(115200);

  pinMode(servoIn1, OUTPUT);
  pinMode(servoIn2, OUTPUT);
  pinMode(servoIn3, OUTPUT);
  pinMode(servoIn4, OUTPUT);

  Serial.println("Starting...")
}
 
void loop() {
  rightForward();
  leftForward();
  delay(1000);
  rightBackward();
  leftBackward();
  delay(1000);
  rightForward();
  leftStop();
  delay(1000);
  leftForward();
  rightStop();
  delay(1000);
}
