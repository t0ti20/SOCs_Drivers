/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _MAIN_H_
 *  Module:  APP
 *  Description:  Application Header FILE
*******************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "NVIC_Interface.h"
#include "GPIO_Interface.h"
#include "GPT_Interface.h"
#include "RCC_Interface.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void Timer_ISR(void);
void System_Initialization(void);
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
#define Delay_Time_ms									(10000)
#endif
/********************************************************************
 *  END OF FILE: Main.h
********************************************************************/	
