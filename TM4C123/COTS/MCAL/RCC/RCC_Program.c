/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  RCC_Program.c
 *  Brief:  Reset and Clock Ctrl
 *  Description:  Configure Reset and Clock For System
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "RCC_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : Void NVIC_VidInterrupt_Initialization(NVIC_STATE Copy_State,NVIC_GROUPS Copy_u8Groups)
* Description     : Initialization Interrupt 
* Sync-Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : (NVIC_Enable-NVIC_Disable),(NVIC_XXX,NVIC_XXY,NVIC_XYY,NVIC_YYY)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void RCC_VidGet_Clock(u32 *Copy_pu32Clock)
	{
	switch(RCC.Bits.OSCSRC)
	{
		case(RCC_Main_Oscillator):break;
		case(RCC_Precision_Internal):*Copy_pu32Clock=(u32)16000000;break;
		case(RCC_Precision_Internal_4):*Copy_pu32Clock=(u32)4000000;break;
		case(RCC_Low_Frequency):break;
	}
}	
/********************************************************************
* Syntax          : Void NVIC_VidInterrupt_Initialization(NVIC_STATE Copy_State,NVIC_GROUPS Copy_u8Groups)
* Description     : Initialization Interrupt 
* Sync-Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : (NVIC_Enable-NVIC_Disable),(NVIC_XXX,NVIC_XXY,NVIC_XYY,NVIC_YYY)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void RCC_VidClock_Select(RCC_SOURCES Copy_Source)
{
	RCC.Bits.OSCSRC=Copy_Source;
}
/********************************************************************
* Syntax          : void RCC_VidClock_Enable(RCC_CLOCK Copy_Target,u8 Copy_u8Module,MACRO_STATE Copy_State)
* Description     : Enable Modules Clock
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Target Module),(Select Module'Bit'),(State)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void RCC_VidClock_Enable(RCC_CLOCK Copy_Target,u8 Copy_u8Module,MACRO_STATE Copy_State)
{
	switch(Copy_Target)
	{
		case(RCC_PWM):Set_Reg(Peripheral_BitBand(CLOCK[RCGCPWM],Copy_u8Module),Copy_State);break;
		case(RCC_GPIO):Set_Reg(Peripheral_BitBand(CLOCK[RCGCGPIO],Copy_u8Module),Copy_State);break;
		case(RCC_WDT):Set_Reg(Peripheral_BitBand(CLOCK[RCGCWD],Copy_u8Module),Copy_State);break;
		case(RCC_GPT):Set_Reg(Peripheral_BitBand(CLOCK[RCGCTIMER],Copy_u8Module),Copy_State);break;
	}
}
