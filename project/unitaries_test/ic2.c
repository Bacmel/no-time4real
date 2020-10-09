#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

#define IR 0x004 // A0

int main(void) {
	//init
    wiringPiI2CSetup(IR);
    int reg;
	while(1) { //loop
        wiringPiI2CReadReg16(IR, reg);
		printf("%d\n", reg);
	}
	return 0;
}
