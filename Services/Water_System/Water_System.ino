/*
  Automatic Water Supply System
  Source: Graduation Project PDF (Page 62-66)
  Sensor: Ultrasonic HC-SR04
  Actuator: Water Pump (Fan)
  Controller: Arduino Mega 2560
*/

#define echoPin 5
#define trigPin 4
#define fanPin 28
#define LowRange 5    // Low water level (pump ON)
#define MidRange 10   // Medium water level

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(fanPin, OUTPUT);
  Serial.println("Water Supply System Ready");
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = duration / 58.2;
  
  // Control pump based on water level
  if (distance > 0 && distance <= LowRange) {
    digitalWrite(fanPin, LOW);   // Pump OFF (tank full)
    Serial.println("Tank Full - Pump OFF");
  }
  else if (distance > LowRange && distance <= MidRange) {
    digitalWrite(fanPin, HIGH);  // Pump ON (filling)
    Serial.println("Filling Tank - Pump ON");
  }
  
  Serial.print("Water Level: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(300);
}
