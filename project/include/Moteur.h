#ifndef _MOTEUR_H_
#define _MOTEUR_H_

#include "Grove_Motor_Driver_TB6612FNG.h"

class Moteur{
private:
  MotorDriver driver;
public:
  Moteur();
  void balayage();
  void stop();
};
#endif _MOTEUR_H_

