#include "lidar.hpp"
#include "pantilt.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	Lidar lidar;
	PanTilt pantilt;
	lidar.start();
	while(1)
	{
		sleep(1);
		lidar.update();
		Donnee d = lidar.getDonnee();
		cout << "At : " << d.step << ", Data : " << d.distance <<endl;
		if(d.distance < 10)
		{
			break;
		}
	}
	lidar.stop();
	pantilt.orientation();
	return 0;
}
