#include "../include/Capteur.h"
#include <wiringPiI2C.h>
#include <math.h>
#include <wiringPi.h>
#include <iostream>
using namespace std;

Capteur::Capteur(){
  fd = wiringPiI2CSetup(DEVICE_ID);
  if (fd==-1){
    cout<<("ERROR: Failed to init i2c communication (IR sensor).\n")<<endl;
  }else{
    cout<<"i2c communication succesfull (IR sensor).\n"<<endl;
  }
}
double Capteur::getDonnees(){
  voltage = wiringPiI2CReadReg16(fd,0x20+CHANNEL)/1000;
  distance = 27.86 *pow(voltage,-1.15);
  return distance;

}
