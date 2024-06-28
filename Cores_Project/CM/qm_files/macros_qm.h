//$file${.::Cores_Project::CM::qm_files::macros_qm.h} vvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CM::qm_files::macros_qm.h}
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
//$endhead${.::Cores_Project::CM::qm_files::macros_qm.h} ^^^^^^^^^^^^^^^^^^^^^
//$declare${Shared::Macros} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

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
#define CRITICAL_LIMIT_SKIIP_TEMPERATURE 90

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

//${Shared::Macros::TIME_MACROS::ANALOG_FAULT_MAX_FREQUENCY_MS} ..............
#define ANALOG_FAULT_MAX_FREQUENCY_MS 1000

//${Shared::Macros::CONDITIONAL_LIMI~::IL_MIN_OPEN} ..........................
#define IL_MIN_OPEN 20

//${Shared::Macros::CONDITIONAL_LIMI~::IL_MIN_STOP} ..........................
#define IL_MIN_STOP 100

//${Shared::Macros::CONDITIONAL_LIMI~::MIN_DELTA_V_PRECHARGE_FINISH} .........
#define MIN_DELTA_V_PRECHARGE_FINISH 20

//${Shared::Macros::CONTROL_MACROS::CONTROL_FREQUENCY_HZ} ....................
#define CONTROL_FREQUENCY_HZ 2000.0f

//${Shared::Macros::CONTROL_MACROS::CONTROL_PERIOD_SEC} ......................
#define CONTROL_PERIOD_SEC (1.0f/CONTROL_FREQUENCY_HZ)

//${Shared::Macros::CONTROL_MACROS::VIN_MIN} .................................
#define VIN_MIN 5

//${Shared::Macros::CONTROL_MACROS::MIN_OFF_DUTY_CICLE_VIN} ..................
#define MIN_OFF_DUTY_CICLE_VIN 0

//${Shared::Macros::CONTROL_MACROS::MIN_OFF_DUTY_CICLE_VOUT} .................
#define MIN_OFF_DUTY_CICLE_VOUT 0

//${Shared::Macros::CONTROL_MACROS::MIN_DUTY_CICLE_VIN_SWITCH} ...............
#define MIN_DUTY_CICLE_VIN_SWITCH 0

//${Shared::Macros::CONTROL_MACROS::MAX_DUTY_CICLE_VIN_SWITCH} ...............
#define MAX_DUTY_CICLE_VIN_SWITCH 1

//${Shared::Macros::CONTROL_MACROS::MIN_DUTY_CICLE_VOUT_SWITCH} ..............
#define MIN_DUTY_CICLE_VOUT_SWITCH 0

//${Shared::Macros::CONTROL_MACROS::MAX_DUTY_CICLE_VOUT_SWITCH} ..............
#define MAX_DUTY_CICLE_VOUT_SWITCH 1

//${Shared::Macros::CONTROL_MACROS::EPWM_DEAD_TIME_COUNT} ....................
#define EPWM_DEAD_TIME_COUNT 600

//${Shared::Macros::CONTROL_MACROS::EPWM_PRD} ................................
#define EPWM_PRD 50000
//$enddecl${Shared::Macros} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
