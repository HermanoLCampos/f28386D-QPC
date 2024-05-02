/*
 * c28x_canb_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */


#include "c28x_interrupts.h"

//
// canB_Isr1 - CANB ISR 1
//
__interrupt void INT_CAN2_0_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// canB_Isr2 - CANB ISR 2
//

__interrupt void INT_CAN2_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
