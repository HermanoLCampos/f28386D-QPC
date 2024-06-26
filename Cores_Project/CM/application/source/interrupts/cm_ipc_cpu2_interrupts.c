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

//    BSP_BKPT;
#ifdef DUALCORE
    QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_receive_msg[OC_IPC_CM_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );

#else
    BSP_BKPT;
#endif
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//OC_Evt_IPC_Message_t Evt_Msg_CPU2 = {
//    .super.super  = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
//    .super.ID = OC_IPC_CM_CPU1_ID,
//    .msg    = {
//        .com_ipc_sig = COM_SIG_IPC_CAN_SEND_MSG,
//        .payload     = {
//            [0] = 2,
//            [1] = 3,
//        }
//    }
//};

__interrupt void IPC_CPU2_ISR2(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG2);

//    QACTIVE_POST_FROM_ISR( p_ao_communication , &Evt_Msg_CPU2.super.super , &xHigherPriorityTaskWoken , (void *) 0 );
    BSP_BKPT;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void IPC_CPU2_ISR3(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG3);

//    BSP_BKPT;

#ifdef DUALCORE
    uint32_t command,addr,data;
    IPC_readCommand( IPC_CM_L_CPU2_R , IPC_RESET_FLAG , IPC_ADDR_CORRECTION_DISABLE, &command, &addr, &data);

    switch (command) {
        case OC_IPC_CMD_REMOTE_RESET:
            QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_remote_reset[OC_IPC_CM_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );
            break;
        case OC_IPC_CMD_RESET_COMPLETE:
            QACTIVE_POST_FROM_ISR( p_ao_communication , &im_evt_ipc_reset_complete[OC_IPC_CM_CPU2_ID].super , &xHigherPriorityTaskWoken , (void *) 0 );
            break;
        default:
            break;
    }
#else
    BSP_BKPT;
#endif

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
