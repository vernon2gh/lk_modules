#define DEBUG

#include <linux/module.h>
#include <linux/slab.h>

struct kmem_cache *cachep;
u8 *objp;

void __mem_init(void)
{
	pr_debug("%s: \n", __func__);

	cachep = kmem_cache_create("tmp_kmem_cache", sizeof(u8), sizeof(void *), SLAB_POISON, NULL);
	objp = kmem_cache_alloc(cachep, GFP_KERNEL);

	pr_debug("%s: 0x%x\n", __func__, *objp);
}

void __mem_exit(void)
{
	pr_debug("%s: \n", __func__);

	kmem_cache_free(cachep, objp);
	kmem_cache_destroy(cachep);
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
MODULE_DESCRIPTION("KMEM CACHE MODULES");
MODULE_LICENSE("GPL");
