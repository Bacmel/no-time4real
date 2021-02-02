

#include "../include/Encoder.h"
using namespace std;

Encoder::Encoder(){
  fd = open("/dev/encoder", O_RDWR) ;
  if(fd < 0) {
    cout<<("ERROR:Cannot open device file...\n")<<endl;
  }

}


int Encoder::getStep()
{

  if (fd>0){
    bytes_read =  read(fd,buff,20);
    cout<< "buff="<< atoi(buff)<<endl;
}
  return atoi(buff);
}
void Encoder::closeDeviceFile(){
  close(fd);
}
