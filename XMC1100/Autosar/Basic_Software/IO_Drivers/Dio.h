/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner: Khaled El-Sayed @t0ti20
 *  File: Dio.h
 *  AUTOSAR Version : R22-11
 *  Module: I/O-Drivers
 *  Source: AUTOSAR_SWS_DIODriver.pdf
 *  Description: API and the configuration of the AUTOSAR Basic Software module DIO Driver
*******************************************************************/
#ifndef _DIO_H_
#define _DIO_H_
/******************************************************************/
/*****************************************
-------------  Common Maros  -------------
*****************************************/
/*------- Reference:@DEV_ERROR ---------*/
#define DIO_DEV_ERROR_DETECT            STD_ON
/*----- Reference:@Module_Version ------*/
#define DIO_SW_MAJOR_VERSION            (22U)
#define DIO_SW_MINOR_VERSION            (11U)
#define DIO_SW_PATCH_VERSION            (0U)
/*-- Reference:@DIO_Module_Information -*/
#define DIO_VENDOR_ID                   (1234U)
#define DIO_MODULE_ID                   (513U)
#define DIO_INSTANCE_ID                 (0U)
/*------ Reference:@DIO_Channels -------*/
/*--------------------------------------*/
/*----------- PORT0 -> 16 PIN ----------*/
/*--------------------------------------*/
#define DIO_Port_0                      (0U)
#define DIO_Channel_0                   (0U)
#define DIO_Channel_1                   (1U)
#define DIO_Channel_2                   (2U)
#define DIO_Channel_3                   (3U)
#define DIO_Channel_4                   (4U)
#define DIO_Channel_5                   (5U)
#define DIO_Channel_6                   (6U)
#define DIO_Channel_7                   (7U)
#define DIO_Channel_8                   (8U)
#define DIO_Channel_9                   (9U)
#define DIO_Channel_10                  (10U)
#define DIO_Channel_11                  (11U)
#define DIO_Channel_12                  (12U)
#define DIO_Channel_13                  (13U)
#define DIO_Channel_14                  (14U)
#define DIO_Channel_15                  (15U)
/*--------------------------------------*/
/*----------- PORT1 -> 6 PIN -----------*/
/*--------------------------------------*/
#define DIO_Port_1                      (1U)
#define DIO_Channel_16                  (16U)
#define DIO_Channel_17                  (17U)
#define DIO_Channel_18                  (18U)
#define DIO_Channel_19                  (19U)
#define DIO_Channel_20                  (20U)
#define DIO_Channel_21                  (21U)
/*--------------------------------------*/
/*----------- PORT2 -> 11 PIN ----------*/
/*--------------------------------------*/
#define DIO_Port_2                      (2U)
#define DIO_Channel_22                  (22U)
#define DIO_Channel_23                  (23U)
#define DIO_Channel_24                  (24U)
#define DIO_Channel_25                  (25U)
#define DIO_Channel_26                  (26U)
#define DIO_Channel_27                  (27U)
#define DIO_Channel_28                  (28U)
#define DIO_Channel_29                  (29U)
#define DIO_Channel_30                  (30U)
#define DIO_Channel_31                  (31U)
#define DIO_Channel_32                  (32U)
/*****************************************
---------  API Service Id Macros  --------
*****************************************/
/*----- Reference:@DIO_Service_ID ------*/
/*DIO read Channel*/
#define DIO_READ_CHANNEL_SID            (uint8)(0x00U)
/*DIO write Channel*/
#define DIO_WRITE_CHANNEL_SID           (uint8)(0x01U)
/*DIO read Port*/
#define DIO_READ_PORT_SID               (uint8)(0x02U)
/*DIO write Port*/
#define DIO_WRITE_PORT_SID              (uint8)(0x03U)
/*DIO read Channel Group*/
#define DIO_READ_CHANNEL_GROUP_SID      (uint8)(0x04U)
/*DIO write Channel Group*/
#define DIO_WRITE_CHANNEL_GROUP_SID     (uint8)(0x05U)
/*DIO GetVersionInfo*/
#define DIO_GET_VERSION_INFO_SID        (uint8)(0x12U)
/*DIO Init Channel*/
#define DIO_INIT_SID                    (uint8)(0x10U)
/*DIO flip Channel*/
#define DIO_FLIP_CHANNEL_SID            (uint8)(0x11U)
/*****************************************
-------  8.6.1 Development Errors  -------
*****************************************/
/*[SWS_Dio_91001]*/
/* Invalid channel requested */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  (uint8)(0x0AU)
/* Invalid port requested */
#define DIO_E_PARAM_INVALID_PORT_ID     (uint8)(0x14U)
/* Invalid channel group requested */
#define DIO_E_PARAM_INVALID_GROUP       (uint8)(0x1FU)
/*API service called with a NULL pointe*/
#define DIO_E_PARAM_POINTER             (uint8)(0x20U)
/*****************************************
----------  9.1 Imported types  ----------
*****************************************/
/*[SWS_Dio_00131] In this chapter all types included from the following modules are listed:*/
#include "Std_Types.h"
/*****************************************
---------  9.2 Type definitions  ---------
*****************************************/
/*-------- 9.2.1 Dio_ChannelType -------*/
/*[SWS_Dio_00182] Numeric ID of a DIO channel.*/
typedef uint8                           Dio_ChannelType;
/*---------- 9.2.2 Dio_PortType --------*/
/*[SWS_Dio_00183] Numeric ID of a DIO port.*/
typedef uint8                           Dio_PortType;
/*----- 9.2.3 Dio_ChannelGroupType -----*/
/*[SWS_Dio_00184] Type for the definition of a channel group, which consists of several adjoining channels within a port.*/
typedef struct Dio_ChannelGroupType
{
     /*This element mask which defines the positions of the channel group*/
     uint16 mask;
     /*This element shall be the position of the Channel Group on the port,counted from the LSB.*/
     uint8 offset;
     /*This shall be the port on which the Channel group is defined.*/
     Dio_PortType port;
}Dio_ChannelGroupType;
/*-------- 9.2.4 Dio_LevelType ---------*/
/*[SWS_Dio_00185] These are the possible levels a DIO channel */
typedef uint8                           Dio_LevelType;
/*------ 9.2.5 Dio_PortLevelType -------*/
/*[SWS_Dio_00186] If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port.*/
typedef uint16                           Dio_PortLevelType;
/*****************************************
-------  9.3 Function definitions  -------
*****************************************/
/*------- 9.3.1 Dio_ReadChannel --------*/
/*[SWS_Dio_00133]*/
/*****************************************************************************************
* Service Name           : Dio_ReadChannel
* Syntax                 : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
* Service ID [hex]       : 0x00
* Sync/Async             : Synchronous
* Reentrancy             : Reentrant
* Parameters (in)        : ChannelId -> ID of DIO channel
* Parameters (in-out)    : None
* Parameters (out)       : None
* Return value           : Dio_LevelType
* Description            : Returns the value of the specified DIO channel.
* Available via          : Dio.h
*****************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

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
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

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
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

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
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

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
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

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
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

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
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

/********************************************************************
 *  END OF FILE:  Dio.h
********************************************************************/
#endif
