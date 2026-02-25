/*
  Remote Device Control System
  Source: Graduation Project PDF (Page 73-76)
  Controller: Arduino Mega 2560
  WiFi: ESP8266
  Actuator: Fan
*/

#include <SoftwareSerial.h>

#define FAN_PIN 28
#define RX_PIN 10
#define TX_PIN 11
#define DEBUG true

SoftwareSerial esp8266(RX_PIN, TX_PIN);
bool fanState = false;

String sendData(String command, const int timeout, boolean debug);

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
  
  // Configure ESP8266
  sendData("AT+RST\r\n", 2000, DEBUG);
  sendData("AT+CWMODE=2\r\n", 1000, DEBUG);
  sendData("AT+CIFSR\r\n", 1000, DEBUG);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
  
  Serial.println("Device Control System Ready");
}

void loop() {
  if (esp8266.available()) {
    if (esp8266.find("+IPD,")) {
      delay(500);
      int connectionId = esp8266.read() - 48;
      esp8266.find("pin=");
      int pinNumber = (esp8266.read() - 48) * 10;
      pinNumber += (esp8266.read() - 48);
      
      if (pinNumber == 49) {  // Fan control
        fanState = !fanState;
        digitalWrite(FAN_PIN, fanState);
        Serial.print("Fan: ");
        Serial.println(fanState ? "ON" : "OFF");
      }
      
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId;
      closeCommand += "\r\n";
      sendData(closeCommand, 1000, DEBUG);
    }
  }
}

String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  esp8266.print(command);
  long int time = millis();
  
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  
  if (debug) Serial.println(response);
  return response;
}
