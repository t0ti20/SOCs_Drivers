/*File Guard*/
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_
/******** Registers ********/
#define   GIFR    *((volatile u8*)0x5A)
#define   GICR    *((volatile u8*)0x5B)
#define   MCUCR   *((volatile u8*)0x55)
#define   MCUCSR  *((volatile u8*)0x54)
/******** MCUCR_Bits ********/
#define   MCUCR_ISC00      0
#define   MCUCR_ISC01      1
#define   MCUCR_ISC10      2
#define   MCUCR_ISC11      3
/******** MCUCSR_Bits ********/
#define   MCUCSR_ISC2      6
/******** GICR_Bits ********/
#define   GICR_INT0		6
#define   GICR_INT1		7
#define   GICR_INT2		5
/******** GIFR_Bits ********/
#define   GIFR_INT0		6
#define   GIFR_INT1		7
#define   GIFR_INT2		5
/*Global*/
#ifndef SREG
#define SREG  *((volatile u8*)0x5F)
#define SREG_I 7
#endif
/************************************************/
/*		    	Macros for Configure 			*/
/************************************************/
typedef enum {Interrupt_0,Interrupt_1,Interrupt_2}EXTI;
typedef enum {Low_Level=10,On_Change,Falling_Edge,Rising_Edge}Interrupt_Mode;

#endif 
/*EXTI_PRIVATE_H_*/
