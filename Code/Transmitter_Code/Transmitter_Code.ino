void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Button 1
  if (digitalRead(4) == HIGH) {
    Serial.println("B1");
    digitalWrite(3, HIGH); delay(100); digitalWrite(3, LOW); delay(100);
    digitalWrite(3, HIGH); delay(100); digitalWrite(3, LOW); delay(100);
    digitalWrite(3, HIGH); delay(100); digitalWrite(3, LOW);
    while(digitalRead(4) == HIGH); // Wait for release
  }
  
  // Button 2
  if (digitalRead(5) == HIGH) {
    Serial.println("B2");
    digitalWrite(3, HIGH); delay(300); digitalWrite(3, LOW); delay(300);
    digitalWrite(3, HIGH); delay(300); digitalWrite(3, LOW);
    while(digitalRead(5) == HIGH);
  }
  
  // Button 3
  if (digitalRead(6) == HIGH) {
    Serial.println("B3");
    digitalWrite(3, HIGH); delay(600); digitalWrite(3, LOW);
    while(digitalRead(6) == HIGH);
  }
}