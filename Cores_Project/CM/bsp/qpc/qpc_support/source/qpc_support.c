/*
 * qpc_support.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "qpc_support.h"

void QF_onStartup(void) {}
void QF_onCleanup(void) {}
void QF_onClockTick(void) {}
void Q_onError(char const * const module, int id) {
    system_assert(module,id);
}
