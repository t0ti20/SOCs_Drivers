/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner: Khaled El-Sayed @t0ti20
 *  File: Std_Types.h
 *  AUTOSAR Version : R21-11
 *  Module: Common
 *  Source: AUTOSAR_SWS_StandardTypes.pdf
 *  Description: Types that are used across several modules of the basic software
*******************************************************************/
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_
/******************************************************************/
/*****************************************
---------------  INCLUDES  ---------------
*****************************************/
#include "Platform_Types.h"
#include "Compiler.h"
/*****************************************
---------  8.1 Type definitions  ---------
*****************************************/
/*--------- 8.1.1 Std_ReturnType -------*/
/*[SRS_BSW_00357] - [SWS_Std_00005]*/
typedef uint8                           Std_ReturnType;
/*------- 8.1.2 Std_VersionInfoType -----*/
/*[SRS_BSW_00004] - [SWS_Std_00015]*/
typedef struct __attribute__((packed)) Std_VersionInfoType
{
	VAR(uint16,AUTOMATIC)vendorID;
	VAR(uint16,AUTOMATIC)moduleID;
	VAR(uint8,AUTOMATIC)sw_major_version;
	VAR(uint8,AUTOMATIC)sw_minor_version;
	VAR(uint8,AUTOMATIC)sw_patch_version;
}Std_VersionInfoType;
/*------ 8.1.3 Std_TransformerError -----*/
/*[SRS_BSW_00008] - [SWS_Std_00022]*/
typedef uint8                           Std_TransformerErrorCode;
/*[SRS_BSW_000010] - [SWS_Std_00024]*/
typedef uint8                           Std_TransformerClass;
#define STD_TRANSFORMER_UNSPECIFIED     ((Std_TransformerClass)0x00U)
#define STD_TRANSFORMER_SERIALIZER      ((Std_TransformerClass)0x01U)
#define STD_TRANSFORMER_SAFETY          ((Std_TransformerClass)0x02U)
#define STD_TRANSFORMER_SECURITY        ((Std_TransformerClass)0x03U)
#define STD_TRANSFORMER_CUSTOM          ((Std_TransformerClass)0xFFU)
/*[SRS_BSW_00004] - [SWS_Std_00021]*/
typedef struct Std_TransformerError
{
	VAR(Std_TransformerErrorCode,AUTOMATIC)errorCode;
	VAR(Std_TransformerClass,AUTOMATIC)transformerClass;
}Std_TransformerError;
/*****************************************
--------  8.2 Symbol definitions  --------
*****************************************/
/*--------- 8.2.1 E_OK, E_NOT_OK -------*/
/*[SRS_BSW_00357] - [SWS_Std_00006]*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK                            ((Std_ReturnType)0x00U)
typedef uint8                           StatusType;
#endif
#define E_NOT_OK                        ((Std_ReturnType)0x01U)
/*------- 8.2.2 STD_HIGH, STD_LOW ------*/
/*[SRS_BSW_00348] - [SWS_Std_00007]*/
#define STD_HIGH                        (0x01U)
#define STD_LOW                         (0x00U)
/*----- 8.2.3 STD_ACTIVE, STD_IDLE -----*/
/*[SRS_BSW_00348] - [SWS_Std_00013]*/
#define STD_ACTIVE                      (0x01U)
#define STD_IDLE                        (0x00U)
/*-------- 8.2.4 STD_ON, STD_OFF -------*/
/*[SRS_BSW_00348] - [SWS_Std_00010]*/
#define STD_ON                          (0x01U)
#define STD_OFF                         (0x00U)
/*------------ 8.2.5 NULL_PTR ----------*/
/*[SRS_BSW_00480] - [SWS_Std_00031]*/
#define NULL_PTR                        ((void *)0U)
/********************************************************************
 *  END OF FILE:  Std_Types.h
********************************************************************/
#endif
