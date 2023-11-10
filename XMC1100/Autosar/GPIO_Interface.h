/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  GPIO_Interface.h
 *  Module:  MCAL/GPIO
 *  Description:  General Input Output Driver Interface File
*******************************************************************/
#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "XMC1100_AB.h"
/*****************************************
---------    Configure Macros    ---------
*****************************************/
/*Modify GPIO As Read Modify Then Write May be Interrupted*/
#define READ_WRITE                                     (1)
/*Modify GPIO As Write Only Operation*/
#define DIRECT_WRITE                                   (0)
/*****************************************
----------   Configuration    ------------
*****************************************/
/*Select Between (DIRECT_WRITE - READ_WRITE)*/
#define SWITCH_MODE                                    (READ_WRITE)
/*****************************************
--------    Type  Definitions    ---------
*****************************************/
/*----------- Pins Numbers -------------*/
typedef enum GPIO_Pin_t
{
     GPIO_Pin_0                                        =(uint8)(0),       /*Pin 0 Is Selected*/
     GPIO_Pin_1                                        =(uint8)(1),       /*Pin 1 Is Selected*/
     GPIO_Pin_2                                        =(uint8)(2),       /*Pin 2 Is Selected*/
     GPIO_Pin_3                                        =(uint8)(3),       /*Pin 3 Is Selected*/
     GPIO_Pin_4                                        =(uint8)(4),       /*Pin 4 Is Selected*/
     GPIO_Pin_5                                        =(uint8)(5),       /*Pin 5 Is Selected*/
     GPIO_Pin_6                                        =(uint8)(6),       /*Pin 6 Is Selected*/
     GPIO_Pin_7                                        =(uint8)(7),       /*Pin 7 Is Selected*/
     GPIO_Pin_8                                        =(uint8)(8),       /*Pin 8 Is Selected*/
     GPIO_Pin_9                                        =(uint8)(9),       /*Pin 9 Is Selected*/
     GPIO_Pin_10                                       =(uint8)(10),      /*Pin 10 Is Selected*/
     GPIO_Pin_11                                       =(uint8)(11),      /*Pin 11 Is Selected*/
     GPIO_Pin_12                                       =(uint8)(12),      /*Pin 12 Is Selected*/
     GPIO_Pin_13                                       =(uint8)(13),      /*Pin 13 Is Selected*/
     GPIO_Pin_14                                       =(uint8)(14),      /*Pin 14 Is Selected*/
     GPIO_Pin_15                                       =(uint8)(15)       /*Pin 15 Is Selected*/
}GPIO_Pin_t;
/*-------------- Pin Mode --------------*/
typedef enum GPIO_Mode_t
{
/*============ Input Direct ============*/
     GPIO_Mode_Input_Direct_Floating           				 =(uint8)(0),       /*No internal pull device active*/
     GPIO_Mode_Input_Direct_Pull_Down                  =(uint8)(1),       /*Internal pull-down device active*/
     GPIO_Mode_Input_Direct_Pull_Up                    =(uint8)(2),       /*Internal pull-up device active*/
     GPIO_Mode_Input_Direct_Sample                     =(uint8)(3),       /*continuously samples the input value*/
/*=========== Input Inverted ===========*/
     GPIO_Mode_Input_Inverted_Floating                 =(uint8)(4),       /*No internal pull device active*/
     GPIO_Mode_Input_Inverted_Pull_Down                =(uint8)(5),       /*Internal pull-down device active*/
     GPIO_Mode_Input_Inverted_Pull_Up                  =(uint8)(6),       /*Internal pull-up device active*/
     GPIO_Mode_Input_Inverted_Sample                   =(uint8)(7),       /*continuously samples the input value*/
/*========== Output Push Pull ==========*/
     GPIO_Mode_Output_Push_Pull                        =(uint8)(16),      /*General-purpose output*/
     GPIO_Mode_Output_Push_Pull_Alternate_1            =(uint8)(17),      /*Alternate output function 1*/
     GPIO_Mode_Output_Push_Pull_Alternate_2            =(uint8)(18),      /*Alternate output function 2*/
     GPIO_Mode_Output_Push_Pull_Alternate_3            =(uint8)(19),      /*Alternate output function 3*/
     GPIO_Mode_Output_Push_Pull_Alternate_4            =(uint8)(20),      /*Alternate output function 4*/
     GPIO_Mode_Output_Push_Pull_Alternate_5            =(uint8)(21),      /*Alternate output function 5*/
     GPIO_Mode_Output_Push_Pull_Alternate_6            =(uint8)(22),      /*Alternate output function 6*/
     GPIO_Mode_Output_Push_Pull_Alternate_7            =(uint8)(23),      /*Alternate output function 7*/
/*========== Output Open Drain =========*/
     GPIO_Mode_Output_Open_Drain                       =(uint8)(24),      /*General-purpose output*/
     GPIO_Mode_Output_Open_Drain_Alternate_1           =(uint8)(25),      /*Alternate output function 1*/
     GPIO_Mode_Output_Open_Drain_Alternate_2           =(uint8)(26),      /*Alternate output function 2*/
     GPIO_Mode_Output_Open_Drain_Alternate_3           =(uint8)(27),      /*Alternate output function 3*/
     GPIO_Mode_Output_Open_Drain_Alternate_4           =(uint8)(28),      /*Alternate output function 4*/
     GPIO_Mode_Output_Open_Drain_Alternate_5           =(uint8)(29),      /*Alternate output function 5*/
     GPIO_Mode_Output_Open_Drain_Alternate_6           =(uint8)(30),      /*Alternate output function 6*/
     GPIO_Mode_Output_Open_Drain_Alternate_7           =(uint8)(31),      /*Alternate output function 7*/
}GPIO_Mode_t;
/*---------- GPIO Hysteresis ----------*/
typedef enum GPIO_Hysteresis_t
{
     GPIO_Hysteresis_Standard                          =(uint8)(0),       /*Standard hysteresis*/
     GPIO_Hysteresis_Large                             =(uint8)(1)        /*Large hysteresis*/
}GPIO_Hysteresis_t;
/*------------- GPIO Ports ------------*/
typedef enum GPIO_Port_t
{
     GPIO_Port_0                                       =(uint8)(0),      /*Select GPIO Port 0 (16-Pins-Only)*/
     GPIO_Port_1                                       =(uint8)(1),      /*Select GPIO Port 1 (6-Pins-Only)*/
     GPIO_Port_2                                       =(uint8)(2)       /*Select GPIO Port 2 (11-Pins-Only)*/
}GPIO_Port_t;
/*------------- GPIO Error ------------*/
typedef enum GPIO_Error_t
{
     GPIO_Error_Ok                                    =(uint8)(0),      /*There Is No Any Errors*/
     GPIO_Error_Port                                  =(uint8)(1),      /*There Is Error In Selection Port*/
     GPIO_Error_Pin                                   =(uint8)(2),      /*There Is Error In Selection Pin*/
     GPIO_Error_Hysteresis                            =(uint8)(3),      /*There Is Error In Hysteresis For This Specific Pin*/
     GPIO_Error_Pin_Not_Input                         =(uint8)(4),      /*There Is Error In Pin It Is Not Input Pin*/
     GPIO_Error_Pin_Not_Output                        =(uint8)(5),      /*There Is Error In Pin It Is Not Output Pin*/
     GPIO_Error_Output_Option                         =(uint8)(6)       /*There Is Error In Output Option User Choose*/
}GPIO_Error_t;
/*------------ GPIO Control -----------*/
typedef enum GPIO_Control_t
{
     GPIO_Control_Software                             =(uint8)(0),      /*Software control only*/
     GPIO_Control_Hardware_Path_0                      =(uint8)(1),      /*HW0 control path can override the software configuration*/
     GPIO_Control_Hardware_Path_1                      =(uint8)(2)       /*HW1 control path can override the software configuration.*/
}GPIO_Control_t;
/*------------- GPIO Output ------------*/
typedef enum GPIO_Output_t
{
     GPIO_Output_Low                                   =(uint8)(0),      /*Drive Pin Is Low*/
     GPIO_Output_Hi                                    =(uint8)(1),      /*Drive Pin Is Hi*/
     GPIO_Output_Toggle                                =(uint8)(2)       /*Toggle Pin*/
}GPIO_Output_t;
/*--------- GPIO Pin Configure ---------*/
typedef struct GPIO_Pin_Config_t
{    
     GPIO_Port_t Port;
     GPIO_Pin_t Pin;
     GPIO_Mode_t Mode;
     GPIO_Hysteresis_t Hysteresis;
     uint8 Pad;
     /*To Do Deep-Sleep Pin Power Save Behavior*/
     uint8 Power_Save;
     GPIO_Control_t Control;
}
GPIO_Pin_Config_t;
/*****************************************
---  Application Programming Interface  --
*****************************************/
/*****************************************************************************************
* Function Name   : GPIO_Initialization
* Description     : This function initializes a specified GPIO pin based on provided configurations.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Pin_Config_tPin - A pointer to the configuration of the GPIO pin.
* Parameters (out): None
* Return value    : GPIO_Error_t - Indicates the status of the initialization process. It 
*                   returns `GPIO_Error_Ok` if successful, or an error code indicating a specific issue.
* Notes           : - The function first validates the input configurations using the `GPIO_Check_Input` function.
*                   - Based on the validation, the function sets several properties for the pin:
*                      1. The digital output and input driver functionality.
*                      2. The pad hysteresis.
*                      3. Configuration for shared analog and digital ports.
*                      4. Power Save option.
*                      5. Control over which peripheral controls the pin.
*                   - It is crucial to ensure that the GPIO peripherals are appropriately initialized 
*                     before using this function.
*                   - Always ensure write operations to hardware are atomic or adequately guarded in 
*                     a multi-threaded or interrupt-driven environment.
*                   - This function configures a pin based on its mode, hysteresis, pad setting, power 
*                     saving mode, and peripheral control. Ensure the provided configurations are valid 
*                     before calling the function.
*****************************************************************************************/
GPIO_Error_t GPIO_Initialization(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin);

