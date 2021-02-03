#ifndef PANTILT_HPP
#define PANTILT_HPP

#include "servo.hpp"
#include "camera.hpp"

#define PAN 0 // BCM 16
#define TILT 4 // BCM 5
#define UP 35
#define DOWN 75


class PanTilt{
private:
  Camera camera;
  Servo pan;
  Servo tilt;

public:
  PanTilt();
  void parisienne();
  void getImage();
  void inclinaison(int degre);
  void orientation(int degre);
};

#endif
