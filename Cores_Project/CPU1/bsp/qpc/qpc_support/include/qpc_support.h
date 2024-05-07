/*
 * qpc_support.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_QPC_QPC_SUPPORT_INCLUDE_QPC_SUPPORT_H_
#define BSP_QPC_QPC_SUPPORT_INCLUDE_QPC_SUPPORT_H_

#include "system_assert.h"

void QF_onStartup(void);
void QF_onCleanup(void);
void QF_onClockTick(void);
void Q_onError(char const * const module, int id);



#endif /* BSP_QPC_QPC_SUPPORT_INCLUDE_QPC_SUPPORT_H_ */
