/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  Application
 *  Description:  Main Application Logic File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
#include "USART_Interface.h"
void Test(void);
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
int main(void) 
{	
	System_Initialization();
	int counter=0;
	while (1)
	{
		//Bootloader_Send_Message("%d",counter++);
		Test();
		Bootloader_Receive_Command();
		//Bootloader_Send_Message((const u8 *)"\033[2J\033[H");
		
		//Flash_Write_Pages(64,Data,5);
		//Bootloader_Send_Message((const u8 *)"- Hello Bootloader ! (%c)\n",(u8)USART_Receive(&UART_ONE));
	}
}
/****************************************/
void Test(void)
{
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_14,1);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_15,1);
	delay_ms(1000);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_14,0);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_15,0);
	delay_ms(1000);
	delay_ms(1000);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_0,1);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_1,1);
	delay_ms(1000);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_0,0);
	MCAL_GPIO_Write_Pin(GPIO_B,Pin_1,0);
	delay_ms(1000);
}
void System_Initialization(void)
{
    GPIO_Pin_Config_t Pin={Pin_14,Output_Push_Pull,Output_10};
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	Pin.Pin_Number=Pin_15;
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	Pin.Pin_Number=Pin_0;
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	Pin.Pin_Number=Pin_1;
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	Bootloader_Initialize();
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
