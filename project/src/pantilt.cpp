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
	inclinaison(UP);
	camera.getPicture();
	inclinaison(DOWN);
	camera.getPicture();
	inclinaison(UP);
	camera.getPicture();
	inclinaison((DOWN+UP)/2);
}

void PanTilt::getImage()
{
	camera.getPicture();
}

void PanTilt::inclinaison(int degre)
{
	tilt.setPos(degre);
}

void PanTilt::orientation(int degre)
{
  degre += 90;
  pan.setPos(degre);
}
