#include "../include/Camera.h"

using namespace std;

Camera::Camera(){
  cvNamedWindow("Parisienne", CV_WINDOW_AUTOSIZE);
  capture = cvCreateCameraCapture(0);
}

void Camera::getPicture(){

  if (!capture.isOpen()){
    cout<<"ERROR: Could not open camera"<<endl;
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
