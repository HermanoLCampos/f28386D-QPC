/*
 * user_board.c
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#include "user_board.h"
#include "dbc_skiip.h"
#include "bsp_can_fifo.h"

extern CAN_FIFO_t CAN_SKIIP_1_fifo;
extern CAN_FIFO_t CAN_SKIIP_2_fifo;

BSP_IPC_MessageQueue_t ipc_message_queue[OC_IPC_NUM_OF_INST];

void user_board_init(){
//    Board_init();
    //Board Init

    // Consider change when activate specifics interrupts

    EALLOW;

    PinMux_init();
    SYSCTL_init();
    INPUTXBAR_init();
    SYNC_init();
    ASYSCTL_init();
    CLA_init();
    MEMCFG_init();
    ADC_init();
//    CAN_init();
//        CAN_PUBLIC_init();
        CAN_SKIIP_init();

    CPUTIMER_init();
    EPWM_init();
    GPIO_init();
    I2C_init();
#ifdef DUALCORE
    IPC_SYSCFG_init();
#endif
    SPI_init();
    XINT_init();
    INTERRUPT_init();

    user_msg_box_init();

    EDIS;


    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT0, IPC_CM_ISR0);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT1, IPC_CM_ISR1);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT2, IPC_CM_ISR2);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT3, IPC_CM_ISR3);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT4, IPC_CM_ISR4);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT5, IPC_CM_ISR5);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT6, IPC_CM_ISR6);
    IPC_registerInterrupt(IPC_CPU1_L_CM_R, IPC_INT7, IPC_CM_ISR7);

    BSP_IPC_initMessageQueue(IPC_CPU1_L_CM_R   , &ipc_message_queue[OC_IPC_CPU1_CM_ID  ] , IPC_INT1 , IPC_INT1);

#ifdef DUALCORE
    BSP_IPC_initMessageQueue(IPC_CPU1_L_CPU2_R , &ipc_message_queue[OC_IPC_CPU1_CPU2_ID] , IPC_INT1 , IPC_INT1);
#endif

}

void user_msg_box_init(){
    uint16_t i_msg;
    for(i_msg = 1; i_msg< DBC_SKIIP_CAN_MAX_MSG; i_msg++){
        // Declare the Message Objects
        CAN_setupMessageObject(
            CAN_SKIIP_BASE,                                     //Base
            i_msg,                                              // MailBox Number
            dbc_skiip_can_messages_proprieties[i_msg].msg_id,   // Message ID
            CAN_MSG_FRAME_STD,                                  // Standard ID
            dbc_skiip_can_messages_proprieties[i_msg].msgType,  // Message Type
           ~dbc_skiip_can_messages_proprieties[i_msg].mask,     // Message Mask
            dbc_skiip_can_messages_proprieties[i_msg].flags,    // Message Flags
            dbc_skiip_can_messages_proprieties[i_msg].dlc       // Message DLC
        );
    }

    i_msg = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX;
    CAN_setupMessageObject(
        CAN_SKIIP_BASE,                                     //Base
        i_msg,                                              // MailBox Number
        dbc_skiip_can_messages_proprieties[i_msg].msg_id,   // Message ID
        CAN_MSG_FRAME_STD,                                  // Standard ID
        dbc_skiip_can_messages_proprieties[i_msg].msgType,  // Message Type
       ~dbc_skiip_can_messages_proprieties[i_msg].mask,     // Message Mask
        dbc_skiip_can_messages_proprieties[i_msg].flags | CAN_MSG_OBJ_TX_INT_ENABLE,    // Message Flags
        dbc_skiip_can_messages_proprieties[i_msg].dlc       // Message DLC
    );
    BSP_CAN_init_fifo(&CAN_SKIIP_1_fifo, CAN_SKIIP_BASE, i_msg);

    i_msg = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX;
    CAN_setupMessageObject(
        CAN_SKIIP_BASE,                                     //Base
        i_msg,                                              // MailBox Number
        dbc_skiip_can_messages_proprieties[i_msg].msg_id,   // Message ID
        CAN_MSG_FRAME_STD,                                  // Standard ID
        dbc_skiip_can_messages_proprieties[i_msg].msgType,  // Message Type
       ~dbc_skiip_can_messages_proprieties[i_msg].mask,     // Message Mask
        dbc_skiip_can_messages_proprieties[i_msg].flags | CAN_MSG_OBJ_TX_INT_ENABLE,    // Message Flags
        dbc_skiip_can_messages_proprieties[i_msg].dlc       // Message DLC
    );
    BSP_CAN_init_fifo(&CAN_SKIIP_2_fifo, CAN_SKIIP_BASE, i_msg);

}
