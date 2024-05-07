/*
 * freertos_support.c
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#include "freertos_support.h"


uint8_t ucHeap[ 1024 ];
#pragma DATA_SECTION(ucHeap,   ".freertosHeap")
#pragma DATA_ALIGN ( ucHeap , portBYTE_ALIGNMENT )

StaticTask_t idleTaskTCBBuffer;
StackType_t idleTaskStack[IDLE_TASK_STACK_SIZE];
#pragma DATA_SECTION(idleTaskStack, ".freertosStaticStack")
#pragma DATA_ALIGN ( idleTaskStack , portBYTE_ALIGNMENT )

//
// vApplicationGetIdleTaskMemory - Application must provide an implementation
// of vApplicationGetIdleTaskMemory() to provide the memory that is used by the
// Idle task if configUSE_STATIC_ALLOCATION is set to 1.
//
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static - otherwise they will be allocated on
    the stack and so not exists after this function exits. */

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &idleTaskTCBBuffer;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = idleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t, size is
    specified in words, not bytes. */
    *pulIdleTaskStackSize = IDLE_TASK_STACK_SIZE;
}


//
// FreeRTOS_init - Initializes added FreeRTOS constructs and starts the scheduler
//
void FreeRTOS_init(){

    //
    // Start the scheduler
    //
    vTaskStartScheduler();
}


void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    // This is a critical erro in your FreeRTOS, this erros musca cause a stop
    // or a reset on your code

    // number: 1 - stack overflow

    system_assert(__FILE__,1);
}


void vApplicationMallocFailedHook(){
    // This is a critical erro in your FreeRTOS, this erros musca cause a stop
    // or a reset on your code

    // number: 2 - malloc failed

    system_assert(__FILE__,2);
}
