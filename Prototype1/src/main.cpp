#include "Arduino.h"

const uint8_t Relay1 = 9;
const uint8_t Relay2 = 10;
const uint8_t Relay3 = 8;
const uint8_t Relay4 = 7;

void InitialState(){
    digitalWrite(Relay1, HIGH);
    digitalWrite(Relay2, HIGH);
    digitalWrite(Relay3, HIGH);
    digitalWrite(Relay4, HIGH);
}

void toggle(const uint8_t &GPIO_PIN, int time){
    digitalWrite(GPIO_PIN, LOW);
    delay(time);
    digitalWrite(GPIO_PIN, HIGH);
    delay(time);
}

void setup() {
    pinMode(Relay1, OUTPUT);
    pinMode(Relay2, OUTPUT);
    pinMode(Relay3, OUTPUT);
    pinMode(Relay4, OUTPUT);
    InitialState();

}

void loop() {
    toggle(Relay1, 1000);
    toggle(Relay2, 1000);
    toggle(Relay3, 1000);
    toggle(Relay4, 1000);
}
