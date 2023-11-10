/* File Guard */
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "UART_Config.h"
#include "UART_Private.h"
#include "DIO_Interface.h"
/*---------------------------- UART Functions ----------------------------*/
void UART_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8Rx_Interrupt,u8 Copy_u8Tx_Interrupt);
void UART_VidReceive_Function(void(*UART_VidCallBack)(u8 *Received_Data));
void UART_VidSend_Receive (u8 Copy_u8Mode,u8 *Copy_u8Data);
void UART_VidSend_String (u8 *Copy_u8Data);
void UART_VidReceive_String (u8 *Copy_u8Data);
#endif
/* UART_INTERFACE_H_ */
