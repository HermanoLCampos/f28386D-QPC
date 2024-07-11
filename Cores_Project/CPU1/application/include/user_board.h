/*
 * user_board.h
 *
 *  Created on: 8 de mai de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_USER_BOARD_H_
#define APPLICATION_INCLUDE_USER_BOARD_H_

#include "bsp_ipc.h"
#include "board.h"
#include "cpu1_interrupts.h"

void user_board_init();

void user_msg_box_init();
void init_cpu2cm_memory();

#endif /* APPLICATION_INCLUDE_USER_BOARD_H_ */
