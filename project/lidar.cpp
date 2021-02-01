#include "include/Motor.h"
#include "include/Capteur.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
	Capteur infra;
    while(1){
      cout<<"distance = "<<infra.getDonnees()<<"\n"<<endl;
      sleep(10);
    }
    return 0;
}


