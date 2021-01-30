
#include "Grove_Motor_Driver_TB6612FNG.h"

class Moteur{
private:
  MotorDriver driver;
public:
  Moteur();
  void balayage();
  void stop();
};
