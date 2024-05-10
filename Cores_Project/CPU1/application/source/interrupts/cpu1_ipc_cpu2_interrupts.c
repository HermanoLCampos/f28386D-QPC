/*
 * c28x_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "board.h"

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

//    BSP_BKPT;

    QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_receive_msg[OC_IPC_CPU1_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );

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

//    BSP_BKPT;

    uint32_t command,addr,data;
    IPC_readCommand( IPC_CPU1_L_CPU2_R , IPC_RESET_FLAG , IPC_ADDR_CORRECTION_DISABLE, &command, &addr, &data);

    switch (command) {
        case OC_IPC_CMD_REMOTE_RESET:
            QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_remote_reset[OC_IPC_CPU1_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );
            break;
        case OC_IPC_CMD_RESET_COMPLETE:
            QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_reset_complete[OC_IPC_CPU1_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );
            break;
        default:
            break;
    }

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
