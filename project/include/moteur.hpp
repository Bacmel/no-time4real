#ifndef MOTOR_HPP
#define MOTOR_HPP

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define CMD_BRAKE            0x00
#define CMD_STOP             0x01
#define CMD_CW               0x02  // commande tourner dans le trigo
#define CMD_CCW              0x03  // anti-horaire / anti-trigo
#define M_CHANNEL 1
#define SPEED 80

class Moteur{
private:
    int fd;	
    int speed;
    int cmd;
    bool ccw;
public:
    Moteur();
    void start();
    void stop();
    void inverse();
    bool estTrigo();
};
#endif
