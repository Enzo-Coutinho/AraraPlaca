#ifndef AraraConfig_h
#define AraraConfig_h
#include "RGBLED.h"
#include "Arduino.h"

struct {
    const int PORTA_1[2] = {4, 13};
    const int PORTA_2[2] = {18, 19};
    const int PORTA_3[2] = {23, 25};
    const int PORTA_4[2] = {32, 33};
    
} MotorInput;

struct {
    const int PORTA_1 = 2;
    const int PORTA_2 = 26;
    const int PORTA_3 = 27;
} ServoInput;

struct {
    const int PORTAS_TOTAIS[11] = {MotorInput.PORTA_1[0], MotorInput.PORTA_1[1],
                      MotorInput.PORTA_2[0], MotorInput.PORTA_2[1],
                      MotorInput.PORTA_3[0], MotorInput.PORTA_3[1],
                      MotorInput.PORTA_4[0], MotorInput.PORTA_4[1],
                      ServoInput.PORTA_1, ServoInput.PORTA_2, 
                      ServoInput.PORTA_3};

    const int QuantPortas = sizeof(PORTAS_TOTAIS) / sizeof(int);

} Portas;

class AraraConfig {
    private:
        void __real_esp_panic_handler(void*);
        void __wrap_esp_panic_handler(void* info);
    public:
};

#endif