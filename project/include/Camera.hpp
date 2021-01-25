#ifndf CAMERA_HPP
#define CAMERA_HPP

class Camera{
private:
  CvCapture* capture;
  IplImage* frame;

public:
  Camera();
  void getPicture();
};


#endif // CAMERA_HPP
