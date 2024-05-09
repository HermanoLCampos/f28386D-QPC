/*
 * user_board.c
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#include "user_board.h"

BSP_IPC_MessageQueue_t ipc_message_queue[OC_IPC_NUM_OF_INST];

void user_board_init(){
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT0, IPC_CPU1_ISR0);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT1, IPC_CPU1_ISR1);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT2, IPC_CPU1_ISR2);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT3, IPC_CPU1_ISR3);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT4, IPC_CPU1_ISR4);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT5, IPC_CPU1_ISR5);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT6, IPC_CPU1_ISR6);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT7, IPC_CPU1_ISR7);

    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT0, IPC_CPU2_ISR0);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT1, IPC_CPU2_ISR1);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT2, IPC_CPU2_ISR2);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT3, IPC_CPU2_ISR3);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT4, IPC_CPU2_ISR4);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT5, IPC_CPU2_ISR5);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT6, IPC_CPU2_ISR6);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT7, IPC_CPU2_ISR7);

    BSP_IPC_initMessageQueue(IPC_CM_L_CPU1_R , &ipc_message_queue[OC_IPC_CM_CPU1_ID] , IPC_INT1 , IPC_INT1);
    BSP_IPC_initMessageQueue(IPC_CM_L_CPU2_R , &ipc_message_queue[OC_IPC_CM_CPU2_ID] , IPC_INT1 , IPC_INT1);
}
