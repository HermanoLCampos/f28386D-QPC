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
#pragma DATA_ALIGN ( communication_stack , portBYTE_ALIGNMENT)

//static Evt2Bytes Evt2Bytes_EvtPool[8];
//static Evt8Bytes Evt8Bytes_EvtPool[8];
//static Evt16Bytes Evt16Bytes_EvtPool[8];
//static Evt32Bytes Evt32Bytes_EvtPool[8];

static QSubscrList subscr_sto[MAX_PUB_SIG];

void active_objects_init(void){

    QF_init();

// Init your Event Pool

//    QF_poolInit(    Evt2Bytes_EvtPool   ,   sizeof( Evt2Bytes_EvtPool)  ,   sizeof( Evt2Bytes_EvtPool[0])   );
//    QF_poolInit(    Evt8Bytes_EvtPool   ,   sizeof( Evt8Bytes_EvtPool)  ,   sizeof( Evt8Bytes_EvtPool[0])   );
//    QF_poolInit(    Evt16Bytes_EvtPool  ,   sizeof(Evt16Bytes_EvtPool)  ,   sizeof(Evt16Bytes_EvtPool[0])   );
//    QF_poolInit(    Evt32Bytes_EvtPool  ,   sizeof(Evt32Bytes_EvtPool)  ,   sizeof(Evt32Bytes_EvtPool[0])   );


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

    //    CLA_forceTasks(myCLA0_BASE, CLA_TASKFLAG_1);

    // Starting AOs
    active_objects_init();
}
