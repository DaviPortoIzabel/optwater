# Phase 1 — Initial Simulation (ESP32 + Button + LED)

## Time Spent
~2–3 hours

## Goal
The goal of this phase was to simulate the basic behavior of the system before using real hardware.  
Instead of using the actual water flow sensor, I used a button to simulate pulses.

---

## What I Built
- ESP32 simulation environment (Wokwi)
- LED connected to pin 2
- Button connected to pin 4
- Basic code to detect input and control output

---

## How It Works
- Pressing the button simulates water flow (like pulses from a sensor)
- When the button is pressed:
  - The LED turns on
  - A message "PULSE DETECT" is printed in the Serial Monitor
- When the button is released:
  - The LED turns off

---

## Challenges
At the beginning, I had a lot of difficulty with the wiring, especially the LED.

- I didn’t understand how to connect the resistor correctly
- The LED didn’t turn on at first
- I had to fix the connections multiple times

After correcting the circuit, everything started working as expected.

---

## What I Learned
- How digital input works using `INPUT_PULLUP`
- Difference between HIGH and LOW signals
- How to control outputs (LED) with the ESP32
- Basic debugging of circuit connections

---

## Result
The simulation is working correctly:
- Button press is detected
- LED responds correctly
- Serial output confirms the logic

---

## Next Steps
- Implement leak detection logic based on time
- Detect continuous flow instead of single pulses
- Add different LED behavior for leak detection