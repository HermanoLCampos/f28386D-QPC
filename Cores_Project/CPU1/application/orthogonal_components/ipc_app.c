/*
 * ipc_app.c
 *
 *  Created on: 25 de abr de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_ipc/oc_ipc.h"
#include "bsp_ipc.h"
#include "common_macros.h"

extern BSP_IPC_MessageQueue_t ipc_message_queue[OC_IPC_NUM_OF_INST];

void OC_IPC_send_msg(OC_IPC * const me,
    QEvt const * const e){

    BSP_IPC_Message_t msg;
    const OC_Evt_Communication_Message_t * com_msg = Q_EVT_CAST(OC_Evt_Communication_Message_t);

    *((Communication_Message_t *) msg.Payload) = com_msg->msg;

    if(
        !BSP_IPC_sendMessageToQueue(
            &ipc_message_queue[me->id],
            &msg,
            IPC_ADDR_CORRECTION_DISABLE,
            IPC_NONBLOCKING_CALL
        )
    ){
        QACTIVE_POST(
            me->owner,
            &im_evt_ipc_full_bus[me->id].super,
            (void *)0
        );
    }
}

void OC_IPC_receive_msg(OC_IPC * const me,
    QEvt const * const e){

    BSP_IPC_Message_t msg_receive;

    for( ; me->n_msg_received<BSP_IPC_BUFFER_SIZE ; me->n_msg_received++){
        if(
            !BSP_IPC_readMessageFromQueue(
                &ipc_message_queue[me->id],
                &msg_receive,
                IPC_ADDR_CORRECTION_DISABLE,
                IPC_NONBLOCKING_CALL
            )
        )
            break;
        me->msg_buffer[me->n_msg_received] = * ( (Communication_Message_t*)  &msg_receive);

    }

}
void OC_IPC_reset_ch(OC_IPC * const me,
    QEvt const * const e){

    ipc_message_queue[me->id].PutBuffer->GetReadIndex = 0;
    ipc_message_queue[me->id].PutBuffer->PutWriteIndex = 0;

    IPC_sendCommand(
        ipc_message_queue[me->id].ipcType,
        IPC_RESET_FLAG,
        IPC_ADDR_CORRECTION_DISABLE,
        OC_IPC_CMD_REMOTE_RESET,
        0,
        0
    );
}
void OC_IPC_remote_reset(OC_IPC * const me,
    QEvt const * const e){

    ipc_message_queue[me->id].PutBuffer->GetReadIndex = 0;
    ipc_message_queue[me->id].PutBuffer->PutWriteIndex = 0;

    IPC_sendCommand(
        ipc_message_queue[me->id].ipcType,
        IPC_RESET_FLAG,
        IPC_ADDR_CORRECTION_DISABLE,
        OC_IPC_CMD_RESET_COMPLETE,
        0,
        0
    );

}
