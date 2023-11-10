/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Macros.h
 *  Module:  Library
 *  Description:  Common Macros Needed In Any Project
*******************************************************************/
#ifndef _MACROS_H_
#define _MACROS_H_
/********************************************************************/
/*---------- Include Files -------------*/
#include "Standard_Types.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Logic -------------*/
typedef enum{False=0,True,FALSE=0,TRUE,Disable=0,Enable,DISABLE=0,ENABLE}logic_t;
/*------------- Magic_Numbers -------------*/
typedef enum{ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN}numbers_t;
/*------------- Null -------------*/
#ifndef NULL
#define NULL   	               ((void*) 0 )                  /* NULL Pointer */
#endif
/*------------- Bit Math -------------*/
/*Write Specific Value On Some Consecutive Bits Givin Register To Edit , Start_Bit , Number Of Bits To Edit , Value To Be Added In Register*/
#define Write_Bits(Reg,Start_Bit,Number_Bits,Val)        ((Reg)=((Reg)&~((((u32)1<<(Number_Bits))-(u32)1)<<(Start_Bit)))|((u32)(Val)<<(Start_Bit)))
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
#define Max(x,y)                   (x>y)?(x):(y)                 /* Max Of Two Digits */
#define Min(x,y)                   (x>y)?(y):(x)                 /* Min Of Two Digits */
/*---------------- DELAY ---------------*/
#define delay_ms(time)                  {u32 i,j;for(i=0;i<time;i++)for(j=0;j<255;j++);}
/********************************************************************
 *  END OF FILE: Macros.h
********************************************************************/
#endif
