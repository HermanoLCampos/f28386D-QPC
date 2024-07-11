/*
 * c28x_cm_memory_shared.h
 *
 *  Created on: 9 de jul de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_COMMON_INCLUDE_C28X_CM_MEMORY_SHARED_H_
#define BSP_COMMON_INCLUDE_C28X_CM_MEMORY_SHARED_H_

#include "application.h"

typedef struct{

    uint16_t skiip1_voltage;
    int16_t skiip1_current;
    uint16_t skiip1_temp;
    uint16_t skiip2_voltage;
    int16_t skiip2_current;
    uint16_t skiip2_temp;
    int16_t hall1_current;
    int16_t hall2_current;
    uint16_t sbc_muxout;
    uint16_t FSBB_IL_Setpoint;

}CPU1_CM_Message_t;


#endif /* BSP_COMMON_INCLUDE_C28X_CM_MEMORY_SHARED_H_ */
