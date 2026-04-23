int pin02 = 2; // LED pin
int pin04 = 4; // Button pin

// Button is touched? Count the time
unsigned long flowStartTime = 0;
bool flowActive = false;

// After 5 seconds, alarm the leak
unsigned long leakThreshold = 5000;

void setup() {
    pinMode(pin02, OUTPUT);
    pinMode(pin04, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
    int sensorState = digitalRead(pin04);

    if (sensorState == LOW) {
        // If flow just started, save the start time
        if (!flowActive) {
            flowActive = true;
            flowStartTime = millis();
        }

        // Calculate how long the flow has been active
        unsigned long flowDuration = millis() - flowStartTime;

        if (flowDuration < leakThreshold) {
            digitalWrite(pin02, HIGH);
            Serial.println("Normal Flow");
        } else {
            Serial.println("Leak Detected");

            for (int i = 0; i < 4; i++) {
                digitalWrite(pin02, HIGH);
                delay(100);
                digitalWrite(pin02, LOW);
                delay(100);
            }
        }

    } else {
        flowActive = false;
        digitalWrite(pin02, LOW);
    }
}