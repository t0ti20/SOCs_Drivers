/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _WDT_PRIVATE_H_
 *  Module:  WDT
 *  Description:  Watch Dog Timer Interface Private
*******************************************************************/
#ifndef _WDT_PRIVATE_H_
#define _WDT_PRIVATE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
/*****************************************
----------     ADDRESSES     -------------
*****************************************/
/* --- Peripheral Address --- */
#define PERIPH_BASE_WDT       			(0x40000000)
#define WDT_KEY											(0x1ACCE551)
#define PIOSC_CLOCK									(16000000)
#define WDT_0_BASE			       			(PERIPH_BASE_WDT+(0x0000))
#define WDT_1_BASE			       			(PERIPH_BASE_WDT+(0x1000))
#define WDT_0												(*((WDT_REGISTERS*)(WDT_0_BASE)))
#define WDT_1												(*((WDT_REGISTERS*)(WDT_1_BASE)))

/*****************************************
----------   Rigister Tag   -------------
*****************************************/
typedef struct
{
  volatile u32 LOAD;                              /* Watchdog Load */
  volatile u32 VALUE;                             /* Watchdog Value */
  volatile u32 CTL;                               /* Watchdog Control */
  volatile u32 ICR;                               /* Watchdog Interrupt Clear */
  volatile u32 RIS;                               /* Watchdog Raw Interrupt Status */
  volatile u32 MIS;                               /* Watchdog Masked Interrupt Status */
  volatile u32 RESERVED[256];
  volatile u32 TEST;                              /* Watchdog Test */
  volatile u32 RESERVED1[505];
  volatile u32 LOCK;                              /* Watchdog Lock */
}WDT_REGISTERS;
#define CTL_WRC									(31)
#define CTL_INTTYPE							(2)
#define CTL_RESEN								(1)
#define CTL_INTEN								(0)
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
#define GPIO_Input      		  (0)
#define GPIO_Output     		  (1)
#define GPIO_Alternate  		  (2)
#define GPIO_Analog    			  (3)
typedef enum
{
	WDT_Disable_Reset						=0,
	WDT_Enable_Reset						=1,
}WDT_CONFIG;
#endif
/********************************************************************
 *  END OF FILE: WDT_Private.h
********************************************************************/
