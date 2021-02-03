#include "pantilt.hpp"
#include <wiringPi.h>
#include <softPwm.h>
#include <math.h>
#include <unistd.h>

PanTilt::PanTilt(): pan(PAN, MIN1, MAX1), tilt(TILT, MIN2, MAX2)
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
	pan.setPos(degre);
}
