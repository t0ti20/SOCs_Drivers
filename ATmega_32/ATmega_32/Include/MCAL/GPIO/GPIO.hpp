/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author: Khaled El-Sayed @t0ti20
 *  File: ./GPIO.cpp
 *  Date: April 8, 2024
 *  Description: Deigtal Input Output Driver For Atmega32
 *  (C) 2023 "@t0ti20". All rights reserved.
*******************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Standard_Types.hpp"
/*****************************************
----------   Include Files    ------------
*****************************************/
namespace Atmega32
{

class GPIO
{
public:
    enum Port:u8{Port_A,Port_B,Port_C,Port_D};
    enum Pin:u8{Pin_0,Pin_1,Pin_2,Pin_3,Pin_4,Pin_5,Pin_6,Pin_7};
    enum Direction:u8{Input,Output};
    GPIO(Port _Port,Pin _Pin,Direction _Direction);
    GPIO(Port _Port,Pin _Pin,bool _Pull_Up);
    GPIO()=delete;
    void Set(void);
    void Clear(void);
private:
    Port m_Port{};
    Pin m_Pin{};
    Direction m_Direction{};
    static volatile Register_t* DDRX[];
    static volatile Register_t* PORTX[];
    // static volatile Register_t DDRX[];
};
}
/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
