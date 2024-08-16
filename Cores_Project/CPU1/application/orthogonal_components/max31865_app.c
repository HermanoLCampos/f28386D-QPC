/*
 * max31865_app.c
 *
 *  Created on: 15 de ago de 2024
 *      Author: ramon.martins
 */

#include "OCs/oc_max31865/oc_max31865.h"
#include "board.h"

static uint16_t oc_max_chipselect[OC_MAX31865_NUM_OF_INST] = {
    [OC_MAX31865_A_ID] = RTD_CSA,
    [OC_MAX31865_B_ID] = RTD_CSB,
};

static uint16_t oc_max_mux0[OC_MAX31865_NUM_OF_INST] = {
    [OC_MAX31865_A_ID] = RTD_MUX_A0,
    [OC_MAX31865_B_ID] = RTD_MUX_B0,
};

static uint16_t oc_max_mux1[OC_MAX31865_NUM_OF_INST] = {
    [OC_MAX31865_A_ID] = RTD_MUX_A1,
    [OC_MAX31865_B_ID] = RTD_MUX_B1,
};

uint16_t OC_MAX31865_local_queue_start(OC_MAX31865 * const me){
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


uint16_t OC_MAX31865_local_queue_send(OC_MAX31865 * const me,
                                      uint16_t const *  data){

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

uint16_t OC_MAX31865_local_queue_receive(OC_MAX31865 * const me,
                                         uint16_t * const data){
    BaseType_t err;

    err = xQueueReceive(
        me->queue_handler,  // Queue Handler
        data,              // Pointer to place the received messsage
        0U                  // Must be zero to nonbloking system
    );

    return (uint16_t) err;
}

void OC_MAX31865_max_config(OC_MAX31865 * const me){

    me->config.v_bias                         = MAX31865_CONFIG_V_BIAS_ON;
    me->config.conversion_mode                = MAX31865_CONFIG_CONVERSION_MODE_NORMALLY_OFF;
    me->config.one_shot                       = MAX31865_CONFIG_ONE_SHOT_NO_ACTION;
    me->config.number_of_wires                = MAX31865_CONFIG_NUMBER_OF_WIRES_2;
    me->config.fault_detection_cycle_control  = MAX31865_CONFIG_FAULT_DETECTION_NO_ACTION;
    me->config.clear_fault_status             = MAX31865_CONFIG_CLEAR_FAULT_STATUS_YES;
    me->config.filter_select                  = MAX31865_CONFIG_FILTER_60HZ;

    me->chip_select = oc_max_chipselect[me->id];

    {
    max31865_data_send_t data;
    data.max_register = MAX31865_WRITE_REGISTER_CONFIG;
    data.max_data = *((uint16_t *) &me->config);

    OC_Evt_SPI_Message_t * max_config = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
    max_config->super.ID = OC_SPI_RTD_SPI_ID;
    max_config->message.chipselect_io = me->chip_select;
    max_config->message.message_to_send = *((uint16_t *) &data);
    QACTIVE_POST( me->owner , &(max_config->super.super) , (void *)0);
    }

    {
    // Read SPI LSB
    max31865_data_send_t data;
    data.max_register = MAX31865_READ_REGISTER_RTD_LSB;
    data.max_data = 0;

    OC_Evt_SPI_Message_t * read_request = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
    read_request->super.ID = OC_SPI_RTD_SPI_ID;
    read_request->message.chipselect_io = me->chip_select;
    read_request->message.message_to_send = *((uint16_t *) &data);
    QACTIVE_POST( me->owner , &(read_request->super.super) , (void *)0);
    }

    {
    // Read SPI MSB
    max31865_data_send_t data;
    data.max_register = MAX31865_READ_REGISTER_RTD_MSB;
    data.max_data = 0;

    OC_Evt_SPI_Message_t * read_request = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
    read_request->super.ID = OC_SPI_RTD_SPI_ID;
    read_request->message.chipselect_io = me->chip_select;
    read_request->message.message_to_send = *((uint16_t *) &data);
    QACTIVE_POST( me->owner , &(read_request->super.super) , (void *)0);
    }

}

void OC_MAX31865_spi_one_shot_request(OC_MAX31865 * const me,
                                      uint16_t measure_id){

    me->current_measure_id = measure_id;
//    me->measure_read_value.data = 0;

    // Select Mux
    GPIO_writePin( oc_max_mux0[me->id] ,  measure_id & 0b01 );
    GPIO_writePin( oc_max_mux1[me->id] ,  measure_id & 0b10 );


    // Request MAX31865 one shot via spi
    max31865_data_send_t data;
    data.max_register = MAX31865_WRITE_REGISTER_CONFIG;

    max31865_config_t config = me->config;
    config.one_shot = MAX31865_CONFIG_ONE_SHOT_START;

    data.max_data = *((uint16_t *) &config);

    OC_Evt_SPI_Message_t * oneshot_request = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
    oneshot_request->super.ID = OC_SPI_RTD_SPI_ID;
    oneshot_request->message.chipselect_io = me->chip_select;
    oneshot_request->message.message_to_send = *((uint16_t *) &data);
    QACTIVE_POST( me->owner , &(oneshot_request->super.super) , (void *)0);


}

void OC_MAX31865_spi_read_request(OC_MAX31865 * const me){
    if(!(me->spi_read_status&0b10)){
        // Read SPI LSB
        max31865_data_send_t data;
        data.max_register = MAX31865_READ_REGISTER_RTD_LSB;
        data.max_data = 0;

        OC_Evt_SPI_Message_t * read_request = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
        read_request->super.ID = OC_SPI_RTD_SPI_ID;
        read_request->message.chipselect_io = me->chip_select;
        read_request->message.message_to_send = *((uint16_t *) &data);
        QACTIVE_POST( me->owner , &(read_request->super.super) , (void *)0);

    }
    if(!(me->spi_read_status&0b01)){
        // Read SPI MSB

        max31865_data_send_t data;
        data.max_register = MAX31865_READ_REGISTER_RTD_MSB;
        data.max_data = 0;

        OC_Evt_SPI_Message_t * read_request = Q_NEW(OC_Evt_SPI_Message_t,SPI_SEND_MSG_SIG);
        read_request->super.ID = OC_SPI_RTD_SPI_ID;
        read_request->message.chipselect_io = me->chip_select;
        read_request->message.message_to_send = *((uint16_t *) &data);
        QACTIVE_POST( me->owner , &(read_request->super.super) , (void *)0);

    }
}

void OC_MAX31865_spi_receive_message(OC_MAX31865 * const me,
                                     SPI_Message_Response_t spi_message){


    if(me->chip_select == spi_message.message_sended.chipselect_io){
        if(
            ((max31865_data_send_t *) &spi_message.message_sended.message_to_send)->max_register == MAX31865_READ_REGISTER_RTD_LSB
        ){
            max31865_lsb_data_t * data = (max31865_lsb_data_t *) &spi_message.response;
            me->spi_read_status |=0b10;
            //Store LSB Data
            me->measure_read_value.two_byte_data.lsb =  data->data;
            me->measure_threshold_fault = data->fault;

        }else if(
            ((max31865_data_send_t *) &spi_message.message_sended.message_to_send)->max_register == MAX31865_READ_REGISTER_RTD_MSB
        ){
            max31865_msb_data_t * data = (max31865_msb_data_t *) &spi_message.response;
            me->spi_read_status |=0b01;
            // Store MSB Data
            me->measure_read_value.two_byte_data.msb = data->data;

        }
    }
}


