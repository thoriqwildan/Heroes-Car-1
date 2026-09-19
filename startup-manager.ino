void PS4Startup() {
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisconnect);
  PS4.begin();
}

void WifiStartup() {
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Gagal mengkonfigurasi IP Statis");
  }

  WiFi.begin(ssid, password);

  unsigned long startTime = millis();
  const unsigned long timeout = 10000;

  while (WiFi.status() != WL_CONNECTED && millis() - startTime < timeout) {
    digitalWrite(wifiInd, !digitalRead(wifiInd)); 
    delay(250);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(wifiInd, HIGH);
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address ESP32: ");
    Serial.println(WiFi.localIP());

    server.on("/cmd", handleCommand);
    server.begin();
  } else {
    Serial.println("\nWiFi Connection Failed/Timeout!");
    digitalWrite(wifiInd, LOW);
    WiFi.mode(WIFI_OFF);
  }
}