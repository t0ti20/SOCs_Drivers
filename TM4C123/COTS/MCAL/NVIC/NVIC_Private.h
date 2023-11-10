/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _NVIC_PRIVATE_H_
 *  Module:  NVIC
 *  Description:  NESTED VICTOR INTERRUPT CTRL REGISTERS
*******************************************************************/
#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Standard_Types.h"
/*****************************************
----------     ADDRESSES     -------------
*****************************************/
/* --- Peripheral Address --- */
#define PERIPH_BASE_NVIC       			(0xE000E000)
#define APINT_BASE             			(PERIPH_BASE_NVIC + 0xD0C)
#define INTCTRL_BASE           			(PERIPH_BASE_NVIC + 0xD04)
#define SYSHNDCTRL_BASE							(PERIPH_BASE_NVIC + 0xD24)
#define SWTRIG_BASE									(PERIPH_BASE_NVIC + 0xF00)
#define INTCTRL           	   			(*((INTCTRL_TAG*)(INTCTRL_BASE)))
#define NVIC_ENABLE_BASE	 	   			((volatile u32*)(PERIPH_BASE_NVIC + 0x100))
#define NVIC_DISABLE_BASE		   			((volatile u32*)(PERIPH_BASE_NVIC + 0x180))
#define NVIC_SET_PENDING_BASE		    ((volatile u32*)(PERIPH_BASE_NVIC + 0x200))
#define NVIC_CLEAR_PENDING_BASE		  ((volatile u32*)(PERIPH_BASE_NVIC + 0x280))
#define NVIC_PRIORITY_BASE	 	   		((volatile u32*)(PERIPH_BASE_NVIC + 0x400))
#define SYSHNDCTRL           	   	 	(*((volatile u32*)(SYSHNDCTRL_BASE)))
#define APINT           	   	 			(*((volatile u32*)(APINT_BASE)))
#define SWTRIG             					(*((volatile u8 *)(SWTRIG_BASE)))
/*****************************************
----------   Rigister Tag   -------------
*****************************************/
/* --- INTCTRL  Definition --- */
typedef struct
{
  volatile u32 VECACT 		: 	8	 ;          /*Interrupt Pending Vector Number*/
  volatile u32 		 				: 	3	 ;
  volatile u32 RETBASE		: 	1	 ;          /*Return to Base*/
  volatile u32 VECPEND		: 	8	 ;          /*Interrupt Pending Vector Number*/
  volatile u32 					 	: 	2	 ;
  volatile u32 ISRPEND		: 	1	 ;          /*Interrupt Pending*/
  volatile u32 ISRPRE 		: 	1	 ;          /*Debug Interrupt Handling*/
  volatile u32 					 	: 	1	 ;
  volatile u32 PENDSTCLR	: 	1	 ;          /*SysTick Clear Pending*/
  volatile u32 PENDSTSET	: 	1	 ;          /*SysTick Set Pending*/
  volatile u32 UNPENDSV 	: 	1	 ;          /*PendSV Clear Pending*/
  volatile u32 PENDSV			: 	1	 ;          /*PendSV Set Pending*/
  volatile u32 					 	: 	2	 ;
  volatile u32 NMISET 		: 	1	 ;          /*NMI Set Pending*/
} INTCTRL_BF;
typedef union{u32 Register;INTCTRL_BF Bits;}INTCTRL_TAG;
/*****************************************
----- GLOBAL DATA TYPES & STRUCTURES -----
*****************************************/
/* --- CORE STATES --- */
#define	MEMORY_MANAGMENT_ACTIVE		(0)
#define	BUS_FAULT_ACTIVE					(1)
#define	USAGE_FAULT_ACTIVE				(3)
#define	SV_CALL_ACTIVE						(7)
#define	BEBUG_MONITOR_ACTIVE			(8)
#define	PEND_SV_ACTIVE						(10)
#define	SYSTICK_ACTIVE						(11)
#define	USAGE_FAULT_PENDING				(12)
#define	MEMORY_MANAGMENT_PENDING	(13)
#define	BUS_FAULT_PENDING					(14)
#define	SV_CALL_PENDING						(15)
#define	MEMORY_MANAGMENT_ENABLE		(16)
#define	BUS_FAULT_ENABLE					(17)
#define	USAGE_FAULT_ENABLE				(18)
#define	APINT_KEY 								(0x05FA0000)
/* --- Group Sub-Group --- */
typedef enum
{
	NVIC_XXX									=0,
	NVIC_XXY									=5,
	NVIC_XYY									=6,
	NVIC_YYY									=7,
	NVIC_GROUP_0							=0,
	NVIC_GROUP_1							=1,
	NVIC_GROUP_2							=2,
	NVIC_GROUP_3							=3,
	NVIC_SUP_GROUP_0					=0,
	NVIC_SUP_GROUP_1					=1,
	NVIC_SUP_GROUP_2					=2,
	NVIC_SUP_GROUP_3					=3,
}NVIC_GROUPS;
/* --- NVIC STATE --- */
typedef enum
{
	NVIC_Disable							=0,
	NVIC_Enable								=1,
	NVIC_Set_Pending					=2,
	NVIC_Clear_Pending				=3,
	NVIC_Active								=4,
	NVIC_Not_Active						=5,
}NVIC_STATE;
/* --- NVIC TYPES --- */
typedef enum
{
	NVIC_Is_Enable						=1,
	NVIC_Is_Actice						=2,
	NVIC_Is_Pending						=3,
	NVIC_Is_Running						=4,
}
NVIC_GET_TYPES;
typedef enum
{
	MEMORY_MANAGMENT					=1,
	BUS_FAULT									=2,
	USAGE_FAULT								=3,
	SV_CALL										=4,
	BEBUG_MONITOR							=5,
	PEND_SV										=6,
	SYSTICK										=7,
}
NVIC_CORE_TYPES;
typedef enum
{
	GPIO_A_INTERRUPT					=0,
	GPIO_B_INTERRUPT					=1,
	GPIO_C_INTERRUPT					=2,
	GPIO_D_INTERRUPT					=3,
	GPIO_E_INTERRUPT					=4,
	UART0											=5,
	SSI0											=6,
	I2C												=7,
	PWM0_FAULT								=8,
	PWM0_GENERATOR_0					=9,
	PWM0_GENERATOR_1					=10,
	PWM0_GENERATOR_2					=11,
	/*To Be Completed*/
	GPT_0_A										=19,
	GPT_0_B										=20,
	/*To Be Completed*/
	PWM1_GENERATOR_0					=134,
	PWM1_GENERATOR_1					=135,
	PWM1_GENERATOR_2					=136,
	PWM1_GENERATOR_3					=137,
	PWM1_FAULT								=138,
}
NVIC_PERIPHERAL_TYPES;
#endif
/********************************************************************
 *  END OF FILE: NVIC_Private.h
********************************************************************/
