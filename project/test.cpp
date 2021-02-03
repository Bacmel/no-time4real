#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

#define SERVO1 0;
#define SERVO2 4;

int main(){
	int angle =90;
	if (wiringPiSetup()==-1)
		printf("Error ");
		return -1;
	}
	pinMode(SERVO1,OUTPUT);
	digitalWrite(SERVO1,0);

	int pulse=(angle/18)+2;
	int left=20000-pulse;
	int i=0;
	while(i<35){
		i++;
		digitalWrite(SERVO1,1);
		delayMicroseconds(pulse);
		digitalWrite(SERVO1,0);
		delayMicroseconds(left);
	}
	return 0;
}

