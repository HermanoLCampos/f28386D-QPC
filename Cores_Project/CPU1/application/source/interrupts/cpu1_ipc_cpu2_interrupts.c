/*
 * c28x_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"

__interrupt void IPC_CPU2_ISR0(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR1(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    BSP_BKPT;

//    BSP_IPC_Message_t Message_received;
//    bool status;
//    do{
//        status = BSP_IPC_readMessageFromQueue(IPC_CPU1_L_CPU2_R, &ipc_message_queue_cpu1_to_cpu2, IPC_ADDR_CORRECTION_DISABLE, &Message_received , IPC_NONBLOCKING_CALL);
//
//        if(status){
//
//        }else{
//            // Treat the error here
//        }
//    }while(status);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR2(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR3(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG3);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
