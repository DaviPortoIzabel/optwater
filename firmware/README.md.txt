# Low-Cost Leak Detector

## Overview
This project is a low-cost smart water leak detection system using an ESP32 and a flow-based logic model.

Instead of using a real flow sensor in the initial stage, a button is used to simulate water flow through pulse signals.

---

## Goal
The goal of this project is to detect continuous water flow that may indicate a leak in a plumbing system.

---

## Phase 1 — Simulation & Core Logic

In this phase, the main focus was to build and validate the core logic of the system before using real hardware.

### What Was Implemented

- ESP32 simulation environment
- LED as output indicator
- Button used to simulate water flow (pulse input)
- Serial monitor for debugging and feedback

---

## System Behavior

The system operates based on the duration of the detected flow:

- **No input (button not pressed)**
  - LED OFF

- **Short input (normal flow)**
  - LED ON
  - Serial output: "Normal Flow"

- **Continuous input (possible leak)**
  - LED blinks
  - Serial output: "Leak Detected"

---

## Leak Detection Logic

The system uses time-based logic to identify abnormal behavior:

- When the button is first pressed:
  - The system records the start time using `millis()`

- While the button remains pressed:
  - The system continuously calculates how long the input has been active

- If the input lasts longer than a defined threshold (5 seconds in simulation):
  - The system triggers a leak alert

---

## Challenges Faced

- Initial difficulty understanding LED and resistor wiring
- Debugging incorrect circuit connections
- Adjusting logic to correctly measure continuous input instead of single events
- Fixing logical error where time was only measured once

---

## What Was Learned

- How digital inputs and outputs work on ESP32
- How `INPUT_PULLUP` affects button behavior
- How to use `millis()` for non-blocking time measurement
- Basic debugging of embedded systems (logic + hardware)

---

## Current Status

Phase 1 is complete:
- Simulation is working correctly
- Flow detection logic is implemented
- Leak detection is functioning based on time

---

## Next Steps (Phase 2)

- Improve system behavior definition
- Refine leak detection rules
- Add buzzer for alerts
- Prepare system architecture for PCB design