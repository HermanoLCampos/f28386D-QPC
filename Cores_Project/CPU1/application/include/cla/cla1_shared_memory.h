/*
 * cla1_shared_memory.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_
#define APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_


//
// Defines
//

//
// Globals
//

// Caution use only variables with n*16bits size
// CLA to CPU Message RAM area
typedef struct{

//Task 1 (C) Variables

    uint16_t skiip1_voltage;
    int16_t skiip1_current;
    uint16_t skiip1_temp;

    uint16_t skiip2_voltage;
    int16_t skiip2_current;
    uint16_t skiip2_temp;

    int16_t hall1_current;
    int16_t hall2_current;

    uint16_t sbc_muxout;

    uint16_t task_1_watchdog_response;

//Task 2 (C) Variables

    uint16_t task_2_watchdog_response;

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables


}CLA_CPU_Message;


// Caution use only variables with n*16bits size
// CPU to CLA Message RAM area
typedef struct{

//Task 1 (C) Variables

    uint16_t task_1_watchdog_request;

//Task 2 (C) Variables
    uint16_t FSBB_Control_State;
    int16_t FSBB_IL_Setpoint;
#ifdef FORCE_DUTY_CICLE
    uint16_t duty_cicle_vin;
    uint16_t duty_cicle_vout;
#endif

    uint16_t task_2_watchdog_request;

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables

}CPU_CLA_Message;

typedef struct{ //Cla_CPU Memory, Be careful this memory can be initialized by CPU, but in real time it is only for CLA
// Put your Cla_Data which is initialized by CPU here, go to "cla1_shared_memory.c" file and initiate this data globally.

}CLA_Memory_CPU_Init;

enum{
    FSBB_CONTROL_RUNNING,
    FSBB_CONTROL_STOPPED,
    FSBB_CONTROL_ERROR,
};

#endif /* APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_ */
