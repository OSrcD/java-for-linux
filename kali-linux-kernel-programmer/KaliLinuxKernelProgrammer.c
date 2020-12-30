#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>



/* 入口函数 */
static int init(void)
{
    printk(KERN_ALERT "init\n");
        return 0;
}

/* 退出函数 */
static void exit(void)
{
    printk(KERN_ALERT "exit\n");
}

/* 注册 */
module_init(init);
module_exit(exit);