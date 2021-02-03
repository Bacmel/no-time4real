#ifndef PANTILT_HPP
#define PANTILT_HPP

#include "servo.hpp"
#include "camera.hpp"

#define PAN 0 // BCM 16
#define TILT 4 // BCM 5

class PanTilt{
private:
  Servo pan;
  Servo tilt;
  int degre;

public:
  PanTilt();
  void parisienne();
  void getImage(int degre);
  void orientation(int degre);
};

#endif
