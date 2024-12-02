/*
 * system_assert.c
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#include "system_assert.h"
#include "resources_config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp_basic.h"
#include "board.h"

void system_assert(const char *filename, int assert_number){
#if USER_ASSERT
    user_assert(filename, assert_number);
#endif
    //Leg Vin
    EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);
    EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
    EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);

    //Leg Vout
    EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);
    EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
    EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);

    taskDISABLE_INTERRUPTS();
    BSP_BKPT;
    while(1);
}
