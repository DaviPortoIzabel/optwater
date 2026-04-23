# Phase 2 — System Behavior Specification

## Overview
This phase defines the final behavior of the leak detection system.

The system is based on a flow sensor (YF-S201) that generates pulses when water flows.  
The ESP32 processes these pulses and determines whether the behavior is normal or indicates a possible leak.

---

## System States

The system operates with three main states:

### 1. IDLE
- No pulses detected
- No water flow

**Behavior:**
- LED OFF

---

### 2. FLOW (Normal Usage)
- Pulses are detected
- Flow duration is within normal limits

**Behavior:**
- LED ON (solid)

---

### 3. LEAK (Leak Detected)
- Continuous pulses for an extended period
- Flow duration exceeds threshold

**Behavior:**
- LED blinking

---

## Flow Detection Logic

- Pulses received → water is flowing
- No pulses for a short period → water stopped

---

## Leak Detection Rule

The system identifies a possible leak based on **continuous flow duration**.

### Simulation Mode
- Threshold: **5 seconds**

### Real Product Mode (YF-S201)
- Threshold: **10 minutes (600,000 ms)**

---

## State Transition Logic

- No pulses → IDLE
- Pulses detected → FLOW
- Continuous flow exceeding threshold → LEAK
- Flow stops → return to IDLE

---

## LED Behavior Summary

| State | LED |
|------|-----|
| IDLE | OFF |
| FLOW | ON |
| LEAK | BLINKING |

---

## System Architecture

---

## Notes

- The current implementation uses a button to simulate pulses.
- In future versions, the YF-S201 will replace the button.
- The leak detection is rule-based and may be extended in the future with smarter analysis or machine learning.

---

## Status

- Core logic implemented
- State-based system working
- Ready for hardware integration (Phase 3)