
#include "../include/Moteur.hpp"

Moteur::Moteur(){
	driver.init()	
}

void Moteur::balayage(){
	driver.dcMotorRun(MotorDriver::MOTOR_CHB, 200);
}

void Moteur::stop(){	
	driver.dcMotorBrake(MotorDriver::MOTOR_CHB);
}
