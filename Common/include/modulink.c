/************************************************************/
// Automatically generated C source file from CAN DBC file
// Source file name: modulink.dbc
// Date created: 2024-06-24
/************************************************************/


#include "application.h"
#include "modulink.h"
const MessageProprieties_t modulink_can_messages_proprieties[MODULINK_CAN_MAX_MSG] = {
    [MODULINK_CAN_MSG_IN_1_INDEX] = {
        .msg_id  = 0x00ff0f00,
        .mask    = 0x1f000fff,
        .msgType = CAN_MSG_OBJ_TYPE_RX,
        .flags   = CAN_MSG_OBJ_RX_INT_ENABLE|CAN_MSG_OBJ_USE_EXT_FILTER,
        .dlc     = 8,
    },
    [MODULINK_CAN_MSG_IN_2_INDEX] = {
        .msg_id  = 0x00ff0f00,
        .mask    = 0x1f000fff,
        .msgType = CAN_MSG_OBJ_TYPE_RX,
        .flags   = CAN_MSG_OBJ_RX_INT_ENABLE|CAN_MSG_OBJ_USE_EXT_FILTER,
        .dlc     = 8,
    },
    [MODULINK_CAN_MSG_VPU_MEASURES_1_IHM_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_MEASURES_1_IHM_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_MEASURES_2_IHM_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_MEASURES_2_IHM_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_SETPOINTS_1_IHM_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_SETPOINTS_1_IHM_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_FAULTS_1_IHM_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_FAULTS_1_IHM_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_VPU_QSPY_IHM_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_VPU_QSPY_IHM_FRAME_ID,
        .mask   = 0x00000000,
        .msgType= CAN_MSG_OBJ_TYPE_TX,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
};

