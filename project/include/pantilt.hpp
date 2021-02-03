#ifndef PANTILT_HPP
#define PANTILT_HPP

#include "servo.hpp"
#include "camera.hpp"

#define PAN 0 // BCM 16
#define TILT 4 // BCM 5

#define MIN1 0
#define MAX1 100

#define MIN2 0
#define MAX2 100

class PanTilt{
private:
  Servo pan;
  Servo tilt;
  Camera camera;

public:
  PanTilt();
  void parisienne();
  void getImage(int degre);
  void orientation(int degre);
};

#endif
