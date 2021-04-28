#define DEBUG

#include <linux/module.h>

struct page *tmp;

void __mem_init(void)
{
	pr_debug("%s: \n", __func__);

	tmp = alloc_pages(GFP_KERNEL, 7);
}

void __mem_exit(void)
{
	pr_debug("%s: \n", __func__);
	__free_pages(tmp, 7);
}

static int __init mem_init(void)
{
	__mem_init();

	return 0;
}

static void __exit mem_exit(void)
{
	__mem_exit();
}

module_init(mem_init);
module_exit(mem_exit);

MODULE_AUTHOR("Vernon Yang <vernon2gm@gmail.com>");
MODULE_DESCRIPTION("BUDDY MODULES");
MODULE_LICENSE("GPL");
