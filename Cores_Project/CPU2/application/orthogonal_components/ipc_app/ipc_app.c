/*
 * ipc_app.c
 *
 *  Created on: 25 de abr de 2024
 *      Author: ramon.martins
 */

#include "./ipc_app.h"
#include "bsp_ipc.h"

extern BSP_IPC_MessageQueue_t ipc_message_queue[OC_IPC_NUM_OF_INST];

bool oc_ipc_send_message(uint16_t * p_msg , uint16_t oc_id){
    BSP_IPC_Message_t * p_msg_to_send = (BSP_IPC_Message_t *)p_msg;
    return BSP_IPC_sendMessageToQueue(&ipc_message_queue[oc_id], p_msg_to_send, IPC_ADDR_CORRECTION_DISABLE , IPC_NONBLOCKING_CALL);
}
bool oc_ipc_receive_message(uint16_t * p_msg , uint16_t oc_id){
    BSP_IPC_Message_t * p_msg_to_receive = (BSP_IPC_Message_t *)p_msg;
    return BSP_IPC_readMessageFromQueue(&ipc_message_queue[oc_id], p_msg_to_receive, IPC_ADDR_CORRECTION_DISABLE , IPC_NONBLOCKING_CALL);
}

void oc_ipc_reset_ch(uint16_t oc_id){
    IPC_sendCommand(
        ipc_message_queue[oc_id].ipcType,
        IPC_RESET_FLAG,
        IPC_ADDR_CORRECTION_DISABLE,
        OC_IPC_CMD_REMOTE_RESET,
        0,
        0
    );
}

void oc_ipc_reset_complete(uint16_t oc_id){
    IPC_sendCommand(
        ipc_message_queue[oc_id].ipcType,
        IPC_RESET_FLAG,
        IPC_ADDR_CORRECTION_DISABLE,
        OC_IPC_CMD_RESET_COMPLETE,
        0,
        0
    );
}
