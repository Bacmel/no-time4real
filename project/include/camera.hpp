#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "opencv2/opencv.hpp"
#include <sstream>

class Camera{
	private:
  		cv::VideoCapture camera;
  		cv::Mat frame;
  		std::ostringstream oss;

	public:
		Camera();
  		void getPicture();
};

#endif
