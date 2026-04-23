int ledPin = 2;
int sensorPin = 4;

unsigned long flowStartTime = 0;
unsigned long leakThreshold = 5000;   // 5 seconds for simulation
unsigned long lastBlinkTime = 0;
unsigned long blinkInterval = 200;    // LED blink speed

enum SystemState {
  IDLE,
  FLOW,
  LEAK
};

SystemState currentState = IDLE;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  unsigned long currentTime = millis();

  // Detect state
  if (sensorState == LOW) {
    // Flow is happening
    if (currentState == IDLE) {
      flowStartTime = currentTime;
      currentState = FLOW;
    }

    unsigned long flowDuration = currentTime - flowStartTime;

    if (flowDuration >= leakThreshold) {
      currentState = LEAK;
    } else {
      currentState = FLOW;
    }
  } else {
    // No flow
    currentState = IDLE;
  }

  // Act based on state
  switch (currentState) {
    case IDLE:
      digitalWrite(ledPin, LOW);
      Serial.println("IDLE - No Flow");
      break;

    case FLOW:
      digitalWrite(ledPin, HIGH);
      Serial.println("FLOW - Normal Flow");
      break;

    case LEAK:
      Serial.println("LEAK - Leak Detected");

      if (currentTime - lastBlinkTime >= blinkInterval) {
        lastBlinkTime = currentTime;
        digitalWrite(ledPin, !digitalRead(ledPin));
      }
      break;
  }

  delay(100);
}