/*
  Music Rhythm Dancing Lights
  Arduino-based version
  Components: Sound sensor, LEDs
  Controller: Arduino Mega 2560
*/

#define MIC_PIN A0      // Microphone analog input
#define LED1_PIN 30     // LED 1
#define LED2_PIN 31     // LED 2
#define LED3_PIN 32     // LED 3
#define LED4_PIN 33     // LED 4

int threshold = 100;    // Sensitivity threshold
int soundLevel = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
  // Start with all LEDs OFF
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  
  Serial.println("Music Rhythm System Ready");
}

void loop() {
  // Read sound level from microphone
  soundLevel = analogRead(MIC_PIN);
  
  Serial.print("Sound Level: ");
  Serial.println(soundLevel);
  
  // If sound detected above threshold
  if (soundLevel > threshold) {
    // Flash LEDs based on sound intensity
    int intensity = map(soundLevel, threshold, 300, 1, 4);
    
    switch(intensity) {
      case 1:
        digitalWrite(LED1_PIN, HIGH);
        delay(50);
        digitalWrite(LED1_PIN, LOW);
        break;
      case 2:
        digitalWrite(LED1_PIN, HIGH);
        digitalWrite(LED2_PIN, HIGH);
        delay(50);
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
        break;
      case 3:
        digitalWrite(LED1_PIN, HIGH);
        digitalWrite(LED2_PIN, HIGH);
        digitalWrite(LED3_PIN, HIGH);
        delay(50);
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
        digitalWrite(LED3_PIN, LOW);
        break;
      case 4:
        digitalWrite(LED1_PIN, HIGH);
        digitalWrite(LED2_PIN, HIGH);
        digitalWrite(LED3_PIN, HIGH);
        digitalWrite(LED4_PIN, HIGH);
        delay(50);
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
        digitalWrite(LED3_PIN, LOW);
        digitalWrite(LED4_PIN, LOW);
        break;
    }
  }
  
  delay(10);
}
