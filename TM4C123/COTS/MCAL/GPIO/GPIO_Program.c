/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  GPIO_Program.c
 *  Brief:  -
 *  Description:  Logic C File For GPIO Module
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "GPIO_Interface.h"
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
void GPIO_VidMode_Pin(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 Copy_u8Mode)
{
	//RCC_VidClock_Enable(RCC_GPIO,Copy_u8Port,Enable);
	switch(Copy_u8Port)
	{
		case(Port_A):
			switch(Copy_u8Mode)
			{
				case(GPIO_Input):
					Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DEN],Copy_u8Pin),ONE);									/* Set Digital */
					Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_AFSEL],Copy_u8Pin));									/* Set Alternate Functions */
					Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_DIR],Copy_u8Pin));										/* Set Port Direction */
					Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DEN],Copy_u8Pin),ONE);									/* Set Analog */
				break;
				case(GPIO_Output):
					Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DEN],Copy_u8Pin),ONE);									/* Set Digital */
					Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_AFSEL],Copy_u8Pin));									/* Set Alternate Functions */
					Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DIR],Copy_u8Pin),ONE);									/* Set Port Direction */
				break;
				case(GPIO_Alternate):
					Set_Bit(GPIO_A[GPIO_AFSEL],Copy_u8Pin);
				break;
				case(GPIO_Analog):
				break;
			}
		break;
		case(Port_B):break;
		case(Port_C):break;
		case(Port_D):break;
		case(Port_E):break;
		case(Port_F):break;
	}
}
/********************************************************************
* Syntax          : void GPIO_VidSet_Pin(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8State)
* Description     : Pin Level Selsect
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Pin Level)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void GPIO_VidPin_Set(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8State)
{
	switch(Copy_u8Port)
	{
		case(Port_A):Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
		case(Port_B):Set_Reg(Peripheral_BitBand(GPIO_B[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
		case(Port_C):Set_Reg(Peripheral_BitBand(GPIO_C[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
		case(Port_D):Set_Reg(Peripheral_BitBand(GPIO_D[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
		case(Port_E):Set_Reg(Peripheral_BitBand(GPIO_E[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
		case(Port_F):Set_Reg(Peripheral_BitBand(GPIO_F[GPIO_DATA],Copy_u8Pin),Copy_u8State);break;
	}
}
/********************************************************************
* Syntax          : void GPIO_VidPin_Mode_Output(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,GPIO_PIN_CONFIG Copy_u8Current,GPIO_PIN_CONFIG Copy_u8Open_Drain,GPIO_PIN_CONFIG Copy_u8Pull_Resistor)
* Description     : Output Mode Configure
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number),(Current),(Open Drain),(Pull Resistor)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void GPIO_VidMode_Pin_Output(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,GPIO_PIN_CONFIG Copy_u8Current,GPIO_PIN_CONFIG Copy_u8Open_Drain,GPIO_PIN_CONFIG Copy_u8Pull_Resistor)
{
	GPIO_VidMode_Pin(Copy_u8Port,Copy_u8Pin,GPIO_Output);
	switch(Copy_u8Port)
	{
		case(Port_A):
			/* Set Current */
			if(Copy_u8Current==_2_mA){Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DR2R],Copy_u8Pin),ONE);}
			else if(Copy_u8Current==_4_mA){Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DR4R],Copy_u8Pin),ONE);}
			else {Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_DR8R],Copy_u8Pin),ONE);}
			/* Set Open Drain */
			if(Copy_u8Open_Drain==Open_Drain_Enable){Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_ODR],Copy_u8Pin),ONE);}
			else {Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_ODR],Copy_u8Pin));}
			/* Set Pull Resistor */
			if(Copy_u8Pull_Resistor==Pull_Up){Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_PUR],Copy_u8Pin),ONE);}
			else if(Copy_u8Pull_Resistor==Pull_Down){Set_Reg(Peripheral_BitBand(GPIO_A[GPIO_PDR],Copy_u8Pin),ONE);}
			else {Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_PUR],Copy_u8Pin));Clear_Reg(Peripheral_BitBand(GPIO_A[GPIO_PDR],Copy_u8Pin));}
		break;
		case(Port_B):break;
		case(Port_C):break;
		case(Port_D):break;
		case(Port_E):break;
		case(Port_F):break;
	}
}
/********************************************************************
* Syntax          : void GPIO_VidPin_Toggle(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin)
* Description     : Toggle GPIO Pin
* Sync-Async      : Synchronous
* Reentrancy      : Nun-Reentrant
* Parameters (in) : (Port Number),(Pin Number)
* Parameters (out): None
* Return value:   : None
********************************************************************/
void GPIO_VidPin_Toggle(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case(Port_A):Toggle_Bit(GPIO_A[GPIO_DATA],Copy_u8Pin);break;
		case(Port_B):Toggle_Bit(GPIO_B[GPIO_DATA],Copy_u8Pin);break;
		case(Port_C):Toggle_Bit(GPIO_C[GPIO_DATA],Copy_u8Pin);break;
		case(Port_D):Toggle_Bit(GPIO_D[GPIO_DATA],Copy_u8Pin);break;
		case(Port_E):Toggle_Bit(GPIO_E[GPIO_DATA],Copy_u8Pin);break;
		case(Port_F):Toggle_Bit(GPIO_F[GPIO_DATA],Copy_u8Pin);break;
	}
}
/********************************************************************
* Syntax          : void GPIO_VidPin_Get(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 *Copy_pu8Status)
* Description     : Get GPIO Pin
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : (Port Number),(Pin Number)
* Parameters (out): (Status)
* Return value:   : None
********************************************************************/
void GPIO_VidPin_Get(GPIO_PORTS Copy_u8Port,GPIO_PINS Copy_u8Pin,u8 *Copy_pu8Status)
{
	switch(Copy_u8Port)
	{
		case(Port_A):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_A[GPIO_DATA],Copy_u8Pin),ZERO);break;
		case(Port_B):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_B[GPIO_DATA],Copy_u8Pin),ZERO);break;
		case(Port_C):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_C[GPIO_DATA],Copy_u8Pin),ZERO);break;
		case(Port_D):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_D[GPIO_DATA],Copy_u8Pin),ZERO);break;
		case(Port_E):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_E[GPIO_DATA],Copy_u8Pin),ZERO);break;
		case(Port_F):*Copy_pu8Status=Get_Bit(Peripheral_BitBand(GPIO_F[GPIO_DATA],Copy_u8Pin),ZERO);break;
	}
}
/********************************************************************
 *  END OF FILE: GPIO_Program.c
********************************************************************/
