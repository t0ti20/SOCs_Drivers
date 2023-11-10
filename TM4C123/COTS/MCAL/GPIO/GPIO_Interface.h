/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _GPIO_INTERFACE_H_
 *  Module:  GPIO
 *  Description:  General Purpose Input / Output Interface
*******************************************************************/
#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
#include "RCC_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void GPIO_VidMode_Pin_Output(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,GPIO_PIN_CONFIG Copy_u8Current,GPIO_PIN_CONFIG Copy_u8Open_Drain,GPIO_PIN_CONFIG Copy_u8Pull_Resistor);
void GPIO_VidMode_Pin(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode);
void GPIO_VidPin_Set(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,GPIO_PIN_CONFIG Copy_u8State);
void GPIO_VidPin_Get(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 *Copy_pu8Status);
void GPIO_VidPin_Toggle(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin);
#endif
/********************************************************************
 *  END OF FILE: GPIO_Interface.h
********************************************************************/
