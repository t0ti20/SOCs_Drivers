#include"UART.h"
/*---------------------------------*/
void UART_0_Send_String(unsigned char String[])
{
	while(*String)
	{
		UART0=(unsigned int)*String;
		String++;
	}
}
/*---------------------------------*/
