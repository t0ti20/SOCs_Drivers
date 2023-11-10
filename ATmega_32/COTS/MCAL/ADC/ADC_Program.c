/*------------------------------- INCLUDE -------------------------------*/
#include "ADC_Interface.h"
/*-------------------------------------------------------------------*/
/*------------------------- OPTIONS FOR ADC -------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidInitialization (void)
{
	/* SELECT REFERANCE */
#if Voltage_Referace == AVCC
	Set_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
#elif Voltage_Referace == AREF
	Clear_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
#elif Voltage_Referace == Internal
	Set_Bit(ADMUX, ADMUX_REFS0);
	Set_Bit(ADMUX, ADMUX_REFS1);
#else
		#warning (" Wrong Configuration !!")
#endif
	/* ACTIVE ADJUST */
#if ADC_Data_Mode == LOW
	Clear_Bit(ADMUX, ADMUX_ADLAR);
#elif ADC_Data_Mode == HIGH
	Set_Bit(ADMUX, ADMUX_ADLAR);
#else
		#warning (" Wrong Configuration !!")
#endif
	/*Trigger Mode*/
#if	ADC_Trigger_Mode == Free
	Clear_Bit(ADCSRA,ADCSRA_ADATE);
#elif ADC_Trigger_Mode == External_0
	Set_Bit(ADCSRA,ADCSRA_ADSC);
	//select channel
	ADMUX &= 0xE0;
	//configure exti
	EXTI_VidInitialization(Interrupt_0,Enable);
	//start conversion
	Set_Bit(ADCSRA,ADCSRA_ADATE);
	//enable interrupt
	Set_Bit(SREG,SREG_I);
	Set_Bit(ADCSRA,ADCSRA_ADIE);
	//Configure External_0 
	Clear_Bit(SFIOR,SFIOR_ADTS0);
	Set_Bit(SFIOR,SFIOR_ADTS1);
	Clear_Bit(SFIOR,SFIOR_ADTS2);
#endif
	/* SELECT PRESCALAR */
#if ADC_Prescaler == Prescaler_2
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_4
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_8
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_16
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_32
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_128
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#else
	#warning (" Wrong Configuration !! ")
#endif
	/*ENABLE*/
	Set_Bit(ADCSRA,ADCSRA_ADEN);
}
/*-------------------------------------------------------------------*/
/*-------------------------- Sync_Reading ---------------------------*/
/*-------------------------------------------------------------------*/
void (*__vector_16_Global)(u16)=NULL;
void ADC_VidSync_Reading (void(*Call_Back_Function)(u16))
{
	__vector_16_Global=Call_Back_Function;
}
void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	u16 Data=ADCH;
	if(__vector_16_Global)__vector_16_Global(Data);
}
/*-------------------------------------------------------------------*/
/*-------------------------- ASync Reading --------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidAsync_Reading (u8 Copy_u8Channel,u16 *Copy_u16Reading)
{
	ADMUX &= 0xE0;
	ADMUX = ADMUX | Copy_u8Channel;
	/* Start Conversion */
	Set_Bit(ADCSRA,ADCSRA_ADSC);
	/* Busy Wait Till Flag */	
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));
	/* Clear Flag */
	Set_Bit(ADCSRA,ADCSRA_ADIF);
	/*Store Reading Data*/
#if ADC_Data_Mode == LOW
	*Copy_u16Reading=ADCH;
#elif ADC_Data_Mode == HIGH
	*Copy_u16Reading=ADCH;
#else
		#warning (" Wrong Configuration !!")
#endif
}
/*-------------------------------------------------------------------*/
/*------------------------- Mapped Reading -------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u32Min,u32 Copy_u32Max,u16 *Copy_u16Reading)
{
	u16 Local_u16Value;
	ADC_VidAsync_Reading (Copy_u8Channel,&Local_u16Value);
	*Copy_u16Reading=((((Local_u16Value)*(Copy_u32Max-Copy_u32Min))/(255UL))+Copy_u32Min);
}
