/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _GPT_INTERFACE_H_
 *  Module:  GPT
 *  Description:  General Purpose Timer Interface
*******************************************************************/
#ifndef _GPT_INTERFACE_H_
#define _GPT_INTERFACE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
#include "GPT_Private.h"
#include "GPT_Config.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void GPT_VidTimer_1_PWM(u8 Copy_Frequency,u8 Copy_Duty);
void GPT_VidTimer_0_Delay_ms(u32 Copy_u32Time,u8 Copy_Interrupt);
void GPT_VidTimer_0_A_ISR(void(*Copy_VidInturrept)(void));
#endif
/********************************************************************
 *  END OF FILE: GPT_Interface.h
********************************************************************/
