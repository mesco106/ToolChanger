#include "Arduino.h"

class Setup {
    public:
        const uint8_t Relay1 = 9;
        const uint8_t Relay2 = 10;
        const uint8_t Relay3 = 8;
        const uint8_t Relay4 = 7;

        void Initialize(){
            pinMode(Relay1, OUTPUT);
            pinMode(Relay2, OUTPUT);
            pinMode(Relay3, OUTPUT);
            pinMode(Relay4, OUTPUT);

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
};
class HardwareControl{
    
};


void setup() {
    Setup OffRiser;
    OffRiser.Initialize();

    while (1)
    {
        
    }
}

void loop() {}