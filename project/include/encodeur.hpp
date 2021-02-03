#ifndef ENCODEUR_HPP
#define ENCODEUR_HPP

#define SIZE 20

class Encodeur{
private:
    char buff[SIZE];
    int fd;
   
public:
    Encodeur();
    int getStep();
    void closeDeviceFile();
};
#endif
