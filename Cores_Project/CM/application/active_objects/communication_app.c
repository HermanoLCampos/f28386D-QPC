/*
 * communication_app.c
 *
 *  Created on: 23 de abr de 2024
 *      Author: ramon.martins
 */

#include "AOs/ao_communication/communication.h"
#include "board.h"
#include "cm.h"
#include "modulink.h"

static void Communication_send_default_message(Communication_Message_t * com_message, const com_tag_t * const com_tag);

void Communication_ipc_process_msg(Communication * const me,
    QEvt const * const e){
    uint16_t ID = Q_EVT_CAST(OC_Evt)->ID;
    Communication_Message_t* msg_to_process;


    if(ID == OC_IPC_CM_CPU1_ID){
        for(; me->ipc_inst[ID].n_msg_received > 0 ; me->ipc_inst[ID].n_msg_received--){
            msg_to_process = & me->ipc_inst[ID].msg_buffer[me->ipc_inst[ID].n_msg_received-1];
            if(msg_to_process->com_sig<=COM_SIG_IPC_CPU1_CM_MAX){
                switch(msg_to_process->com_sig){
                case COM_SIG_IPC_CPU1_CM_NOTHING:
                    // Nothing Here
                    break;
                // Change cases to perform better
                default:
                    Communication_send_default_message(msg_to_process,&com_signals_ipc_cpu1_cm[msg_to_process->com_sig]);
                    break;
                }
            }else{
                // Invalid Signal
            }
        }
    }else
#ifdef DUALCORE
    if(ID == OC_IPC_CM_CPU2_ID){
        for(; me->ipc_inst[ID].n_msg_received > 0 ; me->ipc_inst[ID].n_msg_received--){
            msg_to_process = & me->ipc_inst[ID].msg_buffer[me->ipc_inst[ID].n_msg_received-1];
            if(msg_to_process->com_sig<=COM_SIG_IPC_CPU2_CM_MAX){
                switch(msg_to_process->com_sig){
                case COM_SIG_IPC_CPU2_CM_NOTHING:
                    // Nothing Here
                    break;
                // Change cases to perform better
                default:
                    Communication_send_default_message(msg_to_process,&com_signals_ipc_cpu2_cm[msg_to_process->com_sig]);
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

void Communication_can_process_msg(Communication * const me,
    QEvt const * const e){
    uint16_t ID = Q_EVT_CAST(OC_Evt)->ID;
    Communication_Message_t * msg_received = (Communication_Message_t *) me->can_inst[ID].msg_buffer;
//    BSP_BKPT;
    for(uint16_t buffer_index = 0 ; buffer_index < OC_CAN_MSG_BUFFER_SIZE ; buffer_index = buffer_index + msg_received->message_size+2){
        msg_received = (Communication_Message_t *) ( ( (uint16_t *) me->can_inst[ID].msg_buffer ) + buffer_index);
        if(ID == OC_CAN_CAN_PUBLIC_ID){
            if(msg_received->com_sig < COM_SIG_CAN_PUBLIC_NOTHING){
                switch(msg_received->com_sig){
                default:
                    Communication_send_default_message(msg_received,&com_signals_can_public[msg_received->com_sig]);
                    break;
                }
            }else{
                if(msg_received->com_sig == COM_SIG_CAN_PUBLIC_NOTHING) break;
                //Invalid Com Signal

                break;
            }
        }else if(ID == OC_CAN_MCAN_ID){
            if(msg_received->com_sig < COM_SIG_MCAN_NOTHING){
                switch(msg_received->com_sig){
                default:
                    Communication_send_default_message(msg_received,&com_signals_mcan[msg_received->com_sig]);
                    break;
                }
            }else{
                if(msg_received->com_sig == COM_SIG_MCAN_NOTHING) break;
                //Invalid Com Signal

                break;
            }
        }else{
            break;
            //Invalid ID
        }

    }
}

void Communication_Can_Periodic_Msg(Communication * const me,
                                    QEvt const * const e){
    OC_Evt_CAN_Send_Message_t evt_can_msg = {
        .super = {
            .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
            .ID = OC_CAN_CAN_PUBLIC_ID,
        },
        .Message_Box_ID = 0,
        .Data = {0},
    };

    evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_VPU_FAULTS_1_INDEX;

    MODULINK_CAN_MSG_VPU_FAULTS_1_t * msg_payload = (MODULINK_CAN_MSG_VPU_FAULTS_1_t *) evt_can_msg.Data;
    msg_payload->CAN_SIG_VPU_CAPACITOR_OVERHEAT      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_CAPACITOR_OVERHEAT , me->sys_data.fsbb_data.faults.capacitor_overheat );
    msg_payload->CAN_SIG_VPU_CLA_T1_WATCHDOG_TIMEOUT = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_CLA_T1_WATCHDOG_TIMEOUT , me->sys_data.fsbb_data.faults.cla_t1_watchdog_timeout );
    msg_payload->CAN_SIG_VPU_CLA_T2_WATCHDOG_TIMEOUT = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_CLA_T2_WATCHDOG_TIMEOUT , me->sys_data.fsbb_data.faults.cla_t2_watchdog_timeout );
    msg_payload->CAN_SIG_VPU_EMERGENCY_SHUTDOWN      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_EMERGENCY_SHUTDOWN , me->sys_data.fsbb_data.faults.emergency_shutdown );
    msg_payload->CAN_SIG_VPU_INDUCTOR_OVERHEAT       = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_INDUCTOR_OVERHEAT , me->sys_data.fsbb_data.faults.inductor_overheat );
    msg_payload->CAN_SIG_VPU_SETTLE_TIMEOUT          = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SETTLE_TIMEOUT , me->sys_data.fsbb_data.faults.settle_timeout );
    msg_payload->CAN_SIG_VPU_SKIIP1_ERROR            = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP1_ERROR , me->sys_data.fsbb_data.faults.skiip1_error );
    msg_payload->CAN_SIG_VPU_SKIIP1_HALT             = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP1_HALT , me->sys_data.fsbb_data.faults.skiip1_halt );
    msg_payload->CAN_SIG_VPU_SKIIP1_OVERCURRENT      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP1_OVERCURRENT , me->sys_data.fsbb_data.faults.skiip1_overcurrent );
    msg_payload->CAN_SIG_VPU_SKIIP1_OVERHEAT         = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP1_OVERHEAT , me->sys_data.fsbb_data.faults.skiip1_overheat );
    msg_payload->CAN_SIG_VPU_SKIIP1_OVERVOLTAGE      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP1_OVERVOLTAGE , me->sys_data.fsbb_data.faults.skiip1_overvoltage );
    msg_payload->CAN_SIG_VPU_SKIIP2_ERROR            = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP2_ERROR , me->sys_data.fsbb_data.faults.skiip2_error );
    msg_payload->CAN_SIG_VPU_SKIIP2_HALT             = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP2_HALT , me->sys_data.fsbb_data.faults.skiip2_halt );
    msg_payload->CAN_SIG_VPU_SKIIP2_OVERCURRENT      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP2_OVERCURRENT , me->sys_data.fsbb_data.faults.skiip2_overcurrent );
    msg_payload->CAN_SIG_VPU_SKIIP2_OVERHEAT         = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP2_OVERHEAT , me->sys_data.fsbb_data.faults.skiip2_overheat );
    msg_payload->CAN_SIG_VPU_SKIIP2_OVERVOLTAGE      = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_FAULTS_1, CAN_SIG_VPU_SKIIP2_OVERVOLTAGE , me->sys_data.fsbb_data.faults.skiip2_overvoltage );

    QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );

}

