void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);  // Red
  pinMode(4, OUTPUT);  // Green
  pinMode(5, OUTPUT);  // Blue
  Serial.begin(9600);
  Serial.println("READY");
}

void loop() {
  if (digitalRead(2) == LOW) {
    unsigned long start = millis();
    
    // Wait for signal to end (with timeout)
    while(digitalRead(2) == LOW && millis() - start < 2000);
    
    unsigned long pulseTime = millis() - start;
    
    Serial.print("Got: ");
    Serial.print(pulseTime);
    Serial.println(" ms");
    
    // NON-OVERLAPPING ranges:
    if (pulseTime > 150 && pulseTime < 250) {    // ~200ms
      Serial.println("B1 - RED");
      digitalWrite(3, HIGH); delay(2000); digitalWrite(3, LOW);
    }
    else if (pulseTime > 350 && pulseTime < 450) { // ~400ms
      Serial.println("B2 - GREEN");
      digitalWrite(4, HIGH); delay(2000); digitalWrite(4, LOW);
    }
    else if (pulseTime > 550 && pulseTime < 650) { // ~600ms
      Serial.println("B3 - BLUE");
      digitalWrite(5, HIGH); delay(2000); digitalWrite(5, LOW);
    }
    else {
      Serial.println("Noise - Ignored");
    }
  }
}
