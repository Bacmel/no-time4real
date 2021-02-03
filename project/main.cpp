#include "lidar.hpp"
#include <iostream>

using namespace std;

int main()
{
	Lidar lidar;
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
	return 0;
}
