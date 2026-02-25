/*
  Outdoor Lighting System - LDR Sensor
  Source: Graduation Project PDF (Page 58)
  Sensor: Light Dependent Resistor
  Controller: Arduino Mega 2560
*/

int const LDRPin = A2;
int sensorValue = 0;
#define LEDPin 27

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Outdoor Lighting System Ready");
}

void loop() {
  sensorValue = analogRead(LDRPin);
  
  Serial.print("Light Level: ");
  Serial.println(sensorValue);
  
  // If dark (low light), turn ON
  if (sensorValue < 50) {
    digitalWrite(LEDPin, HIGH);
    Serial.println("Night Time - Light ON");
  } 
  // If bright, turn OFF
  else {
    digitalWrite(LEDPin, LOW);
    Serial.println("Day Time - Light OFF");
  }
  
  delay(500);
}
