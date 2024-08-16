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


const uint16_t rtd_measure[OC_MAX31865_NUM_OF_INST][OC_MAX31865_NUM_OF_MUX] = {
    [OC_MAX31865_A_ID]  = {
        [OC_MAX31865_MUX0] = FSBB_MEASURE_RTDA1_TEMPERATURE,
        [OC_MAX31865_MUX1] = FSBB_MEASURE_RTDA2_TEMPERATURE,
        [OC_MAX31865_MUX2] = FSBB_MEASURE_RTDA3_TEMPERATURE,
        [OC_MAX31865_MUX3] = FSBB_MEASURE_RTDA4_TEMPERATURE,
    },
    [OC_MAX31865_B_ID] = {
        [OC_MAX31865_MUX0] = FSBB_MEASURE_RTDB1_TEMPERATURE,
        [OC_MAX31865_MUX1] = FSBB_MEASURE_RTDB2_TEMPERATURE,
        [OC_MAX31865_MUX2] = FSBB_MEASURE_RTDB3_TEMPERATURE,
        [OC_MAX31865_MUX3] = FSBB_MEASURE_RTDB4_TEMPERATURE,
    }
};

void FSBB_Control_MAX_Request_Temperature(FSBB_Control * const me){
    OC_Evt_MAX31865_Temperature_Request_t max_temperature_request;

    BSP_BKPT;

    max_temperature_request.super = im_evt_max31865_request_temperature[OC_MAX31865_A_ID];
    // MAX31865A
    max_temperature_request.temperature_id = OC_MAX31865_MUX0;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_A_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX1;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_A_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX2;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_A_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX3;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_A_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );


    max_temperature_request.super = im_evt_max31865_request_temperature[OC_MAX31865_B_ID];
    // MAX31865B
    max_temperature_request.temperature_id = OC_MAX31865_MUX0;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_B_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX1;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_B_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX2;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_B_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );
    max_temperature_request.temperature_id = OC_MAX31865_MUX3;
    QASM_DISPATCH( &(me->max31865_inst[OC_MAX31865_B_ID].super) , &(max_temperature_request.super.super) , (void *) 0 );


}
void FSBB_Control_MAX_Update_Temperature(FSBB_Control * const me,
    QEvt const * const e){

    uint16_t id = Q_EVT_CAST(OC_Evt)->ID;
    if(id>OC_SPI_NUM_OF_INST) system_assert(__FILE__,0);

    QASM_DISPATCH( &(me->max31865_inst[id].super) ,e, (void *) 0 );

    me->measures[
        rtd_measure[id][me->max31865_inst[id].measure_read_id]
    ] = (me->max31865_inst[id].measure_read_value.data);


}

