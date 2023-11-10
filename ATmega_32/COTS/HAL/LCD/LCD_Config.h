/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  LCD_Config.h
 *  Module:  HAL->LCD
 *  Description:  LCD 16*2 Charachter Driver
*******************************************************************/
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_
/*****************************************
----------   Configuration    ------------
*****************************************/
/*LCD Operation Mode*/
#define LCD_Mode		Mode_4                        /* Mode_8 - Mode_4 */
/*CONTROL PORT And Pins*/
#define LCD_CTRL_PORT 	Port_B					 /* Port_A-Port_B-Port_C-Port_D */
#define LCD_RW_PIN		Pin_2
#define LCD_RS_PIN		Pin_1					 /* Pin_0-Pin_1-Pin_2-......... */
#define LCD_E_PIN		Pin_3
/*Data PORT*/
#define LCD_DATA_PORT	Port_B				  	 /* Port_A-Port_B-Port_C-Port_D */
#define LCD_DATA_4		Pin_4
#define LCD_DATA_5		Pin_5
#define LCD_DATA_6		Pin_6
#define LCD_DATA_7		Pin_7
#endif
/********************************************************************
 *  END OF FILE: LCD_Config.h
********************************************************************/
