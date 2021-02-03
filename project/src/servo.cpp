#include "servo.hpp"
#include <wiringPi.h>
#include <softPwm.h>
#include <math.h>
#include <unistd.h>
#include <cstdio>


Servo::Servo(int pin){
  this->pin = pin;
  if (wiringPiSetup()==-1){
    printf("Error servo not created");
  }
  softPwmCreate
  pinMode(pin,OUTPUT);
  printf("servo created");
}

void Servo::setPos(int angle){
  pulse = (angle*(1820/180))+600 
  if (angle > max){
    this->angle = max;

  }else if(angle < min) {
    this->angle = min;

  }else{
    this->angle = angle;

  }
  digitalWrite(this->pin, this->angle);

}

void Servo::setTrajet(int angle, int delay){
  float dt = delay/abs(angle - this->angle);
  for(int i = this->angle; i<=angle; i++){
    softPwmWrite(this->pin, i);
    sleep(dt);
  }

}
int Servo::getPos(){
  return this->angle;
}
