/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Det.h
 *  AUTOSAR Version : R22-11
 *  Module:  System Services
 *  Source:  AUTOSAR_SWS_DefaultErrorTracer.pdf
 *  Description: Reports All detected development and runtime errors in the Basic Software 
*******************************************************************/
#ifndef _DET_H_
#define _DET_H_
/********************************************************************/
/*****************************************
----------  9.1 Imported types  ----------
*****************************************/
/*[SRS_BSW_00447] - [SWS_Det_91001]*/
#include "Std_Types.h"
/*****************************************
--------- 8.1.2 Type definitions ---------
*****************************************/
/*------- 8.1.2.1 Det_ConfigType -------*/
/*[SWS_Det_00210] Configuration data structure of the Det module.*/
typedef struct
{
	boolean Det_DevelopmentError;
}Det_ConfigType;
/*****************************************
------- 8.1.3 Function definitions -------
*****************************************/
/*------ 8.1.3.2 Det_ReportError -------*/
/*[SWS_Det_00009]*/
/*****************************************************************************************
* Service Name           : Det_ReportError
* Syntax                 : Std_ReturnType Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
* Service ID [hex]       : 0x01
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ModuleId -> Module ID of calling module
                           InstanceId -> index based instance of a module
                           ApiId -> ID of API service in which error is detected 
                           ErrorId -> ID of detected development error
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Std_ReturnType
* Description            : Service to report development errors.
* Available via          : Det.h
*****************************************************************************************/
Std_ReturnType Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId);

/********************************************************************
 *  END OF FILE:  Compiler.h
********************************************************************/
#endif
