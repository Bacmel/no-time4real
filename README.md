# No Time4Real
*Installation steps for **Informatique Temps reel**'s model*

##  SD card Preparation via [rpi-imager](https://howtoraspberrypi.com/create-sd-card-windows-mac-linux-raspberry-pi-imager/)
For Ubuntu:
```
snap install rpi-imager
```
Once installed, launch `rpi-imager`

- Choose the OS to install (**If you have no preference, choose Recommended**) ;
- Choose the SD card (**It must be insert to your computer before**) ;
- Start writing on the card.

## Installation and Configuration
<*In Progress*>

## Use of OpenCV (Camera)
[This link](https://pysource.com/2018/10/31/raspberry-pi-3-and-opencv-3-installation-tutorial/) + python3-opencv + libopencv-dev

## Grove base HAT
[Library](https://github.com/Seeed-Studio/grove.py)

## Related Documentations

- [Infrared Distance Measurement with the Raspberry Pi](https://tutorials-raspberrypi.com/infrared-distance-measurement-with-the-raspberry-pi-sharp-gp2y0a02yk0f/) ;
- [Code Test For Camera](https://stackoverrun.com/fr/q/7383231)
- [Grove Base HAT](https://wiki.seeedstudio.com/Grove_Base_Hat_for_Raspberry_Pi/)


## Problems (?)

- *Grove Base HAT* (**3.3V**) vs *Sharp IR Distance Sensor* + *Servo Moteur* (**5V**) => Seems to be working
- GPIO not good for realtime
