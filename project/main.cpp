#include "lidar.hpp"
#include "pantilt.hpp"
#include <iostream>

using namespace std;

int main()
{
	Lidar lidar;
//	PanTilt pantilt;
	lidar.start();
	while(1)
	{
		lidar.update();
		Donnee d = lidar.getDonnee();
		cout << "At : " << d.step << ", Data : " << d.distance <<endl;
		if(d.distance < 6.7)
		{
			break;
		}
	}
	lidar.stop();
//	int step = lidar.getStep()+50;
//	pantilt.orientation(step);
	return 0;
}
