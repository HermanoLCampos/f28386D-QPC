/*
 * c28x_interrupts.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_C28X_INTERRUPTS_H_
#define APPLICATION_INCLUDE_C28X_INTERRUPTS_H_

#include "FreeRTOS.h"

__interrupt void cla1Isr1();
__interrupt void cla1Isr2();
__interrupt void cla1Isr3();
__interrupt void cla1Isr4();
__interrupt void cla1Isr5();
__interrupt void cla1Isr6();
__interrupt void cla1Isr7();
__interrupt void cla1Isr8();

__interrupt void INT_CAN1_0_ISR();
__interrupt void INT_CAN1_1_ISR();

__interrupt void INT_CAN2_0_ISR();
__interrupt void INT_CAN2_1_ISR();

__interrupt void INT_FO_HB_1_ISR();
__interrupt void INT_FO_HB_2_ISR();
__interrupt void INT_GD_HB_1_ISR();
__interrupt void INT_GD_HB_2_ISR();

__interrupt void INT_myADCA_1_ISR();
__interrupt void INT_myADCB_1_ISR();
__interrupt void INT_myADCC_1_ISR();
__interrupt void INT_myADCD_1_ISR();


#endif /* APPLICATION_INCLUDE_C28X_INTERRUPTS_H_ */
