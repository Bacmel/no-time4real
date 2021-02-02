

#include "../include/Encoder.h"
using namespace std;

Encoder::Encoder(){
  fd = open("/dev/encoder", O_RDWR) ;
  if(fd < 0) {
    cout<<("ERROR:Cannot open device file...\n")<<endl;
  }

}


long Encoder::getStep()
{
    cout<< "LAAAAAAAAAAAA"<<endl;

  if (fd>0){
    int interrupt =  read(fd,data.res,sizeof(long));
    cout<< "interrupt ="<<interrupt<<endl;
    if (interrupt != sizeof(long)){
	cout<< "Read bytes"<<interrupt<<endl;
    }else{
	 step = data.val;
    cout<< "pas="<<step<<endl;
    }
 }
  return step;
}
void Encoder::closeDeviceFile(){
  close(fd);
}
