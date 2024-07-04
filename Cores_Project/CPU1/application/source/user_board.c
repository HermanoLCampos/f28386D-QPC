/*
 * user_board.c
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#include "user_board.h"

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
