/*-----------------------------------------------------------------------*/
/*------------------------------- INCLUDE -------------------------------*/
/*-----------------------------------------------------------------------*/
#include  "EXTI_Interface.h"
/*-------------------------------------------------------------------------------------------------*/
/*------------------------------------------ Main Functions ---------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*------------------ Interrupt INIT --------------------*/
void EXTI_VidInitialization(u8 Copy_u8Interrupt,u8 Copy_u8Mode)
{
	switch(Copy_u8Interrupt)
	{
		case(Interrupt_0):
				switch(Copy_u8Mode)
				{
					case(Low_Level):Clear_Bit(MCUCR,MCUCR_ISC01);Clear_Bit(MCUCR,MCUCR_ISC00);Set_Bit(GICR,GICR_INT0);break;
					case(On_Change):Set_Bit(MCUCR,MCUCR_ISC00);Clear_Bit(MCUCR,MCUCR_ISC01);Set_Bit(GICR,GICR_INT0);break;
					case(Falling_Edge):Clear_Bit(MCUCR,MCUCR_ISC00);Set_Bit(MCUCR,MCUCR_ISC01);Set_Bit(GICR,GICR_INT0);break;
					case(Rising_Edge):Set_Bit(MCUCR,MCUCR_ISC01);Set_Bit(MCUCR,MCUCR_ISC00);Set_Bit(GICR,GICR_INT0);break;
					case(Disable):Clear_Bit(GICR,GICR_INT0);break;
					case(Enable):Set_Bit(GICR,GICR_INT0);break;
					default:Clear_Bit(GICR,GICR_INT0);break;
				}
		break;
		case(Interrupt_1):
				switch(Copy_u8Mode)
				{
					case(Low_Level):Clear_Bit(MCUCR,MCUCR_ISC11);Clear_Bit(MCUCR,MCUCR_ISC10);Set_Bit(GICR,GICR_INT1);break;
					case(On_Change):Set_Bit(MCUCR,MCUCR_ISC10);Clear_Bit(MCUCR,MCUCR_ISC11);Set_Bit(GICR,GICR_INT1);break;
					case(Falling_Edge):Clear_Bit(MCUCR,MCUCR_ISC10);Set_Bit(MCUCR,MCUCR_ISC11);Set_Bit(GICR,GICR_INT1);break;
					case(Rising_Edge):Set_Bit(MCUCR,MCUCR_ISC10);Set_Bit(MCUCR,MCUCR_ISC11);Set_Bit(GICR,GICR_INT1);break;
					case(Disable):Clear_Bit(GICR,GICR_INT1);break;
					case(Enable):Set_Bit(GICR,GICR_INT1);break;
					default:Clear_Bit(GICR,GICR_INT1);break;
				}
		break;
		case(Interrupt_2):
			switch(Copy_u8Mode)
			{
				case(Falling_Edge):Clear_Bit(MCUCSR,MCUCSR_ISC2);Set_Bit(GICR,GICR_INT2);break;
				case(Rising_Edge):Set_Bit(MCUCSR,MCUCR_ISC00);Set_Bit(GICR,GICR_INT2);break;
				case(Disable):Clear_Bit(GICR,GICR_INT2);break;
				case(Enable):Set_Bit(GICR,GICR_INT2);break;
				default:Clear_Bit(GICR,GICR_INT2);break;
			}
		break;
		default:Clear_Bit(GICR,GICR_INT0);Clear_Bit(GICR,GICR_INT1);Clear_Bit(GICR,GICR_INT2);break;
	}
}

/*------------------ ISR Interrupt_0 --------------------*/
static void (*EXTI_0_Function)(void)=0;
void EXTI_0(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		EXTI_0_Function = Copy_VidInturrept;
	}
}
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(EXTI_0_Function!=0)
	{
		EXTI_VidInitialization(Interrupt_0,Disable);
		EXTI_0_Function();
		EXTI_VidInitialization(Interrupt_0,Enable);
	}
}
/*------------------ ISR Interrupt_1 --------------------*/
static void (*EXTI_1_Function)(void)=0;
void EXTI_1(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		EXTI_1_Function = Copy_VidInturrept;
	}
}
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(EXTI_1_Function!=0)
	{
		EXTI_VidInitialization(Interrupt_1,Disable);
		EXTI_1_Function();
		EXTI_VidInitialization(Interrupt_1,Enable);
	}
}
/*------------------ ISR Interrupt_2 --------------------*/
static void (*EXTI_2_Function)(void)=0;
void EXTI_2(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		EXTI_2_Function = Copy_VidInturrept;
	}
}
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(EXTI_2_Function!=0)
	{
		EXTI_VidInitialization(Interrupt_2,Disable);
		EXTI_2_Function();
		EXTI_VidInitialization(Interrupt_2,Enable);
	}
}


