/*
 * application.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "application.h"

static QEvt const *communication_queue_sto[10];
static StackType_t communication_stack[(unsigned int)(configMINIMAL_STACK_SIZE)];

#pragma DATA_SECTION(communication_stack, ".freertosStaticStack")
#pragma DATA_ALIGN ( communication_stack , portBYTE_ALIGNMENT )

static EvtPool1_t EvtPool1_inst[EVT_POOL_1_SIZE];
static EvtPool2_t EvtPool2_inst[EVT_POOL_2_SIZE];
static EvtPool3_t EvtPool3_inst[EVT_POOL_3_SIZE];
static EvtPool4_t EvtPool4_inst[EVT_POOL_4_SIZE];

static QSubscrList subscr_sto[MAX_PUB_SIG];

void active_objects_init(void){

    QF_init();

    // Init your Event Pool

    QF_poolInit( EvtPool1_inst , sizeof(EvtPool1_inst)  , sizeof(EvtPool1_inst[0]) );
    QF_poolInit( EvtPool2_inst , sizeof(EvtPool2_inst)  , sizeof(EvtPool2_inst[0]) );
    QF_poolInit( EvtPool3_inst , sizeof(EvtPool3_inst)  , sizeof(EvtPool3_inst[0]) );
//    QF_poolInit( EvtPool4_inst , sizeof(EvtPool4_inst)  , sizeof(EvtPool4_inst[0]) );

    // Init your PS List

    QF_psInit(subscr_sto, Q_DIM(subscr_sto));

    // Init your AOs here

    /* instantiate and start the blinky active object */

    ao_communication_ctor(p_ao_communication);
    QACTIVE_START(
        p_ao_communication,                /* active object to start */
        AO_COMMUNICATION_PRIO,             /* priority of the active object */
        communication_queue_sto,           /* event queue buffer */
        Q_DIM(communication_queue_sto),    /* the length of the buffer */
        communication_stack,
        sizeof(communication_stack),
        (QEvt *)0
    );

}

void application_init(void){
    // Initialize your code here

    // Starting AOs
    active_objects_init();
}
