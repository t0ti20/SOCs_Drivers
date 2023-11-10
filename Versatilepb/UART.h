#ifndef _UART_H_
#define _UART_H_
/*---------------------------------*/
#define UART0	(*((volatile unsigned int * const)((unsigned int *)0x101f1000)))
/*---------------------------------*/
void UART_0_Send_String(unsigned char String[]);
/*---------------------------------*/
#endif
