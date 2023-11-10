/********************************************************************
* File Description
-----------------------
* Owner       : Khaled El-Sayed @t0ti20
* File        : Application.c
* Module      : ./Application
* Description : This application tests the GPIO driver for the Infineon XM1100.
*               It configures and controls various GPIO pins for demonstration purposes.
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "GPIO_Interface.h"
/*****************************************
----------- Global Variables -------------
*****************************************/
/*----------- Pin Configure ------------*/
static GPIO_Pin_Config_t Pin=
{
	GPIO_Port_0,
	GPIO_Pin_0,
	GPIO_Mode_Output_Push_Pull,
	GPIO_Hysteresis_Standard,
	Disable,
	Disable,
	GPIO_Control_Software
};
/*------------- Pins Array -------------*/
static GPIO_Pin_t Pins[]={GPIO_Pin_0,GPIO_Pin_2,GPIO_Pin_4,GPIO_Pin_8,GPIO_Pin_12,GPIO_Pin_15};
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{
	u32 Counter,Delay;
	/*Configure Pins From Array*/
	for(Counter=ZERO;Counter<6;Counter++)
	{
		Pin.Pin=Pins[Counter];
		GPIO_Initialization(&Pin);
	}
	while(1)
	{
		/*Change Pin Value*/
		for(Counter=ZERO;Counter<6;Counter++)
		{
			Pin.Pin=Pins[Counter];
			GPIO_Edit_Pin_Value(&Pin,GPIO_Output_Toggle);
			for(Delay=ZERO;Delay<(u32)0xffff;Delay++);
			GPIO_Edit_Pin_Value(&Pin,GPIO_Output_Toggle);
			for(Delay=ZERO;Delay<(u32)0xffff;Delay++);
		}
	}
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
