unsigned long lastTimeStamp = 0;

void notify() {
  char messageString[200];

  int leftStick = PS4.LStickY() + 1;
  int rightStick = PS4.RStickX();

  if (leftStick > 0) {
    rightForwardIn = leftStick;
    leftForwardIn = leftStick;
    rightBackwardIn = 0;
    leftBackwardIn = 0;
  } else if (leftStick < 0) {
    rightForwardIn = 0;
    leftForwardIn = 0;
    rightBackwardIn = abs(leftStick);
    leftBackwardIn = abs(leftStick);
  } else {
    rightForwardIn = 0;
    leftForwardIn = 0;
    rightBackwardIn = 0;
    leftBackwardIn = 0;
  }

  if (rightStick > 0) {
    if (leftStick > 0) {
      rightForwardIn -= rightStick;
      rightBackwardIn = 0;
    } else if (leftStick < 0) {
      rightBackwardIn -= abs(rightStick);
      rightForwardIn = 0;
    } 
  } else if (rightStick < 0) {
    if (leftStick > 0) {
      leftForwardIn -= abs(rightStick);
      leftBackwardIn = 0;
    } else if (leftStick < 0) {
      leftBackwardIn -= abs(rightStick);
      leftForwardIn = 0;
    }
  } 

  // if (PS4.RStickX() > 0) {
  //   if (PS4.LStickY() > 0) {
  //     rightForwardIn += PS4.LStickY();
  //     leftForwardIn -= 0;
  //   } else if (PS4.LStickY() < 0) {
  //     rightForwardIn = 0;
  //     leftForwardIn = PS4.LStickY();
  //   } else {
  //     rightForwardIn = PS4.LStickY();
  //     leftForwardIn = PS4.LStickY();
  //   }
  // } else if (PS4.RStickX() < 0) {

  // }

  sprintf(messageString, "%4d,%4d, %4d, %4d", leftBackwardIn, leftForwardIn, rightForwardIn, rightBackwardIn);

  if (millis() - lastTimeStamp > 50)
  {
    Serial.println(messageString);
    lastTimeStamp = millis();
  }
}

void onConnect() {
  Serial.println("PS4 Connected");
}

void onDisconnect() {
  Serial.println("PS4 Disconnected");
}