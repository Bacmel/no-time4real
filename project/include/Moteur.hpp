#ifndf MOTEUR_HPP
#define MOTEUR_HPP

#define DEVICE_ID 0x04;
#define CHANNEL 1;

class Moteur{

public:
  Moteur();
  void balayage();
  void stop();
};


#endif // MOTEUR_HPP
