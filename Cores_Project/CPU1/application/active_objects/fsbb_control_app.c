/*
 * fsbb_control_app.c
 *
 *  Created on: 23 de abr de 2024
 *      Author: ramon.martins
 */

#include "AOs/ao_fsbb_control/fsbb_control.h"

#include "board.h"

void FSBB_Control_Start_Precharge(FSBB_Control * const me,
    QEvt const * const e){
    GPIO_writePin(HSD1, 1); // Precharge Contactor
}

void FSBB_Control_Finish_Precharge(FSBB_Control * const me,
    QEvt const * const e){
    GPIO_writePin(HSD2, 1);
    GPIO_writePin(HSD1, 0);
}
