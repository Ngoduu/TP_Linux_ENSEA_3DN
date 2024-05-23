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

#define TAILLE 256

static int param;
module_param(param,int,0);
//MODULE_PARAM_DESC(param,"parametre");
static char message[TAILLE];

static struct file_operations proc_fops;

ssize_t fops_write(struct file * file, const char __user * buffer, size_t count, loff_t * ppos) {
	int len = count;
	if (len > TAILLE) len = TAILLE;
	printk(KERN_INFO "Recieving new messag\n");
	if (copy_from_user(message, buffer, count)) {
		return -EFAULT;
	}
	message[count] = '\0';
	printk(KERN_INFO "New message : %s\n", message);
	return count;
}

ssize_t fops_read(struct file *file, char __user * buffer,size_t count, loff_t * ppos) 
{
	int errno=0;
	int copy;
	
	if (count > TAILLE) count=TAILLE;
	if ((copy=copy_to_user(buffer, message, strlen(message)+1)))
	errno = -EFAULT;
	printk(KERN_INFO "message read, %d, %p\n", copy, buffer);
	return count-copy;
}

int hello_init(void)
{
	proc_fops.read = fops_read;
	proc_fops.write = fops_write;
	proc_create(PROC_NAME,0666,NULL,&proc_fops);

	printk(KERN_INFO "Hello world!\n");
	printk(KERN_DEBUG "le paramètre est=%d\n", param);
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

