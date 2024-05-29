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
    [OC_CAN_CANA_ID] = CAN1_BASE,
    [OC_CAN_MCAN_ID] = MCAN_BASE,
};


void OC_CAN_send_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Send_Message_t);
    if(me->id == OC_CAN_MCAN_ID){
        // find out how to send msg by mcan
    }else{
        CAN_sendMessage(oc_can_base[OC_CAN_CANA_ID], Evt_CAN_MSG->Message_Box_ID, 8, Evt_CAN_MSG->Data);
    }
}
void OC_CAN_receive_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Message_Received_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Message_Received_t);

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

    }else if(me->id == OC_CAN_CANA_ID){
        uint16_t buffer_index = 0;
        Communication_Message_t * msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
        float decoded_sig;
        float sig_value;
        switch(Evt_CAN_MSG->Message_ID){
//===================================================================================
//============================Treat the messages received============================
//===================================================================================
        case MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU_FRAME_ID:
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CONTROL_START , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CONTROL_START, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_CONTROL_START;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CONTROL_STOP , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CONTROL_STOP, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_CONTROL_STOP;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_EMERGENCY_SHUTDOWN , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_EMERGENCY_SHUTDOWN, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_EMERGENCY_SHUTDOWN;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_PRECHARGE_START , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_PRECHARGE_START, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_PRECHARGE_START;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CLEAR_FAULT , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_CLEAR_FAULT, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_CLEAR_FAULT;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_SOFT_RESET , Evt_CAN_MSG->Data);
            sig_value = CAN_GET_VALUE_BY_NAME(MODULINK_CAN_MSG_IHM_COMMANDS_1_VPU , CAN_SIG_SOFT_RESET, CAN_VALUE_YES);
            if( decoded_sig == sig_value){
                msg_received->com_sig = COM_SIG_CANA_RESET;
                msg_received->message_size = 0;
                buffer_index = buffer_index + msg_received->message_size + 2;
                msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            }
            break;
        case MODULINK_CAN_MSG_IHM_SETPOINTS_1_VPU_FRAME_ID:

            msg_received->com_sig = COM_SIG_CANA_CHANGE_SETPOINT;
            msg_received->message_size = 3 + (sizeof(Setpoint_Data_t)+1)/sizeof(uint16_t);
            ((OC_Evt_Communication_Message_t *) msg_received)->super.ID = OC_IPC_CM_CPU1_ID;
            ((OC_Evt_Communication_Message_t *) msg_received)->msg.com_sig = COM_SIG_IPC_CM_CPU1_CHANGE_SETPOINT;
            ((OC_Evt_Communication_Message_t *) msg_received)->msg.message_size = 3;

            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_SETPOINTS_1_VPU, CAN_SIG_SETPOINT_ID, Evt_CAN_MSG->Data);
            ((Setpoint_Data_t *) &((OC_Evt_Communication_Message_t *) msg_received)->msg.payload)->setpoint_id = decoded_sig;

            decoded_sig = CAN_SIG_DECODE(MODULINK_CAN_MSG_IHM_SETPOINTS_1_VPU, CAN_SIG_SETPOINT_REQUESTED, Evt_CAN_MSG->Data);
            ((Setpoint_Data_t *) &((OC_Evt_Communication_Message_t *) msg_received)->msg.payload)->setpoint_value = decoded_sig*100.0;

            buffer_index = buffer_index + msg_received->message_size + 2;
            msg_received = (Communication_Message_t *) (((uint16_t *) me->msg_buffer)+buffer_index);
            break;
        default:
            break;
        }
        if( buffer_index < OC_CAN_MSG_BUFFER_SIZE ) me->msg_buffer[buffer_index] = COM_SIG_CANA_NOTHING;
    }else{
//        Invalid ID
    }
}
