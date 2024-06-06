#ifndef Analog_h
#define Analog_h
#include "Arduino.h"


/**
* @brief Classe para sensores analógicos.
*
* Classe que faz o controle da porta analógica da Arara.
* 
*/

enum PortasAnalogicas {
  PORTA_1 = 34,
  PORTA_2 = 35,
  PORTA_3 = 36,
  PORTA_4 = 39,
  PORTA_5 = 17,
};

class Analog {
  public:
    Analog(PortasAnalogicas entrada);  // Construtor da classe analógica
    int getAnalogInput();                             // Obtém uma entrada analógica do sensor acoplado
    void setAnalogOutput(int duty);                   // Define uma saída analógica
    int AnalogPort;         
  private:
};

#endif