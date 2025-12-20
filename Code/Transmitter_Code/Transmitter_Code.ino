void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Button 1 - Single 200ms pulse
  if (digitalRead(4) == HIGH) {
    Serial.println("B1 - 200ms");
    digitalWrite(3, HIGH);
    delay(200);
    digitalWrite(3, LOW);
    while(digitalRead(4) == HIGH);
  }
  
  // Button 2 - Single 400ms pulse  
  if (digitalRead(5) == HIGH) {
    Serial.println("B2 - 400ms");
    digitalWrite(3, HIGH);
    delay(400);
    digitalWrite(3, LOW);
    while(digitalRead(5) == HIGH);
  }
  
  // Button 3 - Single 600ms pulse
  if (digitalRead(6) == HIGH) {
    Serial.println("B3 - 600ms");
    digitalWrite(3, HIGH);
    delay(600);
    digitalWrite(3, LOW);
    while(digitalRead(6) == HIGH);
  }
}
