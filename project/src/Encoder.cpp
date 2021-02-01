
#include "../include/Encoder.h"
using namespace std;

Encoder::Encoder(){
  fd = open("/dev/encoder", O_RDWR) ;
  if(fd < 0) {
    cout<<("ERROR:Cannot open device file...\n")<<endl;
  }else{
    cout<<("File opened\n")<<endl;
  }

}

long Encoder::getStep()
{
  if (fd==1){
    interrupt =  read(fd,buff,sizeof(long));
    if (interrupt == sizeof(long)){
      step =(long)buff;
      cout<< "pas=" step<<endl;
    }
  }
  return step;

}
void Encoder::closeDeviceFile(){
  close(fd);
}
