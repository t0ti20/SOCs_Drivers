/*******************************************************************
 *  FILE DESCRIPTION
--------------------------------------------------------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Standard_Types.h
 *  Module:  Library
 *  Description:  Standard Variables Types
*******************************************************************/
#ifndef _STANDERD_TYPES_H_
#define _STANDERD_TYPES_H_
/*****************************************
----------    GLOBAL DATA     -----------
*****************************************/
/*----------- Unsigned -----------*/
typedef unsigned char u8;               /*Unsigned 1 byte*/
typedef unsigned short int u16;         /*Unsigned 2 bytes*/
typedef unsigned long int u32;          /*Unsigned 4 bytes*/
/*typedef unsigned long long u64;         Unsigned 8 bytes*/
/*----------- Signed -----------*/
typedef signed char s8;                 /*signed 1 byte*/
typedef signed short int s16;           /*signed 2 bytes*/
typedef signed long int s32;            /*signed 4 bytes*/
/*typedef signed long long s64;           signed 8 bytes*/
/*----------- Float -----------*/
typedef float f32;                      /*Float 4 bytes*/
typedef double f64;                     /*Float 8 bytes*/
typedef long double f128;               /*Float 16 bytes*/
/*----------- Bits -----------*/
typedef struct Bits_t
{
    volatile u8 Bit_0:1;
    volatile u8 Bit_1:1;
    volatile u8 Bit_2:1;
    volatile u8 Bit_3:1;
    volatile u8 Bit_4:1;
    volatile u8 Bit_5:1;
    volatile u8 Bit_6:1;
    volatile u8 Bit_7:1;
}Bits_t;
/*----------- Bits -----------*/
typedef union Register_t
{
    volatile Bits_t Bits;
    volatile u8 Register;
}Register_t;
/********************************************************************
 *  END OF FILE: Standard_Types.h
********************************************************************/
#endif
