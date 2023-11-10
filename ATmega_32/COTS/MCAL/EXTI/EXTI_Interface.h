/* File Guard */
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
/*Include*/
#include "Macros.h"
#include "Standard_Types.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
/*External Interrupt Enable */
void EXTI_VidInitialization (u8 Copy_u8Interrupt,u8 Copy_u8Mode);
void EXTI_0(void(*Copy_VidInturrept)(void));
void EXTI_1(void(*Copy_VidInturrept)(void));
void EXTI_2(void(*Copy_VidInturrept)(void));
#endif
/* _EXTI_INTERFACE_H_*/
