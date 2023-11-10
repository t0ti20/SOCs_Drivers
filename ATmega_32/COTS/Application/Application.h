/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.h
 *  Module:  HAL/Keypad
 *  Description:  Keypad Driver Interface File
*******************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"
#include "EXTI_Interface.h"
#include "TMR_Interface.h"
/*****************************************
--------    Type  Definitions    ---------
*****************************************/

/*****************************************
---------    Configure Macros    ---------
*****************************************/

/*****************************************
---------   Prebuild Configure   ---------
*****************************************/

/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
* Syntax          : HAL_Keypad_Initialization(void)
* Description     : Initialize Keypad With Pre Build Configurations
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : None
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void System_Initialization(void);

/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
