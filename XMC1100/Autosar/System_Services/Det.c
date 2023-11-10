/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Det.c
 *  AUTOSAR Version : R22-11
 *  Module:  System Services
 *  Source:  AUTOSAR_SWS_DefaultErrorTracer.pdf
 *  Description: Reports All detected development and runtime errors in the Basic Software 
*******************************************************************/
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Det.h"
/*****************************************
---------------   APIS    ----------------
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
Std_ReturnType Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
{
    while(1)
		{
			if(ModuleId&&InstanceId&&ApiId&&ErrorId){}
		}
    return E_OK;
}
/********************************************************************
 *  END OF FILE:  Det.c
********************************************************************/
