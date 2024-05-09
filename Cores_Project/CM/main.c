//
// Included Files
//

#include "application.h"

void main(void)
{
    CortexM_Init();

    application_init();




    QF_run();

    while(1){
        BSP_BKPT;
    }
}
