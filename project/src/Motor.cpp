
#include "../include/Motor.h"
#include <unistd.h>
using namespace std;

Motor::Motor(){
  fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
  if (fd==-1){
    cout<<("ERROR: Failed to init i2c communication (Motor_driver).\n")<<endl;

  }
  cout<<"i2c communication succesfull (Motor_Driver).\n"<<endl;

}
void Motor::stop(){
  wiringPiI2CWriteReg16(fd, CMD_STOP, 0x01);

}
int Motor::balayage()
{
  speed = 100; // Entre 0 et 255
  cmd = (speed << 8) | (CHANNEL & 0xFF);


  fd2 = open("/dev/encoder", O_RDWR) ;

  cout<<("\nOpening Driver\n")<<endl;
  if(fd2 < 0) {
    cout<<("ERROR:Cannot open device file...\n")<<endl;
    return -1;
  }

  cout<<("File opened\n")<<endl;
  read(fd2,buff,strlen(buff));

  while(1){
    if (buff[0]=='-' && (int)buff[1]<'2'&& (int)buff[2]<'5'){
      wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense anti-trigo
    }else if  ((int)buff[0]<'2'&& (int)buff[1]<'5'){
      wiringPiI2CWriteReg16(fd, CMD_CW, cmd);//sense trigo
    }

  }

  wiringPiI2CWriteReg16(fd, CMD_STOP, 0x01);
  close(fd2);

}
