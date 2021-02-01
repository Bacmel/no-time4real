#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/sched.h>
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/slab.h>

MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "Pilote pour récupération Interruptions sur Raspberry Pi" );


#define N_DEVICES 1

// Numéros des pins utilisés :
#define IRQ_PIN_1 18//18
#define IRQ_PIN_2 19 //19

// Définition des macros pour l'utilisation directe des GPIO de la Raspberry Pi :
#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))
#define OUT_GPIO(g) 
#define GET_GPIO(g) (*(gpio+13)&(1<<g)) 
#define GPIO_PULL *(gpio+37) // Pull up/pull down
#define GPIO_PULLCLK0 *(gpio+38) // Pull up/pull down clock


#define DEVICE_NAME "encoder" ///< The device will appear at /dev/encoder using this value
#define CLASS_NAME "encoder" ///< The device class -- this is a character device driv


// Adresse de base pour les registres correspondant aux GPIO de la Raspberry Pi :
static volatile unsigned* gpio;



static int major;
static struct class* encoder_class = NULL; ///< The device-driver class struct pointer
static struct device* encoder_device = NULL; ///< The device-driver device struct pointer


// Les variables globales et les fonctions sont déclarées statiques afin qu'elles ne soient visibles
// que dans le code de ce fichier. On évite ainsi toute ambiguïté avec autres variables du noyau
// qui partage le même segment de mémoire.

// Valeur correspondant à la position du codeur :
static long encoder_count[N_DEVICES];

