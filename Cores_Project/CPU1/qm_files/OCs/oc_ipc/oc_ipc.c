//$file${.::Cores_Project::CPU1::qm_files::OCs::oc_ipc::oc_ipc.c} vvvvvvvvvvvv
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CPU1::qm_files::OCs::oc_ipc::oc_ipc.c}
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
//$endhead${.::Cores_Project::CPU1::qm_files::OCs::oc_ipc::oc_ipc.c} ^^^^^^^^^
#include "./oc_ipc.h"

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${OCs::OC_IPC} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${OCs::OC_IPC::OC_IPC} .....................................................

//${OCs::OC_IPC::OC_IPC::ctor} ...............................................
void OC_IPC_ctor(OC_IPC * const me,
    QActive * const owner,
    uint16_t id)
{
    QHsm_ctor(&me->super, Q_STATE_CAST(&OC_IPC_initial));
    me->owner = owner;
    me->id = id;
}

//${OCs::OC_IPC::OC_IPC::SM} .................................................
QState OC_IPC_initial(OC_IPC * const me, void const * const par) {
    //${OCs::OC_IPC::OC_IPC::SM::initial}
    return Q_TRAN(&OC_IPC_Waiting_QF);
}

//${OCs::OC_IPC::OC_IPC::SM::Waiting_QF} .....................................
QState OC_IPC_Waiting_QF(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Waiting_QF::RUNNING_QF}
        case RUNNING_QF_SIG: {
            status_ = Q_TRAN(&OC_IPC_Start);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_IPC::OC_IPC::SM::Start} ..........................................
QState OC_IPC_Start(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Start}
        case Q_ENTRY_SIG: {
            me->n_msg_received = 0;
            me->fault_cont = 0;
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Start::INIT_COMPLETE}
        case INIT_COMPLETE_SIG: {
            status_ = Q_TRAN(&OC_IPC_Running);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_IPC::OC_IPC::SM::Operation} ......................................
QState OC_IPC_Operation(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Operation::IPC_RECEIVE_MSG}
        case IPC_RECEIVE_MSG_SIG: {
            OC_IPC_receive_msg(me,e);
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::IPC_SEND_MSG}
        case IPC_SEND_MSG_SIG: {
            OC_IPC_send_msg(me,e);

            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::IPC_FULL_BUS}
        case IPC_FULL_BUS_SIG: {
            status_ = Q_TRAN(&OC_IPC_Error);
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::IPC_RESET_CH}
        case IPC_RESET_CH_SIG: {
            OC_IPC_reset_ch(me,e);
            status_ = Q_TRAN(&OC_IPC_In_Reset);
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::IPC_REMOTE_RESET}
        case IPC_REMOTE_RESET_SIG: {
            OC_IPC_remote_reset(me,e);
            status_ = Q_TRAN(&OC_IPC_Running);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_IPC::OC_IPC::SM::Operation::Running} .............................
QState OC_IPC_Running(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Operation::Running}
        case Q_ENTRY_SIG: {
            BSP_BKPT;
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OC_IPC_Operation);
            break;
        }
    }
    return status_;
}

//${OCs::OC_IPC::OC_IPC::SM::Operation::Error} ...............................
QState OC_IPC_Error(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Operation::Error}
        case Q_ENTRY_SIG: {
            //me->fault_cont++;
            //QACTIVE_POST(
            //    me->owner,
            //    &im_evt_ipc_reset_ch[me->id].super,
            //    (void *)0
            //);
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::Error::IPC_RECEIVE_MSG, IPC_SEND_MSG}
        case IPC_RECEIVE_MSG_SIG: // intentionally fall through
        case IPC_SEND_MSG_SIG: {
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OC_IPC_Operation);
            break;
        }
    }
    return status_;
}

//${OCs::OC_IPC::OC_IPC::SM::Operation::In_Reset} ............................
QState OC_IPC_In_Reset(OC_IPC * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_IPC::OC_IPC::SM::Operation::In_Reset}
        case Q_ENTRY_SIG: {
            //oc_ipc_reset_ch(me->id);
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::In_Reset::IPC_RESET_COMPLETE}
        case IPC_RESET_COMPLETE_SIG: {
            status_ = Q_TRAN(&OC_IPC_Running);
            break;
        }
        //${OCs::OC_IPC::OC_IPC::SM::Operation::In_Reset::IPC_RECEIVE_MSG, IPC_SEND_MSG}
        case IPC_RECEIVE_MSG_SIG: // intentionally fall through
        case IPC_SEND_MSG_SIG: {
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&OC_IPC_Operation);
            break;
        }
    }
    return status_;
}
//$enddef${OCs::OC_IPC} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
