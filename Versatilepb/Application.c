#include"UART.h"
/*---------------------------------*/
#define Printed_String 		"Hello World !"
/*---------------------------------*/
int Intery_Function()
{
	UART_0_Send_String(Printed_String);
	return 0;
}
