#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

#define devId 0x04

int main(void) {
	//init
    int fd =  wiringPiI2CSetup(devId);
    int reg = 0x01;
	while(1) { //loop
		printf("%d\n", wiringPiI2CReadReg16(fd, reg));
	}
	return 0;
}
