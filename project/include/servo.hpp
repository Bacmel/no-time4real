#ifndef SERVO_HPP
#define SERVO_HPP

class Servo{
private:
  int pin;
  int i;
  int pulse;
  int left;
  int angle;

public:
  Servo(int pin);
  void setPos(int angle);
  int getPos();
};

#endif

