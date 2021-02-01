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
#include <unistd.h>
using namespace std; 


#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define CMD_BRAKE            0x01
#define CMD_STOP             0x00
#define CMD_CW               0x02  // commande tourner dans le trigo
#define CMD_CCW              0x03  // anti-horaire / anti-trigo
#define CMD_SET_ADDR         0x11
#define CHANNEL 1



int main(){

  int fd;
  int fd2;
  int speed;
  int cmd;
  char buff[10];//buffer pour lire
  fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
  if (fd==-1){
    cout<<("ERROR: Failed to init i2c communication (Motor_driver).\n")<<endl;

  }
  cout<<"i2c communication succesfull (Motor_Driver).\n"<<endl;

  speed = 110; // Entre 0 et 255
  cmd = (speed << 8) | (CHANNEL & 0xFF);
//  wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense anti-trigo
//  sleep(8);
  wiringPiI2CWriteReg16(fd, CMD_STOP, 0x01);
  fd2 = open("/dev/encoder", O_RDWR) ;
  cout<<("\nOpening Driver\n")<<endl;
  if(fd2 < 0) {
    cout<<("ERROR:Cannot open device file...\n")<<endl;
    return -1;
  }

  read(fd,buff,strlen(buff));
  while(1){
    if (buff[0]=='-' && (int)buff[1]<'2'&& (int)buff[2]<'5'){
      wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense anti-trigo
    }else if  ((int)buff[0]<'2'&& (int)buff[1]<'5'){
      wiringPiI2CWriteReg16(fd, CMD_CW, cmd);//sense trigo
    }

  }
  wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
  close(fd2);
  return 0;

}



