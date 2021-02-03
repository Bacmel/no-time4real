#include "pantilt.hpp"
#include <wiringPi.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
using namespace std;

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
  degre += 90;
  if (degre>180)
  {
  	degre = 180;	
  }
  else if(degre<0)
  {
    degre = 0;
  }
  pan.setPos(degre);
}