/*****************************************************************************************
* Function Name   : GPIO_Read_Port_Value
* Description     : This function reads the value of a specified GPIO port.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Port_tPort - The specified GPIO port from which data is to be read.
* Parameters (out): Ptr_u16Value - A pointer to store the read state of the entire GPIO port.
* Return value    : GPIO_Error_t - Indicates the status of the port reading process. It 
*                   returns `GPIO_Error_Ok` if successful or an error code (`GPIO_Error_Port`) 
*                   indicating an invalid port selection.
*****************************************************************************************/
GPIO_Error_t GPIO_Read_Port_Value(GPIO_Port_t Ptr_GPIO_Port_tPort,uint16 *Ptr_u16Value);

/*****************************************************************************************
* Function Name   : GPIO_Edit_Port_Value
* Description     : This function modifies the value of a specified GPIO port.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Port_tPort - The specified GPIO port which needs to be modified.
*                   Copy_u16Value - The value that the GPIO port should be set to.
* Parameters (out): None
* Return value    : GPIO_Error_t - Indicates the status of the port editing process. It 
*                   returns `GPIO_Error_Ok` if successful or an error code (`GPIO_Error_Port`) 
*                   indicating an invalid port selection.
*****************************************************************************************/
GPIO_Error_t GPIO_Edit_Port_Value(GPIO_Port_t Ptr_GPIO_Port_tPort,uint16 Copy_u16Value);

