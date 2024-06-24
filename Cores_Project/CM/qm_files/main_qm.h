//$file${.::Cores_Project::CM::qm_files::main_qm.h} vvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CM::qm_files::main_qm.h}
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
//$endhead${.::Cores_Project::CM::qm_files::main_qm.h} ^^^^^^^^^^^^^^^^^^^^^^^
#ifndef MAIN_QM_H_
#define MAIN_QM_H_

#include "qpc.h"
#include "macros_qm.h"
#include "bsp_basic.h"

//================================================
//====================Signals=====================
//================================================

//$declare${Shared} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${Shared::Signals::com_tag_t} ..............................................
typedef struct {
// private:
    QActive * const * const p_ao;
    const QEvt * const im_evt;
} com_tag_t;

//${Shared::Signals::Communication_CA~::com_signals_cana} ....................
enum com_signals_cana {
    COM_SIG_CANA_CONTROL_START,
    COM_SIG_CANA_CONTROL_STOP,
    COM_SIG_CANA_EMERGENCY_SHUTDOWN,
    COM_SIG_CANA_PRECHARGE_START,
    COM_SIG_CANA_CHANGE_SETPOINT,
    COM_SIG_CANA_RESET,
    COM_SIG_CANA_CLEAR_FAULT,
    COM_SIG_CANA_MAX,
    COM_SIG_CANA_NOTHING = COM_SIG_CANA_MAX,
};

//${Shared::Signals::Communication_CA~::com_signals_mcan} ....................
enum com_signals_mcan {
    COM_SIG_MCAN_MAX,
    COM_SIG_MCAN_NOTHING = COM_SIG_MCAN_MAX,
};

//${Shared::Signals::Communication_CA~::com_signals_canb} ....................
enum com_signals_canb {
    COM_SIG_CANB_MAX,
    COM_SIG_CANB_NOTHING = COM_SIG_CANB_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cpu1_cpu2_ipc} ...........
enum com_signals_cpu1_cpu2_ipc {
    //Index Signals Here
    COM_SIG_IPC_CPU1_CPU2_MAX,
    COM_SIG_IPC_CPU1_CPU2_NOTHING = COM_SIG_IPC_CPU1_CPU2_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cpu2_cpu1_ipc} ...........
enum com_signals_cpu2_cpu1_ipc {
    //Index Signals Here
    COM_SIG_IPC_CPU2_CPU1_MAX,
    COM_SIG_IPC_CPU2_CPU1_NOTHING = COM_SIG_IPC_CPU2_CPU1_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cpu1_cm_ipc} .............
enum com_signals_cpu1_cm_ipc {
    //Index Signals Here
    COM_SIG_IPC_CPU1_CM_SEND_CANA_MSG,
    COM_SIG_IPC_CPU1_CM_SEND_MCAN_MSG,
    COM_SIG_IPC_CPU1_CM_FSBB_STATUS_REPORT,
    COM_SIG_IPC_CPU1_CM_MAX,
    COM_SIG_IPC_CPU1_CM_NOTHING = COM_SIG_IPC_CPU1_CM_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cm_cpu1_ipc} .............
enum com_signals_cm_cpu1_ipc {
    //Index Signals Here
    COM_SIG_IPC_CM_CPU1_CONTROL_START,
    COM_SIG_IPC_CM_CPU1_CONTROL_STOP,
    COM_SIG_IPC_CM_CPU1_EMERGENCY_SHUTDOWN,
    COM_SIG_IPC_CM_CPU1_PRECHARGE_START,
    COM_SIG_IPC_CM_CPU1_CHANGE_SETPOINT,
    COM_SIG_IPC_CM_CPU1_CLEAR_FAULT,
    COM_SIG_IPC_CM_CPU1_RESET,
    COM_SIG_IPC_CM_CPU1_MAX,
    COM_SIG_IPC_CM_CPU1_NOTHING = COM_SIG_IPC_CM_CPU1_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cpu2_cm_ipc} .............
