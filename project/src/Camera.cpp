#include "../include/Camera.h"
#include <iostream>
using namespace std;
using namespace cv;

Camera::Camera(){
  cvNamedWindow("Parisienne", CV_WINDOW_AUTOSIZE);
  capture = cvCreateCameraCapture(0);
}

void Camera::getPicture(){


  while(1) {
    frame = cvQueryFrame(capture);
    cvShowImage("Parisienne", frame);

    if (cvWaitKey(10)>=0){
      cvReleaseCapture(&capture);
      cvDestroyWindow( "Test");
    }
  }

}
