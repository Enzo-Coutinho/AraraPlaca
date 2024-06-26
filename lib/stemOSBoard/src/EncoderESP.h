#ifndef EncoderESP_h
#define EncoderESP_h
#include "Arduino.h"
#include "ESP32Encoder.h"

/**
* @brief Classe de Encoder.
*
* Classe possibilita a leitura de encoder dos motores.
* 
*/

class EncoderESP {
  public:
    EncoderESP(int entrada); // Construtor da classe encoder
    EncoderESP(void); // Construtor vazio
    double getPosition(); // Obtém a posição do encoder
    void setPosition(int position); // Define a posição do encoder
    void setPositionFactor(double factor); // Define o fator de conversão do encoder
    void update(); // Atualiza o encoder
    ESP32Encoder encoder; // Objeto do encoder da bibilioteca
    static const int PORTA_1_ENCODER = 1;
    static const int PORTA_2_ENCODER = 2;
  private:
    int pinAEncoder; // Encoder pino A
    int pinBEncoder; // Encoder pino B
    double factor = 1; // variável que guarda o valor do fator de conversão
};
#endif