enum com_signals_cpu2_cm_ipc {
    //Index Signals Here
    COM_SIG_IPC_CPU2_CM_SEND_CANA_MSG,
    COM_SIG_IPC_CPU2_CM_SEND_MCAN_MSG,
    COM_SIG_IPC_CPU2_CM_MAX,
    COM_SIG_IPC_CPU2_CM_NOTHING = COM_SIG_IPC_CPU2_CM_MAX,
};

//${Shared::Signals::Communication IP~::com_signals_cm_cpu2_ipc} .............
enum com_signals_cm_cpu2_ipc {
    //Index Signals Here
    COM_SIG_IPC_CM_CPU2_MAX,
    COM_SIG_IPC_CM_CPU2_NOTHING = COM_SIG_IPC_CM_CPU2_MAX,
};

//${Shared::Signals::setpoint_list} ..........................................
enum setpoint_list {
    IL_CURRENT_SETPOINT,
    IO_CURRENT_SETPOINT,
    POWER_SETPOINT,
    NUM_OF_SETPOINTS,
};

//${Shared::Signals::fsbb_faults_list} .......................................
enum fsbb_faults_list {
    FSBB_FAULT_SKIIP1_OVERVOLTAGE = 0,
    FSBB_FAULT_SKIIP1_OVERCURRENT,
    FSBB_FAULT_SKIIP1_OVERHEAT,
    FSBB_FAULT_SKIIP1_HALT,
    FSBB_FAULT_SKIIP2_OVERVOLTAGE,
    FSBB_FAULT_SKIIP2_OVERCURRENT,
    FSBB_FAULT_SKIIP2_OVERHEAT,
    FSBB_FAULT_SKIIP2_HALT,
    FSBB_FAULT_INDUCTOR_OVERHEAT,
    FSBB_FAULT_CAPACITOR_OVERHEAT,
    FSBB_FAULT_ERROR_OUT_1,
    FSBB_FAULT_ERROR_OUT_2,
    FSBB_FAULT_SETTLE_TIMEOUT,
    FSBB_FAULT_CLA_1_WATCHDOG_TIMEOUT,
    FSBB_FAULT_CLA_2_WATCHDOG_TIMEOUT,
    FSBB_FAULT_EMERGENCY_SHUTDOWN,

    FSBB_NUM_OF_FAULTS,
};

//${Shared::Types::com_payload} ..............................................
typedef struct {
// public:
    uint16_t data[MAX_SIG_PAYLOAD];
} com_payload;

//${Shared::Types::Communication_Message_t} ..................................
typedef struct {
// private:
    uint16_t com_sig;
    uint16_t message_size;
    com_payload payload;
} Communication_Message_t;

//${Shared::Types::Setpoint_Data_t} ..........................................
typedef struct {
// private:
    uint16_t setpoint_id;
    uint16_t setpoint_value;
} Setpoint_Data_t;

//${Shared::Event_Types::OC::OC_Evt} .........................................
typedef struct {
// protected:
    QEvt super;

// public:
    uint16_t ID;
} OC_Evt;

//${Shared::Event_Types::OC::OC_TimeEvt} .....................................
typedef struct {
// protected:
    QTimeEvt super;

// public:
    uint16_t ID;
} OC_TimeEvt;

//${Shared::Event_Types::OC::OC_Evt_CAN_Message_Received_t} ..................
typedef struct {
// protected:
    OC_Evt super;

// public:
    uint32_t Message_ID;
    uint8_t Data[8];
} OC_Evt_CAN_Message_Received_t;

//${Shared::Event_Types::OC::OC_Evt_CAN_Send_Message_t} ......................
typedef struct {
// protected:
    OC_Evt super;

// public:
    uint8_t Message_Box_ID;
    uint8_t Data[8];
} OC_Evt_CAN_Send_Message_t;

//${Shared::Event_Types::OC::OC_Evt_Communication_Message_t} .................
typedef struct {
// protected:
    OC_Evt super;

// public:
    Communication_Message_t msg;
} OC_Evt_Communication_Message_t;

