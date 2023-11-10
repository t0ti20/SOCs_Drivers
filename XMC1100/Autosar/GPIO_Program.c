/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  GPIO_Program.c
 *  Module:  MCAL/GPIO
 *  Description:  General Input Output Driver Program File For XMC1100
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./GPIO_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*****************************************************************************************
* Function Name   : GPIO_Check_Input
* Description     : This function checks if the provided GPIO port and pin values are 
*                   valid for the selected microcontroller. It also returns a pointer to 
*                   the corresponding PORTX_t structure for further configuration.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Ptr_GPIO_Pin_Config_tPin - Pointer to GPIO pin configuration.
* Parameters (out): Ptr_PORTX_tPortX - Pointer to the PORTX_t structure for the selected port.
* Return value    : GPIO_Error_t - Error code indicating success or failure.
* Notes           : - The function checks if the provided GPIO port and pin values are 
*                     within valid ranges for the selected microcontroller (XMC1100 in this case).
*                   - It sets Ptr_PORTX_tPortX to point to the correct PORTX_t structure 
*                     based on the selected port.
*                   - Error codes are returned to indicate success or the specific error 
*                     encountered, allowing the caller to handle errors appropriately.
*                   - Ensure that the XMC1100-specific headers are correctly included 
*                     before using this function.
*****************************************************************************************/
static GPIO_Error_t GPIO_Check_Input(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin,PORTX_t** Ptr_PORTX_tPortX)
{
    GPIO_Error_t Local_GPIO_Error_tError_State = GPIO_Error_Ok;
    /* Check If User Entered the Correct GPIO Port */
    if ((Ptr_GPIO_Pin_Config_tPin->Port >= GPIO_Port_0) && (Ptr_GPIO_Pin_Config_tPin->Port <= GPIO_Port_2))
    {
        /* Select the Needed Port and Point to Its Location */
        switch (Ptr_GPIO_Pin_Config_tPin->Port)
        {
            case GPIO_Port_0:
                /* Get the Right Port Address to Configure */
                *Ptr_PORTX_tPortX = PORT0;
                /* Check If User Has Sent the Correct Pin */
                if ((Ptr_GPIO_Pin_Config_tPin->Pin >= GPIO_Pin_0) && (Ptr_GPIO_Pin_Config_tPin->Pin <= GPIO_Pin_15)) {}
                /* Pin is Not Valid for This Port */
                else { Local_GPIO_Error_tError_State = GPIO_Error_Pin; }
            break;
            case GPIO_Port_1:
                /* Get the Right Port Address to Configure */
                *Ptr_PORTX_tPortX = PORT1;
                /* Check If User Has Sent the Correct Pin */
                if ((Ptr_GPIO_Pin_Config_tPin->Pin >= GPIO_Pin_0) && (Ptr_GPIO_Pin_Config_tPin->Pin <= GPIO_Pin_6)) {}
                /* Pin is Not Valid for This Port */
                else { Local_GPIO_Error_tError_State = GPIO_Error_Pin; }
            break;
            case GPIO_Port_2:
                /* Get the Right Port Address to Configure */
                *Ptr_PORTX_tPortX = PORT2;
                /* Check If User Has Sent the Correct Pin */
                if ((Ptr_GPIO_Pin_Config_tPin->Pin >= GPIO_Pin_0) && (Ptr_GPIO_Pin_Config_tPin->Pin <= GPIO_Pin_11)) {}
                /* Pin is Not Valid for This Port */
                else { Local_GPIO_Error_tError_State = GPIO_Error_Pin; }
            break;
        }
    }
    /* User Has Entered an Incorrect Port */
    else { Local_GPIO_Error_tError_State = GPIO_Error_Port; }
    return Local_GPIO_Error_tError_State;
}
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
GPIO_Error_t GPIO_Read_Pin_Value(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin,GPIO_Output_t *Ptr_GPIO_Output_tState)
{
     GPIO_Error_t Local_GPIO_Error_tError_State=GPIO_Error_Ok;
     PORTX_t* Ptr_PORTX_tPortX=NULL_PTR;
     /*Send User Inputs To Check For Inputs And Return Input State And Port Address*/
     Local_GPIO_Error_tError_State=GPIO_Check_Input(Ptr_GPIO_Pin_Config_tPin,&Ptr_PORTX_tPortX);
     /*Check If The Inputs Are Valid*/
     if(Local_GPIO_Error_tError_State==GPIO_Error_Ok)
     {
          /*Check If The Pin Is Input Store Its State*/
          if(Get_Bit(Ptr_GPIO_Pin_Config_tPin->Mode,FOUR)==ZERO){*Ptr_GPIO_Output_tState=(GPIO_Output_t)Get_Bit(Ptr_PORTX_tPortX->Pn_IN.Register,Ptr_GPIO_Pin_Config_tPin->Pin);}
          /*The Pin Is Output Return Error*/
          else {Local_GPIO_Error_tError_State=GPIO_Error_Pin_Not_Input;}
     }
     /*The Input Pin Is Not Valid*/
     else {}
     return Local_GPIO_Error_tError_State;
}
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
GPIO_Error_t GPIO_Read_Port_Value(GPIO_Port_t Ptr_GPIO_Port_tPort,uint16 *Ptr_u16Value)
{
     GPIO_Error_t Local_GPIO_Error_tError_State=GPIO_Error_Ok;
     /*Check If User Entered Right GPIO Port*/
     if((Ptr_GPIO_Port_tPort>=GPIO_Port_0)&&(Ptr_GPIO_Port_tPort<=GPIO_Port_2))
     {
          /*Select Needed Port And Gets Its Input Data*/
          switch (Ptr_GPIO_Port_tPort)
          {
               /*Read Data For Port 0*/
               case GPIO_Port_0:*Ptr_u16Value=(uint16)(PORT0->Pn_IN.Register);break;
               /*Read Data For Port 1*/
               case GPIO_Port_1:*Ptr_u16Value=(uint16)(PORT1->Pn_IN.Register);break;
               /*Read Data For Port 2*/
               case GPIO_Port_2:*Ptr_u16Value=(uint16)(PORT2->Pn_IN.Register);break;
          }
     }
     /*User Entered Wrong Port*/
     else {Local_GPIO_Error_tError_State=GPIO_Error_Port;}
     return Local_GPIO_Error_tError_State;
}
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
GPIO_Error_t GPIO_Edit_Port_Value(GPIO_Port_t Ptr_GPIO_Port_tPort,uint16 Copy_u16Value)
{
     GPIO_Error_t Local_GPIO_Error_tError_State=GPIO_Error_Ok;
     /*Check If User Entered Right GPIO Port*/
     if((Ptr_GPIO_Port_tPort>=GPIO_Port_0)&&(Ptr_GPIO_Port_tPort<=GPIO_Port_2))
     {
          /*Select Needed Port And Set Its Valure*/
          switch (Ptr_GPIO_Port_tPort)
          {
               /*Write Data For Port 0*/
               case GPIO_Port_0:PORT0->Pn_OUT.Register=Copy_u16Value;break;
               /*Write Data For Port 1*/
               case GPIO_Port_1:PORT1->Pn_OUT.Register=Copy_u16Value;break;
               /*Write Data For Port 2*/
               case GPIO_Port_2:PORT2->Pn_OUT.Register=Copy_u16Value;break;
          }
     }
     /*User Entered Wrong Port*/
     else {Local_GPIO_Error_tError_State=GPIO_Error_Port;}
     return Local_GPIO_Error_tError_State;
}
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
GPIO_Error_t GPIO_Edit_Pin_Value(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin,GPIO_Output_t Copy_GPIO_Output_tState)
{
     GPIO_Error_t Local_GPIO_Error_tError_State=GPIO_Error_Ok;
     PORTX_t* Ptr_PORTX_tPortX=NULL_PTR;
     /*Send User Inputs To Check For Inputs And Return Input State And Port Address*/
     Local_GPIO_Error_tError_State=GPIO_Check_Input(Ptr_GPIO_Pin_Config_tPin,&Ptr_PORTX_tPortX);
     /*Check If The Inputs Are Valid*/
	if(Local_GPIO_Error_tError_State==GPIO_Error_Ok)
     {
          /*Check If The Pin Is Out*/
          if(Get_Bit(Ptr_GPIO_Pin_Config_tPin->Mode,FOUR)==ONE)
          {
/*Configure Pin Value By Just Write Ticnique*/
#if SWITCH_MODE == DIRECT_WRITE
               if(Copy_GPIO_Output_tState==GPIO_Output_Hi){Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)(ONE<<Ptr_GPIO_Pin_Config_tPin->Pin);}
               else if(Copy_GPIO_Output_tState==GPIO_Output_Low){Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)(ONE<<((Ptr_GPIO_Pin_Config_tPin->Pin)+16));}
               else if(Copy_GPIO_Output_tState==GPIO_Output_Toggle){Ptr_PORTX_tPortX->Pn_OMR.Register=(uint32)((ONE<<((Ptr_GPIO_Pin_Config_tPin->Pin)+16))|(ONE<<(Ptr_GPIO_Pin_Config_tPin->Pin)));}
               else{Local_GPIO_Error_tError_State=GPIO_Error_Output_Option;}
/*Configure Pin Value By Read Modify Write Ticnique*/
#elif SWITCH_MODE == READ_WRITE
               /*Set Equivilant Bit Hi*/
               if(Copy_GPIO_Output_tState==GPIO_Output_Hi){Set_Bit(Ptr_PORTX_tPortX->Pn_OUT.Register,Ptr_GPIO_Pin_Config_tPin->Pin);}
               /*Clear Equivilant Bit Low*/
               else if(Copy_GPIO_Output_tState==GPIO_Output_Low){Clear_Bit(Ptr_PORTX_tPortX->Pn_OUT.Register,Ptr_GPIO_Pin_Config_tPin->Pin);}
               /*Toggle Equivilant Bit*/
               else if(Copy_GPIO_Output_tState==GPIO_Output_Toggle){Toggle_Bit(Ptr_PORTX_tPortX->Pn_OUT.Register,Ptr_GPIO_Pin_Config_tPin->Pin);}
               /*User Entered Not Valid Input*/
               else{Local_GPIO_Error_tError_State=GPIO_Error_Output_Option;}
#endif
          }
          /*Return Error Pin Is Not Output*/
          else {Local_GPIO_Error_tError_State=GPIO_Error_Pin_Not_Output;}
     }
     /*The Input Pin Is Not Valid*/
     else {}
     return Local_GPIO_Error_tError_State;
}
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
GPIO_Error_t GPIO_Initialization(GPIO_Pin_Config_t *Ptr_GPIO_Pin_Config_tPin)
{
     GPIO_Error_t Local_GPIO_Error_tError_State=GPIO_Error_Ok;
     PORTX_t* Ptr_PORTX_tPortX=NULL_PTR;
     /*Send User Inputs To Check For Inputs And Return Input State And Port Address*/
     Local_GPIO_Error_tError_State=GPIO_Check_Input(Ptr_GPIO_Pin_Config_tPin,&Ptr_PORTX_tPortX);
     if(Local_GPIO_Error_tError_State==GPIO_Error_Ok)
     {
          /*select the digital output and input driver functionality and characteristics of a GPIO port pin*/
          Write_Bits(Ptr_PORTX_tPortX->Pn_IOCRX[Ptr_GPIO_Pin_Config_tPin->Pin/FOUR].Register,(THREE+((Ptr_GPIO_Pin_Config_tPin->Pin%FOUR)*EIGHT)),FIVE,(Ptr_GPIO_Pin_Config_tPin->Mode));
          /*select the pad hysteresis*/
          if((Ptr_GPIO_Pin_Config_tPin->Pin%EIGHT)==ZERO){Write_Bits(Ptr_PORTX_tPortX->Pn_PHCRX[Ptr_GPIO_Pin_Config_tPin->Pin/EIGHT].Register,TWO,ONE,Ptr_GPIO_Pin_Config_tPin->Hysteresis);}
          else{Write_Bits(Ptr_PORTX_tPortX->Pn_PHCRX[Ptr_GPIO_Pin_Config_tPin->Pin/EIGHT].Register,(TWO+(FOUR*(Ptr_GPIO_Pin_Config_tPin->Pin%EIGHT))),ONE,Ptr_GPIO_Pin_Config_tPin->Hysteresis);}
          /*configure the digital pad structure in shared analog and digital ports*/
          Write_Bits(Ptr_PORTX_tPortX->Pn_PDISC.Register,Ptr_GPIO_Pin_Config_tPin->Pin,ONE,!(Ptr_GPIO_Pin_Config_tPin->Pad));
          /*enabled Pin Power Save option*/
          Write_Bits(Ptr_PORTX_tPortX->Pn_PPS.Register,Ptr_GPIO_Pin_Config_tPin->Pin,ONE,Ptr_GPIO_Pin_Config_tPin->Power_Save);
          /*select which peripheral has the control over the pin*/
          Write_Bits(Ptr_PORTX_tPortX->Pn_HWSEL.Register,(Ptr_GPIO_Pin_Config_tPin->Pin*TWO),TWO,Ptr_GPIO_Pin_Config_tPin->Control);
     }
     return Local_GPIO_Error_tError_State;
}
/********************************************************************
 *  END OF FILE:  GPIO_Program.c
********************************************************************/
