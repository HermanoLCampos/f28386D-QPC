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
    GPIO_writePin(HSD3, 1); // Precharge Contactor

    GPIO_writePin(HSD2, 0);
    GPIO_writePin(HSD4, 0);
}

void FSBB_Control_Finish_Precharge(FSBB_Control * const me,
    QEvt const * const e){
    GPIO_writePin(HSD1, 0);
    GPIO_writePin(HSD3, 0);

    GPIO_writePin(HSD2, 1);
    GPIO_writePin(HSD4, 1);
}

void FSBB_Control_Open_Contactors(FSBB_Control * const me,
    QEvt const * const e){
    GPIO_writePin(HSD1, 0);
    GPIO_writePin(HSD3, 0);

    GPIO_writePin(HSD2, 0);
    GPIO_writePin(HSD4, 0);
}

void FSBB_Control_Change_Control_State(FSBB_Control * const me,
    uint16_t control_state){

    CPU2CLA_Message.FSBB_Control_State = control_state;
    switch(control_state){
    case FSBB_CONTROL_INIT:
        //Leg Vin
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);

        //Leg Vout
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);
        break;
    case FSBB_CONTROL_STOPPED:
        //Leg Vin
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);

        //Leg Vout
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_HIGH);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);
        break;
    case FSBB_CONTROL_RUNNING:
        //Leg Vin
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(GD_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(FO_HB_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_DISABLED);

        // Leg Vout
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(GD_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_DISABLED);
        EPWM_setActionQualifierContSWForceAction(FO_HB_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_DISABLED);
        break;
    case FSBB_CONTROL_STOPING:
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
        break;
    case FSBB_CONTROL_ERROR:
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
        break;
    }

}

bool FSBB_Control_Check_Skiip_Error_IO(FSBB_Control * const me){
    return
        (
            GPIO_readPin(HALT1)        ||
            GPIO_readPin(HALT2)        ||
            GPIO_readPin(ERROR_OUT1)   ||
            GPIO_readPin(ERROR_OUT2)
        );
}
