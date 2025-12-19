int sensor = 2;   
int red = 3;      
int green = 4;
int blue = 5;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("RECEIVER READY");
}

void loop() {
  if (digitalRead(sensor) == LOW) {
    
    long t = 0;
    while (digitalRead(sensor) == LOW) {
      delay(1);
      t = t + 1;
    }
    
    // Show measurement
    Serial.print("Got: ");
    Serial.print(t);
    Serial.println(" ms");
    
    // Button 1 (100ms) = RED
    if (t > 80 && t < 120) {
      Serial.println("Button 1 - RED");
      digitalWrite(red, HIGH);
      delay(2000);
      digitalWrite(red, LOW);
    }
    
    // Button 2 (300ms) = GREEN
    else if (t > 250 && t < 350) {
      Serial.println("Button 2 - GREEN");
      digitalWrite(green, HIGH);
      delay(2000);
      digitalWrite(green, LOW);
    }
    
    // Button 3 (600ms) = BLUE
    else if (t > 550 && t < 650) {
      Serial.println("Button 3 - BLUE");
      digitalWrite(blue, HIGH);
      delay(2000);
      digitalWrite(blue, LOW);
    }
    
    // Unknown signal
    else {
      Serial.println("Unknown signal");
    }
  }
}
