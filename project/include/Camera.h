#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera{
private:
  CvCapture* capture;
  IplImage* frame;

public:
  Camera();
  void getPicture();
};

#endif _CAMERA_H_
