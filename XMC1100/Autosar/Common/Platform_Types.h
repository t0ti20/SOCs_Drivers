/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner: Khaled El-Sayed @t0ti20
 *  File: Platform_Types.h
 *  AUTOSAR Version : R22-11
 *  Module: Common
 *  Source: AUTOSAR_SWS_PlatformTypes.pdf
 *  Description: Contains All platform specific abstracted AUTOSAR data types and symbols
*******************************************************************/
#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_
/******************************************************************/
/*****************************************
---------  8.2 Type definitions  ---------
*****************************************/
/*------------ 8.2.1 boolean -----------*/
/*[SRS_BSW_00378] - [SWS_Platform_00026] - [SWS_Platform_00027] - [SWS_Platform_00034]*/
typedef enum boolean
{
     FALSE                              =(0x00U),
     TRUE                               =(0x01U),
}boolean;
/*------------- 8.2.2 uint8 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00013]*/
typedef unsigned char                   uint8;
#define UINT8_MIN                       (0U)
#define UINT8_MAX                       (255U)
/*------------ 8.2.3 uint16 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00014]*/
typedef unsigned short                  uint16;
#define UINT16_MIN                      (0U)
#define UINT16_MAX                      (65535U)
/*------------ 8.2.4 uint32 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00015]*/
typedef unsigned long                   uint32;
#define UINT32_MIN                      (0UL)
#define UINT32_MAX                      (4294967295UL)
/*------------ 8.2.5 uint64 ------------*/
/*[SWS_Platform_00066]*/
typedef unsigned long long              uint64;
#define UINT64_MIN                      (0ULL)
#define UINT64_MAX                      (18446744073709551615ULL)
/*------------- 8.2.6 sint8 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00016]*/
typedef signed char                     sint8;
#define SINT8_MIN                       (-128)
#define SINT8_MAX                       (127)
/*------------ 8.2.7 sint16 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00017]*/
typedef signed short 	               sint16;
#define SINT16_MIN                      (-32768)
#define SINT16_MAX                      (32767)
/*------------ 8.2.8 sint32 ------------*/
/*[SRS_BSW_00304] - [SWS_Platform_00018]*/
typedef signed long 	               sint32;
#define SINT32_MIN                      (-2147483648)
#define SINT32_MAX                      (2147483647L)
/*------------ 8.2.9 sint64 ------------*/
/*[SWS_Platform_00067]*/
typedef signed long long                sint64;
#define SINT64_MIN                      (-9223372036854775808LL)
#define SINT64_MAX                      (9223372036854775807LL)
/*--------- 8.2.10 uint8_least ---------*/
/*[SRS_BSW_00304] - [SWS_Platform_00020]*/
typedef unsigned char                   uint8_least;
/*--------- 8.2.11 uint16_least --------*/
/*[SRS_BSW_00304] - [SWS_Platform_00021]*/
typedef unsigned short                  uint16_least;
/*--------- 8.2.12 uint32_least --------*/
/*[SRS_BSW_00304] - [SWS_Platform_00022]*/
typedef unsigned long                   uint32_least;
/*--------- 8.2.13 sint8_least ---------*/
/*[SRS_BSW_00304] - [SWS_Platform_00023]*/
typedef signed char                     sint8_least;
/*--------- 8.2.14 sint16_least --------*/
/*[SRS_BSW_00304] - [SWS_Platform_00024]*/
typedef signed short                    sint16_least;
/*--------- 8.2.15 sint32_least --------*/
/*[SRS_BSW_00304] - [SWS_Platform_00025]*/
typedef signed long                     sint32_least;
/*------------ 8.2.16 float32 ----------*/
/*[SWS_Platform_00041]*/
typedef float                           float32;
#define FLOAT32_MIN                     (1.17549435e-38F)
#define FLOAT32_MAX                     (3.40282347e+38F)
/*------------ 8.2.17 float64 ----------*/
/*[SWS_Platform_00042]*/
typedef double                          float64;
#define FLOAT64_MIN                     (2.2250738585072014e-308)
#define FLOAT64_MAX                     (1.7976931348623157e+308)
/*------------ 8.2.18 VoidPtr ----------*/
/*[SWS_Platform_91001]*/
typedef void *                          VoidPtr;
/*--------- 8.2.19 ConstVoidPtr --------*/
/*[SWS_Platform_91002]*/
typedef void const *                    ConstVoidPtr;
/*****************************************
-------   8.3 Symbol Definitions   -------
*****************************************/
/*------------ 8.3.1 CPU_TYPE ----------*/
/*[SWS_Platform_00064]*/
#define CPU_TYPE_8 		               (8U)	
#define CPU_TYPE_16 	               (16U)
#define CPU_TYPE_32 	               (32U)
#define CPU_TYPE_64 	               (64U)
#define CPU_TYPE                        (CPU_TYPE_32)
/*--------- 8.3.2 CPU_BIT_ORDER --------*/
/*[SWS_Platform_00038]*/
#define MSB_FIRST 		               (0U)		
#define LSB_FIRST 		               (1U)
#define CPU_BIT_ORDER                   (MSB_FIRST)
/*--------- 8.3.3 CPU_BYTE_ORDER -------*/
/*[SWS_Platform_00039]*/
#define HIGH_BYTE_FIRST 		          (0U)		
#define LOW_BYTE_FIRST 		          (1U)
#define CPU_BYTE_ORDER                  (HIGH_BYTE_FIRST)
/*----------- 8.3.4 TRUE,FALSE ---------*/
/*[SWS_Platform_00056]*/
#ifndef TRUE
#define TRUE                            (0x01U)
#endif
#ifndef FALSE
#define FALSE                           (0x00U)
#endif
/********************************************************************
 *  END OF FILE:  Platform_Types.h
********************************************************************/
#endif
