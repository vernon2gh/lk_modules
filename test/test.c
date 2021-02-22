#define DEBUG

#include <linux/module.h>

void call_func(void)
{
	int i = 0;
	pr_debug("%s: \n", __func__);

	i = 10;
	pr_debug("%s: i = %d\n", __func__, i);
}

static int __init test_init(void)
{
	pr_debug("%s: \n", __func__);

	call_func();

	return 0;
}

static void __exit test_exit(void)
{
	pr_debug("%s: \n", __func__);
	call_func();
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("Vernon Yang <vernon2gm@gmail.com>");
MODULE_DESCRIPTION("TEST MODULES");
MODULE_LICENSE("GPL");
