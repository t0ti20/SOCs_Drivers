/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _RCC_INTERFACE_H_
 *  Module:  RCC
 *  Description:  Reset And Ctrl Clock Interface
*******************************************************************/
#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void RCC_VidGet_Clock(u32 *Copy_pu32Clock);
void RCC_VidClock_Select(RCC_SOURCES Copy_Source);
void RCC_VidClock_Enable(RCC_CLOCK Copy_Target,u8 Copy_u8Module,MACRO_STATE Copy_State);
#endif
/********************************************************************
 *  END OF FILE: RCC_Interface.h
********************************************************************/