//${Shared::Event_Types::AO::AO_Evt_Change_Setpoint_t} .......................
typedef struct {
// protected:
    QEvt super;

// public:
    Setpoint_Data_t data;
} AO_Evt_Change_Setpoint_t;

//${Shared::Event_Types::AO::AO_Evt_Set_Fault_t} .............................
typedef struct {
// protected:
    QEvt super;

// public:
    uint16_t data;
} AO_Evt_Set_Fault_t;

//${Shared::Macros::RTOS_TICK_FREQUENCY_HZ} ..................................
#define RTOS_TICK_FREQUENCY_HZ (1000.0f)

//${Shared::Macros::RTOS_TICK_PERIOD_MS} .....................................
#define RTOS_TICK_PERIOD_MS (1000.f/RTOS_TICK_FREQUENCY_HZ)

//${Shared::Macros::OC_IPC_CMD_REMOTE_RESET} .................................
#define OC_IPC_CMD_REMOTE_RESET 0


//${Shared::Macros::OC_IPC_CMD_RESET_COMPLETE} ...............................
#define OC_IPC_CMD_RESET_COMPLETE 1

//${Shared::Macros::MAX_SIG_PAYLOAD} .........................................
#define MAX_SIG_PAYLOAD 16

//${Shared::Macros::OC_CAN_MSG_BUFFER_SIZE} ..................................
#define OC_CAN_MSG_BUFFER_SIZE 512

//${Shared::Macros::CRITICAL_LIMITS::CRITICAL_LIMIT_SKIIP_CURRENT} ...........
#define CRITICAL_LIMIT_SKIIP_CURRENT 1500

//${Shared::Macros::CRITICAL_LIMITS::CRITICAL_LIMIT_SKIIP_VOLTAGE} ...........
#define CRITICAL_LIMIT_SKIIP_VOLTAGE 1000

//${Shared::Macros::CRITICAL_LIMITS::CRITICAL_LIMIT_SKIIP_TEMPERATURE} .......
#define CRITICAL_LIMIT_SKIIP_TEMPERATURE 200

//${Shared::Macros::CRITICAL_LIMITS::CRITICAL_LIMIT_CAPACITOR_TEMPERA~} ......
#define CRITICAL_LIMIT_CAPACITOR_TEMPERATURE 200

//${Shared::Macros::CRITICAL_LIMITS::CRITICAL_LIMIT_INDUCTOR_TEMPERAT~} ......
#define CRITICAL_LIMIT_INDUCTOR_TEMPERATURE 200

//${Shared::Macros::TIME_MACROS::CHECK_PARAMS_PRECHARGE_TIME_MS} .............
#define CHECK_PARAMS_PRECHARGE_TIME_MS 100

//${Shared::Macros::TIME_MACROS::CHECK_CLA_WATCHDOG_TIME_MS} .................
#define CHECK_CLA_WATCHDOG_TIME_MS 1000

//${Shared::Macros::TIME_MACROS::CHECK_PARAMS_IL_TIME_MS} ....................
#define CHECK_PARAMS_IL_TIME_MS 10

//${Shared::Macros::TIME_MACROS::MAX_SETTLE_TIME_MS} .........................
#define MAX_SETTLE_TIME_MS 100

//${Shared::Macros::TIME_MACROS::REPORT_STATUS_PERIOD_TIME_MS} ...............
#define REPORT_STATUS_PERIOD_TIME_MS 1000

//${Shared::Macros::CONDITIONAL_LIMI~::IL_MIN_OPEN} ..........................
#define IL_MIN_OPEN 20

//${Shared::Macros::CONDITIONAL_LIMI~::IL_MIN_STOP} ..........................
#define IL_MIN_STOP 100

//${Shared::Macros::CONDITIONAL_LIMI~::MIN_DELTA_V_PRECHARGE_FINISH} .........
#define MIN_DELTA_V_PRECHARGE_FINISH 20

//${Shared::Event Pools::EVT_POOL_1_SIZE} ....................................
#define EVT_POOL_1_SIZE 8


