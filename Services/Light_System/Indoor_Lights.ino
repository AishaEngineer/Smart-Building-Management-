/*
  Indoor Lighting System - WiFi Control
  Source: Graduation Project PDF (Page 56-57)
  Controller: Arduino Mega 2560
  WiFi Module: ESP8266
  Last Updated: February 2026
*/

#include <SoftwareSerial.h>

// ==================== PIN DEFINITIONS ====================
// Control pins from web interface
#define ROOM1        40    // Control Room
#define ROOM2        42    // Small Room
#define ROOM3        46    // Big Room/Living Room
#define SWIMMING_POOL 41   // Reserved
#define BATHROOM     43    // Bathroom
#define KITCHEN      44    // Kitchen
#define DOOR_OPEN    48    // Door Open Command
#define DOOR_CLOSE   47    // Door Close Command
#define FAN_PIN      49    // Fan Control

// LED output pins
#define LED1_PIN     25    // Control Room
#define LED2_PIN     26    // Small Room
#define LED3_PIN     24    // Swimming Pool/Reserved
#define LED4_PIN     22    // Bathroom
#define LED5_PIN     23    // Kitchen
#define LED6_PIN     7     // Big Room
#define LED7_PIN     28    // Fan

// ==================== GLOBAL VARIABLES ====================
bool led1State = 0;
bool led2State = 0;
bool led3State = 0;
bool led4State = 0;
bool led5State = 0;
bool led6State = 0;
bool led7State = 0;

// ESP8266 Configuration
#define RX_PIN 10
#define TX_PIN 11
#define DEBUG true

SoftwareSerial esp8266(RX_PIN, TX_PIN);

// ==================== FUNCTION PROTOTYPES ====================
String sendData(String command, const int timeout, boolean debug);
void controlDevice(int pinNumber, int connectionId);

// ==================== SETUP ====================
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  esp8266.begin(9600);
  
  // Configure LED pins as outputs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
  pinMode(LED6_PIN, OUTPUT);
  pinMode(LED7_PIN, OUTPUT);
  
  // Initialize all LEDs to OFF
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  digitalWrite(LED5_PIN, LOW);
  digitalWrite(LED6_PIN, LOW);
  digitalWrite(LED7_PIN, LOW);
  
  Serial.println("System Starting...");
  
  // Configure ESP8266 as Access Point
  sendData("AT+RST\r\n", 2000, DEBUG);           // Reset module
  delay(1000);
  sendData("AT+CWMODE=2\r\n", 1000, DEBUG);      // Set to AP mode
  delay(1000);
  sendData("AT+CIFSR\r\n", 1000, DEBUG);         // Get IP address
  delay(1000);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);      // Enable multiple connections
  delay(1000);
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); // Start server on port 80
  
  Serial.println("System Ready. Connect to WiFi: ESP8266_AP");
}

// ==================== MAIN LOOP ====================
void loop() {
  if (esp8266.available()) {
    if (esp8266.find("+IPD,")) {
      Serial.println("Client Connected");
      delay(1000);
      
      // Get connection ID
      int connectionId = esp8266.read() - 48;
      
      // Find the pin parameter
      esp8266.find("pin=");
      
      // Read pin number (2 digits)
      int pinNumber = (esp8266.read() - 48) * 10;
      pinNumber += (esp8266.read() - 48);
      
      // Control the device
      controlDevice(pinNumber, connectionId);
      
      // Close the connection
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId;
      closeCommand += "\r\n";
      sendData(closeCommand, 1000, DEBUG);
    }
  }
}

// ==================== DEVICE CONTROL FUNCTION ====================
void controlDevice(int pinNumber, int connectionId) {
  switch(pinNumber) {
    case ROOM1:
      led1State = !led1State;
      digitalWrite(LED1_PIN, led1State);
      Serial.print("Control Room: ");
      Serial.println(led1State ? "ON" : "OFF");
      break;
      
    case ROOM2:
      led2State = !led2State;
      digitalWrite(LED2_PIN, led2State);
      Serial.print("Small Room: ");
      Serial.println(led2State ? "ON" : "OFF");
      break;
      
    case ROOM3:
      led6State = !led6State;
      digitalWrite(LED6_PIN, led6State);
      Serial.print("Living Room: ");
      Serial.println(led6State ? "ON" : "OFF");
      break;
      
    case BATHROOM:
      led4State = !led4State;
      digitalWrite(LED4_PIN, led4State);
      Serial.print("Bathroom: ");
      Serial.println(led4State ? "ON" : "OFF");
      break;
      
    case KITCHEN:
      led5State = !led5State;
      digitalWrite(LED5_PIN, led5State);
      Serial.print("Kitchen: ");
      Serial.println(led5State ? "ON" : "OFF");
      break;
      
    case FAN_PIN:
      led7State = !led7State;
      digitalWrite(LED7_PIN, led7State);
      Serial.print("Fan: ");
      Serial.println(led7State ? "ON" : "OFF");
      break;
      
    default:
      Serial.println("Unknown command");
      break;
  }
}

// ==================== ESP8266 COMMUNICATION FUNCTION ====================
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
  
  if (debug) {
    Serial.print(response);
  }
  
  return response;
}
