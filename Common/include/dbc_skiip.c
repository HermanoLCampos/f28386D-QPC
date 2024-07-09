/************************************************************/
// Automatically generated C source file from CAN DBC file
// Source file name: dbc_skiip.dbc
// Date created: 2024-07-09
/************************************************************/


#include "application.h"
#include "dbc_skiip.h"
const MessageProprieties_t dbc_skiip_can_messages_proprieties[DBC_SKIIP_CAN_MAX_MSG] = {
    [DBC_SKIIP_CAN_MSG_STD_IN_INDEX] = {
        .msg_id  = 0x07ad,
        .mask    = 0x0281,
        .msgType = CAN_MSG_OBJ_TYPE_RX,
        .flags   = CAN_MSG_OBJ_RX_INT_ENABLE|CAN_MSG_OBJ_USE_ID_FILTER,
        .dlc     = 8,
            },
    [DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_INDEX] = {
        .msg_id = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP1_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_INDEX] = {
        .msg_id = DBC_SKIIP_CAN_MSG_VPU_MESSAGE_SKIIP2_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [DBC_SKIIP_CAN_MSG_CHANGE_CAN_OPEN_STATE_INDEX] = {
        .msg_id = DBC_SKIIP_CAN_MSG_CHANGE_CAN_OPEN_STATE_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
};

