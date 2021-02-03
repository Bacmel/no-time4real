#include "lidar.hpp"
#include <iostream>

using namespace std;

Lidar::Lidar()
{
}

void Lidar::start()
{
	moteur.start();
}

void Lidar::update()
{
	int step = encodeur.getStep();
	bool ccw = moteur.estTrigo();
	if((ccw && step > RANGE/2) || (!ccw && step < -RANGE/2))
	{
		cout << "Inverse\n";
		moteur.inverse();
	}
}

void Lidar::stop()
{
	moteur.stop();
}

Donnee Lidar::getDonnee()
{
	Donnee d;
	d.distance = infra.getDistance();
	d.step = encodeur.getStep();
	return d;
}