//${Shared::Event Pools::EVT_POOL_2_SIZE} ....................................
#define EVT_POOL_2_SIZE 8


//${Shared::Event Pools::EVT_POOL_3_SIZE} ....................................
#define EVT_POOL_3_SIZE 8


//${Shared::Event Pools::EVT_POOL_4_SIZE} ....................................
#define EVT_POOL_4_SIZE 8


//${Shared::Event Pools::evt_pool_payload_1_t} ...............................
typedef struct {
// public:
    uint16_t data[1];
} evt_pool_payload_1_t;

//${Shared::Event Pools::evt_pool_payload_2_t} ...............................
typedef struct {
// public:
    uint16_t data[4];
} evt_pool_payload_2_t;

//${Shared::Event Pools::evt_pool_payload_3_t} ...............................
typedef struct {
// public:
    uint16_t data[8];
} evt_pool_payload_3_t;

//${Shared::Event Pools::evt_pool_payload_4_t} ...............................
typedef struct {
// public:
    uint16_t data[16];
} evt_pool_payload_4_t;

//${Shared::Event Pools::EvtPool1_t} .........................................
typedef struct {
// protected:
    QEvt super;

// private:
    evt_pool_payload_1_t payload;
} EvtPool1_t;

//${Shared::Event Pools::EvtPool2_t} .........................................
typedef struct {
// protected:
    QEvt super;

// private:
    evt_pool_payload_2_t payload;
} EvtPool2_t;

//${Shared::Event Pools::EvtPool3_t} .........................................
typedef struct {
// protected:
    QEvt super;

// private:
    evt_pool_payload_3_t payload;
} EvtPool3_t;

//${Shared::Event Pools::EvtPool4_t} .........................................
typedef struct {
// protected:
    QEvt super;

// private:
    evt_pool_payload_4_t payload;
} EvtPool4_t;
//$enddecl${Shared} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$declare${OCs::Signals} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${OCs::Signals::OC_IPC_SIGNALS} ............................................
#define OC_IPC_SIGNALS \
    IPC_RECEIVE_MSG_SIG,\
    IPC_SEND_MSG_SIG,\
    IPC_FULL_BUS_SIG,\
    IPC_RESET_CH_SIG,\
    IPC_REMOTE_RESET_SIG,\
    IPC_RESET_COMPLETE_SIG

//${OCs::Signals::OC_CAN_SIGNALS} ............................................
#define OC_CAN_SIGNALS \
    CAN_RECEIVE_MSG_SIG,\
    CAN_SEND_MSG_SIG,\
    CAN_PASSIVE_ERROR_SIG,\
    CAN_BUS_OFF_SIG,\
    CAN_ERROR_CLEAR_SIG
//$enddecl${OCs::Signals} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$declare${CM::Signals} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::Signals::private_signals} ............................................
enum private_signals {
// Publish Subscribe Signals
    TIMEOUT_SIG = Q_USER_SIG,

    // - Only PRIVATE

    MAX_PUB_SIG,

    // COMMON Signals
    RUNNING_QF_SIG,
    INIT_COMPLETE_SIG,

    // CAN OC Signals
    OC_CAN_SIGNALS,

    // IPC OC Signals
    OC_IPC_SIGNALS,

    MAX_PRIVATE_SIG,
};

//${CM::Signals::com_signals_ipc_cpu1_cm[COM_SIG_~} ..........................
extern const com_tag_t com_signals_ipc_cpu1_cm[COM_SIG_IPC_CPU1_CM_MAX];

//${CM::Signals::com_signals_ipc_cpu2_cm[COM_SIG_~} ..........................
extern const com_tag_t com_signals_ipc_cpu2_cm[COM_SIG_IPC_CPU2_CM_MAX];

//${CM::Signals::com_signals_cana[COM_SIG_CANA_MA~} ..........................
extern const com_tag_t com_signals_cana[COM_SIG_CANA_MAX];

//${CM::Signals::com_signals_mcan[COM_SIG_MCAN_MA~} ..........................
extern const com_tag_t com_signals_mcan[COM_SIG_MCAN_MAX];
//$enddecl${CM::Signals} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//================================================
//===================Priorities===================
//================================================

