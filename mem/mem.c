#define DEBUG

#include <linux/module.h>

void call_func(void)
{
	void *p;

	pr_debug("%s: \n", __func__);

	p = kmalloc(16, GFP_KERNEL);
	kfree(p);
}

static int __init mem_init(void)
{
	pr_debug("%s: \n", __func__);

	call_func();

	return 0;
}

static void __exit mem_exit(void)
{
	pr_debug("%s: \n", __func__);
}

module_init(mem_init);
module_exit(mem_exit);

MODULE_AUTHOR("Vernon Yang <vernon2gm@gmail.com>");
MODULE_DESCRIPTION("MEM MODULES");
MODULE_LICENSE("GPL");
