/*
 * can_app.c
 *
 *  Created on: 26 de abr de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_can/oc_can.h"
#include "board.h"


uint32_t oc_can_base[OC_CAN_NUM_OF_INST] = {
    [OC_CAN_CAN_SKIIP_ID] = CAN_SKIIP_BASE,
};


void OC_CAN_send_msg(OC_CAN * const me,
    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t const * Evt_CAN_MSG = Q_EVT_CAST(OC_Evt_CAN_Send_Message_t);
    if(me->id == OC_CAN_CAN_SKIIP_ID){
        CAN_sendMessage(oc_can_base[OC_CAN_CAN_SKIIP_ID], Evt_CAN_MSG->Message_Box_ID, 8, Evt_CAN_MSG->Data);
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


//        case ????:
//        case ????:
//        buffer_index = buffer_index + msg_received->message_size + 2;
//        break;
        default:
            break;
        }
        if( buffer_index < OC_CAN_MSG_BUFFER_SIZE ) me->msg_buffer[buffer_index] = COM_SIG_CAN_SKIIP_NOTHING;
    }else{
        // Invalid ID
    }
}
