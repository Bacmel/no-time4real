#ifndef SERVO_HPP
#define SERVO_HPP

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
