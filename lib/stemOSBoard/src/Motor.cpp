#include "Motor.h"

/**
 * @brief Cria um objeto de Motor
 *
 * @param [in] entrada a porta na qual o motor esta conectado
 * @param [in] reverse define se o motor deve ser invertido ou não
 * @return N/A.
 */
Motor::Motor(int entrada, bool reverse) {
  pinos(entrada);

  if (reverse) {
    ledcSetup(channelA, Motor::FREQUENCY, Motor::RESOLUTION);
    ledcAttachPin(pinPWMA, channelA);

    ledcSetup(channelB, Motor::FREQUENCY, Motor::RESOLUTION);
    ledcAttachPin(pinPWMB, channelB);
  } else {
    ledcSetup(channelA, Motor::FREQUENCY, Motor::RESOLUTION);
    ledcAttachPin(pinPWMA, channelB);

    ledcSetup(channelB, Motor::FREQUENCY, Motor::RESOLUTION);
    ledcAttachPin(pinPWMB, channelA);
  }

  if(Motor::PORTA_1 ^ Motor::PORTA_2) {
   // Encoder encoder(entrada);
    EncoderESP encoderESP(entrada);
  //  this->encoder = encoder;
    this->encoderESP = encoderESP;
  }
}


/**
 * @brief Define as entradas digitais da Arara baseado na porta do motor
 *
 * @param [in] entrada a porta na qual o motor esta conectado
 * @return N/A.
 */
void Motor::pinos(int entrada) {
  switch (entrada) {
    case Motor::PORTA_1:
      pinPWMA = MotorInput.PORTA_1[0]; 
      pinPWMB = MotorInput.PORTA_1[1];
      channelA = 0;
      channelB = 1;
      break;
    case Motor::PORTA_2:
      pinPWMA = MotorInput.PORTA_2[0];
      pinPWMB = MotorInput.PORTA_2[1];
      channelA = 2;
      channelB = 3;
      break;
    case Motor::PORTA_3:
      pinPWMA = MotorInput.PORTA_3[0];
      pinPWMB = MotorInput.PORTA_3[1];
      channelA = 4;
      channelB = 5;
      break;
    case Motor::PORTA_4:
      pinPWMA = MotorInput.PORTA_4[0];
      pinPWMB = MotorInput.PORTA_4[1];
      channelA = 6;
      channelB = 7;
      break;
  }
}


/**
 * @brief Define a velocidade do motor
 *
 * @param [in] power - range de [-1.0, 1.0]
 * @return N/A.
 */
void Motor::setPower(double power) {
  power = max(-1.0, min(1.0, power));
  int output_res = abs(power) * 1023;
  if (power < 0) {
    ledcWrite(channelB, output_res);
  } else if(power > 0){
    ledcWrite(channelA, output_res);
  } else {
    ledcWrite(channelA, 0);
    ledcWrite(channelB, 0);
  }
}