static void Communication_send_default_message(Communication_Message_t * com_message, const com_tag_t * const com_tag){
    if(com_message->message_size==0){ //Imutable Event
        QACTIVE_POST(*com_tag->p_ao , com_tag->im_evt , (void *) 0);
    }else
    if(com_message->message_size*sizeof(uint16_t) <= ( sizeof(EvtPool1_t)-sizeof(QEvt)) ){
        // Mutable Event
        EvtPool1_t * evt_to_send = Q_NEW( EvtPool1_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_1_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size*sizeof(uint16_t) <= ( sizeof(EvtPool2_t)-sizeof(QEvt)) ){
        EvtPool2_t * evt_to_send = Q_NEW( EvtPool2_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_2_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size*sizeof(uint16_t) <= ( sizeof(EvtPool3_t)-sizeof(QEvt)) ){
        EvtPool3_t * evt_to_send = Q_NEW( EvtPool3_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_3_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else
    if(com_message->message_size*sizeof(uint16_t) <= ( sizeof(EvtPool4_t)-sizeof(QEvt)) ){
        EvtPool4_t * evt_to_send = Q_NEW( EvtPool4_t , com_tag->im_evt->sig);
        evt_to_send->payload = * ((evt_pool_payload_4_t *) &com_message->payload);
        QACTIVE_POST( *com_tag->p_ao , &evt_to_send->super , (void *)0);
    }else{
        BSP_BKPT;
        //Invalid Size of Data
    }
}
