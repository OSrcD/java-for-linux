#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>



/* 入口函数 */
static int hello_init(void)
{
    printk(KERN_ALERT "hello_init\n");
        return 0;
}

/* 退出函数 */
static void hello_exit(void)
{
    printk(KERN_ALERT "hello_exit\n");
}

/* 注册 */
module_init(hello_init);
module_exit(hello_exit);