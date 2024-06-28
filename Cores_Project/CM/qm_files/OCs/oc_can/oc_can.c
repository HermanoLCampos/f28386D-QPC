//$file${.::Cores_Project::CM::qm_files::OCs::oc_can::oc_can.c} vvvvvvvvvvvvvv
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CM::qm_files::OCs::oc_can::oc_can.c}
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
//$endhead${.::Cores_Project::CM::qm_files::OCs::oc_can::oc_can.c} ^^^^^^^^^^^
#include "./oc_can.h"

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${OCs::OC_CAN} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${OCs::OC_CAN::OC_CAN} .....................................................

//${OCs::OC_CAN::OC_CAN::ctor} ...............................................
void OC_CAN_ctor(OC_CAN * const me,
    QActive * const owner,
    uint16_t id)
{
    QHsm_ctor(&me->super, Q_STATE_CAST(&OC_CAN_initial));
    me->owner = owner;
    me->id = id;
}

//${OCs::OC_CAN::OC_CAN::SM} .................................................
QState OC_CAN_initial(OC_CAN * const me, void const * const par) {
    //${OCs::OC_CAN::OC_CAN::SM::initial}
    return Q_TRAN(&OC_CAN_Waiting_QF);
}

//${OCs::OC_CAN::OC_CAN::SM::Waiting_QF} .....................................
QState OC_CAN_Waiting_QF(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_CAN::OC_CAN::SM::Waiting_QF::RUNNING_QF}
        case RUNNING_QF_SIG: {
            status_ = Q_TRAN(&OC_CAN_Start);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_CAN::OC_CAN::SM::Start} ..........................................
QState OC_CAN_Start(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_CAN::OC_CAN::SM::Start::INIT_COMPLETE}
        case INIT_COMPLETE_SIG: {
            status_ = Q_TRAN(&OC_CAN_Operation);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_CAN::OC_CAN::SM::Operation} ......................................
QState OC_CAN_Operation(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_CAN::OC_CAN::SM::Operation::initial}
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&OC_CAN_Error_Active);
            break;
        }
        //${OCs::OC_CAN::OC_CAN::SM::Operation::CAN_RECEIVE_MSG}
        case CAN_RECEIVE_MSG_SIG: {
            //BSP_BKPT;
            OC_CAN_receive_msg(me,e);
            //BSP_BKPT;
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_CAN::OC_CAN::SM::Operation::CAN_SEND_MSG}
        case CAN_SEND_MSG_SIG: {
            //BSP_BKPT;
            OC_CAN_send_msg(me,e);
            //BSP_BKPT;
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_CAN::OC_CAN::SM::Operation::CAN_PASSIVE_ERROR}
        case CAN_PASSIVE_ERROR_SIG: {
            status_ = Q_TRAN(&OC_CAN_Error_Passive);
            break;
        }
        //${OCs::OC_CAN::OC_CAN::SM::Operation::CAN_BUS_OFF}
        case CAN_BUS_OFF_SIG: {
            status_ = Q_TRAN(&OC_CAN_Bus_Off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${OCs::OC_CAN::OC_CAN::SM::Operation::Error_Passive} .......................
QState OC_CAN_Error_Passive(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_CAN::OC_CAN::SM::Operation::Error_Passive::CAN_ERROR_CLEAR}
        case CAN_ERROR_CLEAR_SIG: {
            status_ = Q_TRAN(&OC_CAN_Operation);
            break;
        }
        default: {
            status_ = Q_SUPER(&OC_CAN_Operation);
            break;
        }
    }
    return status_;
}

//${OCs::OC_CAN::OC_CAN::SM::Operation::Error_Active} ........................
QState OC_CAN_Error_Active(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_SUPER(&OC_CAN_Operation);
            break;
        }
    }
    return status_;
}

//${OCs::OC_CAN::OC_CAN::SM::Operation::Bus_Off} .............................
QState OC_CAN_Bus_Off(OC_CAN * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${OCs::OC_CAN::OC_CAN::SM::Operation::Bus_Off::CAN_SEND_MSG}
        case CAN_SEND_MSG_SIG: {
            status_ = Q_HANDLED();
            break;
        }
        //${OCs::OC_CAN::OC_CAN::SM::Operation::Bus_Off::CAN_RECEIVE_MSG}
        case CAN_RECEIVE_MSG_SIG: {
            //BSP_BKPT;
            OC_CAN_receive_msg(me,e);
            //BSP_BKPT;
            status_ = Q_TRAN(&OC_CAN_Operation);
            break;
        }
        default: {
            status_ = Q_SUPER(&OC_CAN_Operation);
            break;
        }
    }
    return status_;
}
//$enddef${OCs::OC_CAN} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
