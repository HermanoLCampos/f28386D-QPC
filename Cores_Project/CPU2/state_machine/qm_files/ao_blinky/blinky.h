//$file${.::Cores_Project::CPU2::state_machine::qm_files::ao_blinky::blinky.h} 
//
// Model: main_model.qm.qm
// File:  ${.::Cores_Project::CPU2::state_machine::qm_files::ao_blinky::blinky.h}
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
//$endhead${.::Cores_Project::CPU2::state_machine::qm_files::ao_blinky::blinky.h} 
#ifndef BLINKY_H_
#define BLINKY_H_

#include "qpc.h"
#include "signals.h"
#include "blinky_sup/blinky_app.h"

//$declare${AOs::blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${AOs::blinky} .............................................................
typedef struct blinky {
// protected:
    QActive super;

// private:
    QTimeEvt time_evt;

// public:
} blinky;

extern blinky blinky_inst;

// protected:
QState blinky_initial(blinky * const me, void const * const par);
QState blinky_off(blinky * const me, QEvt const * const e);
QState blinky_on(blinky * const me, QEvt const * const e);
//$enddecl${AOs::blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif // BLINKY_H_
