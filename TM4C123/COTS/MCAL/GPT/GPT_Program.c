/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  GPT_Program.c
 *  Brief:  -
 *  Description:  Logic C File For Timer Module
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "GPT_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : Void GPIO_VidPin_Mode(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode)
* Description     : Pin Mode Select
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Pin Mode Select)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void GPT_VidTimer_0_Delay_ms(u32 Copy_u32Time,u8 Copy_Interrupt)
{
	//Enable Clock To Timer
	//RCC_VidClock_Enable(RCC_GPT,Timer_0,Enable);
	//Select mode (16-32-64)
	Set_Reg(Peripheral_BitBand(GPT_0.CFG,0),ZERO);
	Set_Reg(Peripheral_BitBand(GPT_0.CFG,1),ZERO);
	Set_Reg(Peripheral_BitBand(GPT_0.CFG,2),ZERO);
	//Disable timer (a-b)
	Clear_Bit(GPT_0.CTL,ZERO);
	//Count Down
	Clear_Bit(GPT_0.TAMR,FOUR);
	//Periodic mode 
	Set_Bit(GPT_0.TAMR,ONE);
	//Load value
	GPT_0.TAILR=(Copy_u32Time*(F_CPU/1000));
	//Make sure time flag is clear
	Set_Bit(GPT_0.ICR,ZERO);
	//Enable timer
	Set_Bit(GPT_0.CTL,ZERO);
	//Busy wait or Interrupt
	switch(Copy_Interrupt)
	{
		case(GPT_Interrupt_Enable):Set_Reg(Peripheral_BitBand(GPT_0.IMR,ZERO),ONE);
		break;//Set Interrupt
		case(GPT_Interrupt_Disable):while(!Get_Bit(GPT_0.RIS,ZERO));
		break;//Busy_Wait
	}
	//NVIC_VidInterrupt_Peripheral_Set(GPT_0_A,NVIC_Enable,NVIC_GROUP_0,NVIC_SUP_GROUP_0);
}
/********************************************************************
* Syntax          : Void GPIO_VidPin_Mode(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode)
* Description     : Pin Mode Select
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Pin Mode Select)
* Parameters (out): None
* Return value:   : None
********************************************************************/
static void (*GPT_VidTimer_0_A_ISR_Fuction)(void)=NULL;
void GPT_VidTimer_0_A_ISR(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		GPT_VidTimer_0_A_ISR_Fuction = Copy_VidInturrept;
	}
}
void TIMER0A_Handler(void);
void TIMER0A_Handler(void)
{
	if(GPT_VidTimer_0_A_ISR_Fuction!=0)
	{
		GPT_VidTimer_0_A_ISR_Fuction();
		Set_Bit(GPT_0.ICR,ZERO);
	}
}
/********************************************************************
* Syntax          : Void GPIO_VidPin_Mode(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode)
* Description     : Pin Mode Select
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Pin Mode Select)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void GPT_VidTimer_1_PWM(u8 Copy_Prescalar,u8 Copy_Duty)
{
	u32 Local_u32Match=((1<<(16+Copy_Prescalar))-1);
	//Enable Timer Clock
	RCC_VidClock_Enable(RCC_GPT,Timer_1,Enable);
	//Ensure the timer is disabled - (GPTMCTL) TnEN
	Set_Reg(Peripheral_BitBand(GPT_1.CTL,ZERO),ZERO);
	//Config 16 Bit Timer	-	(GPTMCFG)
	Set_Reg(Peripheral_BitBand(GPT_1.CFG,TWO),ONE);
	//Set PWM Mode	-	(GPTMTAMR) TnAMS=1/TnCMR=0/TnMR=2
	Set_Reg(Peripheral_BitBand(GPT_1.TAMR,THREE),ONE);
	Set_Reg(Peripheral_BitBand(GPT_1.TAMR,TWO),ZERO);
	Set_Reg(Peripheral_BitBand(GPT_1.TAMR,ONE),ONE);
	//Inversion Type	-	(GPTMCTL) TAPWML=0
	Set_Reg(Peripheral_BitBand(GPT_1.CTL,GPT_CTL_TBPWML),ZERO);
	//Prescaler Select	-	(GPTMTnPR)
	Set_Reg(GPT_1.TAPR,Local_u32Match>>16);
	//Interrupt Configure	-	(GPTMCTL)(GPTMTnMR)
	//Load The Timer Start Value - (GPTMTnILR)
	Set_Reg(GPT_1.TAILR,(u16)Local_u32Match);
	//equation
	Local_u32Match=Local_u32Match*(1-(Copy_Duty/100));
	//Load Timer Match -	(GPTMTnMATCHR)
	Set_Reg(GPT_1.TAMATCHR,Local_u32Match);
	//Enable Timer - (GPTMCTL) TnEN
	Set_Reg(Peripheral_BitBand(GPT_1.CTL,ZERO),ONE);
}
/********************************************************************
 *  END OF FILE: GPT_Program.c
********************************************************************/
