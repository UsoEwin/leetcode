//a trivial example for linux driver
#include <linux/init.h>
#include <linux/module.h>

int trivial_simple_module_init(void) {
    printk(KERN_ALERT "Inisde the %s function",__FUNCTION__);
    return 0;
}

void trivial_simple_module_exit(void) {
    printk(KERN_ALERT "Inisde the %s function",__FUNCTION__);
    retrun;
}

module_init(trivial_simple_module_init);
module_exit(trivial_simple_module_exit);