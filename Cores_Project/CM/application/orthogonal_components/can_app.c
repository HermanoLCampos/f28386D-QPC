/*
 * can_app.c
 *
 *  Created on: 26 de abr de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_can/oc_can.h"
#include "board.h"
#include "cm.h"
#include "modulink.h"


uint32_t oc_can_base[OC_CAN_NUM_OF_INST] = {
    [OC_CAN_CAN_PUBLIC_ID] = CAN_PUBLIC_BASE,
    [OC_CAN_MCAN_ID] = MCAN_BASE,
};


void OC_CAN_send_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Send_Message_t);
    if(me->id == OC_CAN_MCAN_ID){
        // find out how to send msg by mcan
    }else{
        CAN_sendMessage(oc_can_base[OC_CAN_CAN_PUBLIC_ID], Evt_CAN_MSG->Message_Box_ID, 8, (uint8_t *) Evt_CAN_MSG->Data);
    }
}
void OC_CAN_receive_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Message_Received_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Message_Received_t);

    Can_Payload_t can_payload = {
        .full_payload = *((uint64_t *) Evt_CAN_MSG->Data)
    };

    if(me->id == OC_CAN_MCAN_ID){
        uint16_t buffer_index = 0;
        Communication_Message_t * msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
        switch(Evt_CAN_MSG->Message_ID){
//===================================================================================
//============================Treat the messages received============================
//===================================================================================

//        case ???:
//        case ???:
//            buffer_index = buffer_index + msg_received->message_size + 2;
//            break;
        default:
            break;
        }
        if( buffer_index < OC_CAN_MSG_BUFFER_SIZE ) me->msg_buffer[buffer_index] = COM_SIG_MCAN_NOTHING;

    }else if(me->id == OC_CAN_CAN_PUBLIC_ID){
        uint16_t buffer_index = 0;
        Communication_Message_t * msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);

        switch(Evt_CAN_MSG->Message_ID){
//===================================================================================
//============================Treat the messages received============================
//===================================================================================
        case MODULINK_CAN_MSG_VPU_COMMANDS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB_FRAME_ID & 0x00FFFF00:{

            uint16_t named_value_read;
            uint16_t named_value_yes;

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CONTROL_START , can_payload.byte_data );
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CONTROL_START , MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_CONTROL_START;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CONTROL_STOP , can_payload.byte_data);
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CONTROL_STOP, MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_CONTROL_STOP;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_EMERGENCY_SHUTDOWN , can_payload.byte_data );
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_EMERGENCY_SHUTDOWN , MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_EMERGENCY_SHUTDOWN;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_PRECHARGE_START , can_payload.byte_data );
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_PRECHARGE_START , MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_PRECHARGE_START;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CLEAR_FAULT , can_payload.byte_data );
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_CLEAR_FAULT , MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_CLEAR_FAULT;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }

            named_value_read = CAN_GET_ENCODED_VALUE(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_SOFT_RESET , can_payload.byte_data );
            named_value_yes  = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_FSBB , MODULINK_CAN_SIG_SOFT_RESET , MODULINK_CAN_VALUE_YES);
            if( named_value_read == named_value_yes){
                msg_received->com_sig = COM_SIG_CAN_PUBLIC_RESET;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            break;
        }
        case MODULINK_CAN_MSG_VPU_SETPOINTS_1_FSBB_FRAME_ID & 0x00FFFF00:
        case MODULINK_CAN_MSG_IHM_SETPOINTS_1_FSBB_FRAME_ID & 0x00FFFF00:{

            float decoded_sig;

            msg_received->com_sig = COM_SIG_CAN_PUBLIC_CHANGE_SETPOINT;
            msg_received->message_size = 3 + (sizeof(Setpoint_Data_t)+1)/sizeof(uint16_t);
            ((OC_Evt_Communication_Message_t *) msg_received)->super.ID = OC_IPC_CM_CPU1_ID;
            ((OC_Evt_Communication_Message_t *) msg_received)->msg.com_sig = COM_SIG_IPC_CM_CPU1_CHANGE_SETPOINT;
            ((OC_Evt_Communication_Message_t *) msg_received)->msg.message_size = 3;

            decoded_sig = CAN_GET_DECODED_VALUE(MODULINK_CAN_MSG_IHM_SETPOINTS_1_FSBB , MODULINK_CAN_SIG_SETPOINT_ID , can_payload.byte_data );
            ((Setpoint_Data_t *) &((OC_Evt_Communication_Message_t *) msg_received)->msg.payload)->setpoint_id = decoded_sig;

            decoded_sig = CAN_GET_DECODED_VALUE(MODULINK_CAN_MSG_IHM_SETPOINTS_1_FSBB , MODULINK_CAN_SIG_SETPOINT_REQUESTED , can_payload.byte_data );
            ((Setpoint_Data_t *) &((OC_Evt_Communication_Message_t *) msg_received)->msg.payload)->setpoint_value = decoded_sig;

            buffer_index = buffer_index + msg_received->message_size + 2;
            msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            break;
        }
        default:
            break;
        }
        if( buffer_index < OC_CAN_MSG_BUFFER_SIZE ) me->msg_buffer[buffer_index] = COM_SIG_CAN_PUBLIC_NOTHING;
    }else{
//        Invalid ID
    }
}
