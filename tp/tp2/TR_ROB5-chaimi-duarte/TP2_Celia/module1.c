 /*
 * Includes
 */
#include <linux/kernel.h>	/* printk() */
#include <linux/module.h>	/* modules */
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/moduleparam.h> /* parameters of module */

MODULE_AUTHOR("Hugo et Celia");//Question2.3
MODULE_DESCRIPTION("First Driver");
MODULE_LICENSE("GPL");

static int parm = 30;// Question 2.4
module_param(parm, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // pour changer parm  quand on charge le driver
MODULE_PARM_DESC(parm, "An integer"); // Pour regarder dans modinfo

static int __init modules1_init(void)
{
 	//printk("Hello world ! \n"); //Question2.2
	printk(KERN_INFO "param = %d\n", parm);
	return 0;
}

static void __exit modules1_exit(void)
{
}

/*
 * Module entry points
 */
module_init(modules1_init);
module_exit(modules1_exit);
