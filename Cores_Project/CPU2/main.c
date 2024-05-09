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
}
