/*
 * max31865.h
 *
 *  Created on: 20 de jun de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_LIBS_MAX31865_MAX31865_H_
#define APPLICATION_LIBS_MAX31865_MAX31865_H_


#define MAX31865_ADC_RESOLUTION 32768.0f

typedef enum max31865_registers{
// Read Registers
    MAX31865_READ_REGISTER_CONFIG                       = 0x00,
    MAX31865_READ_REGISTER_RTD_MSB                      = 0x01,
    MAX31865_READ_REGISTER_RTD_LSB                      = 0x02,
    MAX31865_READ_REGISTER_HIGH_FAULT_THRESHOULD_MSB    = 0x03,
    MAX31865_READ_REGISTER_HIGH_FAULT_THRESHOULD_LSB    = 0x04,
    MAX31865_READ_REGISTER_LOW_FAULT_THRESHOULD_MSB     = 0x05,
    MAX31865_READ_REGISTER_LOW_FAULT_THRESHOULD_LSB     = 0x06,
    MAX31865_READ_REGISTER_FALT_STATUS                  = 0x07,
// Write Registers
    MAX31865_WRITE_REGISTER_CONFIG                      = 0x80,
//    MAX31865_WRITE_REGISTER_RTD_MSB                     = 0x81, // This Register Shouldn't be Writed
//    MAX31865_WRITE_REGISTER_RTD_LSB                     = 0x82, // This Register Shouldn't be Writed
    MAX31865_WRITE_REGISTER_HIGH_FAULT_THRESHOULD_MSB   = 0x83,
    MAX31865_WRITE_REGISTER_HIGH_FAULT_THRESHOULD_LSB   = 0x84,
    MAX31865_WRITE_REGISTER_LOW_FAULT_THRESHOULD_MSB    = 0x85,
    MAX31865_WRITE_REGISTER_LOW_FAULT_THRESHOULD_LSB    = 0x86,
//    MAX31865_WRITE_REGISTER_FALT_STATUS                 = 0x87, // This Register Shouldn't be Writed
}max31865_registers_t;

typedef enum{
    MAX31865_CONFIG_FILTER_60HZ = 0b0,
    MAX31865_CONFIG_FILTER_50HZ = 0b1,
}max31865_config_filter_t;

typedef enum{
    MAX31865_CONFIG_CLEAR_FAULT_STATUS_NO  = 0b0,
    MAX31865_CONFIG_CLEAR_FAULT_STATUS_YES = 0b1,
}max31865_config_clear_fault_t;

typedef enum{
    MAX31865_CONFIG_FAULT_DETECTION_NO_ACTION = 0b00,
    MAX31865_CONFIG_FAULT_DETECTION_AUTOMATIC = 0b01,
    MAX31865_CONFIG_FAULT_DETECTION_1_STAGE   = 0b10,
    MAX31865_CONFIG_FAULT_DETECTION_2_STAGE   = 0b11,
}max31865_config_fault_detection_t;

typedef enum{
    MAX31865_CONFIG_NUMBER_OF_WIRES_2 = 0b0,
    MAX31865_CONFIG_NUMBER_OF_WIRES_3 = 0b1,
    MAX31865_CONFIG_NUMBER_OF_WIRES_4 = 0b0,
}max31865_config_number_of_wires_t;

typedef enum{
    MAX31865_CONFIG_ONE_SHOT_NO_ACTION = 0b0,
    MAX31865_CONFIG_ONE_SHOT_START     = 0b1,
}max31865_config_one_shot_t;

typedef enum{
    MAX31865_CONFIG_CONVERSION_MODE_NORMALLY_OFF = 0b0, // Needs Trigger the One-Shot
    MAX31865_CONFIG_CONVERSION_MODE_AUTOMATIC    = 0b0, // ADC Converst Automaticly
}max31865_config_conversion_mode_t;

typedef enum{
    MAX31865_CONFIG_V_BIAS_OFF = 0, //
    MAX31865_CONFIG_V_BIAS_ON  = 1,
    // Activate Vbias 10.5 time constants of the input RC network plus an additional 1ms before the conversion
    //
}max31865_config_vbias_t;

typedef struct{
    max31865_config_filter_t            filter_select:1;
    max31865_config_clear_fault_t       clear_fault_status:1;
    max31865_config_fault_detection_t   fault_detection_cycle_control:2;
    max31865_config_number_of_wires_t   number_of_wires:1;
    max31865_config_one_shot_t          one_shot:1;
    max31865_config_conversion_mode_t   conversion_mode:1;
    max31865_config_vbias_t v_bias:1;
    uint16_t reseverd:8;
}max31865_config_t;

typedef struct{
    uint16_t reserved_1:2;
    uint16_t overvoltage_undervoltage_fault:1;
    uint16_t rtd_in_fault:1;
    uint16_t low_ref_in_fault:1;
    uint16_t hi_ref_in_fault:1;
    uint16_t rtd_low_threshold:1;
    uint16_t rtd_hi_threshold:1;
    uint16_t reseverd_2:8;
}max31865_falt_status_t;

typedef struct{
    uint16_t data:8;
    uint16_t reserved:8;
}max31865_msb_data_t;

typedef struct{
    uint16_t fault:1; // just in case of RTD
    uint16_t data:7;
    uint16_t reserved:8;
}max31865_lsb_data_t;

typedef struct{
    uint16_t max_data:8;
    uint16_t max_register:8;
}max31865_data_send_t;

typedef struct{
    uint16_t register_requested;
    uint16_t chip_select_requested;
}max31865_semaphore_t;

void max31865_start_semaphore(max31865_semaphore_t * semaphore);
uint16_t max31865_send_message(uint32_t spi_base, uint16_t chip_select_gpio, max31865_registers_t max_31865_register, uint16_t max_31865_data, max31865_semaphore_t * semaphore);
uint16_t max31865_write_config(uint32_t spi_base, uint16_t chip_select_gpio, max31865_config_t config_data, max31865_semaphore_t * semaphore);

// Put this function on SPI Interrupt
uint16_t max31865_read_message(uint32_t spi_base, max31865_semaphore_t * semaphore);


#endif /* APPLICATION_LIBS_MAX31865_MAX31865_H_ */
