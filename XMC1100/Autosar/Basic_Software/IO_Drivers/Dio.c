/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner: Khaled El-Sayed @t0ti20
 *  File: Dio.c
 *  AUTOSAR Version : R22-11
 *  Module: I/O-Drivers
 *  Source: AUTOSAR_SWS_DIODriver.pdf
 *  Description: API and the configuration of the AUTOSAR Basic Software module DIO Driver
*******************************************************************/
/*****************************************
----------------  Includes  --------------
*****************************************/
#include "XMC1100_AB.h"
#include "Dio.h"
#include "Det.h"
/*****************************************
---------------  Variables  --------------
*****************************************/
/*****************************************
-------  9.3 Function definitions  -------
*****************************************/
/****************************************************************************************************
* Function Name   : Static_Dio_GetPort
* Description     : Retrieves the PORT address for the given port type.
*                   Determines and assigns the appropriate PORT address (PORT0, PORT1, or PORT2)
*                   based on the specified port type.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant (Assumed based on code structure. Ensure if it's true.)
* Parameters (in) : Dio_PortTypePort - Type of the port for which the address is required.
* Parameters (out): Ptr2Ptr_PORTX_tPortX - Double pointer to store the address of the determined port.
* Return value    : boolean - Returns TRUE if the operation was successful, FALSE otherwise.
* Notes           : - The function uses preprocessor directives to verify if development errors 
*                     are enabled or disabled.
*                   - Based on the provided port type, the function determines which PORT address
*                     is associated with the specified port type.
*                   - If the port type is recognized, the appropriate PORT address is assigned.
*                     Otherwise, no action is taken.
*****************************************************************************************************/
static boolean Static_Dio_GetPort(Dio_PortType Dio_PortTypePort,volatile PORTX_t** Ptr2Ptr_PORTX_tPortX)
{
     boolean Local_booleanState = FALSE;
/* Check If Development Errors Enabled */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /* For Valid Port requested */
     if((DIO_Port_0 <= Dio_PortTypePort) && (DIO_Port_2 >= Dio_PortTypePort))
     {
          /*Set Flag*/
          Local_booleanState = TRUE;
     }
     /* Invalid Port requested */
     else{}
/*Check If Development Errors Disabled */
#elif (DIO_DEV_ERROR_DETECT == STD_OFF)
     /*Set Flag*/
     Local_booleanState = TRUE;
/*Wrong Configuration For DIO_DEV_ERROR_DETECT */
#else
#warning "Wrong DIO_DEV_ERROR_DETECT Configuration !"
#endif
     /* Check For Flag */
     if (TRUE == Local_booleanState)
     {
          /*Get Correspond Port Address*/
          switch (Dio_PortTypePort)
          {
               case DIO_Port_0:*Ptr2Ptr_PORTX_tPortX = PORT0;break;
               case DIO_Port_1:*Ptr2Ptr_PORTX_tPortX = PORT1;break;
               case DIO_Port_2:*Ptr2Ptr_PORTX_tPortX = PORT2;break;
               default:break;
          }
     }
     /*Always Return True If There Is No Errors*/
     return Local_booleanState;
}
/*****************************************************************************************************
* Function Name   : Static_Dio_GetChannel
* Description     : This function determines the PORT address for a given channel ID.
*                   Depending on the channel ID provided, the function assigns the address 
*                   of the appropriate port (PORT0, PORT1, or PORT2) to the provided pointer.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant (Assumed based on the code's structure. Ensure if it's true.)
* Parameters (in) : Ptr_Dio_ChannelTypeChannelId - Pointer to channel ID to get the associated port.
* Parameters (out): Ptr2Ptr_PORTX_tPortX - Double pointer to store the address of the determined port.
* Return value    : boolean - Returns TRUE if the operation was successful, FALSE otherwise.
* Notes           : - The function uses preprocessor directives to check if development errors 
*                     are enabled or disabled.
*                   - Based on the channel ID range, the function determines which port is associated 
*                     with the channel ID.
*                   - If the channel ID belongs to a port other than PORT0, the channel ID is 
*                     adjusted relative to the base of the port it belongs to.
******************************************************************************************************/
static boolean Static_Dio_GetChannel(Dio_ChannelType * Ptr_Dio_ChannelTypeChannelId,volatile PORTX_t** Ptr2Ptr_PORTX_tPortX)
{
     boolean Local_booleanState = FALSE;
/* Check If Development Errors Enabled */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /* For Valid channel requested */
     if((DIO_Channel_0 <= (*Ptr_Dio_ChannelTypeChannelId)) && (DIO_Channel_32 >= (*Ptr_Dio_ChannelTypeChannelId)))
     {
          /*Set Flag*/
          Local_booleanState = TRUE;
     }
     /* Invalid channel requested */
     else{}
/*Check If Development Errors Disabled */
#elif (DIO_DEV_ERROR_DETECT == STD_OFF)
     /*Set Flag*/
     Local_booleanState = TRUE;
/*Wrong Configuration For DIO_DEV_ERROR_DETECT */
#else
#warning "Wrong DIO_DEV_ERROR_DETECT Configuration !"
#endif
     /* Check For Flag */
     if (TRUE == Local_booleanState)
     {
          /*Get Port0 Address*/
          if((DIO_Channel_0 <= (*Ptr_Dio_ChannelTypeChannelId)) && (DIO_Channel_15>=(*Ptr_Dio_ChannelTypeChannelId)))
          {
               /*Store The Correct Pin Address*/
               *Ptr2Ptr_PORTX_tPortX = PORT0;
          }
          /*Get Port1 Address*/
          else if((DIO_Channel_16 <= (*Ptr_Dio_ChannelTypeChannelId)) && (DIO_Channel_21>=(*Ptr_Dio_ChannelTypeChannelId)))
          {
               /*Store The Correct Pin Address*/
               *Ptr2Ptr_PORTX_tPortX = PORT1;
               /*Edit Pin To Its Port Base*/
               *Ptr_Dio_ChannelTypeChannelId-=DIO_Channel_16;
          }
          /*Get Port2 Address*/
          else if((DIO_Channel_22 <= (*Ptr_Dio_ChannelTypeChannelId)) && (DIO_Channel_32>=(*Ptr_Dio_ChannelTypeChannelId)))
          {
               /*Store The Correct Pin Address*/
               *Ptr2Ptr_PORTX_tPortX = PORT2;
               /*Edit Pin To Its Port Base*/
               *Ptr_Dio_ChannelTypeChannelId-=DIO_Channel_22;
          }
          else{}
     }
     /*Always Return True If There Is No Errors*/
     return Local_booleanState;
}
/*------- 9.3.1 Dio_ReadChannel --------*/
/*[SWS_Dio_00133]*/
/*****************************************************************************************
* Service Name           : Dio_ReadChannel
* Syntax                 : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
* Service ID [hex]       : 0x00
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelId
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Dio_LevelType
* Description            : Returns the value of the specified DIO channel.
* Available via          : Dio.h
*****************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
     Dio_LevelType Local_Dio_LevelTypeState = STD_LOW;
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     /*Check For The Channel Id*/
     boolean Local_booleanState = Static_Dio_GetChannel(&ChannelId,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /* Get And Store Pin State */
               Local_Dio_LevelTypeState=(Dio_LevelType)Get_Bit(Ptr_PORTX_tPortX->Pn_IN.Register,ChannelId);
          }
          else{}
     }
     else
     {
          /*Report Error*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
     }
     /* Return Pin State */
     return Local_Dio_LevelTypeState;
}
/*------- 9.3.2 Dio_WriteChannel -------*/
/*[SWS_Dio_00134]*/
/*****************************************************************************************
* Service Name           : Dio_WriteChannel
* Syntax                 : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
* Service ID [hex]       : 0x01
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelId -> ID of DIO channel
                           Level -> Value to be written
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : None
* Description            : Service to set a level of a channel.
* Available via          : Dio.h
*****************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     /*Check For The Channel Id*/
     boolean Local_booleanState = Static_Dio_GetChannel(&ChannelId,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Check If Bit Is Hi-Level*/
               if(ONE==(Level&ONE)){Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)(ONE<<ChannelId);}
               /*Check If Bit Is Low-Level*/
               else{Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)ONE<<(ChannelId+16);}
          }
          else{}
     }
     else
     {
          /*Report Error*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
     }
}
/*--------- 9.3.3 Dio_ReadPort ---------*/
/*[SWS_Dio_00135]*/
/*****************************************************************************************
* Service Name           : Dio_ReadPort
* Syntax                 : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
* Service ID [hex]       : 0x02
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : PortId -> ID of DIO channel
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Dio_PortLevelType -> Level of all channels of that port
* Description            : Returns the level of all channels of that port
* Available via          : Dio.h
*****************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
     Dio_PortLevelType Local_Dio_LevelTypeValue = STD_LOW;
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     /*Check For The Channel Id*/
     boolean Local_booleanState = Static_Dio_GetPort(PortId,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Read Port*/
               Local_Dio_LevelTypeValue=(Dio_PortLevelType)(Ptr_PORTX_tPortX->Pn_IN.Register);
          }
          else{}
     }
     else
     {
          /*Report Error Invalid Port Number*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
     }
     return Local_Dio_LevelTypeValue;
}
/*--------- 9.3.4 Dio_WritePort --------*/
/*[SWS_Dio_00136]*/
/*****************************************************************************************
* Service Name           : Dio_WritePort
* Syntax                 : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
* Service ID [hex]       : 0x03
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : PortId -> ID of DIO channel
                           Level -> Value to be written
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : None
* Description            : Service to set a value of the port
* Available via          : Dio.h
*****************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     /*Check For The Channel Id*/
     boolean Local_booleanState = Static_Dio_GetPort(PortId,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Write Port*/
               Ptr_PORTX_tPortX->Pn_OUT.Register=Level;
          }
          else{}
     }
     else
     {
          /*Report Error Invalid Port Number*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
     }
}

/*----- 9.3.5 Dio_ReadChannelGroup -----*/
/*[SWS_Dio_00137]*/
/*****************************************************************************************
* Service Name           : Dio_ReadChannelGroup
* Syntax                 : Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
* Service ID [hex]       : 0x04
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelGroupIdPtr -> Pointer to ChannelGroup
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Dio_PortLevelType -> Level of a subset of the adjoining bits of a port
* Description            : This Service reads a subset of the adjoining bits of a port
* Available via          : Dio.h
*****************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     Dio_PortLevelType Local_Dio_LevelTypeValue = STD_LOW;
     /* Check For The Channel Id*/
     boolean Local_booleanState = Static_Dio_GetPort(ChannelGroupIdPtr->port,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Read Channel Group*/
               Local_Dio_LevelTypeValue=(((Ptr_PORTX_tPortX->Pn_IN.Register)&(ChannelGroupIdPtr->mask))>>ChannelGroupIdPtr->offset);
          }
          else{}
     }
     else
     {
          /*Report Error Invalid Port Number*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_GROUP_SID,DIO_E_PARAM_INVALID_PORT_ID);
     }
     return Local_Dio_LevelTypeValue;
}

/*----- 9.3.6 Dio_WriteChannelGroup ----*/
/*[SWS_Dio_00138]*/
/*****************************************************************************************
* Service Name           : Dio_WriteChannelGroup
* Syntax                 : void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
* Service ID [hex]       : 0x05
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelGroupIdPtr -> Pointer to ChannelGroup
                           Level -> Value to be written
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : None
* Description            : Service to set a subset of the adjoining bits of a port to a specified level.
* Available via          : Dio.h
*****************************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR ;
/*Check If Development Errors Enabled */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     if(NULL_PTR==ChannelGroupIdPtr)
     {
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_GROUP_SID,DIO_E_PARAM_POINTER);
     }
     else
