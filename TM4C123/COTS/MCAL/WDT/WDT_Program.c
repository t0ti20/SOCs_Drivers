/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  WDT_Program.c
 *  Brief:  -
 *  Description:  Configure Watch Dog Timers
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "WDT_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : Void WDT_VidTimer_1_Initialization(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode)
* Description     : Pin Mode Select
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Pin Mode Select)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void WDT_VidTimer_1_Initialization(u32 Copy_u32Time_MS,WDT_CONFIG Copy_Reset)
{
	//enable clock
	RCC_VidClock_Enable(RCC_WDT,ONE,Enable);
	RCC_VidClock_Enable(RCC_WDT,ZERO,Enable);
	//load with desired value+wait
	WDT_1.LOAD=((PIOSC_CLOCK)*(Copy_u32Time_MS)/1000);
	while(!Get_Bit(WDT_1.CTL,CTL_WRC));
	//enable or disable reset+wait
	if(Copy_Reset) Set_Bit(WDT_1.CTL,CTL_RESEN);
	else	Clear_Bit(WDT_1.CTL,CTL_RESEN);
	while(!Get_Bit(WDT_1.CTL,CTL_WRC));
	//interrupt enable and start
	Set_Bit(WDT_1.CTL,CTL_INTEN);
	//lock timer
}
/********************************************************************
 *  END OF FILE: WDT_Program.c
********************************************************************/
