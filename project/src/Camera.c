#include "../include/Camera.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/core/types_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/videoio/videoio_c.h"


Camera::Camera(){
	cvNamedWindow("Parisienne", CV_WINDOW_AUTOSIZE);	
	capture = cvCreateCameraCapture(0);
}

void Camera::getPicture(){
	
	if (!capture.isOpen()){
		printf("ERROR: Could not open camera");
		break;
	}

	while(1) {
		frame = cvQueryFrame(capture);
		cvShowImage("Parisienne", frame);
	
		if (waitKey(10)>=0){
			cvReleaseCapture(&capture);
			cvDestroyWindow( "Test");
		}
	}

}
