/*
 * c28x_canb_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */


#include "cpu1_interrupts.h"
#include "dbc_skiip.h"
#include "board.h"

typedef struct{
    uint16_t data1:8;
    uint16_t data2:8;
    uint16_t data3:8;
    uint16_t data4:8;
    uint16_t data5:8;
    uint16_t data6:8;
    uint16_t data7:8;
    uint16_t data8:8;
}c2000_can_data_adapter_t;


#include "bsp_can_fifo.h"


extern CAN_FIFO_t CAN_SKIIP_1_fifo;
extern CAN_FIFO_t CAN_SKIIP_2_fifo;

//
// canB_Isr1 - CAN ISR 1
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

    case DBC_SKIIP_CAN_MSG_STD_IN_INDEX:{


        CAN_MsgFrameType frameType;
        uint16_t data[8];
        OC_Evt_CAN_Message_Received_t  * CAN_Received = Q_NEW_FROM_ISR(OC_Evt_CAN_Message_Received_t,CAN_RECEIVE_MSG_SIG);
        CAN_Received->super.ID = OC_CAN_CAN_SKIIP_ID;

        CAN_readMessageWithID(CAN_SKIIP_BASE, status , &frameType, &CAN_Received->Message_ID , data);
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data1 = data[0];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data2 = data[1];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data3 = data[2];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data4 = data[3];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data5 = data[4];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data6 = data[5];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data7 = data[6];
        ((c2000_can_data_adapter_t *)CAN_Received->Data)->data8 = data[7];

        QACTIVE_POST_FROM_ISR(p_ao_communication, &CAN_Received->super.super,&xHigherPriorityTaskWoken,(void *)0);

        CAN_clearInterruptStatus(CAN_SKIIP_BASE, status );


        break;
    }

    case DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX:{
        BSP_CAN_fifo_msg_transmited(&CAN_SKIIP_1_fifo);
        CAN_clearInterruptStatus(CAN_SKIIP_BASE, status );
        break;
    }
    case DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX:{
        BSP_CAN_fifo_msg_transmited(&CAN_SKIIP_2_fifo);
        CAN_clearInterruptStatus(CAN_SKIIP_BASE, status );
        break;
    }


//    case DBC_SKIIP_CAN_MSG_EXT_IN_INDEX:{
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
// canB_Isr2 - CAN ISR 2
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
