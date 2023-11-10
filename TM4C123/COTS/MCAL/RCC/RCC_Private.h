/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _RCC_PRIVATE_H_
 *  Module:  RCC
 *  Description:  RESET AND CLOCK CTRL REGISTERS
*******************************************************************/
#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
/*****************************************
----------     ADDRESSES     -------------
*****************************************/
/* --- Peripheral Address --- */
#define PERIPH_BASE_RCC       (0x400FE000)
#define RCC_BASE		   				(PERIPH_BASE_RCC + 0x060)
#define RCC					          (*((RCC_TAG*)(RCC_BASE)))
#define CLOCK       					((volatile u32*)(PERIPH_BASE_RCC))
#define RCGCWD								(0x180)
#define RCGCTIMER							(0x181)
#define RCGCGPIO							(0x182)
#define RCGCPWM								(0x190)
/*****************************************
----------   Rigister Tag   -------------
*****************************************/
/* --- INTCTRL  Definition --- */
typedef struct
{
  u32 MOSCDIS 		: 	1	 ;          /* Main Oscillator Disable */
  u32 				 		: 	3	 ;         	
  u32 OSCSRC 			: 	2	 ;          /* Oscillator Source */
	u32 XTAL		 		: 	5	 ;          /* Crystal Value */
	u32 BYPASS 			: 	1	 ;          /* PLL Bypass */
	u32 				 		: 	1	 ;          
	u32 PWRDN	 			: 	1	 ;          /* PLL Power Down */
	u32 			 			: 	3	 ;         	
	u32 PWMDIV 			: 	3	 ;          /* PWM Unit Clock Divisor */
	u32 USEPWMDIV		: 	1	 ;          /* Enable PWM Clock Divisor */
	u32 				 		: 	1	 ;          
	u32 USESYSDIV		: 	1	 ;          /* Enable System Clock Divider */
	u32 SYSDIV			: 	4	 ;          /* System Clock Divisor */
	u32 ACG			 		: 	1	 ;          /* Auto Clock Gating */
	u32 				 		: 	4	 ;          
} RCC_BF;
typedef union{u32 Register;RCC_BF Bits;}RCC_TAG;
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
typedef enum
{
			RCC_WDT										=0,
			RCC_GPIO									=1,
			RCC_GPT										=2,
			RCC_PWM										=3,
}RCC_CLOCK;
typedef enum
{
			RCC_Main_Oscillator				=0,
			RCC_Precision_Internal		=1,
			RCC_Precision_Internal_4	=2,
			RCC_Low_Frequency					=3,
}RCC_SOURCES;
typedef enum
{
			RCC_5Mhz									=0x09,
			RCC_6Mhz									=0x0B,
			RCC_8Mhz									=0x0E,
			RCC_10Mhz									=0x10,
			RCC_12Mhz									=0x11,
			RCC_24Mhz									=0x19,
			RCC_25Mhz									=0x1A,
}RCC_CRYSTAL_VALUE;
typedef enum
{
			RCC_Dev_1									=0x00,
			RCC_Dev_2									=0x01,
			RCC_Dev_3									=0x02,
			RCC_Dev_4									=0x03,
			RCC_Dev_5									=0x04,
			RCC_Dev_6									=0x05,
			RCC_Dev_16								=0x0F,
}RCC_DEVISOR;
#endif
/********************************************************************
 *  END OF FILE: RCC_Private.h
********************************************************************/
