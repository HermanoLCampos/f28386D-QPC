/*
 * c28x_interrupts.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_C28X_INTERRUPTS_H_
#define APPLICATION_INCLUDE_C28X_INTERRUPTS_H_

#include "main_qm.h"

__interrupt void cla1Isr1();
__interrupt void cla1Isr2();
__interrupt void cla1Isr3();
__interrupt void cla1Isr4();
__interrupt void cla1Isr5();
__interrupt void cla1Isr6();
__interrupt void cla1Isr7();
__interrupt void cla1Isr8();

__interrupt void INT_CAN_SKIIP_0_ISR();
__interrupt void INT_CAN_SKIIP_1_ISR();

__interrupt void INT_CAN_PUBLIC_0_ISR();
__interrupt void INT_CAN_PUBLIC_1_ISR();

__interrupt void INT_FO_HB_1_ISR();
__interrupt void INT_FO_HB_2_ISR();
__interrupt void INT_GD_HB_1_ISR();
__interrupt void INT_GD_HB_2_ISR();

__interrupt void INT_myADCA_1_ISR();
__interrupt void INT_myADCB_1_ISR();
__interrupt void INT_myADCC_1_ISR();
__interrupt void INT_myADCD_1_ISR();

// IPC interrupts CM
__interrupt void IPC_CM_ISR0();
__interrupt void IPC_CM_ISR1();
__interrupt void IPC_CM_ISR2();
__interrupt void IPC_CM_ISR3();
__interrupt void IPC_CM_ISR4();
__interrupt void IPC_CM_ISR5();
__interrupt void IPC_CM_ISR6();
__interrupt void IPC_CM_ISR7();

// IPC interrupts CPU2
__interrupt void IPC_CPU2_ISR0();
__interrupt void IPC_CPU2_ISR1();
__interrupt void IPC_CPU2_ISR2();
__interrupt void IPC_CPU2_ISR3();


#endif /* APPLICATION_INCLUDE_C28X_INTERRUPTS_H_ */
