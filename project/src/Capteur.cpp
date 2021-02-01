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
float Capteur::getDonnees(){
  int raw = wiringPiI2CReadReg16(fd,0x31);
  cout<<"raww="<<raw<<"\n"<<endl;
  float voltage = (float)raw * 0.0048828125;
  cout<<"volt="<<voltage<<"\n"<<endl;

  distance = 27.86 * pow(voltage,-1.15);
  cout<<"distance="<<distance<<"\n"<<endl;

  return distance;

}
