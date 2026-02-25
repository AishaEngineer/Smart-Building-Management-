/*
  Soil Humidity Monitoring System
  Source: Graduation Project PDF (Page 70-72)
  Sensor: YL-69 Soil Moisture Sensor
  Indicator: LED
  Controller: Arduino Mega 2560
*/

#define sensorPin A1
#define ledPin 3

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Soil Humidity System Ready");
}

void loop() {
  // Read soil moisture value (0-1023)
  int sensorValue = analogRead(sensorPin);
  
  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue);
  
  // If soil is dry (low moisture)
  if (sensorValue < 600) {
    digitalWrite(ledPin, HIGH);  // LED ON - Water needed
    Serial.println("Soil DRY - Water Needed");
  } 
  // If soil is wet (high moisture)
  else {
    digitalWrite(ledPin, LOW);   // LED OFF - Soil OK
    Serial.println("Soil WET - OK");
  }
  
  delay(1000);
}
