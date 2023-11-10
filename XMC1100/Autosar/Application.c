/********************************************************************
* File Description
-----------------------
* Owner       : Khaled El-Sayed @t0ti20
* File        : Application.c
* Module      : ./Application
* Description : This application tests the GPIO driver for the Infineon XM1100.
*               It configures and controls various GPIO pins for demonstrationpurposes.
*               Developed in compliance with the Autosar Standard.
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
/* Standard AUTOSAR includes */
#include "Dio.h"
/* Custom includes specific to the XM1100 for testing purposes */
#include "./GPIO_Interface.h"
/*****************************************
----------- Global Variables -------------
*****************************************/
/* Channel 0 Configuration */
static GPIO_Pin_Config_t Channel_0 =
{
    GPIO_Port_0,
    GPIO_Pin_0,
    GPIO_Mode_Output_Push_Pull,
    GPIO_Hysteresis_Standard,
    ZERO,
    ZERO,
    GPIO_Control_Software
};
/* Channel 1 Configuration */
static GPIO_Pin_Config_t Channel_1 =
{
	GPIO_Port_0,
	GPIO_Pin_1,
	GPIO_Mode_Input_Direct_Floating,
	GPIO_Hysteresis_Standard,
	ZERO,
	ZERO,
	GPIO_Control_Software
};
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{
	Dio_LevelType Dio_Level;
	Dio_PortLevelType Dio_PortLevel;
	Std_VersionInfoType Std_VersionInfo;
	const Dio_ChannelGroupType Dio_ChannelGroup =
	{
		.mask=0x000f,
		.offset=0,
		.port=DIO_Port_0
	};
	/* Initialize channels */
	GPIO_Initialization(&Channel_0);
	GPIO_Initialization(&Channel_1);
	while (1) 
	{
		/* Read from DIO channel 1 */
		Dio_Level=Dio_ReadChannel(DIO_Channel_1);
		/* Write HIGH value to DIO channel 0 */
		Dio_WriteChannel(DIO_Channel_0,STD_HIGH);
		/* Read the level of all channels of port 0 */
		Dio_PortLevel=Dio_ReadPort(DIO_Port_0);
		/* Write the acquired port level to port 0 */
		Dio_WritePort(DIO_Port_0,Dio_PortLevel);
		/* Read a subset of adjoining bits of a port */
		Dio_PortLevel=Dio_ReadChannelGroup(&Dio_ChannelGroup);
		/* Write a subset of the adjoining bits of a port to a specified level */
		Dio_WriteChannelGroup(&Dio_ChannelGroup,Dio_PortLevel);
		/* Acquire version information */
		Dio_GetVersionInfo(&Std_VersionInfo);
		/* Flip the level of DIO channel 0 */
		Dio_Level=Dio_FlipChannel(DIO_Channel_0);
		/* Set the value of port 0 with required mask */
		Dio_MaskedWritePort(DIO_Port_0,Dio_PortLevel,0x000f);
		if(Dio_Level){}
	}
}
/********************************************************************
 *  END OF FILE:  Application.c
 ********************************************************************/
