#include "Analog.h"

/**
 * @brief Cria um objeto da porta analógica
 *
 * @param [in] entrada - define a porta do sensor analógico
 * @return N/A.
 */
Analog::Analog(PortasAnalogicas entrada) {
 AnalogPort = entrada;
}


/**
 * @brief Retorna o valor lido pela entrada analógica
 *
 * @param [void]
 * @return int.
 */
int Analog::getAnalogInput() {
  return analogRead(AnalogPort);
}

/**
 * @brief Define uma saída analógica
 *
 * @param [in] duty - valor da saída [0, 1023]
 * @return N/A.
 */
void Analog::setAnalogOutput(int duty) {
  analogWrite(AnalogPort, duty);
}