/*Wrong Configuration For DIO_DEV_ERROR_DETECT */
#else
#warning "Wrong DIO_DEV_ERROR_DETECT Configuration !"
#endif
     {
          uint8 Local_uint8Bit_Counter=ZERO;
          uint16 Local_uint16Mask=ZERO;
          /* Check For The Channel Id*/
          boolean Local_booleanState = Static_Dio_GetPort(ChannelGroupIdPtr->port,&Ptr_PORTX_tPortX);
          if(TRUE == Local_booleanState)
          {
               if(NULL_PTR != Ptr_PORTX_tPortX)
               {
                    /*Write Channel Group (Reentrant)*/
                    Ptr_PORTX_tPortX->Pn_OMR.Register=((ChannelGroupIdPtr->mask&Level)<<ChannelGroupIdPtr->offset)|((((~Level)&ChannelGroupIdPtr->mask)<<(16+ChannelGroupIdPtr->offset)));
               }
               else{}
          }
          else
          {
               /*Report Error Invalid Port Number*/
               Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_GROUP_SID,DIO_E_PARAM_INVALID_PORT_ID);
          }
     }
}
/*----- 9.3.7 Dio_GetVersionInfo -----*/
/*[SWS_Dio_00139]*/
/*****************************************************************************************
* Service Name           : Dio_GetVersionInfo
* Syntax                 : void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
* Service ID [hex]       : 0x12
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : None
* Parameters (in-out)    : None
* Parameters (out)       : VersionInfo -> Pointer to where to store the version information of this module.
* Return value           : None
* Description            : Service to get the version information of this module.
* Available via          : Dio.h
*****************************************************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
/*Check If Development Errors Enabled */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     if(NULL_PTR==VersionInfo)
     {
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_GET_VERSION_INFO_SID,DIO_E_PARAM_POINTER);
     }
     else
