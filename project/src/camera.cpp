#include "camera.hpp"
#include <ctime>
#include <iomanip>

using namespace std;
using namespace cv;

Camera::Camera(){
  camera = VideoCapture(0);
}

void Camera::getPicture(){
	camera >> frame;
	auto t = time(nullptr);
	oss.clear();
    oss << "photo/" << put_time(localtime(&t), "%d-%m-%Y_%H-%M-%S") << ".jpg";
    auto str = oss.str();
	imwrite(str, frame);
}
