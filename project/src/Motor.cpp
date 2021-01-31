
#include "../include/Motor.h"
#include <wiringPi.h>
using namespace std;

Motor::Motor(){
  fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
  if (fd==-1){
    cout<<("ERROR: Failed to init i2c communication (Motor_driver).\n")<<endl;

  }
  cout<<"i2c communication succesfull (Motor_Driver).\n"<<endl;

}
void Motor::balayage(char choice)
{

    speed = 100; // Entre 0 et 255
    cmd = (speed << 8) | (CHANNEL & 0xFF);



        switch(choice){
        case 'r':
            wiringPiI2CWriteReg16(fd, CMD_CW, cmd);
            break;
        case 'l':
            wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
            break;
        case 'b':
            wiringPiI2CWriteReg16(fd, CMD_BRAKE, 0x00);
            break;
        case 's':
            wiringPiI2CWriteReg16(fd, CMD_STOP, 0x00);
            break;
        }

}
