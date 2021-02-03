#include "encodeur.hpp"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

using namespace std;

Encodeur::Encodeur()
{
  fd = open("/dev/encoder", O_RDWR) ;
  if(fd < 0) {
    printf("ERROR:Cannot open device file...\n");
  }
}

int Encodeur::getStep()
{
  if (fd>0){
    read(fd,buff,SIZE);
}
  return atoi(buff);
}

void Encodeur::closeDeviceFile(){
  close(fd);
}
