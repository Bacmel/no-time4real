#include "capteur.hpp"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int filtreMedian(vector<int> &vector)
{
	int raw = 0;
	sort(vector.begin(), vector.end());
	size_t s = vector.size();
	if(s%2==0)
	{
		raw = vector.at((s-1)/2);
	}
	else
	{
		raw = vector.at(s/2);
	}
	return raw;
}

Capteur::Capteur()
{
  fd = wiringPiI2CSetup(DEVICE_ID);
  if (fd==-1)
  {
    cout<<("ERROR: Failed to init i2c communication (IR sensor).\n")<<endl;
  }
  else
  {
    cout<<"i2c communication succesfull (IR sensor).\n"<<endl;
  }
}

double Capteur::getDistance()
{
  /* Partie Filtrage */
  vector<int> memory = vector<int>();
  for(size_t i=0; i<MEMORY; i++)
  {
  	memory.push_back(wiringPiI2CReadReg16(fd,0x31));
  }
  int raw = filtreMedian(memory);

  /* Partie Conversion */ 
  double voltage = (float)raw * 0.0048828125;
  double distance = 27.86 * pow(voltage,-1.15);
  distance = round(distance*10)/10;

  return distance;
}
