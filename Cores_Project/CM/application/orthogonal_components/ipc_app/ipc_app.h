/*
 * ipc_app.h
 *
 *  Created on: 25 de abr de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_ORTHOGONAL_COMPONENTS_IPC_APP_IPC_APP_H_
#define APPLICATION_ORTHOGONAL_COMPONENTS_IPC_APP_IPC_APP_H_

#include "main_qm.h"
#include "ipc_config.h"
#include "system_assert.h"

bool oc_ipc_send_message(uint16_t    * p_msg , uint16_t oc_id);
bool oc_ipc_receive_message(uint16_t * p_msg , uint16_t oc_id);
void oc_ipc_reset_ch(uint16_t oc_id);
void oc_ipc_reset_complete(uint16_t oc_id);


#endif /* APPLICATION_ORTHOGONAL_COMPONENTS_IPC_APP_IPC_APP_H_ */
