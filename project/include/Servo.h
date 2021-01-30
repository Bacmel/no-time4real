
class Servo{
private:
  int pin;
  int min;
  int max;
  int angle;

public:
  Servo(int pin, int min, int max);
  void setPos(int angle);
  int getPos();
};
