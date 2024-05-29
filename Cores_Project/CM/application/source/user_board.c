/*
 * user_board.c
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#include "user_board.h"
#include "board.h"
#include "modulink.h"

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

    user_CAN_Init();
}

void user_CAN_Init(){
    CAN_initModule(CAN1_BASE);
    CAN_setBitRate(CAN1_BASE, CM_CLK_FREQ, 250000, 16);

    CAN_enableInterrupt(CAN1_BASE, CAN_INT_ERROR|CAN_INT_IE0|CAN_INT_IE1|CAN_INT_STATUS);

    Interrupt_enable(INT_CANA0);

    CAN_enableGlobalInterrupt(CAN1_BASE,CAN_GLOBAL_INT_CANINT0);
    CAN_enableGlobalInterrupt(CAN1_BASE,CAN_GLOBAL_INT_CANINT1);

    Interrupt_registerHandler(INT_CANA0, &CAN_1_ISR0);
    Interrupt_registerHandler(INT_CANA1, &CAN_1_ISR1);

    CAN_setInterruptMux(CAN1_BASE, 0);

    for(uint16_t i_msg = 1; i_msg<= MODULINK_CAN_MAX_MSG; i_msg++){
        // Declare the Message Objects
        CAN_setupMessageObject(
            CAN1_BASE,                                          //Base
            i_msg,                                              // MailBox Number
            modulink_can_messages_proprieties[i_msg].msg_id,    // Message ID
            CAN_MSG_FRAME_EXT,                                  // Extended ID
            modulink_can_messages_proprieties[i_msg].msgType,   // Message Type
            modulink_can_messages_proprieties[i_msg].mask,      // Message Mask
            modulink_can_messages_proprieties[i_msg].flags,     // Message Flags
            modulink_can_messages_proprieties[i_msg].dlc        // Message DLC
        );
    }

    CAN_startModule(CAN1_BASE);

    CAN_enableAutoBusOn(CAN1_BASE);
    CAN_setAutoBusOnTime(CAN1_BASE, 250000);
}
