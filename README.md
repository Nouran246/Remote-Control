# Arduino Custom Remote Control Project

## Overview
This project implements a **custom remote control system** using Arduino, buttons, and LEDs.  
The system demonstrates **command transmission and reception** without using standard IR protocols.  
It uses **time-based (pulse-duration) encoding** for transmitting signals and **threshold-based decoding** on the receiver.  

We implemented the project on **real hardware** and also built a **simulator** for testing.

---

## Features
- **Transmitter:** Arduino reads push buttons and generates unique timing-based signals for each button.  
- **Receiver:** Arduino measures signal duration, decodes the command, and activates a corresponding LED.  
- **Debugging:** Serial messages are printed for verification on both transmitter and receiver.  
- **Simulator:** Allows testing signal generation and decoding logic without hardware.  
- Works fully on **real hardware**, demonstrating LED activation based on custom signals.

---

## Hardware Setup

### Transmitter
- Push buttons connected to digital input pins (e.g., pins 4, 5, 6).
- LED connected to digital output pin (e.g., pin 3) to visualize signals.  
- Arduino reads button presses and generates different pulse durations for each command.

### Receiver
- Sensor/input pin connected to Arduino (detects LOW pulse from transmitter).  
- RGB LEDs connected to digital output pins (red, green, blue).  
- Arduino measures pulse duration, matches it to a range, and lights up corresponding LED.

---

## How It Works

### Transmitter Logic
1. User presses a button.  
2. Arduino reads the input and generates a **pulse-duration signal**.  
3. Output pin sends the signal.  
4. Serial prints the button pressed for debugging.

### Receiver Logic
1. Arduino monitors input pin for LOW pulses.  
2. Measures duration of the pulse.  
3. Decodes the command by comparing pulse duration with predefined ranges.  
4. Activates corresponding LED.  
5. Serial prints debug information; unknown signals are ignored.

---

## Challenges
- Synchronizing pulse-duration signals with accurate detection on the receiver.  
- Ensuring reliable decoding without using standard IR protocols.

---

## Lessons Learned
- Custom signal encoding and decoding using Arduino digital I/O.  
- Wiring and integrating buttons, LEDs, and sensors.  
- Debugging signal timing using Serial monitor.  
- Simulator allows testing logic before hardware implementation.

---

## Code Example

### Transmitter
```
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
````
### Reciever
```` 
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
````

---
### Simulator
- A software-based simulator replicates button presses and pulse-duration signals.  
- Helps verify decoding logic without physical Arduino boards.  
- Outputs simulated LED states and serial debug messages.  

---

## Hardware Implementation
- Fully tested on real Arduino hardware.  
- LEDs correctly light up based on pulse-duration signals from each button.  
- Works reliably with three buttons and RGB LEDs.

---

## Future Improvements
- Upgrade to **IRremote library** for standard IR protocol support.  
- Expand to more commands using binary or NEC codes.  
- Improve simulator UI for easier visualization of signals.  
- Optimize pulse-duration ranges for more reliable decoding.

---

## Acknowledgements
- Arduino documentation and tutorials on digital I/O.  
- KY-033 sensor datasheets and examples.  
- Online resources for timing-based signal handling and debugging.

---

## Authors
- [@Roaa Khaled](https://github.com/Rowlkh)
- [@Nouran Hassan](https://github.com/nouran246)

