//$file${.::Cores_Project::CPU1::qm_files::AOs::ao_communication::communication.h} 
//
// Model: main_model.qm
// File:  ${.::Cores_Project::CPU1::qm_files::AOs::ao_communication::communication.h}
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
//$endhead${.::Cores_Project::CPU1::qm_files::AOs::ao_communication::communication.h} 
#ifndef AO_COMMUNICATION_H_
#define AO_COMMUNICATION_H_

#include "main_qm.h"
#include "communication_app/communication_app.h"

// Orthogonal Component
#include "OCs/oc_ipc/oc_ipc.h"
#include "OCs/oc_can/oc_can.h"

//$declare${CPU1::AOs::AO_Communication} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${CPU1::AOs::AO_Communication::Communication} ..............................
typedef struct {
// protected:
    QActive super;

// private:
    OC_IPC ipc_inst[OC_IPC_NUM_OF_INST];
    OC_CAN can_inst[OC_CAN_NUM_OF_INST];
} Communication;

// protected:
QState Communication_initial(Communication * const me, void const * const par);
QState Communication_Waiting_QF(Communication * const me, QEvt const * const e);
QState Communication_Start(Communication * const me, QEvt const * const e);
QState Communication_Operation(Communication * const me, QEvt const * const e);

//${CPU1::AOs::AO_Communication::inst_ao_communication} ......................
extern Communication inst_ao_communication;

//${CPU1::AOs::AO_Communication::globals::p_ao_communication} ................
extern QActive * const p_ao_communication;

//${CPU1::AOs::AO_Communication::globals::ao_communication_ctor} .............
void ao_communication_ctor(const QActive  * const pAO);
//$enddecl${CPU1::AOs::AO_Communication} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif
