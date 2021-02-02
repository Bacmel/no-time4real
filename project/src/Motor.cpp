
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
  speed = 80; // Entre 0 et 255
  cmd = (speed << 8) | (CHANNEL & 0xFF);
 
  if(encoder.getStep()==0){
	  wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense trig
	  sleep(0.5);
  }else if (encoder.getStep()>70){
	  wiringPiI2CWriteReg16(fd,CMD_CW,cmd);//sense anti_trigo
	  sleep(0.5);
  }else if (encoder.getStep()<0){
	  wiringPiI2CWriteReg16(fd,CMD_CCW,cmd);//sense trigo
	  sleep(0.5);
   }
}
