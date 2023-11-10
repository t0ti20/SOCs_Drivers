/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _GPIO_PRIVATE_H_
 *  Module:  GPIO
 *  Description:  General Purpose Input / Output Private
*******************************************************************/
#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
/*****************************************
----------     ADDRESSES     -------------
*****************************************/
/* --- Peripheral Address --- */
#define PERIPH_BASE_GPIO       			(0x40000000)
//#define RCGCGPIO       							(*(volatile u32*)(0x400FE608))
#define GPIO_A            					((volatile u32*)(PERIPH_BASE_GPIO+0x04000))
#define GPIO_B            					((volatile u32*)(PERIPH_BASE_GPIO+0x05000))
#define GPIO_C            					((volatile u32*)(PERIPH_BASE_GPIO+0x06000))
#define GPIO_D            					((volatile u32*)(PERIPH_BASE_GPIO+0x07000))
#define GPIO_E       						    ((volatile u32*)(PERIPH_BASE_GPIO+0x24000))
#define GPIO_F					            ((volatile u32*)(PERIPH_BASE_GPIO+0x25000))
#define GPIO_DATA       						(0x0FF)
#define GPIO_DIR       							(0x100)
#define GPIO_IS       							(0x101)
#define GPIO_IBE       							(0x102)
#define GPIO_IEV       							(0x103)
#define GPIO_IM       							(0x104)
#define GPIO_RIS       							(0x105)
#define GPIO_MIS       							(0x106)
#define GPIO_ICR       							(0x107)
#define GPIO_AFSEL       						(0x108)
#define GPIO_DR2R       						(0x140)
#define GPIO_DR4R       						(0x141)
#define GPIO_DR8R       						(0x142)
#define GPIO_ODR       							(0x143)
#define GPIO_PUR       							(0x144)
#define GPIO_PDR      	 						(0x145)
#define GPIO_SLR       							(0x146)
#define GPIO_DEN       							(0x147)
#define GPIO_LOCK       						(0x148)
#define GPIO_CR       							(0x149)
#define GPIO_AMSEL       						(0x14A)
#define GPIO_PCTL       						(0x14B)
#define GPIO_ADCCTL       					(0x14C)
#define GPIO_MACTL       						(0x14D)
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
#define GPIO_Input      		  (0)
#define GPIO_Output     		  (1)
#define GPIO_Alternate  		  (2)
#define GPIO_Analog    			  (3)
typedef enum
{
	_2_mA											   =15,
	_4_mA												 =16,
	_8_mA												 =17,
	Hi													 =1,
	Low													 =0,
	Open_Drain_Enable						 =1,
	Open_Drain_Disable					 =0,
	Pull_Up											 =2,
	Pull_Down										 =1,
	No_Pull											 =0,
}GPIO_PIN_CONFIG;
typedef enum
{
	Port_A											 =0,
	Port_B											 =1,
	Port_C											 =2,
	Port_D											 =3,
	Port_E											 =4,
	Port_F											 =5,
}GPIO_PORTS;
typedef enum
{
	Pin_0												 =0,
	Pin_1												 =1,
	Pin_2												 =2,
	Pin_3						 						 =3,
	Pin_4												 =4,
	Pin_5												 =5,
	Pin_6												 =6,
	Pin_7												 =7,
}GPIO_PINS;
#endif
/********************************************************************
 *  END OF FILE: RCC_Private.h
********************************************************************/
