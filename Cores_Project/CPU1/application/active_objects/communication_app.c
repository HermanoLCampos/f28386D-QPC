/*
 * communication_app.c
 *
 *  Created on: 23 de abr de 2024
 *      Author: ramon.martins
 */

#include "AOs/ao_communication/communication.h"
#include "dbc_skiip.h"

static void Communication_send_default_message(Communication_Message_t * com_message, const com_tag_t * const com_tag);

void Communication_ipc_process_msg(Communication * const me,
    QEvt const * const e){
    uint16_t ID = Q_EVT_CAST(OC_Evt)->ID;
    Communication_Message_t* msg_to_process;


    if(ID == OC_IPC_CPU1_CM_ID){
        for(; me->ipc_inst[ID].n_msg_received > 0 ; me->ipc_inst[ID].n_msg_received--){
            msg_to_process = & me->ipc_inst[ID].msg_buffer[me->ipc_inst[ID].n_msg_received-1];
            if(msg_to_process->com_sig<=COM_SIG_IPC_CM_CPU1_MAX){
                switch(msg_to_process->com_sig){
                case COM_SIG_IPC_CM_CPU1_NOTHING:
                    // Nothing Here
                    break;
                // Change cases to perform better
                default:
                    Communication_send_default_message(msg_to_process,&com_signals_ipc_cm_cpu1[msg_to_process->com_sig]);
                    break;
                }
            }else{
                // Invalid Signal
            }
        }
    }else
#ifdef DUALCORE
        if(ID == OC_IPC_CPU1_CPU2_ID){
        for(; me->ipc_inst[ID].n_msg_received > 0 ; me->ipc_inst[ID].n_msg_received--){
            msg_to_process = & me->ipc_inst[ID].msg_buffer[me->ipc_inst[ID].n_msg_received-1];
            if(msg_to_process->com_sig<=COM_SIG_IPC_CPU2_CPU1_MAX){
                switch(msg_to_process->com_sig){
                case COM_SIG_IPC_CPU2_CPU1_NOTHING:
                    // Nothing Here
                    break;
                // Change cases to perform better
                default:
                    Communication_send_default_message(msg_to_process,&com_signals_ipc_cpu2_cpu1[msg_to_process->com_sig]);
                    break;
                }
            }else{
                // Invalid Signal
            }
        }
    }else
#endif
    {
        //Invalid ID
    }

}

void Communication_skiip_can_open_config(Communication * const me){
    OC_Evt_CAN_Send_Message_t evt_to_send;

    evt_to_send.super = im_evt_can_send_msg[OC_CAN_CAN_SKIIP_ID];
    evt_to_send.Message_Box_ID = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX;

    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->header    = 0x2B;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_PRODUCER_HEARTBEAT);
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex = 0x00;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->data = SKIIP_HEARTBEAT_TIMEOUT_MS*0.5;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->reserved = 0x0000;

    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    evt_to_send.Message_Box_ID = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX;

    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->header    = 0x2B;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_PRODUCER_HEARTBEAT);
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex = 0x00;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->data = SKIIP_HEARTBEAT_TIMEOUT_MS*0.5;
    ((CAN_Open_2_Byte_Data_Decode_t *) &evt_to_send.Data)->reserved = 0x0000;

    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );
}

void Communication_update_measure_request(Communication * const me,
    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t evt_to_send;

    evt_to_send.super = im_evt_can_send_msg[OC_CAN_CAN_SKIIP_ID];
    evt_to_send.Message_Box_ID = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX;
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->header    = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_HEADER , CAN_VALUE_READ_DEFAULT);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->data  = 0;


    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_DCB);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 1;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_PCB);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 0;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1 , CAN_SIG_VPU_TO_SKIIP1_OBJ_ID , CAN_VALUE_OBJ_NUMBER_ERROR_STATE);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 0;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    evt_to_send.Message_Box_ID = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX;

    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_DCB);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 1;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_TEMPERATURE_PCB);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 0;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->object_id = CAN_GET_VALUE_BY_NAME( DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2 , CAN_SIG_VPU_TO_SKIIP2_OBJ_ID , CAN_VALUE_OBJ_NUMBER_ERROR_STATE);
    ((CAN_Open_4_Byte_Data_Decode_t *) &evt_to_send.Data)->subindex  = 0;
    QASM_DISPATCH( &(me->can_inst[OC_CAN_CAN_SKIIP_ID].super) ,&evt_to_send.super.super, (void *) 0 );

}

void Communication_can_process_msg(Communication * const me,
    QEvt const * const e){
    uint16_t ID = Q_EVT_CAST(OC_Evt)->ID;
    Communication_Message_t * msg_received = (Communication_Message_t *) me->can_inst[ID].msg_buffer;
    for(uint16_t buffer_index = 0 ; buffer_index < OC_CAN_MSG_BUFFER_SIZE ; buffer_index = buffer_index + msg_received->message_size+2){
        msg_received = (Communication_Message_t *) ( ( (uint16_t *) me->can_inst[ID].msg_buffer ) + buffer_index);
        if(ID == OC_CAN_CAN_SKIIP_ID){
            if(msg_received->com_sig < COM_SIG_CAN_SKIIP_NOTHING){
                switch(msg_received->com_sig){
                default:
                    Communication_send_default_message(msg_received,&com_signals_can_skiip[msg_received->com_sig]);
                    break;
                }
            }else{
                if(msg_received->com_sig == COM_SIG_CAN_SKIIP_NOTHING) break;
                //Invalid Com Signal

                break;
            }
        }else{
            break;
            //Invalid ID
        }
    }
}

static void Communication_send_default_message(Communication_Message_t * com_message, const com_tag_t * const com_tag){
    if(com_message->message_size==0){ //Imutable Event
        QACTIVE_POST(*com_tag->p_ao , com_tag->im_evt , (void *) 0);
    }else
    if(com_message->message_size <= ( sizeof(EvtPool1_t)-sizeof(QEvt)) ){
        // Mutable Event
        EvtPool1_t * evt_to_send = Q_NEW( EvtPool1_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_1_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size <= ( sizeof(EvtPool2_t)-sizeof(QEvt)) ){
        EvtPool2_t * evt_to_send = Q_NEW( EvtPool2_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_2_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size <= ( sizeof(EvtPool3_t)-sizeof(QEvt)) ){
        EvtPool3_t * evt_to_send = Q_NEW( EvtPool3_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_3_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size <= ( sizeof(EvtPool4_t)-sizeof(QEvt)) ){
        EvtPool4_t * evt_to_send = Q_NEW( EvtPool4_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_4_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else{
        //Invalid Size of Data
    }
}
