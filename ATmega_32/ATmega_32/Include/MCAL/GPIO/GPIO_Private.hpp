/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author: Khaled El-Sayed @t0ti20
 *  File: ./Atmega32.cpp
 *  Date: April 8, 2024
 *  Description: Deigtal Input Output Driver For Atmega32
 *  (C) 2023 "@t0ti20". All rights reserved.
*******************************************************************/
#ifndef _ATMEGA32_H_
#define _ATMEGA32_H_
/*****************************************
---------------   GPIO    ----------------
*****************************************/
/*FOR PORT A*/
#define PORTA (((volatile Register_t*)0X3B))
#define DDRA  (((volatile Register_t*)0X3A))
#define PINA  (((volatile Register_t*)0X39))
/*FOR PORT B*/
#define PORTB (((volatile Register_t*)0X38))
#define DDRB  (((volatile Register_t*)0X37))
#define PINB  (((volatile Register_t*)0X36))
/*FOR PORT C*/
#define PORTC (((volatile Register_t*)0X35))
#define DDRC  (((volatile Register_t*)0X34))
#define PINC  (((volatile Register_t*)0X33))
/*FOR PORT D*/
#define PORTD (((volatile Register_t*)0X32))
#define DDRD  (((volatile Register_t*)0X31))
#define PIND  (((volatile Register_t*)0X30))

/********************************************************************
 *  END OF FILE:  Atmega32.h
********************************************************************/
#endif
