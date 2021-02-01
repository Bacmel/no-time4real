#ifndef MOTOR_H
#define MOTOR_H

#include <WiringPiI2C.h>
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

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define CMD_BRAKE            0x00
#define CMD_STOP             0x01
#define CMD_CW               0x02  // commande tourner dans le trigo
#define CMD_CCW              0x03  // anti-horaire / anti-trigo
#define CMD_SET_ADDR         0x11
#define CHANNEL 1

class Motor{
private:
    int fd;
	int fd2;	
    int speed;
    int cmd;
	char buff[10];//buffer pour lire
public:
    Motor();
    int balayage();
};
#endif
