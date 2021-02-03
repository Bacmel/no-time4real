#ifndef LIDAR_HPP
#define LIDAR_HPP

#include "capteur.hpp"
#include "moteur.hpp"
#include "encodeur.hpp"

#define RANGE 50

typedef struct donnee{
	double distance;
	int step;
} Donnee;

class Lidar
{
	private:
	    Capteur infra;
    	Moteur moteur;
    	Encodeur encodeur;
    			
    public:
    	Lidar();
    	void start();
		void update();
    	void stop();
    	Donnee getDonnee();
};

#endif
