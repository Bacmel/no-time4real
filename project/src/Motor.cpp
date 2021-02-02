
#include "../include/Motor.h" include <unistd.h>
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

//  wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);
  while(1){
    if (encoder.getStep()>=0 && encoder.getStep()<25){
      wiringPiI2CWriteReg16(fd, CMD_CW, cmd);//sense trigo
    }else if (encoder.getStep()>=-25 && encoder.getStep()<0){
      wiringPiI2CWriteReg16(fd, CMD_CCW, cmd);//sense anti-trigo
    }else{
      this->stop();
  }
 }
}
