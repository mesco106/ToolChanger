#include "Arduino.h"

using Pin = uint8_t;




class LinearActuators{
    public:
        LinearActuators(Pin relay1, Pin relay2, Pin relay3, Pin relay4){
            m_relay1 = relay1;
            m_relay2 = relay2;
            m_relay3 = relay3;
            m_relay4 = relay4;

            setup();
            off();
        }

        void CounterClockwiseTurn(float executionTime){
            m_currentTimer = millis();
            m_executionTime = executionTime*1000.;
            if (enable == true){
                m_timerCapture = m_currentTimer;
                enable = false;
                Serial.println("layer2");
            }
            if (m_currentTimer <= m_timerCapture + executionTime){
                on(Left);
                Serial.print(m_currentTimer);
                Serial.print(" <= ");
                Serial.print(m_timerCapture);
                Serial.print(" + ");          
                Serial.println(m_executionTime);
            }else{
                Serial.println("layer1");
                off();
                enable = true;
                m_timerCapture = 0;
            }
    
        }

        // void ClockwiseTurn(float executionTime){ 
        //     m_timer = millis();
        //     m_executionTime = executionTime*1000.;

        //     if((m_executionTime - m_previousCapture) >= 0){
        //         on(Right);
        //         m_previousCapture = m_timer;
        //     }else{off();}
        // } 
        
    private:
        void off(){
            digitalWrite(m_relay1, LOW);
            digitalWrite(m_relay2, LOW);
            digitalWrite(m_relay3, LOW);
            digitalWrite(m_relay4, LOW);
        }

        void on(bool Direction){
            if (Direction == Right) {
                digitalWrite(m_relay1, LOW);
                digitalWrite(m_relay2, LOW);
                digitalWrite(m_relay3, HIGH);
                digitalWrite(m_relay4, HIGH);
            } else {
                digitalWrite(m_relay1, HIGH);
                digitalWrite(m_relay2, HIGH);
                digitalWrite(m_relay3, LOW);
                digitalWrite(m_relay4, LOW);
            }
        }

        void setup(){
            pinMode(m_relay1, OUTPUT);
            pinMode(m_relay2, OUTPUT);
            pinMode(m_relay3, OUTPUT);
            pinMode(m_relay4, OUTPUT);  
        }
        
        Pin m_relay1;
        Pin m_relay2;
        Pin m_relay3;
        Pin m_relay4;
        bool Right = 1;
        bool Left = 0;
        bool enable;
        float m_executionTime;
        unsigned long m_currentTimer = 0;
        static unsigned long m_timerCapture = 0;
};

class RotaryEncoder{
    public:
        RotaryEncoder(Pin inputPulse){
            m_inputPulse = inputPulse;
            pinMode(m_inputPulse, INPUT);
        }

        long Position(Pin m_inputPulse){
            m_position = pulseIn(m_inputPulse, HIGH);
            return m_position;
        }

    private:
        Pin m_inputPulse;
        uint16_t m_position;
};

class PIDController{
    public:

    private:
    long m_input;
    long m_output;
    float m_Kp;
    float m_Ki;
};

void setup(){
    Serial.begin(115200);
    LinearActuators linearActuators(10, 9, 8, 7);

    while(1){
        linearActuators.CounterClockwiseTurn(30);
    }
}

void loop(){}
