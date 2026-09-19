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
    rightBackwardIn = abs(leftStick) + 1;
    leftBackwardIn = abs(leftStick) + 1;
  } else {
    rightForwardIn = 0;
    leftForwardIn = 0;
    rightBackwardIn = 0;
    leftBackwardIn = 0;
  }

  if (rightStick > 0) {
    if (leftStick > 0) {
      rightForwardIn -= rightStick - 1;
      rightBackwardIn = 0;
    } else if (leftStick < 0) {
      rightBackwardIn -= abs(rightStick) - 1;
      rightForwardIn = 0;
    } else {
      rightForwardIn = 0;
      rightBackwardIn += rightStick + 1;
      leftForwardIn += rightStick + 1;
      leftBackwardIn = 0;
      
    }
  } else if (rightStick < 0) {
    if (leftStick > 0) {
      leftForwardIn -= abs(rightStick);
      leftBackwardIn = 0;
    } else if (leftStick < 0) {
      leftBackwardIn -= abs(rightStick);
      leftForwardIn = 0;
    } else {
      rightForwardIn += abs(rightStick);
      rightBackwardIn = 0;
      leftForwardIn = 0;
      leftBackwardIn += abs(rightStick);
    }
  } 

  if (PS4.R2() == 1) {
    gripper.write(180);
    Serial.println("grip masuk");
  } else if (PS4.L2() == 1) {
    gripper.write(0);
    Serial.println("grip keluar");
  }

  analogWrite(servoIn1, 
    map(constrain(rightForwardIn, 0, 128), 0, 128, 0, 220)
  );
  analogWrite(servoIn2,  
    map(constrain(rightBackwardIn, 0, 128), 0, 128, 0, 220)
  );
  analogWrite(servoIn3,  
    map(constrain(leftForwardIn, 0, 128), 0, 128, 0, 220)
  );
  analogWrite(servoIn4,  
    map(constrain(leftBackwardIn, 0, 128), 0, 128, 0, 220)
  );

  sprintf(messageString, "%4d,%4d, %4d, %4d", 
  map(constrain(leftBackwardIn, 0, 128), 0, 128, 0, 220), 
  map(constrain(leftForwardIn, 0, 128), 0, 128, 0, 220), 
  map(constrain(rightForwardIn, 0, 128), 0, 128, 0, 220), 
  map(constrain(rightBackwardIn, 0, 128), 0, 128, 0, 220)
  );

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