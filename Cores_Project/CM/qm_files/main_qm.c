//$file${.::Cores_Project::CM::qm_files::main_qm.c} vvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CM::qm_files::main_qm.c}
//
// This code has been generated by QM 6.1.1 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${.::Cores_Project::CM::qm_files::main_qm.c} ^^^^^^^^^^^^^^^^^^^^^^^
#include "main_qm.h"

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${Shared} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//$enddef${Shared} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${CM::Immutable_Events} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::Immutable_Events::General::im_evt_running_qf} ........................
QEvt const im_evt_running_qf = QEVT_INITIALIZER(RUNNING_QF_SIG);

//${CM::Immutable_Events::General::im_evt_init_complete} .....................
QEvt const im_evt_init_complete = QEVT_INITIALIZER(INIT_COMPLETE_SIG);

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_reset_ch[OC_IPC_NUM_O~}
OC_Evt const im_evt_ipc_reset_ch[OC_IPC_NUM_OF_INST] ={
    [OC_IPC_CM_CPU1_ID] = {
        .super = QEVT_INITIALIZER(IPC_RESET_CH_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
#ifdef DUALCORE
    [OC_IPC_CM_CPU2_ID] = {
        .super = QEVT_INITIALIZER(IPC_RESET_CH_SIG),
        .ID = OC_IPC_CM_CPU2_ID,
    },
#endif
};

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_reset_complete[OC_IPC~}
OC_Evt const im_evt_ipc_reset_complete[OC_IPC_NUM_OF_INST] ={
    [OC_IPC_CM_CPU1_ID] = {
        .super = QEVT_INITIALIZER(IPC_RESET_COMPLETE_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
#ifdef DUALCORE
    [OC_IPC_CM_CPU2_ID] = {
        .super = QEVT_INITIALIZER(IPC_RESET_COMPLETE_SIG),
        .ID = OC_IPC_CM_CPU2_ID,
    },
#endif
};

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_receive_msg[OC_IPC_NU~}
OC_Evt const im_evt_ipc_receive_msg[OC_IPC_NUM_OF_INST] ={
    [OC_IPC_CM_CPU1_ID] = {
        .super = QEVT_INITIALIZER(IPC_RECEIVE_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
#ifdef DUALCORE
    [OC_IPC_CM_CPU2_ID] = {
        .super = QEVT_INITIALIZER(IPC_RECEIVE_MSG_SIG),
        .ID = OC_IPC_CM_CPU2_ID,
    },
#endif
};

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_full_bus[OC_IPC_NUM_O~}
OC_Evt const im_evt_ipc_full_bus[OC_IPC_NUM_OF_INST] ={
    [OC_IPC_CM_CPU1_ID] = {
        .super = QEVT_INITIALIZER(IPC_FULL_BUS_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
#ifdef DUALCORE
    [OC_IPC_CM_CPU2_ID] = {
        .super = QEVT_INITIALIZER(IPC_FULL_BUS_SIG),
        .ID = OC_IPC_CM_CPU2_ID,
    },
#endif
};

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_remote_reset[OC_IPC_N~}
OC_Evt const im_evt_ipc_remote_reset[OC_IPC_NUM_OF_INST] ={
    [OC_IPC_CM_CPU1_ID] = {
        .super = QEVT_INITIALIZER(IPC_REMOTE_RESET_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
#ifdef DUALCORE
    [OC_IPC_CM_CPU2_ID] = {
        .super = QEVT_INITIALIZER(IPC_REMOTE_RESET_SIG),
        .ID = OC_IPC_CM_CPU2_ID,
    },
#endif
};

//${CM::Immutable_Events::Communication::CAN::im_evt_can_send_msg[OC_CAN_NUM_O~}
OC_Evt const im_evt_can_send_msg[OC_CAN_NUM_OF_INST] ={
    [OC_CAN_CAN_PUBLIC_ID] = {
        .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
        .ID = OC_CAN_CAN_PUBLIC_ID,
    },
    [OC_CAN_MCAN_ID] = {
        .super = QEVT_INITIALIZER(CAN_SEND_MSG_SIG),
        .ID = OC_CAN_MCAN_ID,
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_start_control} .....................
OC_Evt_Communication_Message_t const im_evt_start_control = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_CONTROL_START,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_stop_control} ......................
OC_Evt_Communication_Message_t const im_evt_stop_control = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_CONTROL_STOP,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_emergency_shutdown} ................
OC_Evt_Communication_Message_t const im_evt_emergency_shutdown = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_EMERGENCY_SHUTDOWN,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_precharge_start} ...................
OC_Evt_Communication_Message_t const im_evt_precharge_start = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_PRECHARGE_START,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_clear_fault} .......................
OC_Evt_Communication_Message_t const im_evt_clear_fault = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_CLEAR_FAULT,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_reset} .............................
OC_Evt_Communication_Message_t const im_evt_reset = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_RESET,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::To CPU1::im_evt_change_setpoint} ...................
OC_Evt_Communication_Message_t const im_evt_change_setpoint = {
    .super = {
        .super = QEVT_INITIALIZER(IPC_SEND_MSG_SIG),
        .ID = OC_IPC_CM_CPU1_ID,
    },
    .msg = {
        .com_sig = COM_SIG_IPC_CM_CPU1_CHANGE_SETPOINT,
        .message_size = 0,
        .payload = {0}
    }
};

//${CM::Immutable_Events::From CPU1::im_evt_update_fsbb_data} ................
QEvt const im_evt_update_fsbb_data = QEVT_INITIALIZER(UPDATE_FSBB_DATA_SIG);
//$enddef${CM::Immutable_Events} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${CM::Signals} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::Signals::com_signals_ipc_cpu1_cm[COM_SIG_~} ..........................
const com_tag_t com_signals_ipc_cpu1_cm[COM_SIG_IPC_CPU1_CM_MAX] ={
    [COM_SIG_IPC_CPU1_CM_SEND_CAN_PUBLIC_MSG] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_can_send_msg[OC_CAN_CAN_PUBLIC_ID].super,
    },
    [COM_SIG_IPC_CPU1_CM_SEND_MCAN_MSG] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_can_send_msg[OC_CAN_MCAN_ID].super,
    },
    [COM_SIG_IPC_CPU1_CM_FSBB_STATUS_REPORT] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_update_fsbb_data,
    }
};

//${CM::Signals::com_signals_ipc_cpu2_cm[COM_SIG_~} ..........................
const com_tag_t com_signals_ipc_cpu2_cm[COM_SIG_IPC_CPU2_CM_MAX] ={
    [COM_SIG_IPC_CPU2_CM_SEND_CAN_PUBLIC_MSG] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_can_send_msg[OC_CAN_CAN_PUBLIC_ID].super,
    },
    [COM_SIG_IPC_CPU2_CM_SEND_MCAN_MSG] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_can_send_msg[OC_CAN_MCAN_ID].super,
    }
};

