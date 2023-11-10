/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Bootloader.h
 *  Module:  Library/Bootloader
 *  Description:  Bootloader Interface File
*******************************************************************/
#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_
/********************************************************************/
/*****************************************
--------    Type  Definitions    ---------
*****************************************/
/*-------------- Send State ------------*/
typedef enum Bootloader_State_t
{
     Bootloader_State_ACK               =(0),
     Bootloader_State_NACK              =(1),
     Bootloader_State_Successful_Erase  =(2),
     Bootloader_State_Unsuccessful_Erase=(3),
     Bootloader_State_Successful_Write  =(4),
     Bootloader_State_Unsuccessful_Write=(5)
}Bootloader_State_t;
/*---------------- Command -------------*/
typedef enum Bootloader_Command_t
{    
     Bootloader_Command_Send_Help       =(1),
     Bootloader_Command_Send_ID         =(2),
     Bootloader_Command_Send_Version    =(3),
     Bootloader_Command_Erase_Flash     =(4),
     Bootloader_Command_Write_Flash     =(5)
}Bootloader_Command_t;
/*****************************************
---------    Configure Macros    ---------
*****************************************/
#define Chip_ID_Number                  (1234)
#define Maximum_Buffer_Size             (250)
#define Bootloader_Total_Pages          (32)
#define Basic_SW_Major_Version          (1)
#define Basic_SW_Minor_Version          (1)
#define Basic_SW_Patch_Version          (1)
/*****************************************
---  Application Programming Interface  --
*****************************************/
void Bootloader_Initialize(void);
void Bootloader_Receive_Command(void);
void Bootloader_Send_Message(const u8 Message[],...);
/********************************************************************
 *  END OF FILE:  Bootloader.h
********************************************************************/
#endif
