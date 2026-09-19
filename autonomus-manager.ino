void robotMaju() {
  digitalWrite(servoIn1, HIGH);
  digitalWrite(servoIn2, LOW);
  digitalWrite(servoIn3, HIGH);
  digitalWrite(servoIn4, LOW);
}

void robotBelokKanan() {
  digitalWrite(servoIn1, LOW);
  digitalWrite(servoIn2, HIGH);  // kiri maju
  digitalWrite(servoIn3, HIGH);
  digitalWrite(servoIn4, LOW); // kanan mundur
}

void robotBelokKiri() {
  digitalWrite(servoIn1, HIGH);
  digitalWrite(servoIn2, LOW); // kiri mundur
  digitalWrite(servoIn3, LOW);
  digitalWrite(servoIn4, HIGH);  // kanan maju
}

void robotStop() {
  digitalWrite(servoIn1, LOW);
  digitalWrite(servoIn2, LOW);
  digitalWrite(servoIn3, LOW);
  digitalWrite(servoIn4, LOW);
}

void handleCommand() {
  if (server.hasArg("val")) {
    String command = server.arg("val");
    lastCommandTime = millis(); // reset timer tiap kali perintah masuk
    
    // command marker aruco
    if (command == "0") {
      robotMaju();
      Serial.println(">>> [ROBOT] 0: MAJU LURUS");
    } 
    else if (command == "1") {
      robotBelokKanan();
      Serial.println(">>> [ROBOT] 1: BELOK KANAN");
    } 
    else if (command == "2") {
      robotBelokKiri();
      Serial.println(">>> [ROBOT] 2: BELOK KIRI");
    } 
    else if (command == "3") {
      robotStop();
      Serial.println(">>> [ROBOT] 3: BERHENTI / STOP");
    }

    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}