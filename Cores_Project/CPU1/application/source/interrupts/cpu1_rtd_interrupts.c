/*
 * cpu1_rtd_interrupts.c
 *
 *  Created on: 20 de jun de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "board.h"

#include "max31865/max31865.h"

__interrupt void INT_RTD_DRDYA_XINT_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    BSP_BKPT;

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void INT_RTD_DRDYB_XINT_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    BSP_BKPT;

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

max31865_semaphore_t RTD_Semaphore = {
    .chip_select_requested = 0x00,
    .register_requested = 0xFF,
};

uint16_t data_received = 0;

__interrupt void INT_RTD_SPI_RX_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    data_received = max31865_read_message(RTD_SPI_BASE, &RTD_Semaphore);

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void INT_RTD_SPI_TX_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    BSP_BKPT;

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
