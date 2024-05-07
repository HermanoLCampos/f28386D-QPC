//$file${.::Cores_Project::CPU2::qm_files::AOs::ao_communication::communication.c} 
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CPU2::qm_files::AOs::ao_communication::communication.c}
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
//$endhead${.::Cores_Project::CPU2::qm_files::AOs::ao_communication::communication.c} 
#include "./communication.h"

Q_DEFINE_THIS_FILE

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${CPU2::AOs::AO_Communication} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CPU2::AOs::AO_Communication::Communication} ..............................

//${CPU2::AOs::AO_Communication::Communication::SM} ..........................
QState Communication_initial(Communication * const me, void const * const par) {
    //${CPU2::AOs::AO_Communication::Communication::SM::initial}
    return Q_TRAN(&Communication_Waiting_QF);
}

//${CPU2::AOs::AO_Communication::Communication::SM::Waiting_QF} ..............
QState Communication_Waiting_QF(Communication * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${CPU2::AOs::AO_Communication::Communication::SM::Waiting_QF}
        case Q_ENTRY_SIG: {
            //BSP_BKPT;

            QASM_INIT( &(me->ipc_cpu2_cpu1.super) , (void *)0, (void *)0 );
            QASM_INIT( &(me->ipc_cpu2_cm.super)   , (void *)0, (void *)0 );

            QACTIVE_POST(&me->super,&im_evt_running_qf,(void *)0);
            status_ = Q_HANDLED();
            break;
        }
        //${CPU2::AOs::AO_Communication::Communication::SM::Waiting_QF::RUNNING_QF}
        case RUNNING_QF_SIG: {
            status_ = Q_TRAN(&Communication_Start);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${CPU2::AOs::AO_Communication::Communication::SM::Start} ...................
QState Communication_Start(Communication * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${CPU2::AOs::AO_Communication::Communication::SM::Start}
        case Q_ENTRY_SIG: {
            BSP_BKPT;

            QASM_DISPATCH( &(me->ipc_cpu2_cpu1.super),&im_evt_running_qf, (void *) 0 );
            QASM_DISPATCH( &(me->ipc_cpu2_cm.super)  ,&im_evt_running_qf, (void *) 0 );
            status_ = Q_HANDLED();
            break;
        }
        //${CPU2::AOs::AO_Communication::Communication::SM::Start::INIT_COMPLETE}
        case INIT_COMPLETE_SIG: {
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${CPU2::AOs::AO_Communication::inst_ao_communication} ......................
Communication inst_ao_communication;

//${CPU2::AOs::AO_Communication::globals::p_ao_communication} ................
QActive * const p_ao_communication = &inst_ao_communication.super;

//${CPU2::AOs::AO_Communication::globals::ao_communication_ctor} .............
void ao_communication_ctor(const QActive  * const pAO) {
    Communication * const me = (Communication *) pAO;
    QActive_ctor(&me->super, Q_STATE_CAST(&Communication_initial));

    // Orthogonal Components

    OC_IPC_ctor(&me->ipc_cpu2_cpu1 ,&me->super, 1);
    OC_IPC_ctor(&me->ipc_cpu2_cm   ,&me->super, 2);
}
//$enddef${CPU2::AOs::AO_Communication} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
