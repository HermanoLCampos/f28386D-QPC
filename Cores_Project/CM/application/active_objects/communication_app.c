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

#include "cpu1_cm_memory_shared.h"

CPU1_CM_Message_t * CPU1_CM_Message;

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

void Communication_Can_Periodic_Msg(Communication * const me){
    OC_Evt_CAN_Send_Message_t evt_can_msg = {
        .super = {
            .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
            .ID = OC_CAN_CAN_PUBLIC_ID,
        },
        .Message_Box_ID = 0,
        .Data = {0},
    };


    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_FAULTS_1_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_CAPACITOR_OVERHEAT        , can_payload.byte_data , me->sys_data.fsbb_data.faults.capacitor_overheat       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_CLA_T1_WATCHDOG_TIMEOUT   , can_payload.byte_data , me->sys_data.fsbb_data.faults.cla_t1_watchdog_timeout  );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_CLA_T2_WATCHDOG_TIMEOUT   , can_payload.byte_data , me->sys_data.fsbb_data.faults.cla_t2_watchdog_timeout  );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_EMERGENCY_SHUTDOWN        , can_payload.byte_data , me->sys_data.fsbb_data.faults.emergency_shutdown       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_INDUCTOR_OVERHEAT         , can_payload.byte_data , me->sys_data.fsbb_data.faults.inductor_overheat        );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SETTLE_TIMEOUT            , can_payload.byte_data , me->sys_data.fsbb_data.faults.settle_timeout           );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_ERROR              , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_error             );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_HALT               , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_halt              );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_OVERCURRENT        , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_overcurrent       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_OVERHEAT           , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_overheat          );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_OVERVOLTAGE        , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_overvoltage       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP1_CARDIAC_ARRREST    , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip1_cardiac_arrest    );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_ERROR              , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_error             );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_HALT               , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_halt              );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_OVERCURRENT        , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_overcurrent       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_OVERHEAT           , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_overheat          );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_OVERVOLTAGE        , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_overvoltage       );
        CAN_WRITE_ENCODED_VALUE( MODULINK_CAN_MSG_FSBB_FAULTS_1 , MODULINK_CAN_SIG_SKIIP2_CARDIAC_ARRREST    , can_payload.byte_data , me->sys_data.fsbb_data.faults.skiip2_cardiac_arrest    );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

//    {
//        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_VPU_MEASURES_1_INDEX;
//        MODULINK_CAN_MSG_VPU_MEASURES_1_t * msg_payload = (MODULINK_CAN_MSG_VPU_MEASURES_1_t *) evt_can_msg.Data;
//        msg_payload->CAN_SIG_VPU_SKIIP_1_CURRENT = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_MEASURES_1 , CAN_SIG_VPU_SKIIP_1_CURRENT, CPU1_CM_Message->skiip1_current );
//        msg_payload->CAN_SIG_VPU_SKIIP_1_VOLTAGE = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_MEASURES_1 , CAN_SIG_VPU_SKIIP_1_VOLTAGE, CPU1_CM_Message->skiip1_voltage );
//        msg_payload->CAN_SIG_VPU_SKIIP_2_CURRENT = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_MEASURES_1 , CAN_SIG_VPU_SKIIP_2_CURRENT, CPU1_CM_Message->skiip2_current );
//        msg_payload->CAN_SIG_VPU_SKIIP_2_VOLTAGE = CAN_SIG_ENCODE(MODULINK_CAN_MSG_VPU_MEASURES_1 , CAN_SIG_VPU_SKIIP_2_VOLTAGE, CPU1_CM_Message->skiip2_voltage );
//
//        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
//    }

    {

        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_SETPOINTS_1_INDEX;


        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_SETPOINTS_1 , MODULINK_CAN_SIG_IND_CURRENT_SP , can_payload.byte_data , CPU1_CM_Message->FSBB_IL_Setpoint);
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_SETPOINTS_1 , MODULINK_CAN_SIG_POWER_SP       , can_payload.byte_data , 0 );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }


    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_RESPONSE_VPU_INDEX;

        Can_Payload_t can_payload = {0};

        switch(me->sys_data.fsbb_data.state){
        case FSBB_ERROR:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_ERROR);
            break;
        case FSBB_STOPPING:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_STOPPING);
            break;
        case FSBB_INIT:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_INIT);
            break;
        case FSBB_READY:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_READY);
            break;
        case FSBB_RUNNING:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_RUNNING);
            break;
        case FSBB_IN_PRECHARGE:
            CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_RESPONSE_VPU , MODULINK_CAN_SIG_STATE , can_payload.byte_data , MODULINK_CAN_VALUE_IN_PRECHARGE);
            break;
        }

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_3_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_3 , MODULINK_CAN_SIG_SKIIP1_ANALOG_TEMP      , can_payload.byte_data , CPU1_CM_Message->skiip1_temp/10.0f );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_3 , MODULINK_CAN_SIG_SKIIP1_DCB_TEMPERATURE  , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_SKIIP1_DCB_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_3 , MODULINK_CAN_SIG_SKIIP1_PCB_TEMPERATURE  , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_SKIIP1_PCB_TEMPERATURE] );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_4_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_4 , MODULINK_CAN_SIG_SKIIP2_ANALOG_TEMP      , can_payload.byte_data , CPU1_CM_Message->skiip2_temp/10.0f );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_4 , MODULINK_CAN_SIG_SKIIP2_DCB_TEMPERATURE  , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_SKIIP2_DCB_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_4 , MODULINK_CAN_SIG_SKIIP2_PCB_TEMPERATURE  , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_SKIIP2_PCB_TEMPERATURE] );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_5_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_5 , MODULINK_CAN_SIG_CAPACITOR_1_TEMP       , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDA1_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_5 , MODULINK_CAN_SIG_INDUCTOR_1_TEMP_1      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDA2_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_5 , MODULINK_CAN_SIG_INDUCTOR_1_TEMP_2      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDA3_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_5 , MODULINK_CAN_SIG_INDUCTOR_1_TEMP_3      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDA4_TEMPERATURE] );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_6_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_6 , MODULINK_CAN_SIG_CAPACITOR_2_TEMP       , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDB1_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_6 , MODULINK_CAN_SIG_INDUCTOR_2_TEMP_1      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDB2_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_6 , MODULINK_CAN_SIG_INDUCTOR_2_TEMP_2      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDB3_TEMPERATURE] );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_6 , MODULINK_CAN_SIG_INDUCTOR_2_TEMP_3      , can_payload.byte_data , CPU1_CM_Message->fsbb_temp_measures[FSBB_MEASURE_RTDB4_TEMPERATURE] );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

}

