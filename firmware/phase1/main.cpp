int pin02 = 2;
int pin04 = 4;

void setup(){
    pinMode(pin02, OUTPUT);
    pinMode(pin04, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop(){
    int sensorState = digitalRead(pin04);
    if (sensorState == LOW){
        digitalWrite(pin02, HIGH);
        Serial.println("PULSED DETECT");
    }
    else{
        digitalWrite(pin02, LOW);
    }

    delay(100);
}