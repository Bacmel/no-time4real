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
