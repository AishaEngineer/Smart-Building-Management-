/*
  Wall Protection System
  Source: Graduation Project PDF (Page 84-87)
  Sensor: Laser + Photoresistor
  Output: Buzzer + SMS Alert
  Controller: Arduino Mega 2560
  GSM: SIM900A
*/

#define LASER_PIN A2     // Photoresistor
#define BUZZER_PIN 50    // Buzzer
#define GSM_RX 52        // GSM RX
#define GSM_TX 53        // GSM TX

#include <SoftwareSerial.h>
SoftwareSerial gsm(GSM_RX, GSM_TX);

int laserValue = 0;
bool alarmActive = false;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println("Wall Protection System Ready");
  
  // Initialize GSM
  gsm.println("AT");
  delay(1000);
  gsm.println("AT+CMGF=1");  // Text mode
  delay(1000);
}

void loop() {
  laserValue = analogRead(LASER_PIN);
  
  Serial.print("Laser Sensor: ");
  Serial.println(laserValue);
  
  // If laser beam broken (value changes significantly)
  if (laserValue < 500) {  // Adjust threshold as needed
    if (!alarmActive) {
      // Trigger alarm
      digitalWrite(BUZZER_PIN, HIGH);
      alarmActive = true;
      
      // Send SMS
      sendSMS("+966XXXXXXXXX", "ALERT! Laser beam broken at home wall!");
      
      Serial.println("!!! INTRUSION DETECTED !!!");
    }
  } else {
    // No intrusion
    digitalWrite(BUZZER_PIN, LOW);
    alarmActive = false;
  }
  
  delay(100);
}

void sendSMS(String number, String message) {
  gsm.println("AT+CMGS=\"" + number + "\"");
  delay(500);
  gsm.print(message);
  delay(500);
  gsm.write(26);  // Ctrl+Z to send SMS
  delay(5000);
  
  Serial.println("SMS Sent");
}
