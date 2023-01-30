#include "Arduino.h"

using Pin = uint8_t;

class RelayStripSetup{
    public:
        RelayStripSetup(Pin relay1, Pin relay2, Pin relay3, Pin relay4){
            m_relay1 = relay1;
            m_relay2 = relay2;
            m_relay3 = relay3;
            m_relay4 = relay4;
            pinMode(m_relay1, OUTPUT);
            pinMode(m_relay2, OUTPUT);
            pinMode(m_relay3, OUTPUT);
            pinMode(m_relay4, OUTPUT);
        }

    private:
        Pin m_relay1;
        Pin m_relay2;
        Pin m_relay3;
        Pin m_relay4;
};

class LinearActuators{
    public:
        //NOTE: Ask boss if I can set the member variable ousite the classic declaration.
        void CounterClockwiseTurn(RelayStripSetup relayStripSetup, long executionTime){
            m_executionTime = executionTime;
            m_relayStripSetup = relayStripSetup;
            digitalWrite(m_relayStripSetup.m_relay1, HIGH);
        }
        


    private:
    long m_executionTime;
    RelayStripSetup m_relayStripSetup;
};

void setup(){
    RelayStripSetup(1,2,3,4);
    LinearActuators Actuators();

    Actuators.CounterClockwiseTurn()

}

void loop(){}
