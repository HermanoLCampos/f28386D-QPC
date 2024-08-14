//
// Included Files
//

#include "application.h"

void main(void)
{
    C2000_Init();

    application_init();

    EINT;
    ERTM;

    QF_run();

    while(1){
        BSP_BKPT;
    }



//    OC_SPI_ctor(&instance , (void *) 0 , OC_SPI_RTD_SPI_ID);
//    QASM_INIT( &(instance.super) , (void *)0, (void *)0 );
//    QASM_DISPATCH( &(instance.super),&im_evt_running_qf, (void *) 0 );
//    QASM_DISPATCH( &(instance.super) ,&im_evt_init_complete, (void *) 0 );



//    max31865_config_t config ={
//        .v_bias                         = MAX31865_CONFIG_V_BIAS_ON,
//        .conversion_mode                = MAX31865_CONFIG_CONVERSION_MODE_NORMALLY_OFF,
//        .one_shot                       = MAX31865_CONFIG_ONE_SHOT_NO_ACTION,
//        .number_of_wires                = MAX31865_CONFIG_NUMBER_OF_WIRES_2,
//        .fault_detection_cycle_control  = MAX31865_CONFIG_FAULT_DETECTION_NO_ACTION,
//        .clear_fault_status             = MAX31865_CONFIG_CLEAR_FAULT_STATUS_YES,
//        .filter_select                  = MAX31865_CONFIG_FILTER_60HZ,
//    };
//
//
//    extern max31865_semaphore_t RTD_Semaphore;
//    max31865_write_config(RTD_SPI_BASE, RTD_CSA, config, &RTD_Semaphore);
//
//    while(1){
//        DEVICE_DELAY_US(1000000);
//        max31865_send_message(RTD_SPI_BASE, RTD_CSA, MAX31865_READ_REGISTER_CONFIG, 0 , &RTD_Semaphore);
//    }
//

}
