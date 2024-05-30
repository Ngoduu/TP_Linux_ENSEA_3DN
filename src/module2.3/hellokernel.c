#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define DRIVER_AUTHOR "Tenzin"
#define DRIVER_DESC "Exemple"
#define DRIVER_LICENSE "GPL"
#define DRIVER_SUPPORT "Presque tous"
#define PROC_NAME "helloproc"

int hello_init(void)
{
	printk(KERN_INFO "Hello world!\n");
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bye bye...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE(DRIVER_SUPPORT);

