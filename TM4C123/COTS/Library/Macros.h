/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  Macros.h
 *  Module:  Library
 *  Description:  Common Usage Macros
*******************************************************************/
#ifndef _MACROS_H_
#define _MACROS_H_
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/* Peripheral BitBand */
/*Only Valid From 0x4000.0000 -> 0x400F.FFFF */
#define SRAM_BIT_BAND_BASE       								(0x22000000)
#define PERIPHERAL_BIT_BAND_BASE       					(0x42000000)
#define PERIPH_BASE															(0x40000000)
#define Peripheral_BitBand(Register,Bit)        (*((volatile u32*)(PERIPHERAL_BIT_BAND_BASE+(((((u32)&(Register)))-PERIPH_BASE)*(32))+(Bit*(4)))))
#define NULL 																		((void*)0)
/* Magic Numbers */
typedef enum{FALSE,TRUE,ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHTH,NINE,TEN}MAGIC_NUMBERS;
/* Macro State */
typedef enum{Disable,Enable}MACRO_STATE;
/* Bit Math */
#define Clear_Reg(Reg) 					((Reg)  =  (0))													/* Clear Register */
#define Set_Reg(Reg,Value) 			((Reg)  =  (Value))											/* Set Register */
#define Modify_Reg(Reg,Value) 	((Reg) |=  (Value))											/* Modify Register */
#define Set_Bit(Reg,Bit)    		((Reg) |=  ((u32)1<<(u32)Bit))					/* Set Bit */
#define Clear_Bit(Reg,Bit)  		((Reg) &=~ ((u32)1<<(u32)Bit))					/* Clear Bit */
#define Get_Bit(Reg,Bit)    		(((Reg) >> (u32)Bit) & (u32)1)					/* Get Bit */
#define Toggle_Bit(Reg,Bit)     ((Reg) ^=  ((u32)1<<(u32)Bit))					/* Toggle Bit */
#endif
/********************************************************************
 *  END OF FILE: Macros.h
********************************************************************/
