void notify() {
  if (PS4.LStickY() >= 126) {
    leftForward();
  } else if (PS4.LStickY() <= -126) {
    leftBackward();
  } else {
    leftStop();
  }

  if (PS4.RStickY() >= 126) {
    rightForward();
  } else if (PS4.RStickY() <= -126) {
    rightBackward();
  } else {
    rightStop();
  }
}

void onConnect() {
  Serial.println("PS4 Connected");
}

void onDisconnect() {
  Serial.println("PS4 Disconnected");
}