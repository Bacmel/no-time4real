#include "../include/Capteur.hpp"
#include <WiringPiI2C.h>
#include <iostream.h>

Capteur::Capteur(){
	fd = wiringPiI2CSetup(DEVICE_ID);
	if (fd==-1){
		printf("ERROR: Failed to init i2c communication (IR sensor).\n");
		break;
	}
	printf("i2c communication succesfull (IR sensor).\n");
	
}

double Capteur::getDonnees(){
	voltage = wiringPiI2CReadReg16(fd,0x20+CHANNEL)/1000;
	distance = 27.86 *pow(voltage,-1.15);
	return distance;

}
