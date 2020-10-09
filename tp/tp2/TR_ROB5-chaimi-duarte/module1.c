/*
 * Includes
 */
#include <linux/kernel.h>	/* printk() */
#include <linux/module.h>	/* modules */
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/moduleparam.h> /* parameters of module */

static int __init modules1_init(void)
{
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