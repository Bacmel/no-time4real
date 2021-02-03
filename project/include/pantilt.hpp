#ifndef PANTILT_HPP
#define PANTILT_HPP

#include "servo.hpp"
#include "camera.hpp"
#include "lidar.hpp"

#define PAN 0 // BCM 16
#define TILT 4 // BCM 5

class PanTilt{
private:
  Servo pan;
  Servo tilt;
  Lidar lidar;
  Donnee d;
  int degre;

public:
  PanTilt();
  void parisienne();
  void getImage(int degre);
  void orientation();
};

#endif
