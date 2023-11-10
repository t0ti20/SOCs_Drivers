/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  XMC1100_AB.h
 *  Module:  Library/MCU
 *  Description:  Headder File For MCU "Infineon XMC1100"
*******************************************************************/
#ifndef _XMC1100_AB_H_
#define _XMC1100_AB_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Std_Types.h"
#include "Bit_Banging.h"
/*****************************************
------    Memory Base Addresses    -------
*****************************************/
#define SYSTEM_PERIPHERALS_BASE                   (0x40000000UL)                      
/*****************************************
-----   Pheriphal Offset Addresses   -----
*****************************************/
#define PORT0_OFFSET                              (0x40000UL)
/*High current bidirectional pad*/
#define PORT1_OFFSET                              (0X40100UL)
/*Analog/Digital inputand bi-directional pad*/
#define PORT2_OFFSET                              (0X40200UL)
/*****************************************
------   Pheriphal Base Addresses   ------
*****************************************/
/*GPIO Port 0 Base Address*/
#define PORT0_BASE                                (PORT0_OFFSET+SYSTEM_PERIPHERALS_BASE)
/*GPIO Port 1 Base Address*/
#define PORT1_BASE                                (PORT1_OFFSET+SYSTEM_PERIPHERALS_BASE)
/*GPIO Port 2 Base Address*/
#define PORT2_BASE                                (PORT2_OFFSET+SYSTEM_PERIPHERALS_BASE)
/****************************************
----------   Generic Macros    ----------
*****************************************/
/*------------- BitField -------------*/
typedef struct Bits_t
{
     volatile uint32 Bit_0:ONE;volatile uint32 Bit_1:ONE;
     volatile uint32 Bit_2:ONE;volatile uint32 Bit_3:ONE;
     volatile uint32 Bit_4:ONE;volatile uint32 Bit_5:ONE;
     volatile uint32 Bit_6:ONE;volatile uint32 Bit_7:ONE;
     volatile uint32 Bit_8:ONE;volatile uint32 Bit_9:ONE;
     volatile uint32 Bit_10:ONE;volatile uint32 Bit_11:ONE;
     volatile uint32 Bit_12:ONE;volatile uint32 Bit_13:ONE;
     volatile uint32 Bit_14:ONE;volatile uint32 Bit_15:ONE;
     volatile uint32 Bit_16:ONE;volatile uint32 Bit_17:ONE;
     volatile uint32 Bit_18:ONE;volatile uint32 Bit_19:ONE;
     volatile uint32 Bit_20:ONE;volatile uint32 Bit_21:ONE;
     volatile uint32 Bit_22:ONE;volatile uint32 Bit_23:ONE;
     volatile uint32 Bit_24:ONE;volatile uint32 Bit_25:ONE;
     volatile uint32 Bit_26:ONE;volatile uint32 Bit_27:ONE;
     volatile uint32 Bit_28:ONE;volatile uint32 Bit_29:ONE;
     volatile uint32 Bit_30:ONE;volatile uint32 Bit_31:ONE;
}Bits_t;
typedef union Register_t
{
     volatile uint32 Register;
     volatile Bits_t Bits;
}Register_t;
/*---------------- PORT ----------------*/
typedef struct PORTX_t
{
     /*Port n Output Register*/
     Register_t Pn_OUT;                                /*0x00*/
     /*Port n Output Modification Register*/
     Register_t Pn_OMR;                                /*0x04*/
     /*Reserved Register*/
     Register_t RESERVED_0[2];                         /*0x08->0x0C*/
     /*Port n Input/Output Control Register 0->12*/
     Register_t Pn_IOCRX[4];                           /*0x10->0x1C*/                          
     /*Reserved Register*/
     Register_t RESERVED_1;                            /*0x20*/
     /*Port n Input Register*/
     Register_t Pn_IN;                                 /*0x24*/
     /*Reserved Register*/
     Register_t RESERVED_2[6];                         /*0x28->0x3c*/
     /*Port n Pad Hysteresis Control Register 0->1*/
     Register_t Pn_PHCRX[2];                           /*0x40->0x44*/
     /*Reserved Register*/
     Register_t RESERVED_3[6];                         /*0x48->0x5C*/
     /*P0-P1(non-ADC ports)*//*P2(ADC ports)*/
     Register_t Pn_PDISC;                              /*0x60*/
     /*Reserved Register*/
     Register_t RESERVED_4[3];                         /*0x64->0x6C*/
     /*Port n Pin Power Save Register*/
     Register_t Pn_PPS;                                /*0x70*/
     /*Port n Hardware Select Register*/
     Register_t Pn_HWSEL;                              /*0x74*/
}PORTX_t;
/****************************************
--------   Pheripheral Instants  ---------
*****************************************/
/*GPIO Port 0 Module Address*/
#define PORT0                                     (((PORTX_t*)(PORT0_BASE)))
/*GPIO Port 1 Module Address*/
#define PORT1                                     (((PORTX_t*)(PORT1_BASE)))
/*GPIO Port 2 Module Address*/
#define PORT2                                     (((PORTX_t*)(PORT2_BASE)))
/********************************************************************
 *  END OF FILE: XMC1100_AB.h
********************************************************************/
#endif
