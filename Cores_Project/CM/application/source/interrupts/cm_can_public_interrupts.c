/*
 * cm_can_public_interrupts.c
 *
 *  Created on: 15 de mai de 2024
 *      Author: ramon.martins
 */

#include "cm_interrupts.h"
#include "modulink.h"

__interrupt void CAN_PUBLIC_ISR0(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    uint32_t status;
    CAN_MsgFrameType frameType;

    status = CAN_getInterruptCause(CAN_PUBLIC_BASE);

//    BSP_BKPT;

    switch(status){

    case CAN_INT_INT0ID_STATUS:
        status = CAN_getStatus(CAN_PUBLIC_BASE);

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
//    case MODULINK_CAN_MSG_STD_IN_INDEX:{
//
//        break;
//    }
    case MODULINK_CAN_MSG_EXT_IN_INDEX:{
//        BSP_BKPT;
        OC_Evt_CAN_Message_Received_t CAN_Received_1;
        CAN_readMessageWithID(CAN_PUBLIC_BASE, status , &frameType, &CAN_Received_1.Message_ID , (uint8_t *) CAN_Received_1.Data);
        CAN_clearInterruptStatus(CAN_PUBLIC_BASE, status );

        switch(CAN_Received_1.Message_ID & 0x00FFFF00){
        case MODULINK_CAN_MSG_VPU_COMMANDS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_VPU_SETPOINTS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_IHM_SETPOINTS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_SMU_COMMANDS_FSBB_FRAME_ID & 0x00FFFF00:{
            OC_Evt_CAN_Message_Received_t * CAN_Received = Q_NEW_FROM_ISR(OC_Evt_CAN_Message_Received_t,CAN_RECEIVE_MSG_SIG);
            CAN_Received->super.ID  = OC_CAN_CAN_PUBLIC_ID;
            CAN_Received->Message_ID = CAN_Received_1.Message_ID;
            CAN_Received->Data[0]    = CAN_Received_1.Data[0];
            CAN_Received->Data[1]    = CAN_Received_1.Data[1];
            CAN_Received->Data[2]    = CAN_Received_1.Data[2];
            CAN_Received->Data[3]    = CAN_Received_1.Data[3];
            if(QEvt_verify_(&CAN_Received->super.super) == 0){
                system_assert("cm_can_public",0);
            }
            QACTIVE_POST_FROM_ISR(p_ao_communication, &CAN_Received->super.super,&xHigherPriorityTaskWoken,(void *)0);


            break;
        }
        default:
            break;
        }

        /* Parser Data */

//         Message Received Evt

        break;
    }
    default:
        break;
    }

//    BSP_BKPT;

    CAN_clearGlobalInterruptStatus(CAN_PUBLIC_BASE, CAN_GLOBAL_INT_CANINT0);

    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}

__interrupt void CAN_PUBLIC_ISR1(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

//    BSP_BKPT;

    CAN_clearGlobalInterruptStatus(CAN_PUBLIC_BASE, CAN_GLOBAL_INT_CANINT1);

    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}