/*****************************************************************************************
* Function Name   : GPIO_Edit_Pin_Value
* Description     : This function sets the value of a specified GPIO pin.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Pin_Config_tPin - A pointer to the configuration of the GPIO pin.
*                   Copy_GPIO_Output_tState - The desired output state for the pin (High, Low, or Toggle).
* Parameters (out): None
* Return value    : GPIO_Error_t - Indicates the status of the pin editing process. It 
*                   returns `GPIO_Error_Ok` if successful, or an error code indicating 
*                   a specific issue such as an invalid pin, incorrect mode, or invalid output option.
*****************************************************************************************/
GPIO_Error_t GPIO_Edit_Pin_Value(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin,GPIO_Output_t Copy_GPIO_Output_tState);

/*****************************************************************************************
* Function Name   : GPIO_Read_Pin_Value
* Description     : This function reads the value of a specified GPIO pin and determines 
*                   its current state (either GPIO_Output_Low or GPIO_Output_Hi).
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Pin_Config_tPin - A pointer to the configuration structure 
*                   that specifies the GPIO pin to be read.
* Parameters (out): Ptr_GPIO_Output_tState - A pointer to store the read state of the GPIO pin.
* Return value    : GPIO_Error_t - Indicates the status of the pin reading process. It 
*                   returns `GPIO_Error_Ok` if successful or an error code indicating the type 
*                   of error that occurred.
*****************************************************************************************/
GPIO_Error_t GPIO_Read_Pin_Value(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin,GPIO_Output_t *Ptr_GPIO_Output_tState);

/********************************************************************
 *  END OF FILE:  GPIO_Interface.h
********************************************************************/
#endif