//${CM::Signals::com_signals_can_public[COM_SIG_C~} ..........................
const com_tag_t com_signals_can_public[COM_SIG_CAN_PUBLIC_MAX] ={
    [COM_SIG_CAN_PUBLIC_CONTROL_START] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_start_control.super.super,
    },
    [COM_SIG_CAN_PUBLIC_CONTROL_STOP] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_stop_control.super.super,
    },
    [COM_SIG_CAN_PUBLIC_EMERGENCY_SHUTDOWN] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_emergency_shutdown.super.super,
    },
    [COM_SIG_CAN_PUBLIC_PRECHARGE_START] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_precharge_start.super.super,
    },
    [COM_SIG_CAN_PUBLIC_RESET] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_reset.super.super,
    },
    [COM_SIG_CAN_PUBLIC_CLEAR_FAULT] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_clear_fault.super.super,
    },
    [COM_SIG_CAN_PUBLIC_CHANGE_SETPOINT] = {
        .p_ao = &p_ao_communication,
        .im_evt = &im_evt_change_setpoint.super.super,
    },
};

//${CM::Signals::com_signals_mcan[COM_SIG_MCAN_MA~} ..........................
const com_tag_t com_signals_mcan[COM_SIG_MCAN_MAX] ={
};
//$enddef${CM::Signals} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
