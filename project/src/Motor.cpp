#include "../include/Motor.h"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>

Motor::Motor(){
  fd = wiringPiI2CSetup(GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);
  if (fd==-1){
    printf("ERROR: Failed to init i2c communication (Motor_driver).\n");
    break;
  }
  cout<<"i2c communication succesfull (Motor_Driver).\n"<<endl;

}
void balayage(char choice)
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
