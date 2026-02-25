/*
  Stair Lighting System - Motion Activated
  Source: Graduation Project PDF (Page 57)
  Sensor: Ultrasonic HC-SR04
  Controller: Arduino Mega 2560
*/

#define trigPin 48
#define echoPin 49
#define ledPin 6

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Stair Lighting System Ready");
}

void loop() {
  long duration, distance;
  
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = (duration / 2) / 29.1;
  
  // Control LED based on distance
  if (distance < 20) {  // Motion detected within 20cm
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detected - Light ON");
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(100);
}
