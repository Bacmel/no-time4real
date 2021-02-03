#ifndef ENCODEUR_HPP
#define ENCODEUR_HPP

#define SIZE 20

class Encodeur{
private:
    char buff[SIZE];
    int fd;
    int pas;
    int angle;
   
public:
    Encodeur();
    int getStep();
    int getAngle();
    void closeDeviceFile();
};
#endif
