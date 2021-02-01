#include "../include/Servo.h"
#include <wiringPi.h>
#include <softPwm.h>


Servo::Servo(int pin, int min, int max){
  this->pin = pin;
  this->min = min;
  this->max = max;
  wiringPiSetup();
  softPwmCreate(pin, min, max);
}

void Servo::setPos(int angle){
  if (angle > max){
    this->angle = max;

  }else if(angle < min) {
    this->angle = min;

  }else{
    this->angle = angle;

  }
  softPwmWrite(this->pin, this->angle);

}

void Servo::setTrajet(int angle, int delay){
  float dt = delay/abs(angle - this->angle);
  for(int i = this->angle; i<=angle; i++){
    softPwmWrite(this->pin, i);
    delay(dt);
  }

}
int Servo::getPos(){
  return this->angle;
}
