#ifndef CAMERA_HPP
#define CAMERA_HPP

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

#endif
