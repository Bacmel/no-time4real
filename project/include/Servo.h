
#ifndef SERVO_H
#define SERVO_H

class Servo{
private:
  int pin;
  int min;
  int max;
  int angle;

public:
  Servo(int pin, int min, int max);
  void setPos(int angle);
  void setTrajet(int angle, int delay);
  int getPos();
};

#endif

