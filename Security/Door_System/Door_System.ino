/*
  Automatic Door Control System
  Source: Graduation Project PDF (Page 81-84)
  Actuator: Servo Motor
  Control: WiFi via ESP8266
  Controller: Arduino Mega 2560
*/

#include <SoftwareSerial.h>
#include <Servo.h>

Servo doorServo;
#define SERVO_PIN 30

#define RX_PIN 10
#define TX_PIN 11
#define DEBUG true

SoftwareSerial esp8266(RX_PIN, TX_PIN);

String sendData(String command, const int timeout, boolean debug);

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  
  doorServo.attach(SERVO_PIN);
  doorServo.write(0);  // Door closed position
  
  // Configure ESP8266
  sendData("AT+RST\r\n", 2000, DEBUG);
  sendData("AT+CWMODE=2\r\n", 1000, DEBUG);
  sendData("AT+CIFSR\r\n", 1000, DEBUG);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
  
  Serial.println("Door Control System Ready");
}

void loop() {
  if (esp8266.available()) {
    if (esp8266.find("+IPD,")) {
      delay(500);
      int connectionId = esp8266.read() - 48;
      esp8266.find("pin=");
      int pinNumber = (esp8266.read() - 48) * 10;
      pinNumber += (esp8266.read() - 48);
      
      // Door control commands
      if (pinNumber == 48) {  // DOOR_OPEN
        doorServo.write(90);   // Open door
        Serial.println("Door OPEN");
      }
      else if (pinNumber == 47) {  // DOOR_CLOSE
        doorServo.write(0);        // Close door
        Serial.println("Door CLOSED");
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
