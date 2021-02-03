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

void PanTilt::orientation()
{
  d= lidar.getDonnee();
  degre = d.angle + 90;
  cout<<"angle donnees a la camera pan ="<<degre<<endl;  
  if (degre>180 || degre<0){
    degre = 0;
  }
  pan.setPos(degre);
}
