/*
 * cpu1_rtd_interrupts.c
 *
 *  Created on: 20 de jun de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "board.h"

__interrupt void INT_RTD_DRDYA_XINT_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    QACTIVE_POST_FROM_ISR( p_ao_fsbb_control, &(im_evt_max31865_read_finish[OC_MAX31865_A_ID].super) , &xHigherPriorityTaskWoken ,(void *) 0 );

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void INT_RTD_DRDYB_XINT_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    QACTIVE_POST_FROM_ISR( p_ao_fsbb_control, &(im_evt_max31865_read_finish[OC_MAX31865_B_ID].super) , &xHigherPriorityTaskWoken ,(void *) 0 );

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


uint16_t data_received = 0;

__interrupt void INT_RTD_SPI_RX_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    //Send Message to AO
    QACTIVE_POST_FROM_ISR( p_ao_fsbb_control, &(im_evt_spi_receive_message[OC_SPI_RTD_SPI_ID].super) , &xHigherPriorityTaskWoken ,(void *) 0 );

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

__interrupt void INT_RTD_SPI_TX_ISR(void){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    BSP_BKPT;

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
