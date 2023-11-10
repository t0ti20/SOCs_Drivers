/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  LCD_Program.c
 *  Module:  HAL->LCD
 *  Description:  LCD 16*2 Charachter Driver
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "LCD_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void LCD_VidInitialization(void)
* Description     : Initialize LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Void
* Parameters (out): Void
* Return value:   : Void
********************************************************************/
void LCD_VidInitialization(void)
{
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_E_PIN,OUTPUT);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	/* Mode Control */
#if LCD_Mode == Mode_8
	DIO_VidSet_Whole_Port_Direction(LCD_DATA_PORT,OUTPUT);					/* Port Direction Select */
	delay_ms(40);													/*DELAY*/
	LCD_VidSend_Command(0x3C);										/*1ST FROM DATA SHEET(Function Set)*/
	LCD_VidSend_Command(0x0C);										/*2ND FROM DATA SHEET(Display On-Off)*/
	LCD_VidSend_Command(HI);
#elif LCD_Mode == Mode_4
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,LCD_DATA_4,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,LCD_DATA_5,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,LCD_DATA_6,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,LCD_DATA_7,OUTPUT);
	delay_ms(40);
	LCD_VidSend_Command(0X02);
	LCD_VidSend_Command(0X28);
	LCD_VidSend_Command(0X0C);
	LCD_VidSend_Command(0X06);
#else
#warning (" Wrong Configuration !!")
#endif
}
/********************************************************************
* Syntax          : void LCD_VidSend_Command(u8 Copy_u8Command)
* Description     : Send Command To LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (u8 Copy_u8Command)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSend_Command(u8 Copy_u8Command)
{
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,LOW);							/*SET RS PIN AS LOW*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);							/*SET RW PIN AS LOW TO WRITE*/
#if LCD_Mode == Mode_8
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Command);							/*SEND COMMAND*/
#elif LCD_Mode == Mode_4
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_4,Get_Bit(Copy_u8Command,4));			/*Send Most 4-Bits*/
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_5,Get_Bit(Copy_u8Command,5));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_6,Get_Bit(Copy_u8Command,6));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_7,Get_Bit(Copy_u8Command,7));
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);								/*SET ENABLE PIN*/
	delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	delay_ms(50);
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_4,Get_Bit(Copy_u8Command,0));			/*Send Least 4-Bits*/
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_5,Get_Bit(Copy_u8Command,1));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_6,Get_Bit(Copy_u8Command,2));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_7,Get_Bit(Copy_u8Command,3));
#else
#warning (" Wrong Configuration !!")
#endif
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);							/*SET ENABLE PIN*/
	delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	delay_ms(2);
}
/********************************************************************
* Syntax          : itoa(u32 Data,u8 String[])
* Description     : Convert Integer To String
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Copy To Integer) (Ptr To String)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
static void itoa(u32 Data,char String[])
{
     u8 Digit=ZERO,Count;
     if(!Data)String[Digit++]='0';
     else for(;Data;Digit++,Data/=TEN)String[Digit]=(Data%TEN+'0');
     String[Digit]=ZERO;
     for(Count=ZERO;Count<(Digit>>ONE);Count++)
     {
          String[Count]^=String[Digit-Count-ONE];
          String[Digit-Count-ONE]^=String[Count];
          String[Count]^=String[Digit-Count-ONE];
     }
}
/********************************************************************
* Syntax          : HAL_LCD_Send_Number(u32 Data)
* Description     : Send An Intiger To LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Copy To u32 INT)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSend_Number(u32 Data)
{
     char String[8];
     itoa(Data,String);
     LCD_VidSend_String((u8 const *)String);
}
/********************************************************************
* Syntax          : void LCD_VidSend_Data(u8 Copy_u8Data)
* Description     : Send Command To LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (u8 Data)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSend_Data(u8 Copy_u8Data)
{
	delay_ms(50);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,HI);						/*SET RS PIN AS HI*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);						/*SET RW PIN AS LOW TO WRITE*/
#if LCD_Mode == Mode_8
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Data);							/*SEND Data*/
#elif LCD_Mode == Mode_4
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_4,Get_Bit(Copy_u8Data,4));		/*Send Most 4-Bits*/
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_5,Get_Bit(Copy_u8Data,5));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_6,Get_Bit(Copy_u8Data,6));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_7,Get_Bit(Copy_u8Data,7));
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);							/*SET ENABLE PIN*/
	delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	delay_ms(50);
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_4,Get_Bit(Copy_u8Data,0));		/*Send Least 4-Bits*/
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_5,Get_Bit(Copy_u8Data,1));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_6,Get_Bit(Copy_u8Data,2));
	DIO_VidSet_Pin_Value(LCD_DATA_PORT,LCD_DATA_7,Get_Bit(Copy_u8Data,3));
#else
#warning (" Wrong Configuration !!")
#endif
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);							/*SET ENABLE PIN*/
	delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	delay_ms(2);
}
/********************************************************************
* Syntax          : void LCD_VidSet_Position(u8 Copy_u8x_location,u8 Copy_u8y_location)
* Description     : Set Courser Location
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (u8 x_axis) (u8 y_axis)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSet_Position(u8 Copy_u8y_location,u8 Copy_u8x_location)
{
	LCD_VidSend_Command((128|(((Copy_u8y_location)*0x40)+Copy_u8x_location)));
}
/********************************************************************
* Syntax          : void LCD_VidSend_Special_Character(u8 *Copy_u8Pattern,u8 Copy_u8Pattern_Location,u8 Copy_u8x_location,u8 Copy_u8y_location)
* Description     : Send Special Character To LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (ptr to_pattern) (u8 location_to_be_stored) (u8 x_axis) (u8 y_axis)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSend_Special_Character(u8 *Copy_u8Pattern,u8 Copy_u8Pattern_Location,u8 Copy_u8y_location,u8 Copy_u8x_location)
{
	LCD_VidSend_Command(64+(8*Copy_u8Pattern_Location));
	for(u8 i=0;i<8;i++)
	{
		LCD_VidSend_Data(Copy_u8Pattern[i]);
	}
	LCD_VidSet_Position(Copy_u8x_location,Copy_u8y_location);
	LCD_VidSend_Data(Copy_u8Pattern_Location);
}
/********************************************************************
* Syntax          : void LCD_VidSend_String(u8 *Copy_u8String);
* Description     : Send String To LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (ptr to_string)
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidSend_String(u8 const *Copy_u8String)
{
	u8 Local_u8Counter=0;
	while(((Copy_u8String[Local_u8Counter])!=0)&&Local_u8Counter<16)
	{
		LCD_VidSend_Data(Copy_u8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/********************************************************************
* Syntax          : void LCD_VidClear(void)
* Description     : Clear The LCD
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : None
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void LCD_VidClear(void)
{
	LCD_VidSend_Command(Clear_Screen);
}
/********************************************************************
 *  END OF FILE: LCD_Progeam.c
********************************************************************/
