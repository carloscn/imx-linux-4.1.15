#include <linux/init.h>
#include <linux/module.h>


extern int export_api_sum(int a, int b);

static int debug = 1;
module_param(debug, int, 0644);
MODULE_PARM_DESC(debug,"carlos enable debug function\n");

#define carlos_debug_printk(args...)                \
        if (debug) {                                \
            printk(KERN_DEBUG args);                \
        }                                           \

static int __init my_test_init(void)
{
    int a = 10, b = 20;
    printk("my first kernel module init\n");
    a = export_api_sum(a, b);
    printk("sum is %d\n", a);
    carlos_debug_printk("init : carlos_debug_printk to debug ko param\n");
    return 0;
}

static void __exit my_test_exit(void)
{
    printk("carlos test goodbye.\n");
    carlos_debug_printk("exit : carlos_debug_printk to debug ko param\n");
}

module_init(my_test_init);
module_exit(my_test_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("carlos wei");
MODULE_DESCRIPTION("this is the hello kernel driver");
MODULE_ALIAS("mytest");