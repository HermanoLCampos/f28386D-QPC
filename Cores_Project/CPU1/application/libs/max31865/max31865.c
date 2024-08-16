/*
 * max31865.c
 *
 *  Created on: 20 de jun de 2024
 *      Author: ramon.martins
 */

//#include "./max31865.h"


//void max31865_send_message(uint32_t spi_base, uint16_t chip_select_gpio, max31865_registers_t max_31865_register, uint16_t max_31865_data){
//
//    max31865_data_send_t data;
//
//    data.max_register = max_31865_register;
//    data.max_data     = max_31865_data;
//
//    GPIO_writePin( chip_select_gpio , 0 );
//    SPI_writeDataNonBlocking( spi_base , *((uint16_t*) &data));
//
//}
//
//uint16_t max31865_read_message(uint32_t spi_base){
//    uint16_t data;
//
//    GPIO_writePin( semaphore->chip_select_requested , 1);
//    data = SPI_readDataNonBlocking(spi_base);
//
//    return data;
//}
//
//
//uint16_t max31865_write_config(uint32_t spi_base, uint16_t chip_select_gpio, max31865_config_t config_data){
//    return max31865_send_message(spi_base, chip_select_gpio, MAX31865_WRITE_REGISTER_CONFIG, *((uint16_t *) &config_data));
//}
