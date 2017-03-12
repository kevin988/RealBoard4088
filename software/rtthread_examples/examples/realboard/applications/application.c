/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-05-02     Aozima       add led function
 */

#include <rtthread.h>

#include <board.h>
#include <components.h>

#include <rtdevice.h>
#include "startup_checking.h"

extern void realtouch_ui_init(void);
/* thread phase init */
void rt_init_thread_entry(void *parameter)
{
	rt_components_init();

    {
        struct rt_completion done;
        rt_completion_init(&done);
        
        startup_checking(&done);
        rt_completion_wait(&done, RT_WAITING_FOREVER);
        rt_kprintf("\nChecking resource files done!!\n");
    }
    
    internal_app_init();
    app_mainui_init();
}

int rt_application_init(void)
{
    rt_thread_t tid;
    tid = rt_thread_create("init",
                           rt_init_thread_entry, RT_NULL,
                           2048, RT_THREAD_PRIORITY_MAX / 3, 20);
    if (tid != RT_NULL) rt_thread_startup(tid);

    return 0;
}
