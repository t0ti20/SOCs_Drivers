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
// static USART_Config_t UART_ONE={NULL,USART_1,USART_No_Parity,USART_Rx_Tx,Disable,USART_Eight_Bits,USART_One_Stop,USART_9600,USART_Disable_Interrupt};

/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/****************************************/
int main(void) 
{	
	
     //Bootloader_Send_Message((const u8 *)"Hello Boot Loader (%d)\n",10);
	//Flash_Erase_Pages(20,107);
		//u32 Data[]={0x20004000,0x20005000,0x20006000,0x20007000,0x20008000};
	System_Initialization();
	
	while (1)
	{
		Bootloader_Receive_Command();
		// MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_1);
		// delay_ms(2000)
		// MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_2);
		// delay_ms(2000)
		// MCAL_GPIO_Toggle_Pin(GPIO_B,Pin_6);
		// delay_ms(2000)
		// MCAL_GPIO_Toggle_Pin(GPIO_B,Pin_7);
		//Bootloader_Send_Message((const u8 *)"\033[2J\033[H");
		//delay_ms(4000);
		//Flash_Write_Pages(64,Data,5);
		// Bootloader_Send_Message((const u8 *)"- Hello Bootloader ! (%c)\n",(u8)USART_Receive(&UART_ONE));
	}
}
/****************************************/

void System_Initialization(void)
{
     GPIO_Pin_Config_t Pin={Pin_1,Output_Push_Pull,Output_10};
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_2;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_7;
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	Pin.Pin_Number=Pin_6;
	MCAL_GPIO_Initialize(GPIO_B,Pin);
	while(1)MCAL_GPIO_Toggle_Pin(GPIO_B,Pin_6);
	//Bootloader_Initialize();
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
