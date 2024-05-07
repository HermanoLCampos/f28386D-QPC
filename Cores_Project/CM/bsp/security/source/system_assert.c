/*
 * system_assert.c
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#include "system_assert.h"
#include "resources_config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp_basic.h"

void system_assert(const char *filename, int assert_number){
#if USER_ASSERT
    user_assert(filename, assert_number);
#endif
    taskDISABLE_INTERRUPTS();
    BSP_BKPT;
    while(1);
}

