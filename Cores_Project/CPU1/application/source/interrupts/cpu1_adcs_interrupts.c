/*
 * c28x_adcs_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"

//
// INT_myADCA_1_ISR
//
__interrupt void INT_myADCA_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP10);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCB_1_ISR
//
__interrupt void INT_myADCB_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP10);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCC_1_ISR
//
__interrupt void INT_myADCC_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP10);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCD_1_ISR
//
__interrupt void INT_myADCD_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP10);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


