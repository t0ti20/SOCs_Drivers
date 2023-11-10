/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _GPT_PRIVATE_H_
 *  Module:  GPT
 *  Description:  General Purpose Timer Private
*******************************************************************/
#ifndef _GPT_PRIVATE_H_
#define _GPT_PRIVATE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
/*****************************************
----------     ADDRESSES     -------------
*****************************************/
/* --- Peripheral Address --- */
#define PERIPH_BASE_GPT       			(0x40000000)
#define GPT_0_BASE       						(0x30000)
#define GPT_1_BASE       						(0x31000)
#define GPT_0            						(*((GPT_TYPES*)(PERIPH_BASE_GPT+GPT_0_BASE)))
#define GPT_1	            					(*((GPT_TYPES*)(PERIPH_BASE_GPT+GPT_1_BASE)))
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
#define GPT_Interrupt_Disable				(0)
#define GPT_Interrupt_Enable				(1)

#define GPT_CTL_TBPWML							(14)
typedef struct {                                   /* TIMER0 Structure */
  volatile u32  CFG;                               /* GPT Configuration */
  volatile u32  TAMR;                              /* GPT Timer A Mode */
  volatile u32  TBMR;                              /* GPT Timer B Mode */
  volatile u32  CTL;                               /* GPT Control */
  volatile u32  SYNC;                              /* GPT Synchronize */
  volatile u32  RESERVED;
  volatile u32  IMR;                               /* GPT Interrupt Mask */
  volatile u32  RIS;                               /* GPT Raw Interrupt Status */
  volatile u32  MIS;                               /* GPT Masked Interrupt Status */
  volatile u32  ICR;                               /* GPT Interrupt Clear */
  volatile u32  TAILR;                             /* GPT Timer A Interval Load */
  volatile u32  TBILR;                             /* GPT Timer B Interval Load */
  volatile u32  TAMATCHR;                          /* GPT Timer A Match */
  volatile u32  TBMATCHR;                          /* GPT Timer B Match */
  volatile u32  TAPR;                              /* GPT Timer A Prescale */
  volatile u32  TBPR;                              /* GPT Timer B Prescale */
  volatile u32  TAPMR;                             /* GPT TimerA Prescale Match */
  volatile u32  TBPMR;                             /* GPT TimerB Prescale Match */
  volatile u32  TAR;                               /* GPT Timer A */
  volatile u32  TBR;                               /* GPT Timer B */
  volatile u32  TAV;                               /* GPT Timer A Value */
  volatile u32  TBV;															 /* GPT Timer A Value  */
	volatile u32  RTCPD;                             /* GPT RTC Predivide */
  volatile u32  TAPS;                              /* GPT Timer A Prescale Snapshot */
  volatile u32  TBPS;                              /* GPT Timer B Prescale Snapshot */
  volatile u32  TAPV;                              /* GPT Timer A Prescale Value */
  volatile u32  TBPV;                              /* GPT Timer B Prescale Value */
  volatile u32  RESERVED1[981];
  volatile u32  PP;                                /* GPT Peripheral Properties */
}GPT_TYPES;

typedef enum
{
	Timer_0												 =0,
	Timer_1												 =1,
	Timer_2												 =2,
	Timer_3						 						 =3,
	Timer_4												 =4,
	Timer_5												 =5,
	Timer_6												 =6,
	Timer_7												 =7,
	Timer_8												 =8,
	Timer_9												 =9,
	Timer_10											 =10,
	Timer_11											 =11,
	Timer_12											 =12,
}GPT_NUMBERS;

typedef enum
{
	GPT_One_Shot									 =0,
	GPT_Periodic									 =1,
	GPT_RTC												 =2,
	GPT_Input_Edge_Count					 =3,
	GPT_Input_Edge_Time						 =4,
	GPT_PWM												 =5,
}GPT_MODES;

typedef enum
{
	GPT_Count_Up									 =0,
	GPT_Count_Down								 =1,
}GPT_COUNTS;

typedef enum
{
	GPT_Prescaler_1								 =0,
	GPT_Prescaler_2								 =1,
	GPT_Prescaler_4								 =2,
	GPT_Prescaler_8								 =3,
	GPT_Prescaler_16							 =4,
	GPT_Prescaler_32							 =5,
}GPT_PRESCALER;
#endif
/********************************************************************
 *  END OF FILE: GPT_Private.h
********************************************************************/
