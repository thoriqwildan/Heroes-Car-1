#include <PS4Controller.h>
#include <cmath>

#define servoIn1 12
#define servoIn2 13
#define servoIn3 14
#define servoIn4 15

int right = 0;
int left = 0;

int rightForwardIn = 0;
int rightBackwardIn = 0;
int leftForwardIn = 0;
int leftBackwardIn = 0;

void setup() {
  Serial.begin(115200);

  pinMode(servoIn1, OUTPUT);
  pinMode(servoIn2, OUTPUT);
  pinMode(servoIn3, OUTPUT);
  pinMode(servoIn4, OUTPUT);

  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisconnect);
  PS4.begin();

  Serial.println("Starting...");
}
 
void loop() {
}
