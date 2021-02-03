#include "pantilt.hpp"
#include <wiringPi.h>
#include <math.h>
#include <unistd.h>

PanTilt::PanTilt(): pan(PAN), tilt(TILT)
{
}

void PanTilt::parisienne()
{
	//TODO
	// Traitement Image
}

void PanTilt::getImage(int degre)
{
	//TODO
	//Photo
}

void PanTilt::orientation(int degre)
{
  if (degre>180 || angle<0){
    degre = 0;
  }
  pan.setPos(degre);
}
