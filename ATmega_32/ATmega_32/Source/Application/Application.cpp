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
#include "GPIO.hpp"
#include <util/delay.h>
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
using namespace Atmega32;
int main(void)
{
     GPIO Pin_LED{GPIO::Port::Port_A,GPIO::Pin::Pin_0,GPIO::Direction::Output};
     // DIO_VidSet_Port_Direction(Port_C,255);
     // while (1)
     // {
     //      DIO_VidSet_Port_Value(Port_C,255);
     //      _delay_ms(1000);
     //      DIO_VidSet_Port_Value(Port_C,0);
     //      _delay_ms(1000);
     // }
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/