/*Wrong Configuration For DIO_DEV_ERROR_DETECT */
#else
#warning "Wrong DIO_DEV_ERROR_DETECT Configuration !"
#endif
     {
          if(NULL_PTR != VersionInfo)
          {
               VersionInfo->moduleID=DIO_MODULE_ID;
               VersionInfo->sw_major_version=DIO_SW_MAJOR_VERSION;
               VersionInfo->sw_minor_version=DIO_SW_MINOR_VERSION;
               VersionInfo->sw_patch_version=DIO_SW_PATCH_VERSION;
               VersionInfo->vendorID=DIO_VENDOR_ID;
          }
          else{}
     }
}

/*----- 9.3.8 Dio_FlipChannel -----*/
/*[SWS_Dio_00190]*/
/*****************************************************************************************
* Service Name           : Dio_FlipChannel
* Syntax                 : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
* Service ID [hex]       : 0x11
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelId -> ID of DIO channel
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Dio_LevelType
* Description            : Service to flip (change from 1 to 0 or from 0 to 1) the level of 
                           a channel and return the level of the channel after flip.
* Available via          : Dio.h
*****************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     Dio_LevelType Local_Dio_LevelTypeState=STD_LOW;
     /*Check For The Channel Id*/
     boolean Local_booleanState=Static_Dio_GetChannel(&ChannelId,&Ptr_PORTX_tPortX);
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Toggle Channel*/
               Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)((ONE<<ChannelId)|(ONE<<(ChannelId+16)));
               /*Read Channel*/
               Local_Dio_LevelTypeState=(Dio_LevelType)Get_Bit(Ptr_PORTX_tPortX->Pn_IN.Register,ChannelId);
          }
          else{}
     }
     else
     {
          /*Report Error*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
     }
     return Local_Dio_LevelTypeState;
}
/*----- 9.3.9 Dio_MaskedWritePort -----*/
/*[SWS_Dio_00300]*/
/*****************************************************************************************
* Service Name           : Dio_MaskedWritePort
* Syntax                 : void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
* Service ID [hex]       : 0x13
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : PortId   -> ID of DIO Port
                           Level    -> Value to be written
                           Mask     -> Channels to be masked in the port
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : None
* Description            : Service to set the value of a given port with required mask.
* Available via          : Dio.h
*****************************************************************************************/
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
     volatile PORTX_t * Ptr_PORTX_tPortX=NULL_PTR;
     /*Check For The Channel Id*/
     boolean Local_booleanState=Static_Dio_GetPort(PortId,&Ptr_PORTX_tPortX);
     uint8 Local_uint8Bit_Counter=ZERO;
     if(TRUE == Local_booleanState)
     {
          if(NULL_PTR != Ptr_PORTX_tPortX)
          {
               /*Write Channel Group Bit By Bit (Reentrant)*/
               Ptr_PORTX_tPortX->Pn_OMR.Register=(Mask&Level)|((((~Level)&Mask)<<16));
          }
          else{}
     }
     else
     {
          /*Report Error Invalid Port Number*/
          Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_PORT_SID,DIO_E_PARAM_INVALID_PORT_ID);
     }
}
/********************************************************************
 *  END OF FILE:  Dio.c
********************************************************************/
