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

    BSP_IPC_initMessageQueue(IPC_CM_L_CPU1_R , &ipc_message_queue[OC_IPC_CM_CPU1_ID] , IPC_INT1 , IPC_INT1);

#ifdef DUALCORE

    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT0, IPC_CPU2_ISR0);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT1, IPC_CPU2_ISR1);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT2, IPC_CPU2_ISR2);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT3, IPC_CPU2_ISR3);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT4, IPC_CPU2_ISR4);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT5, IPC_CPU2_ISR5);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT6, IPC_CPU2_ISR6);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT7, IPC_CPU2_ISR7);


    BSP_IPC_initMessageQueue(IPC_CM_L_CPU2_R , &ipc_message_queue[OC_IPC_CM_CPU2_ID] , IPC_INT1 , IPC_INT1);

#endif

    user_CAN_Init();

    init_cpu2cm_memory();
}

void user_CAN_Init(){
    CAN_initModule(CAN_PUBLIC_BASE);
    CAN_setBitRate(CAN_PUBLIC_BASE, CM_CLK_FREQ, 250000, 16);

    CAN_enableInterrupt(CAN_PUBLIC_BASE, CAN_INT_ERROR|CAN_INT_IE0|CAN_INT_IE1|CAN_INT_STATUS);

    Interrupt_enable(INT_CAN_PUBLIC_0);

    CAN_enableGlobalInterrupt(CAN_PUBLIC_BASE,CAN_GLOBAL_INT_CANINT0);
    CAN_enableGlobalInterrupt(CAN_PUBLIC_BASE,CAN_GLOBAL_INT_CANINT1);

    Interrupt_registerHandler(INT_CAN_PUBLIC_0, &CAN_PUBLIC_ISR0);
    Interrupt_registerHandler(INT_CAN_PUBLIC_1, &CAN_PUBLIC_ISR1);

    CAN_setInterruptMux(CAN_PUBLIC_BASE, 0);

    for(uint16_t i_msg = 1; i_msg < MODULINK_CAN_MAX_MSG; i_msg++){
        // Declare the Message Objects
        CAN_setupMessageObject(
            CAN_PUBLIC_BASE,                                    //Base
            i_msg,                                              // MailBox Number
            modulink_can_messages_proprieties[i_msg].msg_id,    // Message ID
            CAN_MSG_FRAME_EXT,                                  // Extended ID
            modulink_can_messages_proprieties[i_msg].msgType,   // Message Type
           ~modulink_can_messages_proprieties[i_msg].mask,      // Message Mask
            modulink_can_messages_proprieties[i_msg].flags,     // Message Flags
            modulink_can_messages_proprieties[i_msg].dlc        // Message DLC
        );
    }

    CAN_startModule(CAN_PUBLIC_BASE);

    CAN_enableAutoBusOn(CAN_PUBLIC_BASE);
    CAN_setAutoBusOnTime(CAN_PUBLIC_BASE, 250000);
}

#include "cpu1_cm_memory_shared.h"


// Initialization of CM to C28x shared memory
void init_cpu2cm_memory(){
    extern CPU1_CM_Message_t * CPU1_CM_Message;
    uint32_t command;
    uint32_t data;

    IPC_waitForFlag(IPC_CM_L_CPU1_R, IPC_FLAG31);
    IPC_readCommand(IPC_CM_L_CPU1_R, IPC_FLAG31, IPC_ADDR_CORRECTION_ENABLE, &command,(uint32_t*) &CPU1_CM_Message, &data);
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG31);
}

