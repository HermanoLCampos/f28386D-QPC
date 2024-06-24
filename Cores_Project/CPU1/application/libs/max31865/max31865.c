/*
 * max31865.c
 *
 *  Created on: 20 de jun de 2024
 *      Author: ramon.martins
 */

#include "./max31865.h"

void max31865_start_semaphore(max31865_semaphore_t * semaphore){
    semaphore->chip_select_requested = 0x00;
    semaphore->register_requested = 0xFF;
}

uint16_t max31865_send_message(uint32_t spi_base, uint16_t chip_select_gpio, max31865_registers_t max_31865_register, uint16_t max_31865_data, max31865_semaphore_t * semaphore){

    max31865_data_send_t data;

    if(semaphore->register_requested == 0xFF){
        semaphore->register_requested = max_31865_register;
        semaphore->chip_select_requested = chip_select_gpio;

        data.max_register = max_31865_register;
        data.max_data     = max_31865_data;

        GPIO_writePin( chip_select_gpio , 0 );
        SPI_writeDataNonBlocking( spi_base , *((uint16_t*) &data));
        return 1;
    }else
        return 0;
}

uint16_t max31865_read_message(uint32_t spi_base, max31865_semaphore_t * semaphore){
    uint16_t data;

    GPIO_writePin( semaphore->chip_select_requested , 1);
    data = SPI_readDataNonBlocking(spi_base);

    semaphore->register_requested = 0xFF;
    semaphore->chip_select_requested = 0x00;
    return data;
}


uint16_t max31865_write_config(uint32_t spi_base, uint16_t chip_select_gpio, max31865_config_t config_data, max31865_semaphore_t * semaphore){
    return max31865_send_message(spi_base, chip_select_gpio, MAX31865_WRITE_REGISTER_CONFIG, *((uint16_t *) &config_data), semaphore);
}
