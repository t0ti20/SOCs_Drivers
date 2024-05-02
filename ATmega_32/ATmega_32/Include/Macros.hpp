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
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Magic_Numbers -------------*/
typedef enum{ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN}numbers_t;
/*------------- Null -------------*/
#ifndef NULL
#define NULL   	               ((void*) 0 )                  /* NULL Pointer */
#endif
/*------------- Bit Math -------------*/
/* Set Bit */
#define Set_Bit(Reg,Bit_Num)       ((Reg)|=static_cast<u8>(1)<<static_cast<u8>(Bit_Num))	
/* Clear Bit */
#define Clear_Bit(Reg,Bit_Num)     ((Reg)&=~(static_cast<u8>(1)<<static_cast<u8>(Bit_Num)))
/* Toggle Bit */		        
#define Toggle_Bit(Reg,Bit_Num)    ((Reg)^=(static_cast<u8>(1)<<static_cast<u8>(Bit_Num)))
/* Get_Bit */		        
#define Get_Bit(Reg,Bit_Num)       (((Reg)>>static_cast<u8>Bit_Num)&static_cast<u8>(1))		        
/*------------- Max-Min -------------*/
#define Max(x,y)                   (x>y)?(x):(y)                 /* Max Of Two Digits */
#define Min(x,y)                   (x>y)?(y):(x)                 /* Min Of Two Digits */
/*---------------- DELAY ---------------*/
#define delay_ms(time)                  {u32 i,j;for(i=0;i<time>>2;i++)for(j=0;j<255;j++);}
/********************************************************************
 *  END OF FILE: Macros.h
********************************************************************/
#endif
