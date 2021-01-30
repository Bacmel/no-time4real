
class Camera{
private:
  CvCapture* capture;
  IplImage* frame;

public:
  Camera();
  void getPicture();
};

