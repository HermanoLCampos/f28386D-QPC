/*
 * ipc_config.h
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_COMMON_IPC_CONFIG_H_
#define BSP_COMMON_IPC_CONFIG_H_

#include "macros_qm.h"

#define BSP_MQ_SUPPORT 1

#define BSP_USE_COMMAND_IPC_MQ 0
#define BSP_USE_POINTER_IPC_MQ 0
#define BSP_USE_PAYLOAD_IPC_MQ 1

// consider use buffersize + 1. this MQ let a
// dead space in the buffer because the head tail use
#define BSP_IPC_BUFFER_SIZE    4
#define BSP_IPC_MAX_PAYLOAD_SIZE   MAX_SIG_PAYLOAD+1

#define BSP_IPC_INTERRUPTS_CPU1_CPU2_USED 1
#define BSP_IPC_INTERRUPTS_CPU1_CM_USED 1
#define BSP_IPC_INTERRUPTS_CPU2_CM_USED 1

#define BSP_IPC_REGISTER_CMD 0xFFFFFF01


#endif /* BSP_COMMON_IPC_CONFIG_H_ */
