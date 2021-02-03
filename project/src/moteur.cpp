#include "moteur.hpp" 
#include <unistd.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

using namespace std;

Moteur::Moteur()
{
  ccw = true;
  speed = SPEED;
  cmd = (SPEED << 8) | (M_CHANNEL & 0xFF);
  fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
  if (fd==-1)
  {
    cout<<("ERROR: Failed to init i2c communication (Motor_driver).\n")<<endl;
  }
  cout<<"i2c communication succesfull (Motor_Driver).\n"<<endl;
}

void Moteur::start()
{
	wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense trig	
	ccw = true;
}

void Moteur::stop()
{
  wiringPiI2CWriteReg16(fd, CMD_STOP, 0x01);

}
void Moteur::inverse()
{
  if(ccw)
  {
    wiringPiI2CWriteReg16(fd,CMD_CW,cmd);//sense anti_trigo
    ccw = false;
  }
  else
  {
	wiringPiI2CWriteReg16(fd,CMD_CCW,cmd);//sense trigo
	ccw = true;
  }
}

bool Moteur::estTrigo()
{
	return ccw;
}
