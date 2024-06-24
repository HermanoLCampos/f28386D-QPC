/*
 * c28x_adcs_interrupts.c
 *
 *  Created on: 2 de mai de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "board.h"

//
// INT_myADCA_1_ISR
//
__interrupt void INT_myADCA_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

//    measure_count = (measure_count+1)%100;
//    measure[measure_count] = ((float32_t) ( (1/0.36)*(1/32768.0)) )*(ADC_readResult(myADCA_RESULT_BASE, myADCA_HALL2_CURRENT)-32768);
//    measure[measure_count] = ((float32_t) ( (1/32768.0)) )*(ADC_readResult(myADCA_RESULT_BASE, myADCA_HALL2_CURRENT)-32768);
    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);
    if(true == ADC_getInterruptOverflowStatus(myADCA_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);
    }

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCB_1_ISR
//
__interrupt void INT_myADCB_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

//    measure_count = (measure_count+1)%100;
//    measure[measure_count] = ADC_readResult(myADCB_RESULT_BASE, myADCB_SKIIP2_DC_LINK_VOLTAGE);
    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    ADC_clearInterruptStatus(myADCB_BASE, ADC_INT_NUMBER1);
    if(true == ADC_getInterruptOverflowStatus(myADCB_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADCB_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADCB_BASE, ADC_INT_NUMBER1);
    }


    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCC_1_ISR
//
__interrupt void INT_myADCC_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    ADC_clearInterruptStatus(myADCC_BASE, ADC_INT_NUMBER1);
    if(true == ADC_getInterruptOverflowStatus(myADCC_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADCC_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADCC_BASE, ADC_INT_NUMBER1);
    }

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

//
// INT_myADCD_1_ISR
//
__interrupt void INT_myADCD_1_ISR(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //BreakPoint, this function shoudn't be called
//    BSP_BKPT;

    ADC_clearInterruptStatus(myADCD_BASE, ADC_INT_NUMBER1);
    if(true == ADC_getInterruptOverflowStatus(myADCD_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADCD_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADCD_BASE, ADC_INT_NUMBER1);
    }

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    // FreeRTOS: End of the ISR
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


