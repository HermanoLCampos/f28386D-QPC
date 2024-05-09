/*
 * cm_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cm_interrupts.h"

__interrupt void IPC_CPU2_ISR0(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG0);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR1(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG1);

    BSP_BKPT;

//    BSP_IPC_Message_t Message_received;
//    bool status;
//    do{
//        status = BSP_IPC_readMessageFromQueue( IPC_CM_L_CPU2_R , &ipc_message_queue_cm_to_cpu2 , IPC_ADDR_CORRECTION_DISABLE , &Message_received , IPC_NONBLOCKING_CALL);
//        if(status==true){
//            // Message_received
//        }else{
//            // Treat the error here
//        }
//    }while(status);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
__interrupt void IPC_CPU2_ISR2(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG2);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
__interrupt void IPC_CPU2_ISR3(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG3);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR4(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG4);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR5(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG5);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR6(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG6);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR7(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG7);

    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
