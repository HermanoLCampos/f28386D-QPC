/*
 * spi_app.c
 *
 *  Created on: 14 de ago de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_spi/oc_spi.h"
#include "bsp_ipc.h"
#include "common_macros.h"


uint32_t oc_spi_base[OC_SPI_NUM_OF_INST] = {
    [OC_SPI_RTD_SPI_ID] = RTD_SPI_BASE,
};

void OC_SPI_spi_send_message(OC_SPI * const me,
                             SPI_Message_t message){

    // Send Message
    SPI_writeDataNonBlocking( oc_spi_base[me->id] , message.message_to_send);

    // Enable the Chip Select
    GPIO_writePin( message.chipselect_io , 0 );

    me->last_message_sended = message;

}

void OC_SPI_spi_receive_message(OC_SPI * const me){

    // Block the Chip Select
    GPIO_writePin( me->last_message_sended.chipselect_io , 1 );

    // Flush Message
    me->message_request = me->last_message_sended;

    // Get Response
    me->message_response = SPI_readDataNonBlocking( oc_spi_base[me->id] );

}

uint16_t OC_SPI_local_queue_start(OC_SPI * const me){

    me->queue_handler = xQueueCreateStatic(
            sizeof(me->queue_storage)/sizeof(me->queue_storage[0]),
            sizeof(me->queue_storage[0]),
            (uint16_t *) me->queue_storage,
            &(me->queue_buffer)
    );
    if(me->queue_handler != 0){
        return 1;
    }else{
        return 0;
    }

}
uint16_t OC_SPI_local_queue_send(OC_SPI * const me,
                                 SPI_Message_t const * data){

    BaseType_t err;

//    Space Free on the queue
//    uint16_t nfree;
//    nfree = static_queue_buffer_test.uxDummy4[1] - static_queue_buffer_test.uxDummy4[0];

    err = xQueueSendToBack(
        me->queue_handler,   // Queue Handler
        (void const *) data, // Pointer to message to send
        0U                   // Must be zero to nonbloking system
    );

    return (uint16_t) err;
}
uint16_t OC_SPI_local_queue_receive(OC_SPI * const me,
                                    SPI_Message_t * const data){

    BaseType_t err;

    err = xQueueReceive(
        me->queue_handler,  // Queue Handler
        data,              // Pointer to place the received messsage
        0U                  // Must be zero to nonbloking system
    );

    return (uint16_t) err;
}