// Déclaration des numéros de pins comme paramètres du module :
static int irq_pin_1 = IRQ_PIN_1;
static int irq_pin_2 = IRQ_PIN_2;
module_param( irq_pin_1, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
module_param( irq_pin_2, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );


// Structure utilisée pour traiter les interruptions :
typedef struct encoder_data {
	char* label;
	int irq_pin;
	long* count;
	unsigned int irq;
} encoder_data;

// Déclaration des structures de données utilisées pour traiter les interruptions :
static encoder_data data_1;



//-------------------------------------
// Fonctions gérant les interruptions :
//-------------------------------------

// Fonction appelée à chaque interruption :
static irqreturn_t encoder_irq_handler( int irq, void* dev_id )
{
	// Interprétation du pointeur vers les données de l'interruption :
	encoder_data* data = (encoder_data*) dev_id;

	// TODO : Incrémentation du codeur.
	INP_GPIO(IRQ_PIN_2); // pin en in 
	int res = GET_GPIO( IRQ_PIN_2); //retourne ( 1 << numéro_du_pin ) si le pin est à 5V, 0 s'il est à 0V.
    printk("data = %d",res);
    if (res > 0){
		(*(data->count))++;
	}
	else {
		(*(data->count))--;
	}
	printk("irq_rcvd count = %ld \n",*(data->count));
	return IRQ_HANDLED;
}


// Fonction pour allouer les pins :
static void setup_irq_pin( encoder_data* data )
{
	// Initialisations propre à la Raspberry Pi :
	INP_GPIO( data->irq_pin );
	SET_GPIO_ALT( data->irq_pin, 0 );

	// Allocation de l'interruption :
	gpio_request_one( data->irq_pin, GPIOF_IN, data->label ); // Réservation système en input

	data->irq = gpio_to_irq( data->irq_pin ); // Recherche du numéro d'interruption à partir du numéro de pin

	if ( request_any_context_irq(
		data->irq,
		encoder_irq_handler,
		IRQF_TRIGGER_RISING,
		THIS_MODULE->name,
		data
	) >= 0 )
		printk( KERN_INFO "%s: interruption \"%s\" allocated on line %u\n", THIS_MODULE->name, data->label, data->irq );
}

// Fonction pour libérer les pins :
static void free_encoder_pins( encoder_data* data )
{
	free_irq( data->irq, data );
	gpio_free( data->irq_pin );

}

//-------------------------------------
//    Device management functions     :
//-------------------------------------
typedef union Buffer_int
{
	long count;
	char count_byte[sizeof(long)];
} Buffer_int;



static int encoder_open(struct inode* inode, struct file* file) { return 0; }

static int encoder_release(struct inode* inode, struct file* file) { return 0; }

static ssize_t encoder_read(struct file* file, char* buf, size_t count, loff_t* ppos)
{
   
    int res;
	Buffer_int buf_noy;
	buf_noy.count = encoder_count[0];

    // Ensure the reader wants the full long value
    if (count < sizeof(long)) { return 0; }
    // Convert the long value to an array of bytes
    // Transmit that array to the user
    res = raw_copy_to_user(buf, buf_noy.count_byte, sizeof(long));
    if (res < 0)
    {
        printk(KERN_ALERT "Failed to copy to user");
        return 0;
    }
    return sizeof(long);
}

static ssize_t encoder_write(struct file* file, const char* buf, size_t count, loff_t* ppos) { return 0; }

//-----------------------------
// Fonctions gérant le module :
//-----------------------------
static struct file_operations encoder_fops = {
	.owner =	THIS_MODULE,
	.read =		encoder_read,
	.write =	encoder_write,
	.open =		encoder_open,
	.release =	encoder_release,
};
// Fonction appelée au chargement du module :
int init_module( void )
{
	void* gpio_map;
	int i;
	
	// Register the device
	major = register_chrdev(major,"encoder", &encoder_fops);

	if (major<0)
	{
		printk(KERN_ALERT "failed to register the device \n");
		return major;
	}
	  // Register the device class
	    encoder_class = class_create(THIS_MODULE, CLASS_NAME);
	    if (IS_ERR(encoder_class))
	    { // Check for error and clean up if there is
		unregister_chrdev(major, DEVICE_NAME);
		printk(KERN_ALERT "Failed to register device class\n");
		return PTR_ERR(encoder_class); // Correct way to return an error on a pointer
	    }

	
		   // Create the device
	    encoder_device = device_create(encoder_class, NULL, MKDEV(major, 0), NULL, DEVICE_NAME);
	    if (IS_ERR(encoder_device))
	    { // Clean up if there is an error
		class_destroy(encoder_class); // Repeated code but the alternative is goto statements
		unregister_chrdev(major, DEVICE_NAME);
		printk(KERN_ALERT "Failed to create the device\n");
		return PTR_ERR(encoder_device);
	    }
	
	// Translation des adresses pour l'utilisation directe des GPIO de la Raspberry Pi :
	gpio_map = ioremap( 0x3F200000, SZ_16K );
	if ( gpio_map == NULL )
	{
		printk( KERN_ALERT "%s: ioremap failed !\n", THIS_MODULE->name );
		return -EBUSY;
	}
	gpio = (volatile unsigned*) gpio_map;

	// Remplissage des structures de données utilisées pour traiter les interruptions :
	data_1.label = "irq 1";
	data_1.irq_pin = irq_pin_1;
	encoder_count[0] = 0; 
	data_1.count = &encoder_count[0];
	printk("adresse data_1 = %ld, adresse encodeur = %ld\n",*(data_1.count),encoder_count[0]);

	// Allocation des pins :
	
	setup_irq_pin( &data_1 );
	INP_GPIO(IRQ_PIN_2);
	SET_GPIO_ALT(IRQ_PIN_2,0);

	// enable pull-up on GPIO16&17
    GPIO_PULL = 2;
	for (i=0; i<150;i++);
	
    // clock on GPIO 22 & 23 (bit 24 & 25 set)
    GPIO_PULLCLK0 = (1 << IRQ_PIN_1) | (1 << IRQ_PIN_2);

	return 0;
}

// Fonction appelée au retrait du module :
void cleanup_module( void )
{
	device_destroy(encoder_class, MKDEV(major, 0)); // Remove the device
   	class_unregister(encoder_class); // Unregister the device class
   	class_destroy(encoder_class); // Remove the device class
    	unregister_chrdev(major, "encoder"); // Unregister the device

	encoder_count[0] = 0; 
	data_1.count = &encoder_count[0];

	// Libération des pins :
	free_encoder_pins( &data_1 );

	// Deactive the pull up
	GPIO_PULL = 0;
   	GPIO_PULLCLK0 = 0;

	printk( KERN_INFO "%s: module removed\n", THIS_MODULE->name );
}
