/*
 * c28x_canb_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */


#include "cpu1_interrupts.h"
#include "modulink.h"
#include "board.h"

//
// canB_Isr1 - CANB ISR 1
//
__interrupt void INT_CAN_SKIIP_0_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    uint32_t status;
//    CAN_MsgFrameType frameType;

    status = CAN_getInterruptCause(CAN_SKIIP_BASE);

    switch(status){

    case CAN_INT_INT0ID_STATUS:
        status = CAN_getStatus(CAN_SKIIP_BASE);

        if(status & CAN_STATUS_RXOK || status & CAN_STATUS_TXOK){
            // Bus Off state

        }else if(
                    (
                        ((status  & ~CAN_STATUS_RXOK) != CAN_STATUS_LEC_MSK)  &&
                        ((status  & ~CAN_STATUS_RXOK) != CAN_STATUS_LEC_NONE)
                    ) || (
                        ((status  & ~CAN_STATUS_TXOK) != CAN_STATUS_LEC_MSK)  &&
                        ((status  & ~CAN_STATUS_TXOK) != CAN_STATUS_LEC_NONE)
                    )
                ){
            if(status & CAN_STATUS_PERR){
                // parity error.

            }
            if(status & CAN_STATUS_BUS_OFF){
                // Bus Off state

            }else if(status & CAN_STATUS_EPASS){
                // Reached error passive level

            }else if(status & CAN_STATUS_EWARN){
                // Reached warning level

            }
            if(status & CAN_STATUS_LEC_MSK){
                switch(status&CAN_STATUS_LEC_MSK){
                case CAN_STATUS_LEC_STUFF:
                    // bit stuffing error
                    break;

                case CAN_STATUS_LEC_FORM:
                    // A formatting error

                    break;

                case CAN_STATUS_LEC_ACK:
                    // acknowledge error
                    break;

                case CAN_STATUS_LEC_BIT1:
                    // bus remained a bit level of 1

                    break;

                case CAN_STATUS_LEC_BIT0:
                    // bus remained a bit level of 0

                    break;

                case CAN_STATUS_LEC_CRC:
                    // CRC error
                    break;

                }
            }
        }
        break;
//    case CAN_MSG_IN_1_INDEX:
//    case CAN_MSG_IN_2_INDEX:{
//
//        OC_Evt_CAN_Message_Received_t * CAN_Received = Q_NEW_FROM_ISR(OC_Evt_CAN_Message_Received_t,CAN_RECEIVE_MSG_SIG);
//        CAN_Received->super.ID = OC_CAN_CANB_ID;
//        CAN_readMessageWithID(CAN_SKIIP_BASE, status , &frameType, &CAN_Received->Message_ID , CAN_Received->Data);
//        CAN_clearInterruptStatus(CAN_SKIIP_BASE, status );
//
//        QACTIVE_POST_FROM_ISR(p_ao_communication, &CAN_Received->super.super,&xHigherPriorityTaskWoken,(void *)0);
//
//        /* Parser Data */
//
//         Message Received Evt
//
//        break;
//    }
    default:
        break;
    }

//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    CAN_clearGlobalInterruptStatus(CAN_SKIIP_BASE, CAN_GLOBAL_INT_CANINT0);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// canB_Isr2 - CANB ISR 2
//

__interrupt void INT_CAN_SKIIP_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
