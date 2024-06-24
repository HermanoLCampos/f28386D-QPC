/*
 * signal_processing_cla.h
 *
 *  Created on: 7 de jun de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_
#define APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_

#include "CLAmath.h"

#include "board.h"

#define N_STAGES 8

typedef struct {
    float b[N_STAGES + 1]; // Numerator coefficients
    float a[N_STAGES + 1]; // Denominator coefficients
    float x[N_STAGES + 1];
    float y[N_STAGES + 1];
}IIRFilter;

void initializeIIRFilter(IIRFilter *filter, float *b, float *a);
float applyIIRFilter(IIRFilter *filter, float input);

// Control

typedef struct{

    float Kp;
    float Ki;
    float Kd;
    float Tau;

    float P_Component;
    float I_Component;
    float D_Component;

    float Klim;

    float Max_Lim;
    float Min_Lim;

    float BackCalculation;
    float Error;

    float Ktt;

    float Error_Prev;

} PID_Control_t;

#endif /* APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_ */
