#ifndef CAPTEUR_H
#define CAPTEUR_H

#define DEVICE_ID 0x04
#define CHANNEL 0

class Capteur{
private:
  int fd;
  float voltage;
  float distance;

public:
  Capteur();
  float getDonnees();//distance
};

#endif 
