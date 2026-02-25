/*
  Gas Leak Detection System
  Source: Graduation Project PDF (Page 90-93)
  Sensor: MQ-6 Gas Sensor
  Output: Buzzer, LED, SMS Alert
  Controller: Arduino Mega 2560
  GSM: SIM900A
*/

#define GAS_SENSOR A0
#define BUZZER_PIN 50
#define LED_PIN 51
#define GSM_RX 52
#define GSM_TX 53

#include <SoftwareSerial.h>
SoftwareSerial gsm(GSM_RX, GSM_TX);

int sensorValue = 0;
float sinVal;
int toneVal;
bool alarmActive = false;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  gsm.begin(9600);
  
  Serial.println("Gas Detection System Ready");
  
  // Initialize GSM
  gsm.println("AT");
  delay(1000);
  gsm.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  sensorValue = analogRead(GAS_SENSOR);
  Serial.print("Gas Level: ");
  Serial.println(sensorValue);
  
  // If gas detected above threshold
  if (sensorValue > 300) {
    digitalWrite(LED_PIN, HIGH);
    
    if (!alarmActive) {
      // Send SMS alert
      sendSMS("+966XXXXXXXXX", "WARNING! Gas leak detected in home!");
      alarmActive = true;
    }
    
    // Generate alarm sound
    for (int x = 0; x < 180; x++) {
      sinVal = sin(x * (3.1412 / 180));
      toneVal = 2000 + int(sinVal * 1000);
      tone(BUZZER_PIN, toneVal);
      delay(2);
    }
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    alarmActive = false;
  }
  
  delay(100);
}

void sendSMS(String number, String message) {
  gsm.println("AT+CMGS=\"" + number + "\"");
  delay(500);
  gsm.print(message);
  delay(500);
  gsm.write(26);  // Ctrl+Z
  delay(5000);
  
  Serial.println("Gas Alert SMS Sent");
}
