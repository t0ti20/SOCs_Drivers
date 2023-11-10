/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  Application
 *  Description:  Main Application Logic File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
#include "FreeRTOS.h"
#include "task.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
TaskHandle_t My_Task=NULL;
void Task(void *p)
{
     while (1)
     {
          PORTA ^= 0xFF;
          vTaskDelay(500);
     }
}    
int main(void)
{
     DDRA = 0xFF;
     xTaskCreate(Task,"Task_1",200,(void*)0,tskIDLE_PRIORITY,&My_Task);
     vTaskStartScheduler();
     while (1)
     {
     }
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