//$declare${CM::ao_priority} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::ao_priority} .........................................................
enum ao_priority {
    // Priority in ascendance order
    IDLE_TASK=0U,
    AO_COMMUNICATION_PRIO,
};
//$enddecl${CM::ao_priority} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//================================================
//=================Active-Objects=================
//================================================

// AO_Communication
//$declare${CM::AOs::AO_Communication::globals} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::AOs::AO_Communication::globals::p_ao_communication} ..................
extern QActive * const p_ao_communication;

//${CM::AOs::AO_Communication::globals::ao_communication_ctor} ...............
void ao_communication_ctor(const QActive  * const pAO);
//$enddecl${CM::AOs::AO_Communication::globals} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//================================================
//=============Orthogonal-Components==============
//================================================

//$declare${CM::OC_enum} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::OC_enum::IPC::ipc_named} .............................................
enum ipc_named {
    OC_IPC_CM_CPU1_ID,
#ifdef DUALCORE
    OC_IPC_CM_CPU2_ID,
#endif
    OC_IPC_NUM_OF_INST,
};

//${CM::OC_enum::CAN::can_named} .............................................
enum can_named {
    OC_CAN_CANA_ID,
    OC_CAN_MCAN_ID,
    OC_CAN_NUM_OF_INST,
};
//$enddecl${CM::OC_enum} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//================================================
//================Immutable-Events================
//================================================

//$declare${CM::Immutable_Events} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CM::Immutable_Events::General::im_evt_running_qf} ........................
extern QEvt const im_evt_running_qf;

//${CM::Immutable_Events::General::im_evt_init_complete} .....................
extern QEvt const im_evt_init_complete;

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_reset_ch[OC_IPC_NUM_O~}
extern OC_Evt const im_evt_ipc_reset_ch[OC_IPC_NUM_OF_INST];

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_reset_complete[OC_IPC~}
extern OC_Evt const im_evt_ipc_reset_complete[OC_IPC_NUM_OF_INST];

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_receive_msg[OC_IPC_NU~}
extern OC_Evt const im_evt_ipc_receive_msg[OC_IPC_NUM_OF_INST];

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_full_bus[OC_IPC_NUM_O~}
extern OC_Evt const im_evt_ipc_full_bus[OC_IPC_NUM_OF_INST];

//${CM::Immutable_Events::Communication::IPC::im_evt_ipc_remote_reset[OC_IPC_N~}
extern OC_Evt const im_evt_ipc_remote_reset[OC_IPC_NUM_OF_INST];

//${CM::Immutable_Events::Communication::CAN::im_evt_can_send_msg[OC_CAN_NUM_O~}
extern OC_Evt const im_evt_can_send_msg[OC_CAN_NUM_OF_INST];

//${CM::Immutable_Events::To CPU1::im_evt_start_control} .....................
extern OC_Evt_Communication_Message_t const im_evt_start_control;

//${CM::Immutable_Events::To CPU1::im_evt_stop_control} ......................
extern OC_Evt_Communication_Message_t const im_evt_stop_control;

//${CM::Immutable_Events::To CPU1::im_evt_emergency_shutdown} ................
extern OC_Evt_Communication_Message_t const im_evt_emergency_shutdown;

//${CM::Immutable_Events::To CPU1::im_evt_precharge_start} ...................
extern OC_Evt_Communication_Message_t const im_evt_precharge_start;

//${CM::Immutable_Events::To CPU1::im_evt_clear_fault} .......................
extern OC_Evt_Communication_Message_t const im_evt_clear_fault;

//${CM::Immutable_Events::To CPU1::im_evt_reset} .............................
extern OC_Evt_Communication_Message_t const im_evt_reset;

//${CM::Immutable_Events::To CPU1::im_evt_change_setpoint} ...................
extern OC_Evt_Communication_Message_t const im_evt_change_setpoint;
//$enddecl${CM::Immutable_Events} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif // MAIN_QM_H_
