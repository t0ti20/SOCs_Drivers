/* File Guard */
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
/* Include */
#include "Macros.h"
#include "Standard_Types.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "EXTI_Interface.h"
/*ADC Functions*/
void ADC_VidInitialization (void);
void ADC_VidAsync_Reading (u8 Copy_u8Channel,u16 *Copy_u16Reading);
void ADC_VidSync_Reading (void(*Call_Back_Function)(u16));
void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u32Min,u32 Copy_u32Max,u16 *Copy_u32Reading);
#endif
/* _EXTERNAL_INTERFACE_H_*/
