/*
 * freertos_support.h
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_FREERTOS_INCLUDE_FREERTOS_SUPPORT_H_
#define BSP_FREERTOS_INCLUDE_FREERTOS_SUPPORT_H_

#include "driverlib_cm.h"
#include "FreeRTOS.h"
#include "task.h"

#include "system_assert.h"

extern uint8_t ucHeap[ 1024 ];

//
// Idle task specific macros
//
#define IDLE_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

//
// Idle task specific variables
//
extern StaticTask_t idleTaskTCBBuffer;
extern StackType_t idleTaskStack[IDLE_TASK_STACK_SIZE];


//
// Init Functions
//
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize );
void vApplicationSetupTimerInterrupt( void );
void FreeRTOS_init();

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationMallocFailedHook( void );

#endif /* BSP_FREERTOS_INCLUDE_FREERTOS_SUPPORT_H_ */
