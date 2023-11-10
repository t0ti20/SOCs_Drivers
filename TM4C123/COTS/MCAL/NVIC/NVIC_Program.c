/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  NVIC_Program.c
 *  Brief:  -
 *  Description:  Logic C File For Interrupt Ctrl Module
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "NVIC_Interface.h"
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
void NVIC_VidInterrupt_Initialization(NVIC_STATE Copy_State,NVIC_GROUPS Copy_u8Groups)
{
	if(Copy_State==NVIC_Enable)
	{
		/* RIMASK */					/* FAULTMASK */
		__asm ("CPSIE i") ;	__asm ("CPSIE f") ;	
		/* BASEPRI */
		// CONFIGURE BASE MASK
	}
	else
	{
		/* RIMASK */					/* FAULTMASK */
		__asm ("CPSID i") ; __asm ("CPSID f") ;
	}
	Set_Reg(APINT,(u32)(APINT_KEY|(Copy_u8Groups<<8)));
}
/********************************************************************
* Syntax          : Void NVIC_VidInterrupt_Set(NVIC_TYPES Copy_Interrupt,NVIC_STATE Copy_State)
* Description     : Configure Victor Table Interrupts
* Sync-Async      : -
* Reentrancy      : Non Reentrant
* Parameters (in) : (NVIC_PERIPHERAL_TYPES),(NVIC_STATE),(Group_Number),(Sub_Group_Number)
* Parameters (out): -
* Return value:   : -
********************************************************************/
void NVIC_VidInterrupt_Peripheral_Set(NVIC_PERIPHERAL_TYPES Copy_Interrupt,NVIC_STATE Copy_State,NVIC_GROUPS Copy_u8Group,NVIC_GROUPS Copy_u8Sub_Group)
{
	u8 Local_u8Group_SubGroup=(u8)(((APINT>>8)&7));
	if(Copy_Interrupt<=138)
	{
		switch(Copy_State)
		{
			case(NVIC_Disable):Set_Reg(NVIC_DISABLE_BASE[(Copy_Interrupt/32)],((u32)ONE<<(Copy_Interrupt%32)));break;
			case(NVIC_Enable):Set_Reg(NVIC_ENABLE_BASE[(Copy_Interrupt/32)],((u32)ONE<<(Copy_Interrupt%32)));break;
			case(NVIC_Set_Pending):Set_Reg(NVIC_SET_PENDING_BASE[(Copy_Interrupt/32)],((u32)ONE<<(Copy_Interrupt%32)));break;
			case(NVIC_Clear_Pending):Set_Reg(NVIC_CLEAR_PENDING_BASE[(Copy_Interrupt/32)],((u32)ONE<<(Copy_Interrupt%32)));break;
			case(NVIC_Active):Set_Reg(SWTRIG,Copy_Interrupt);break;
			case(NVIC_Not_Active):break;
		}
		switch(Local_u8Group_SubGroup)
		{
			case(NVIC_XXX):Local_u8Group_SubGroup=Copy_u8Group;break;
			case(NVIC_XXY):Local_u8Group_SubGroup=(u8)((Copy_u8Group<<1)|Copy_u8Sub_Group);break;
			case(NVIC_XYY):Local_u8Group_SubGroup=(u8)((Copy_u8Group<<2)|Copy_u8Sub_Group);break;
			case(NVIC_YYY):Local_u8Group_SubGroup=Copy_u8Sub_Group;break;
		}
		Modify_Reg(NVIC_PRIORITY_BASE[Copy_Interrupt/4],(u32)(Local_u8Group_SubGroup<<(((Copy_Interrupt%4)<<3)+4)));
	}
}
/********************************************************************
* Syntax          : Void NVIC_VidInterrupt_Core_Set(u8 Copy_u8Fault,NVIC_STATE Copy_State)
* Description     : Configure Core Interrupts
* Sync-Async      : -
* Reentrancy      : Reentrant
* Parameters (in) : (Fault Name From NVIC_CORE_TYPES) , (Fault State From NVIC_STATE)
* Parameters (out): -
* Return value:   : -
********************************************************************/
void NVIC_VidInterrupt_Core_Set(u8 Copy_u8Fault,NVIC_STATE Copy_State)
{
	switch(Copy_State)
		{
			case(NVIC_Active):
				switch(Copy_u8Fault)
				{
					case(BUS_FAULT):Set_Bit(SYSHNDCTRL,BUS_FAULT_ACTIVE);break;
					case(USAGE_FAULT):Set_Bit(SYSHNDCTRL,USAGE_FAULT_ACTIVE);break;
					case(SV_CALL):Set_Bit(SYSHNDCTRL,SV_CALL_ACTIVE);break;
					case(PEND_SV):Set_Bit(SYSHNDCTRL,PEND_SV_ACTIVE);break;
					case(SYSTICK):Set_Bit(SYSHNDCTRL,SYSTICK_ACTIVE);break;
					case(BEBUG_MONITOR):Set_Bit(SYSHNDCTRL,BEBUG_MONITOR_ACTIVE);break;
					case(MEMORY_MANAGMENT):Set_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_ACTIVE);break;
				}
			break;
			case(NVIC_Not_Active):
				switch(Copy_u8Fault)
				{
					case(BUS_FAULT):Clear_Bit(SYSHNDCTRL,BUS_FAULT_ACTIVE);break;
					case(USAGE_FAULT):Clear_Bit(SYSHNDCTRL,USAGE_FAULT_ACTIVE);break;
					case(SV_CALL):Clear_Bit(SYSHNDCTRL,SV_CALL_ACTIVE);break;
					case(PEND_SV):Clear_Bit(SYSHNDCTRL,PEND_SV_ACTIVE);break;
					case(SYSTICK):Clear_Bit(SYSHNDCTRL,SYSTICK_ACTIVE);break;
					case(BEBUG_MONITOR):Clear_Bit(SYSHNDCTRL,BEBUG_MONITOR_ACTIVE);break;
					case(MEMORY_MANAGMENT):Clear_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_ACTIVE);break;
				}
			break;
			case(NVIC_Disable):
				switch(Copy_u8Fault)
				{
					case(MEMORY_MANAGMENT):Clear_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_ENABLE);break;
					case(BUS_FAULT):Clear_Bit(SYSHNDCTRL,BUS_FAULT_ENABLE);break;
					case(USAGE_FAULT):Clear_Bit(SYSHNDCTRL,USAGE_FAULT_ENABLE);break;
				}
			break;
			case(NVIC_Enable):
				switch(Copy_u8Fault)
				{
					case(MEMORY_MANAGMENT):Set_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_ENABLE);break;
					case(BUS_FAULT):Set_Bit(SYSHNDCTRL,BUS_FAULT_ENABLE);break;
					case(USAGE_FAULT):Set_Bit(SYSHNDCTRL,USAGE_FAULT_ENABLE);break;
				}
			break;
			case(NVIC_Set_Pending):
				switch(Copy_u8Fault)
				{
					case(MEMORY_MANAGMENT):Set_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_PENDING);break;
					case(USAGE_FAULT):Set_Bit(SYSHNDCTRL,USAGE_FAULT_PENDING);break;
					case(BUS_FAULT):Set_Bit(SYSHNDCTRL,BUS_FAULT_PENDING);break;
					case(SV_CALL):Set_Bit(SYSHNDCTRL,SV_CALL_PENDING);break;
				}
			break;
			case(NVIC_Clear_Pending):
				switch(Copy_u8Fault)
				{
					case(MEMORY_MANAGMENT):Clear_Bit(SYSHNDCTRL,MEMORY_MANAGMENT_PENDING);break;
					case(USAGE_FAULT):Clear_Bit(SYSHNDCTRL,USAGE_FAULT_PENDING);break;
					case(BUS_FAULT):Clear_Bit(SYSHNDCTRL,BUS_FAULT_PENDING);break;
					case(SV_CALL):Clear_Bit(SYSHNDCTRL,SV_CALL_PENDING);break;
				}
			break;
		}
}
/********************************************************************
 *  END OF FILE: NVIC_Program.c
********************************************************************/
