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
```cpp
if (digitalRead(5) == HIGH) {
  Serial.println("B2");
  digitalWrite(3, HIGH); delay(300);
  digitalWrite(3, LOW);  delay(300);
}


