/*
 * c28x_cla1interrupts.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "board.h"
#include "cla1_config.h"
//int16_t measure[1000] = {0};
//uint16_t measure_count = 0;
//uint16_t bkpt_counter = 0;

#include "adc_macros.h"

#include "cla1_shared_memory.h"
#include "cpu1_cm_memory_shared.h"

#include "modulink.h"

//
// cla1Isr1 - CLA1 ISR 1
//
__interrupt void cla1Isr1()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;
//    bkpt_counter = (bkpt_counter+1)%1000;
//    measure_count = (measure_count+1)%1000;
//    measure[measure_count] = CLA2CPU_Message.hall2_current;
//    measure[measure_count] = ADC_readResult(myADCB_RESULT_BASE, myADCB_SKIIP2_DC_LINK_VOLTAGE);

//    if(bkpt_counter == 0){
//        measure_count = 0;
//    }

//    EPWM_AQ_OUTPUT_A
//    EPWM_forceActionQualifierSWAction(GD_HB_1_BASE, epwmOutput)
    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr2 - CLA1 ISR 2
//

//#define HALL1_CURRENT_LOW_LIMIT_CHECK ???/HALL1_CURRENT_BIT_FACTOR+HALL1_CURRENT_BIT_OFFSET
//#define HALL1_CURRENT_HIGH_LIMIT_CHECK ???/HALL1_CURRENT_BIT_FACTOR+HALL1_CURRENT_BIT_OFFSET

//#define HALL2_CURRENT_LOW_LIMIT_CHECK ???/HALL2_CURRENT_BIT_FACTOR+HALL2_CURRENT_BIT_OFFSET
//#define HALL2_CURRENT_HIGH_LIMIT_CHECK ???/HALL2_CURRENT_BIT_FACTOR+HALL2_CURRENT_BIT_OFFSET


#define SKIIP1_CURRENT_LOW_LIMIT_CHECK      ((uint16_t)(SKIIP1_CURRENT_BIT_OFFSET-CRITICAL_LIMIT_SKIIP_CURRENT/SKIIP1_CURRENT_BIT_FACTOR))
#define SKIIP1_CURRENT_HIGH_LIMIT_CHECK     ((uint16_t)(SKIIP1_CURRENT_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_CURRENT/SKIIP1_CURRENT_BIT_FACTOR))

#define SKIIP1_VOLTAGE_HIGH_LIMIT_CHECK     ((uint16_t)(SKIIP1_VOLTAGE_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_VOLTAGE/SKIIP1_VOLTAGE_BIT_FACTOR))

#define SKIIP1_TEMERATURE_HIGH_LIMIT_CHECK  ((uint16_t)(SKIIP1_TEMP_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_TEMPERATURE/SKIIP1_TEMP_BIT_FACTOR))

//values inverted
#define SKIIP2_CURRENT_LOW_LIMIT_CHECK      ((uint16_t)(SKIIP2_CURRENT_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_CURRENT/SKIIP2_CURRENT_BIT_FACTOR))
#define SKIIP2_CURRENT_HIGH_LIMIT_CHECK     ((uint16_t)(SKIIP2_CURRENT_BIT_OFFSET-CRITICAL_LIMIT_SKIIP_CURRENT/SKIIP2_CURRENT_BIT_FACTOR))

#define SKIIP2_VOLTAGE_HIGH_LIMIT_CHECK     ((uint16_t)(SKIIP2_VOLTAGE_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_VOLTAGE/SKIIP2_VOLTAGE_BIT_FACTOR))

#define SKIIP2_TEMERATURE_HIGH_LIMIT_CHECK  ((uint16_t)(SKIIP2_TEMP_BIT_OFFSET+CRITICAL_LIMIT_SKIIP_TEMPERATURE/SKIIP2_TEMP_BIT_FACTOR))


uint16_t analog_fault_counter = 0;
//float teste = 0;

//uint16_t count_timer = 0;
//uint16_t index_test;
//uint16_t vl_m[1024];
//uint16_t d_vin[1024];
//uint16_t d_vout[1024];
//uint16_t i_l_m[1024];

#pragma DATA_SECTION(CPU1_CM_Message , "MSGRAM_CPU_TO_CM")
CPU1_CM_Message_t CPU1_CM_Message;

__interrupt void cla1Isr2()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    uint16_t hall1_current_adc_val      = ADC_readResult(myADCC_RESULT_BASE, myADCC_HALL1_CURRENT);
    uint16_t hall2_current_adc_val      = ADC_readResult(myADCA_RESULT_BASE, myADCA_HALL2_CURRENT);

    uint16_t skiip1_current_adc_val     = ADC_readResult(myADCA_RESULT_BASE, myADCA_SKIIP1_CURRENT);
    uint16_t skiip1_voltage_adc_val     = ADC_readResult(myADCD_RESULT_BASE, myADCD_SKIIP1_TEMP);
    uint16_t skiip1_temperature_adc_val = ADC_readResult(myADCB_RESULT_BASE, myADCB_SKIIP1_DC_LINK_VOLTAGE);

    uint16_t skiip2_current_adc_val     = ADC_readResult(myADCC_RESULT_BASE, myADCC_SKIIP2_CURRENT);
    uint16_t skiip2_voltage_adc_val     = ADC_readResult(myADCD_RESULT_BASE, myADCD_SKIIP2_TEMP);
    uint16_t skiip2_temperature_adc_val = ADC_readResult(myADCB_RESULT_BASE, myADCB_SKIIP2_DC_LINK_VOLTAGE);

//    count_timer++;
//    if(count_timer>10){
//        count_timer = 0;
//        index_test = (index_test+1)%1024;
//        vl_m[index_test] = CLA2CPU_Message.V_L;
//        d_vin[index_test] = CLA2CPU_Message.D_Vin;
//        d_vout[index_test] = CLA2CPU_Message.D_Vout;
//        i_l_m[index_test] = CLA2CPU_Message.I_L;
//    }

    if(
        (skiip1_current_adc_val      > SKIIP1_CURRENT_HIGH_LIMIT_CHECK)       ||
        (skiip1_current_adc_val      < SKIIP1_CURRENT_LOW_LIMIT_CHECK)        ||
        (skiip1_voltage_adc_val      > SKIIP1_VOLTAGE_HIGH_LIMIT_CHECK)       ||
        (skiip1_temperature_adc_val  > SKIIP1_TEMERATURE_HIGH_LIMIT_CHECK)    ||
        (skiip2_current_adc_val      > SKIIP2_CURRENT_HIGH_LIMIT_CHECK)       ||
        (skiip2_current_adc_val      < SKIIP2_CURRENT_LOW_LIMIT_CHECK)        ||
        (skiip2_voltage_adc_val      > SKIIP2_VOLTAGE_HIGH_LIMIT_CHECK)       ||
        (skiip2_temperature_adc_val  > SKIIP2_TEMERATURE_HIGH_LIMIT_CHECK)
    ){
        if(analog_fault_counter == 0){
            analog_fault_counter = (uint16_t)(ANALOG_FAULT_MIN_TIME_MS/1000.0f*CONTROL_FREQUENCY_HZ);
            AO_Evt_Set_Multiple_Faults_t aux = {0};
            AO_Evt_Set_Multiple_Faults_t * analog_faults = Q_NEW_FROM_ISR(AO_Evt_Set_Multiple_Faults_t, SET_MULTIPLE_FAULTS_SIG);
            analog_faults->faults = aux.faults;

            analog_faults->faults.skiip1_overcurrent = (skiip1_current_adc_val      > SKIIP1_CURRENT_HIGH_LIMIT_CHECK) ||
                                                       (skiip1_current_adc_val      < SKIIP1_CURRENT_LOW_LIMIT_CHECK );
            analog_faults->faults.skiip1_overvoltage = (skiip1_voltage_adc_val      > SKIIP1_VOLTAGE_HIGH_LIMIT_CHECK);
            analog_faults->faults.skiip1_overheat    = (skiip1_temperature_adc_val  > SKIIP1_TEMERATURE_HIGH_LIMIT_CHECK);

            analog_faults->faults.skiip2_overcurrent = (skiip2_current_adc_val      > SKIIP2_CURRENT_HIGH_LIMIT_CHECK) ||
                                                       (skiip2_current_adc_val      < SKIIP2_CURRENT_LOW_LIMIT_CHECK );
//            teste = skiip2_current_adc_val;
            analog_faults->faults.skiip2_overvoltage = (skiip2_voltage_adc_val      > SKIIP2_VOLTAGE_HIGH_LIMIT_CHECK);
            analog_faults->faults.skiip2_overheat    = (skiip2_temperature_adc_val  > SKIIP2_TEMERATURE_HIGH_LIMIT_CHECK);

            QACTIVE_POST_FROM_ISR(p_ao_fsbb_control, &analog_faults->super, &xHigherPriorityTaskWoken, (void *) 0 );
        }else{
            analog_fault_counter--;
        }
    }


    // Update data directly by cla.
    CPU1_CM_Message.FSBB_IL_Setpoint = CLA2CPU_Message.FSBB_IL_Setpoint;
    CPU1_CM_Message.hall1_current    = CLA2CPU_Message.hall1_current;
    CPU1_CM_Message.hall2_current    = CLA2CPU_Message.hall2_current;
    CPU1_CM_Message.sbc_muxout       = CLA2CPU_Message.sbc_muxout;
    CPU1_CM_Message.skiip1_current   = CLA2CPU_Message.skiip1_current;
    CPU1_CM_Message.skiip1_temp      = CLA2CPU_Message.skiip1_temp;
    CPU1_CM_Message.skiip1_voltage   = CLA2CPU_Message.skiip1_voltage;
    CPU1_CM_Message.skiip2_current   = CLA2CPU_Message.skiip2_current;
    CPU1_CM_Message.skiip2_temp      = CLA2CPU_Message.skiip2_temp;
    CPU1_CM_Message.skiip2_voltage   = CLA2CPU_Message.skiip2_voltage;



    CPU1_CM_Message.D_VIN  = CLA2CPU_Message.D_Vin*1000.0f;
    CPU1_CM_Message.D_VOUT = CLA2CPU_Message.D_Vout*1000.0f;
    CPU1_CM_Message.I_COMP = (CLA2CPU_Message.I_COMP+100.0f)*10;
    CPU1_CM_Message.P_COMP = (CLA2CPU_Message.P_COMP+100.0f)*10;
    CPU1_CM_Message.V_L    = (CLA2CPU_Message.V_L+10)*1000;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr3 - CLA1 ISR 3
//
__interrupt void cla1Isr3()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr4 - CLA1 ISR 4
//
__interrupt void cla1Isr4()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr5 - CLA1 ISR 5
//
__interrupt void cla1Isr5()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr6 - CLA1 ISR 6
//
__interrupt void cla1Isr6()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr7 - CLA1 ISR 7
//
__interrupt void cla1Isr7()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// cla1Isr8 - CLA1 ISR 8
//
__interrupt void cla1Isr8()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
