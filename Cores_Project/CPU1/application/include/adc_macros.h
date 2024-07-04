/*
 * adc_macros.h
 *
 *  Created on: 26 de jun de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_ADC_MACROS_H_
#define APPLICATION_INCLUDE_ADC_MACROS_H_

#define HALL1_CURRENT_BIT_FACTOR   ((3.0f/0.35f)/32768.0f)
#define HALL2_CURRENT_BIT_FACTOR   ((3.0f/0.35f)/32768.0f)

#define SKIIP1_CURRENT_BIT_FACTOR  ((1000.0f/1.85f)*((3.0f/0.35f)/32768.0f))
#define SKIIP1_TEMP_BIT_FACTOR     (10.5f*((3.0f*34.7f/10.0f)/65536.0f))
#define SKIIP1_VOLTAGE_BIT_FACTOR  ((1000.0f/7.5f)*((3.0f*34.7f/10.0f)/65536.0f))

#define SKIIP2_CURRENT_BIT_FACTOR  ((1000.0f/1.85f)*((3.0f/0.35f)/32768.0f))
#define SKIIP2_TEMP_BIT_FACTOR     ((10.5f)*((3.0f*34.7f/10.0f)/65536.0f))
#define SKIIP2_VOLTAGE_BIT_FACTOR  ((1000.0f/7.5f)*((3.0f*34.7f/10.0f)/65536.0f))


#define HALL1_CURRENT_BIT_OFFSET (32768)
#define HALL2_CURRENT_BIT_OFFSET (32768)

#define SKIIP1_CURRENT_BIT_OFFSET (32768)
#define SKIIP1_TEMP_BIT_OFFSET (-35.0f/SKIIP1_TEMP_BIT_FACTOR)
#define SKIIP1_VOLTAGE_BIT_OFFSET (0)

#define SKIIP2_CURRENT_BIT_OFFSET (32768)
#define SKIIP2_TEMP_BIT_OFFSET (-35.0f/SKIIP2_TEMP_BIT_FACTOR)
#define SKIIP2_VOLTAGE_BIT_OFFSET (0)


#endif /* APPLICATION_INCLUDE_ADC_MACROS_H_ */