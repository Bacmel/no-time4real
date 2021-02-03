#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP

#include <vector>

#define DEVICE_ID 0x04
#define C_CHANNEL 0
#define MEMORY 27

int filtreMedian(std::vector<int> &vector);

class Capteur{
private:
  int fd;
  
public:
  Capteur();
  double getDistance();//distance
};

#endif
