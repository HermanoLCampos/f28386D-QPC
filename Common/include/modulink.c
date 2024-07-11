/************************************************************/
// Automatically generated C source file from CAN DBC file
// Source file name: modulink.dbc
// Date created: 2024-07-11
/************************************************************/


#include "application.h"
#include "modulink.h"
const MessageProprieties_t modulink_can_messages_proprieties[MODULINK_CAN_MAX_MSG] = {
    [MODULINK_CAN_MSG_EXT_IN_INDEX] = {
        .msg_id  = 0x00ff8300,
        .mask    = 0x1e000300,
        .msgType = CAN_MSG_OBJ_TYPE_RX,
        .flags   = CAN_MSG_OBJ_RX_INT_ENABLE|CAN_MSG_OBJ_USE_EXT_FILTER|CAN_MSG_OBJ_USE_ID_FILTER,
        .dlc     = 8,
            },
    [MODULINK_CAN_MSG_VPU_MEASURES_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_MEASURES_1_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_MEASURES_2_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_MEASURES_2_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_SETPOINTS_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_SETPOINTS_1_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_FAULTS_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_FAULTS_1_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_QSPY_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_QSPY_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_SYSTEM_STATUS_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_SYSTEM_STATUS_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
};

