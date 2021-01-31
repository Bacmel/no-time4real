#ifndef CAMERA_H
#define CAMERA_H
#include "opencv2/core/core_c.h"
#include "opencv2/core/types_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/videoio/videoio_c.h"

class Camera{
private:
  CvCapture* capture;
  IplImage* frame;

public:
  Camera();
  void getPicture();
};

#endif CAMERA_H
