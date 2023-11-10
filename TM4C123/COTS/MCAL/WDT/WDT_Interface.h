/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _WDT_INTERFACE_H_
 *  Module:  WDT
 *  Description:  Watch Dog Timer Interface
*******************************************************************/
#ifndef _WDT_INTERFACE_H_
#define _WDT_INTERFACE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
#include "RCC_Interface.h"
#include "WDT_Private.h"
#include "WDT_Config.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void WDT_VidTimer_1_Initialization(u32 Copy_u32Time_MS,WDT_CONFIG Copy_Reset);
#endif
/********************************************************************
 *  END OF FILE: WDT_Interface.h
********************************************************************/