void Communication_Can_Periodic_Msg_Control(Communication * const me){

    OC_Evt_CAN_Send_Message_t evt_can_msg = {
        .super = {
            .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
            .ID = OC_CAN_CAN_PUBLIC_ID,
        },
        .Message_Box_ID = 0,
        .Data = {0},
    };

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_1_INDEX;

        Can_Payload_t can_payload = {0};


        CAN_WRITE_DECODED_VALUE(MODULINK_CAN_MSG_FSBB_MEASURES_1 , MODULINK_CAN_SIG_SKIIP_1_CURRENT , can_payload.byte_data , (CPU1_CM_Message->skiip1_current*0.1f) );
        CAN_WRITE_DECODED_VALUE(MODULINK_CAN_MSG_FSBB_MEASURES_1 , MODULINK_CAN_SIG_SKIIP_1_VOLTAGE , can_payload.byte_data , (CPU1_CM_Message->skiip1_voltage*0.1f) );
        CAN_WRITE_DECODED_VALUE(MODULINK_CAN_MSG_FSBB_MEASURES_1 , MODULINK_CAN_SIG_SKIIP_2_CURRENT , can_payload.byte_data , (CPU1_CM_Message->skiip2_current*0.1f) );
        CAN_WRITE_DECODED_VALUE(MODULINK_CAN_MSG_FSBB_MEASURES_1 , MODULINK_CAN_SIG_SKIIP_2_VOLTAGE , can_payload.byte_data , (CPU1_CM_Message->skiip2_voltage*0.1f) );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }


    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_MEASURES_2_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_2 , MODULINK_CAN_SIG_D_VIN  , can_payload.byte_data , (   CPU1_CM_Message->D_VIN*0.001   ) );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_2 , MODULINK_CAN_SIG_D_VOUT , can_payload.byte_data , (   CPU1_CM_Message->D_VOUT*0.001  ) );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_2 , MODULINK_CAN_SIG_I_COMP , can_payload.byte_data , (CPU1_CM_Message->I_COMP*0.1-100.0f) );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_2 , MODULINK_CAN_SIG_P_COMP , can_payload.byte_data , (CPU1_CM_Message->P_COMP*0.1-100.0f) );
        CAN_WRITE_DECODED_VALUE( MODULINK_CAN_MSG_FSBB_MEASURES_2 , MODULINK_CAN_SIG_VL     , can_payload.byte_data , ( CPU1_CM_Message->V_L*0.001-10.0f ) );

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

}

void Communication_start_precharge(Communication * const me){

    OC_Evt_CAN_Send_Message_t evt_can_msg = {
        .super = {
            .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
            .ID = OC_CAN_CAN_PUBLIC_ID,
        },
        .Message_Box_ID = 0,
        .Data = {0},
    };

    {
        evt_can_msg.Message_Box_ID = MODULINK_CAN_MSG_FSBB_COMMAND_SMU_INDEX;

        Can_Payload_t can_payload = {0};

        CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_COMMAND_SMU , MODULINK_CAN_SIG_COMMUNICATION_ID , can_payload.byte_data , MODULINK_CAN_VALUE_PRECHARGE);
        CAN_WRITE_NAMED_VALUE(MODULINK_CAN_MSG_FSBB_COMMAND_SMU , MODULINK_CAN_SIG_PAYLOAD , can_payload.byte_data , MODULINK_CAN_VALUE_START_PRECHARGE);

        *((uint64_t *) evt_can_msg.Data) = can_payload.full_payload;

        QASM_DISPATCH( &(me->can_inst[evt_can_msg.super.ID].super), &evt_can_msg.super.super , (void *) 0 );
    }

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
