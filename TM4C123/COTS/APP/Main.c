/******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  Main_Program.c
 *  Brief:  Blink LED With Timer
 *  Description:  Logic C File For Main Module
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Main.h"
/*****************************************
----------    GLOBAL DATA     -----------
*****************************************/
/********************************************************************
* Syntax          : int main()
* Description     : Main Function
********************************************************************/
int main()
{
	System_Initialization();
	GPT_VidTimer_0_A_ISR(Timer_ISR);
	while(TRUE){}//Busy_Wait
}
void System_Initialization(void)
{
	RCC_VidClock_Enable(RCC_GPIO,Port_A,Enable);
	RCC_VidClock_Enable(RCC_GPT,Timer_0,Enable);
	GPIO_VidMode_Pin(Port_A,Pin_0,GPIO_Output);
	GPT_VidTimer_0_Delay_ms(Delay_Time_ms,GPT_Interrupt_Enable);
	NVIC_VidInterrupt_Peripheral_Set(GPT_0_A,NVIC_Enable,NVIC_GROUP_0,NVIC_SUP_GROUP_0);
}
void Timer_ISR(void)
{
	GPIO_VidPin_Toggle(Port_A,Pin_0);
}
