#include "Arduino.h"
#include "Vector.h"

class Setup {
    public:
        const uint8_t Relay1 = 9;
        const uint8_t Relay2 = 10;
        const uint8_t Relay3 = 8;
        const uint8_t Relay4 = 7;
        const uint8_t EncoderPort = 5;

        void Initialize(){
            Serial.begin(115200);

            pinMode(Relay1, OUTPUT);
            pinMode(Relay2, OUTPUT);
            pinMode(Relay3, OUTPUT);
            pinMode(Relay4, OUTPUT);
            pinMode(EncoderPort, INPUT);

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
    public:
    
        uint16_t Position = 0;
        unsigned long timer = micros();
        unsigned long DeltaTime = 0;
        unsigned long previousTime = 0;

        uint16_t EncoderPosition(const uint8_t &GPIO_ATTACHED_TO_ENCODER){
            Position = pulseIn(GPIO_ATTACHED_TO_ENCODER, HIGH); 
            return Position;
        }

        void TurnRight(){
            digitalWrite(Setup->Relay1, HIGH);
            digitalWrite(Relay2, HIGH);
            digitalWrite(Relay3, HIGH);
            digitalWrite(Relay4, HIGH);
        }

        void TurnShaft(bool Direction){
            //if (Direction == True)

        }
        void delay(uint64_t time){

        }

    


};

void setup() {
    Setup OffRiser;
    HardwareControl Encoder;
    OffRiser.Initialize();
    while (1)
    {   
        Serial.println(Encoder.EncoderPosition(OffRiser.EncoderPort));
    }
}

void loop() {}