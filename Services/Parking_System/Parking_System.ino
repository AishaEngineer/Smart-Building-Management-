/*
  Parking Assistance System
  Source: Graduation Project PDF (Page 94-97)
  Sensor: Ultrasonic HC-SR04
  Output: Green LED (safe), White LED (stop)
  Controller: Arduino Mega 2560
*/

#define echoPin 12
#define trigPin 13
#define greenLED 8   // Safe distance
#define whiteLED 9   // Too close
#define SAFE_DISTANCE 5  // cm

long duration, distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  
  // Initial state
  digitalWrite(greenLED, HIGH);   // Green ON = safe
  digitalWrite(whiteLED, LOW);    // White OFF
  
  Serial.println("Parking System Ready");
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
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Control LEDs based on distance
  if (distance > 0 && distance <= SAFE_DISTANCE) {
    // Too close - STOP
    digitalWrite(greenLED, LOW);   // Green OFF
    digitalWrite(whiteLED, HIGH);  // White ON
    Serial.println("STOP! Too close");
  } else {
    // Safe distance
    digitalWrite(greenLED, HIGH);  // Green ON
    digitalWrite(whiteLED, LOW);   // White OFF
    Serial.println("Safe - Continue");
  }
  
  delay(300);
}
