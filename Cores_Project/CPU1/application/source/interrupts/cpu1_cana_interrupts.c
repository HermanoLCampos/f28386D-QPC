/*
 * c28x_cana_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */


#include "cpu1_interrupts.h"

//
// canA_Isr1 - CANA ISR 1
//
__interrupt void INT_CAN1_0_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// canA_Isr2 - CANA ISR 2
//

__interrupt void INT_CAN1_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
