#ifndef ENCODER_H
#define ENCODER_H

#include <math.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>



class Encoder{
private:
    char buff[20];
    ssize_t bytes_read;
    int fd;
   
public:
    Encoder();
    int getStep();
    void closeDeviceFile();
};
#endif
