/************************************************************/
// Automatically generated C source file from CAN DBC file
// Source file name: modulink.dbc
// Date created: 2024-10-01
/************************************************************/


#include "application.h"
#include "modulink.h"


const MessageProprieties_t modulink_can_messages_proprieties[MODULINK_CAN_MAX_MSG] = {
    [MODULINK_CAN_MSG_EXT_IN_INDEX] = {
        .msg_id     = 0x00fffffe,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type   = CAN_MSG_OBJ_TYPE_RX,
        .mask       = 0x1e00fffe,
        .flags      = CAN_MSG_OBJ_RX_INT_ENABLE|CAN_MSG_OBJ_USE_EXT_FILTER|CAN_MSG_OBJ_USE_ID_FILTER,
        .dlc        = 8,
            },
    [MODULINK_CAN_MSG_FSBB_RESPONSE_VPU_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_RESPONSE_VPU_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_FSBB_MEASURES_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_MEASURES_1_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_FSBB_MEASURES_2_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_MEASURES_2_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_FSBB_SETPOINTS_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_SETPOINTS_1_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_FSBB_FAULTS_1_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_FAULTS_1_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_TO_QSPY_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_TO_QSPY_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
    [MODULINK_CAN_MSG_FSBB_COMMAND_SMU_INDEX] = {
        .msg_id = MODULINK_CAN_MSG_FSBB_COMMAND_SMU_FRAME_ID,
        .frame_type = CAN_MSG_FRAME_EXT,
        .msg_type= CAN_MSG_OBJ_TYPE_TX,
        .mask   = 0x00000000,
        .flags  = CAN_MSG_OBJ_NO_FLAGS,
        .dlc    = 8,
    },
};

