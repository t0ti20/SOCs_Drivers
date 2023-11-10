/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Bootloader.c
 *  Module:  Library/Bootloader
 *  Description:  Bootloader Logic File
*******************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "USART_Interface.h"
#include "Bootloader.h"
#include "FLASH.h"
#include "CRC.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
static u16 Chip_ID=Chip_ID_Number;
//static u8 UART_Buffer[Maximum_Buffer_Size];
static u32 UART_Buffer[Maximum_Buffer_Size];
static u8 SW_Major_Version=Basic_SW_Major_Version;
static u8 SW_Minor_Version=Basic_SW_Minor_Version;
static u8 SW_Patch_Version=Basic_SW_Patch_Version;
static USART_Config_t UART_ONE={NULL,USART_1,USART_No_Parity,USART_Rx_Tx,Disable,USART_Eight_Bits,USART_One_Stop,USART_9600,USART_Disable_Interrupt};
/*****************************************
---  Application Programming Interface  --
*****************************************/
static void Bootloader_Send_ACK(u8 Data_Length)
{
	USART_Transmit(&UART_ONE,(u16)Bootloader_State_ACK);
	USART_Transmit(&UART_ONE,(u16)Data_Length);
}
static void Bootloader_Send_NACK(void)
{
	USART_Transmit(&UART_ONE,(u16)Bootloader_State_NACK);
}

static logic_t Bootloader_CRC_Check(void)
{
	u8 Counter;
	u32 Actual_Value=ZERO;
	CRC_Reset();
	for(Counter=ONE;Counter<UART_Buffer[ZERO];Counter++)
	{
		Actual_Value=CRC_Accumulate(UART_Buffer[Counter]);
	}
	return (UART_Buffer[UART_Buffer[ZERO]])==Actual_Value?TRUE:FALSE;
}
static void Bootloader_Send_Version(void)
{
	u8 Message[6]={SW_Major_Version,SW_Minor_Version,SW_Patch_Version};
	Bootloader_Send_ACK(THREE);
	USART_Send_Array(&UART_ONE,Message,THREE);
}
static void Bootloader_Erase_Flash(void)
{
	Bootloader_Send_ACK(ONE);
	if(Bootloader_State_Ok==Flash_Erase_Pages(Bootloader_Total_Pages,(128-Bootloader_Total_Pages)))
	{
		USART_Transmit(&UART_ONE,Bootloader_State_Successful_Erase);
	}
	else
	{
		USART_Transmit(&UART_ONE,Bootloader_State_Unsuccessful_Erase);
	}
}

static void Bootloader_Send_ID(void)
{
	Bootloader_Send_ACK(THREE);
	USART_Send_Array(&UART_ONE,(u8*)&Chip_ID,TWO);
}

static void Bootloader_Send_Help(void)
{
	u8 Message[6]={Bootloader_Command_Send_Version,Bootloader_Command_Send_ID,Bootloader_Command_Send_Help,Bootloader_Command_Erase_Flash,Bootloader_Command_Write_Flash};
	Bootloader_Send_ACK(SIX);
	USART_Send_Array(&UART_ONE,Message,SIX);
}

static void Bootloader_Write_Flash(void)
{
	Bootloader_Send_ACK(ONE);
	
	if(Bootloader_State_Ok==Flash_Write_Pages(Bootloader_Total_Pages,(u16*)(&UART_Buffer[TWO]),UART_Buffer[TWO]-FIVE))
	{
		USART_Transmit(&UART_ONE,Bootloader_State_Successful_Write);
	}
	else
	{
		USART_Transmit(&UART_ONE,Bootloader_State_Unsuccessful_Write);
	}
}

static void Bootloader_Check_Command(void)
{
	switch ((Bootloader_Command_t)UART_Buffer[1])
	{
		case Bootloader_Command_Send_Help:Bootloader_Send_Help();break;
		case Bootloader_Command_Send_ID:Bootloader_Send_ID();break;
		case Bootloader_Command_Send_Version:Bootloader_Send_Version();break;
		case Bootloader_Command_Erase_Flash:Bootloader_Erase_Flash();break;
		case Bootloader_Command_Write_Flash:Bootloader_Write_Flash();break;
	}
}

void Bootloader_Receive_Command(void)
{
	while(1)Bootloader_Send_Help();
	u8 Frame_Length=ZERO;
	UART_Buffer[ZERO]=(u8)USART_Receive(&UART_ONE);
	for(Frame_Length=ONE;Frame_Length<=UART_Buffer[ZERO];Frame_Length++)
	{
		UART_Buffer[Frame_Length]=ZERO;
		UART_Buffer[Frame_Length]|=((u8)USART_Receive(&UART_ONE)<<24);
		UART_Buffer[Frame_Length]|=((u8)USART_Receive(&UART_ONE)<<16);
		UART_Buffer[Frame_Length]|=((u8)USART_Receive(&UART_ONE)<<8);
		UART_Buffer[Frame_Length]|=(u8)USART_Receive(&UART_ONE);
	}
	if(TRUE==Bootloader_CRC_Check())
	{
		Bootloader_Check_Command();
	}
	else
	{
		Bootloader_Send_NACK();
	}
}
 

void Bootloader_Send_Message(const u8 *Message,...)
{
	va_list Arguments;
	va_start(Arguments,Message);
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
	vsprintf((char *)UART_Buffer,(const char *)Message,Arguments);
#pragma clang diagnostic pop
	USART_Send_String(&UART_ONE,(const u8 *)UART_Buffer);
	va_end(Arguments);
}


void Bootloader_Initialize(void)
{
	USART_Initialization(&UART_ONE);
	CRC_Initialization();
}
/********************************************************************
 *  END OF FILE:  Bootloader.c
********************************************************************/
