#include "common.h"

/**********************************************************************
 * ----------------------- GLOBAL VARIABLES ---------------------------
 **********************************************************************/


/**********************************************************************
 * ----------------------- LOCAL FUNCTIONS ----------------------------
 **********************************************************************/


/**********************************************************************
 * ------------------------------ TASK1 -------------------------------
 *
 * Basic echo function test. Type $hello: in cutecom and receive hello
 *
 **********************************************************************/
TASK(LCD) 
{
    PIE1bits.RCIE = 1;
    TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = 0;
    SetRelAlarm(LCD_ALARM_ID, 100, 2000);
	while(1) {
        WaitEvent(LCD_EVENT);
        ClearEvent(LCD_EVENT);
//        data_size = receiveBuffer_pop(data);
        if(1)
        {
            LATAbits.LATA0 = ~LATAbits.LATA0;
            
        }
	}
	TerminateTask();
}

/* End of File : tsk_task1.c */