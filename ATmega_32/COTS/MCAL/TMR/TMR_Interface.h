/* File Guard */
#ifndef _TMR_INTERFACE_H_
#define _TMR_INTERFACE_H_
/* Include */
#include "Macros.h"
#include "Standard_Types.h"
#include "TMR_Config.h"
#include "TMR_Private.h"
/* Global Variables */
void WDT_VidStart(void);
void WDT_VidStop(void);
/************************************************/
/*					TMR 0 			   */
/************************************************/
void TMR_0_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8TMR_Pre_Scalar);
void TMR_0_VidBusy_Wait_ms(u32 Copy_u32Delay);
void TMR_0_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));
void TMR_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));
void TMR_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));
u8 TMR_0_VidGet_Count(void);
/************************************************/
/*				     TMR 2  			   */
/************************************************/
void TMR_2_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8TMR_Pre_Scalar);
void TMR_2_VidBusy_Wait_ms(u32 Copy_u32Delay);
void TMR_2_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));
void TMR_2_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));
void TMR_2_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));
/************************************************/
/*                     General                  */
/************************************************/
void TMR_VidPwm_Duty_Cycle(u8 Copy_u8TMR,u8 Copy_u8Duty_Cycle);
#endif
/*_TMR_INTERFACE_H_*/
