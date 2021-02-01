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
    int fd;	
    char buff[sizeof(long)];
    long step;
    int interrupt;

public:
    Encoder();
    long getStep();
    void closeDeviceFile();
};
#endif
