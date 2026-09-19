#include <PS4Controller.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

#define servoIn1 16
#define servoIn2 4
#define servoIn3 18
#define servoIn4 19

#define button 23
#define wifiInd 22
#define servoGrip 33

int rightForwardIn = 0;
int rightBackwardIn = 0;
int leftForwardIn = 0;
int leftBackwardIn = 0;

IPAddress local_IP(172, 20, 10, 20);
IPAddress gateway(172, 20, 10, 1);
IPAddress subnet(255, 255, 255, 240);
IPAddress primaryDNS(8, 8, 8, 8);   
IPAddress secondaryDNS(8, 8, 4, 4);

// const char* ssid = "Tselhome-3697";
// const char* password = "63791966";

const char* ssid = "iPad";
const char* password = "pacarkakjosh";

unsigned long lastCommandTime = 0;
const unsigned long TIMEOUT_MS = 1500;

WebServer server(80);
Servo gripper;

int buttonState = 0;
bool lastButtonState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(servoIn1, OUTPUT);
  pinMode(servoIn2, OUTPUT);
  pinMode(servoIn3, OUTPUT);
  pinMode(servoIn4, OUTPUT);

  pinMode(button, INPUT_PULLDOWN);
  pinMode(wifiInd, OUTPUT);

  gripper.attach(servoGrip);
  digitalWrite(wifiInd, LOW);

  Serial.println("Starting...");
}
 
void loop() {
  bool currentButtonState = digitalRead(button);

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    delay(50);

    buttonState++;
    if (buttonState > 2) {
      buttonState = 0;
    }

    Serial.print("Current Mode: ");
    Serial.println(buttonState);

    if (buttonState == 1) {
      Serial.println("Starting PS4 Controller...");
      WiFi.mode(WIFI_OFF);
      digitalWrite(wifiInd, LOW);
      PS4Startup();
    } 
    else if (buttonState == 2) {
      Serial.println("Starting WiFi...");
      PS4.end();
      WifiStartup();
      digitalWrite(wifiInd, HIGH);
      
      lastCommandTime = millis();
    }
    else {
      Serial.println("Stopping All Connections...");
      PS4.end();
      WiFi.mode(WIFI_OFF);
      digitalWrite(wifiInd, LOW);
    }
  }

  lastButtonState = currentButtonState;

  if (buttonState == 2) {
    server.handleClient();

    if (millis() - lastCommandTime > TIMEOUT_MS) {
    robotStop();
  }
  }
}
