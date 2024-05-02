/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author: Khaled El-Sayed @t0ti20
 *  File: ./GPIO.cpp
 *  Date: April 8, 2024
 *  Description: Deigtal Input Output Driver For Atmega32
 *  (C) 2023 "@t0ti20". All rights reserved.
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "GPIO.hpp"
#include "GPIO_Private.hpp"
#include "Macros.hpp"
#include "Standard_Types.hpp"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
namespace Atmega32
{
volatile Register_t* DDRX[]{DDRA,DDRB,DDRC,DDRD};
volatile Register_t* PORTX[]{PORTA,PORTB,PORTC,PORTD};
GPIO::GPIO(Port _Port,Pin _Pin,Direction _Direction):
m_Port(_Port),m_Pin(_Pin),m_Direction(_Direction)
{
	/*SET PIN Direction*/
	if(m_Direction==Output){Set_Bit(DDRX[m_Port].Register,m_Pin);}
	else{Clear_Bit(DDRX[m_Port].Register,m_Pin);}
	/*INTERNAL PIN PULL UP*/
	/*SET PIN Value*/
	/*SET PORT Direction*/
}

GPIO::GPIO(Port _Port,Pin _Pin,bool _Pull_Up):
GPIO{_Port,_Pin,Output}
{
	if(_Pull_Up){Set_Bit(PORTX[m_Port].Register,m_Pin);}
}
void GPIO::Set(void)
{
	Set_Bit(PORTX[m_Port].Register,m_Pin);
}
void GPIO::Clear(void)
{
	Clear_Bit(PORTX[m_Port].Register,m_Pin);
}
}
/********************************************************************
 *  END OF FILE:  GPIO.cpp
********************************************************************/