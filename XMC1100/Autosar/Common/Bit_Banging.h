/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Bit_Banging.h
 *  Module:  Common
 *  Description:  Macros for Bit Manpulation 
*******************************************************************/
#ifndef _BIT_BANGING_H_
#define _BIT_BANGING_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Std_Types.h"
/*------------- Magic_Numbers -------------*/
typedef enum{ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN}numbers_t;
/*------------- Bit Math -------------*/
/*Write Specific Value On Some Consecutive Bits Givin Register To Edit , Start_Bit , Number Of Bits To Edit , Value To Be Added In Register*/
#define Write_Bits(Reg,Start_Bit,Number_Bits,Val)        ((Reg)=((Reg)&~((((uint32)1<<(Number_Bits))-(uint32)1)<<(Start_Bit)))|((uint32)(Val)<<(Start_Bit)))
/*Set Specific Bit To One In Register*/
#define Set_Bit(Reg,Bit_Num)                             ((Reg)|=1<<(Bit_Num))	
/*Set Specific Bit To Zero In Register*/		                                                       
#define Clear_Bit(Reg,Bit_Num)                           ((Reg)&=~(1<<(Bit_Num)))
/*Toggle Specific Bit In Register*/
#define Toggle_Bit(Reg,Bit_Num)                          ((Reg)^=(1<<(Bit_Num)))	
/*Get Specific Bit In Register*/
#define Get_Bit(Reg,Bit_Num)                             (((Reg)>>(Bit_Num))&1)
/*Get Some Bit In Register Given Register , Start Bit , Number Of Bits*/                  
#define Get_Bits(Reg,Start_Bit,Number_Bits)              (((Reg)>>Start_Bit)&(~((~0UL)<<Number_Bits)))   
/*------------- Max-Min -------------*/
#define Max(x,y)                   ((x)>(y))?(x):(y)                   /* Max Of Two Digits */
#define Min(x,y)                   ((x)>(y))?((y)):(x)                 /* Min Of Two Digits */
/********************************************************************
 *  END OF FILE:  Bit_Banging.h
********************************************************************/
#endif
