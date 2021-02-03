#include "servo.hpp"
#include <wiringPi.h>
#include <math.h>
#include <unistd.h>
#include <cstdio>


Servo::Servo(int pin){
  this->pin = pin;
  if (wiringPiSetup()==-1){
    printf("Error servo not created");
  }
  pinMode(pin,OUTPUT);
  printf("servo created");
}

void Servo::setPos(int angle){

  digitalWrite(pin,0);
  pulse=(angle*(1820/180))+600;
  left=20000-pulse;
  i=0;
  while(i<35){
    i++;
    digitalWrite(pin,1);
    delayMicroseconds(pulse);
    digitalWrite(pin,0);
    delayMicroseconds(left);
  }

}

int Servo::getPos(){
  return this->angle;
}
