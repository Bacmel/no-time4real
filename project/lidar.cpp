#include "include/Motor.h"
#include "include/Capteur.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    Motor moteur;
    Encoder encoder;
    encoder.getStep();
  moteur.stop();
//   moteur.balayage();
//    moteur.stop();
    return 0;
}


