/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Compiler.h
 *  AUTOSAR Version : R21-11
 *  Module:  Common
 *  Source:  AUTOSAR_SWS_CompilerAbstraction.pdf
 *  Description:  macros for the abstraction of compiler specific keywords
*******************************************************************/
#ifndef _COMPILER_H_
#define _COMPILER_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Std_Types.h"
/*****************************************
------ 7.1 Functional specification ------
*****************************************/
/*---- 7.1.3 Contents of Compiler.h ----*/
/*[SWS_COMPILER_00005]*/
#define FUNC(type, memclass)            type
/*****************************************
--------  8.2 Macro definitions  ---------
*****************************************/
/*------ 8.2.1 General definitions -----*/
/*[SRS_BSW_00361] - [SWS_COMPILER_00046]*/
#define AUTOMATIC
/*[SRS_BSW_00404] - [SWS_COMPILER_00059]*/
#define TYPEDEF
/*[SRS_BSW_00361] - [SWS_COMPILER_00057]*/
#define INLINE                          inline
/*[SRS_BSW_00361] - [SWS_COMPILER_00060]*/
#define LOCAL_INLINE                    static inline
/*----- 8.2.2 FUNC identification  -----*/
/*[SRS_BSW_00361] - [SWS_COMPILER_00061]*/
#define FUNC_P2CONST(rettype, ptrclass, memclass)      const ptrclass rettype * memclass
/*[SRS_BSW_00361] - [SWS_COMPILER_00063]*/
#define FUNC_P2VAR(rettype, ptrclass, memclass)        ptrclass rettype * memclass
/*---  8.2.3 Pointer identification  ---*/
/*[SRS_BSW_00361] - [SWS_COMPILER_00006]*/
#define P2VAR(ptrtype, memclass, ptrclass)             ptrclass ptrtype * memclass
/*----  8.2.4 Constant definitions  ----*/
/*[SRS_BSW_00309] - [SWS_COMPILER_00023]*/
#define CONST(type, memclass)           memclass const type
/*----  8.2.4 Constant definitions  ----*/
/*[SRS_BSW_00361] - [SWS_COMPILER_00026]*/
#define VAR(type, memclass)             memclass type
/********************************************************************
 *  END OF FILE:  Compiler.h
********************************************************************/
#endif
