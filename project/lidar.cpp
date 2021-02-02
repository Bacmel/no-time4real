#include "include/Motor.h"
#include "include/Capteur.h"
#include <iostream>
#include <unistd.h>
#include <chrono>

using namespace std;

int main(){
    Capteur infra;
    Motor moteur;
    Encoder encoder;
    encoder.getStep();
// moteur.stop();
   while(infra.getDonnees()>15){
     moteur.balayage();
   }

    moteur.stop();
    return 0;
}


