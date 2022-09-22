#include <linux/init.h>
#include <linux/module.h>

static int __init sum_init(void)
{
    printk("my first kernel module init\n");
    return 0;
}

static void __exit sum_exit(void)
{
    printk("carlos test goodbye.\n");
}

static int sum(int a, int b)
{
    return a + b;
}

int export_api_sum(int a, int b)
{
    return sum(a, b);
}

EXPORT_SYMBOL_GPL(export_api_sum);
module_init(sum_init);
module_exit(sum_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("carlos wei");
MODULE_DESCRIPTION("this is the sum kernel driver");
MODULE_ALIAS("sum");