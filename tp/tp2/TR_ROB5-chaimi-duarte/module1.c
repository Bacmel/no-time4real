/*
 * Includes
 */
#include <linux/kernel.h>	/* printk() */
#include <linux/module.h>	/* modules */
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/moduleparam.h> /* parameters of module */

#define DRIVER_AUTHOR "Hugo Duarte"
#define DRIVER_DESCRIPTION "Driver for Real-Time TP2"
#define DRIVER_LICENSE "GPL"

static int parm = 42; // Question 2.4

static int __init modules1_init(void)
{
	//printk("Hello World !\n"); // Question 2.2
	printk("Hello World (%d)!\n", parm); // Question 2.4
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

MODULE_AUTHOR(DRIVER_AUTHOR); // Question 2.3
MODULE_DESCRIPTION(DRIVER_DESCRIPTION); // Question 2.3
MODULE_LICENSE(DRIVER_LICENSE); // Question 2.3


module_param(parm, int, 0); // Question 2.4
MODULE_PARM_DESC(parm, "integer to print in dmesg"); // Question 2.4