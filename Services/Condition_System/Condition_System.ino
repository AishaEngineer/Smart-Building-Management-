/*
  Air Conditioning System
  Source: Graduation Project PDF (Page 67-69)
  Sensor: DHT11 Temperature & Humidity
  Actuator: Fan (Air Conditioner)
  Controller: Arduino Mega 2560
*/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 28

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("DHT11 Test - Air Conditioning System");
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Control fan based on temperature
  if (temperature > 28) {  // If temperature > 28°C
    digitalWrite(FAN_PIN, HIGH);  // Fan ON
    Serial.println("High Temperature - Fan ON");
  } else {
    digitalWrite(FAN_PIN, LOW);   // Fan OFF
    Serial.println("Normal Temperature - Fan OFF");
  }
  
  // Display readings
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(1000);
}
