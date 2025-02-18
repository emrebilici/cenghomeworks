/**********************************************************************/
/*                                                                    */
/* File name: tsk_task2.c                                             */
/*                                                                    */
/* Since:     2004-Sept-20                                            */
/*                                                                    */
/* Version:   PICos18 v2.10                                           */
/*            Copyright (C) 2003, 2004, 2005 Pragmatec.               */
/*                                                                    */
/* Author:    Designed by Pragmatec S.A.R.L.        www.pragmatec.net */
/*            MONTAGNE Xavier [XM]      xavier.montagne@pragmatec.net */
/*                                                                    */
/* Purpose:   Third task of the tutorial.                             */
/*                                                                    */
/* Distribution: This file is part of PICos18.                        */
/*            PICos18 is free software; you can redistribute it       */
/*            and/or modify it under the terms of the GNU General     */
/*            Public License as published by the Free Software        */
/*            Foundation; either version 2, or (at your option)       */
/*            any later version.                                      */
/*                                                                    */
/*            PICos18 is distributed in the hope that it will be      */
/*            useful, but WITHOUT ANY WARRANTY; without even the      */
/*            implied warranty of MERCHANTABILITY or FITNESS FOR A    */
/*            PARTICULAR PURPOSE.  See the GNU General Public         */
/*            License for more details.                               */
/*                                                                    */
/*            You should have received a copy of the GNU General      */
/*            Public License along with gpsim; see the file           */
/*            COPYING.txt. If not, write to the Free Software         */
/*            Foundation, 59 Temple Place - Suite 330,                */
/*            Boston, MA 02111-1307, USA.                             */
/*                                                                    */
/*          > A special exception to the GPL can be applied should    */
/*            you wish to distribute a combined work that includes    */
/*            PICos18, without being obliged to provide the source    */
/*            code for any proprietary components.                    */
/*                                                                    */
/* History:                                                           */
/* 2004/09/20 [XM]  Create this file.                                 */
/*                                                                    */
/**********************************************************************/

#include "define.h"

void MyOwnISR(void);

/**********************************************************************
 * Definition dedicated to the local functions.
 **********************************************************************/
#define ALARM_TSK0      0

extern unsigned char hour;

/**********************************************************************
 * ------------------------------ TASK2 -------------------------------
 *
 * Third task of the tutorial.
 *
 **********************************************************************/
TASK(TASK2) 
{
  hour++;
  if (hour == 24)
    hour = 0;
  SetEvent(TASK4_ID, UPDATE_EVENT);
  INTCON3bits.INT1IF = 0;
  INTCON3bits.INT1IE = 1;
  TerminateTask();
}

void MyOwnISR(void)
{
  TaskStateType State;

  if (INTCON3bits.INT1IF)
  {
    INTCON3bits.INT1IE = 0;
    GetTaskState(TASK2_ID, &State);
    if (State == SUSPENDED) 
      ActivateTask(TASK2_ID);
  }
  if (INTCON3bits.INT2IF)
  {
    INTCON3bits.INT2IE = 0;
    GetTaskState(TASK3_ID, &State);
    if (State == SUSPENDED) 
      ActivateTask(TASK3_ID);
  }
}
 
/* End of File : tsk_task2.c */
