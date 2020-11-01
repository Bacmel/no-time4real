# Real time : Lab2 Driver

## User guide
To compile the drivers you need to type on the terminal the first time :
```
sudo make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
```
To load the drivers in the kernel you need to type : 
```
sudo insmod module1.ko
sudo insmod char.ko 

```
You can also check that they have indeed been loaded by typing :
```
lsmod
```

For the second part of this lab we have three computer programms that we created, you can execute them with this commands:
```
sudo ./utilisateur
sudo ./lire
sudo ./ecrire
```
 ## Module
 This part focuses on driver implemantation and manipulation inside the kernel.
### Question 2.1
As explained above, we need first to compile the driver and then load it in the kernel. Each time we change the code of the driver we need to remove it from the kernel with : 
```
sudo rmmod module1.mod
```
And then we can repeat the processus explained before.
### Question 2.2
To visualize **"Hello World !"** in the kernel logs we need to use `printk()` inside the `static int __init modules1_init(void)` function , `printk()` is a function from the Linux kernel interface that prints messages to the kernel log.
Then we type this command line to visualize it after removing, compiling and uploading it to the kernel.
```
sudo dmesg
or
sudo tail -f /var/log/kern.log
```
### Question 2.3
To show the meta-informations on our driver we need first to add them as macros in module1.c.
```
MODULE_AUTHOR("Hugo et Celia");//Question2.3
MODULE_DESCRIPTION("First Driver");
MODULE_LICENSE("GPL");
```
We can then see the informations by typing in the terminal : 
```
sudo modinfo
```
### Question 2.4
The goal now is to give a parameter while loading the driver, we added a static int parameter and we modified the ```printk()``` to visualize it in the kernel logs. 

```
static int parm = 30 ; 
module_param(parm, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);// For changing the value of parm when loading the kernel
MODULE_PARM_DESC(parm, integer); // show the parameter when using modinfo
printk(KERN_INFO " Hello World ! \n parm=%d\n", parm); // show value in kernel logs
```
To change the value of parm you need to do it while loading the kernel, else parm will be equal to the value given above.
```
sudo insmod module1.ko parm=20
```
## Char device
### Question 2.5
After changing the **Makefile** and loading the driver in the kernel, we can see in **/dev** repository a new file appear **mychar**. This name is given by the constant DEVICE_NAME that appears when using the function `create_device()` in `modules1_init()` class.
If we type the command below we can see two numbers (separated by a comma) in the device file entries before the date of last modification. These numbers are the major device number and minor device number for the particular device.
```
ls -l
```
The major number identifies the driver associated with the device.
The minor number is used only by the driver specified by the major number. It is common for a driver to control several devices, the minor number provides a way for the driver to differentiate among them.
Here the major number is 239 and the minor number is 0. The assignment is made at the driver initialization by calling the following function.
```
register_chrdev(major, "mychar", &char_fops);
```
We can also visualize the major and minor numbers in **/proc/device**.
### Question 2.6
We add now ```printk()``` in ```char_open()```, ```char_close()```, ```char_release()```, ```char_read()```, ```char_write()``` and ```char_ioctl()``` function to understand how they work.
 To read the printk() in ```char_open()``` and```char_release()``` we first need to type the command below. It creates an empty file. If we load the driver again in the kernel we can read the printk() in the kernel logs.
```
sudo touch /dev/mychar
```
 We don't have permissions to write or read on the new file so we need to create a virtual file that points on the same driver and we activate the pemissions.
 We create this file in **/tmp**.
 ```
 sudo mknod -m 666 /tmp/mychar c 239 0
 ```
 We can now write with **echo** and read with **cat**. But those commands creates infinite loops that crashes the raspberry. 
 ### Question 2.7
Now for the ioctl function, we need to create a user file in c. IOCTL is referred to as Input and Output Control, which is used to talking to device drivers. 
For that we need to open the file, use the ioctl function then close the file again.
```
fd = open("/dev/mychar", O_RDWR); 
ioctl(fd, 42,NULL); 
close(fd);
 ```
 We can see the printk() in the kernel logs.
 ### Question 2.8
 Same for the read and write function, we can add them in the code above to visualize the printk in the kernel logs.
 ```
fd = open("/dev/mychar", O_RDWR); 
ioctl(fd, 42,NULL); 
write(fd, buff, strln(buff));
read(fd, buff2, strln(buff2);
close(fd);
 ```
  
