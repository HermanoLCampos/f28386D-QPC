/*
 * can_app.c
 *
 *  Created on: 26 de abr de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_can/oc_can.h"
#include "dbc_skiip.h"
#include "board.h"
#include "bsp_can_fifo.h"

uint32_t oc_can_base[OC_CAN_NUM_OF_INST] = {
    [OC_CAN_CAN_SKIIP_ID] = CAN_SKIIP_BASE,
};

CAN_FIFO_t CAN_SKIIP_1_fifo, CAN_SKIIP_2_fifo;

void OC_CAN_send_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Send_Message_t);
    if(me->id == OC_CAN_CAN_SKIIP_ID){
        if(Evt_CAN_MSG->Message_Box_ID == DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX){
            BSP_CAN_fifo_add_msg( &CAN_SKIIP_1_fifo , *((uint64_t *) &Evt_CAN_MSG->Data));
        }else
        if(Evt_CAN_MSG->Message_Box_ID == DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX){
            BSP_CAN_fifo_add_msg( &CAN_SKIIP_2_fifo , *((uint64_t *) &Evt_CAN_MSG->Data));
        }else
            CAN_sendMessage_16bit(oc_can_base[OC_CAN_CAN_SKIIP_ID], Evt_CAN_MSG->Message_Box_ID, 8, (uint16_t *) &Evt_CAN_MSG->Data);
    }else{
        // Invalid ID
    }
}

void OC_CAN_receive_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Message_Received_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Message_Received_t);

    if(me->id == OC_CAN_CAN_SKIIP_ID){
        uint16_t buffer_index = 0;
        Communication_Message_t * msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
        switch(Evt_CAN_MSG->Message_ID){
//===================================================================================
//============================Treat the messages received============================
//===================================================================================

        case DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_FRAME_ID:
            if(( (DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP1_HEADER == 0x80){
                // Error on request
                // 0x06020000 -> Object does not exist in the object dictionary
                // 0x06010000 -> Attempt to read a write only object
                // 0x06010002 -> Attempt to write a read only object
                // 0x08000000 -> General error
            }else{
                switch( ((DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_t *) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP1_OBJ_ID ){
                case CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_DCB):
                    if(
                        (((DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP1_SUB_INDEX == 1)
                    ){
                        msg_received->com_sig = COM_SIG_CAN_SKIIP_UPDATE_MEASURE;
                        msg_received->message_size = sizeof(FSBB_Measure_Update_t)/sizeof(uint16_t);
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure_id = FSBB_MEASURE_SKIIP1_DCB_TEMPERATURE;
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure = ((CAN_Open_2_Byte_Data_Decode_t*) &Evt_CAN_MSG->Data)->data;
                        buffer_index = buffer_index + msg_received->message_size + 2;
                        msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
                    }
                    break;
                case CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_PCB):
                    if(
                        (((DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP1_SUB_INDEX == 0)
                    ){
                        msg_received->com_sig = COM_SIG_CAN_SKIIP_UPDATE_MEASURE;
                        msg_received->message_size = sizeof(FSBB_Measure_Update_t)/sizeof(uint16_t);
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure_id = FSBB_MEASURE_SKIIP1_PCB_TEMPERATURE;
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure = ((CAN_Open_2_Byte_Data_Decode_t*) &Evt_CAN_MSG->Data)->data;
                        buffer_index = buffer_index + msg_received->message_size + 2;
                        msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
                    }
                    break;
                default:
                    // unhandled message
                    break;
                }
            }
            break;
        case DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_FRAME_ID:
            if(( (DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP2_HEADER == 0x80){
                // Error on request
                // 0x06020000 -> Object does not exist in the object dictionary
                // 0x06010000 -> Attempt to read a write only object
                // 0x06010002 -> Attempt to write a read only object
                // 0x08000000 -> General error
            }else{
                switch( ((DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_t *) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP2_OBJ_ID ){
                case CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_DCB):
                    if(
                        (((DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP2_SUB_INDEX == 1)
                    ){
                        msg_received->com_sig = COM_SIG_CAN_SKIIP_UPDATE_MEASURE;
                        msg_received->message_size = sizeof(FSBB_Measure_Update_t)/sizeof(uint16_t);
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure_id = FSBB_MEASURE_SKIIP2_DCB_TEMPERATURE;
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure = ((CAN_Open_2_Byte_Data_Decode_t*) &Evt_CAN_MSG->Data)->data;
                        buffer_index = buffer_index + msg_received->message_size + 2;
                        msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
                    }
                    break;
                case CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_PCB):
                    if(
                        (((DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_t*) &Evt_CAN_MSG->Data)->CAN_SIG_SKIIP2_SUB_INDEX == 0)
                    ){
                        msg_received->com_sig = COM_SIG_CAN_SKIIP_UPDATE_MEASURE;
                        msg_received->message_size = sizeof(FSBB_Measure_Update_t)/sizeof(uint16_t);
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure_id = FSBB_MEASURE_SKIIP2_PCB_TEMPERATURE;
                        ((FSBB_Measure_Update_t *) &msg_received->payload)->measure = ((CAN_Open_2_Byte_Data_Decode_t*) &Evt_CAN_MSG->Data)->data;
                        buffer_index = buffer_index + msg_received->message_size + 2;
                        msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
                    }
                    break;
                default:
                    // unhandled message
                    break;
                }
            }
            break;
        case DBC_SKIIP_CAN_MSG_SKIIP1_MESSAGE_HEARTBEAT_FRAME_ID:
            msg_received->com_sig = COM_SIG_CAN_SKIIP_1_HEART_BEAT;
            msg_received->message_size = 0;
            buffer_index = buffer_index + msg_received->message_size + 2;
            msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            break;
        case DBC_SKIIP_CAN_MSG_SKIIP2_MESSAGE_HEARTBEAT_FRAME_ID:
            msg_received->com_sig = COM_SIG_CAN_SKIIP_2_HEART_BEAT;
            msg_received->message_size = 0;
            buffer_index = buffer_index + msg_received->message_size + 2;
            msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            break;
        default:
            break;
        }
        if( buffer_index < OC_CAN_MSG_BUFFER_SIZE ) me->msg_buffer[buffer_index] = COM_SIG_CAN_SKIIP_NOTHING;
    }else{
        // Invalid ID
    }
}
