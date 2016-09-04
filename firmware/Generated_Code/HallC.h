/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : HallC.h
**     Project     : ProcessorExpert
**     Processor   : MK20DX128VLH5
**     Component   : ExtInt
**     Version     : Component 02.105, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-15, 00:20, # CodeGen: 20
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : INT_PORTA
**         User handling procedure     : HallC_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       29            |  PTA13/LLWU_P4/FTM1_CH1/I2S0_TX_FS/FTM1_QD_PHB
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 13
**         Bit mask of the port        : 0x2000
**
**         Signal edge/level           : both
**         Priority                    : 8
**         Pull option                 : off
**         Initial state               : Enabled
**
**
**         Port data register          : GPIOA_PDOR [0x400FF000]
**         Port control register       : GPIOA_PDDR [0x400FF014]
**     Contents    :
**         Enable  - void HallC_Enable(void);
**         Disable - void HallC_Disable(void);
**         GetVal  - bool HallC_GetVal(void);
**         SetEdge - byte HallC_SetEdge(byte edge);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file HallC.h
** @version 01.00
** @brief
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup HallC_module HallC module documentation
**  @{
*/         

#ifndef __HallC_H
#define __HallC_H

/* MODULE HallC. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "ExtIntLdd3.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  HallC_Enable (component ExtInt)
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HallC_Enable() (ExtIntLdd3_Enable(ExtIntLdd3_DeviceData))

/*
** ===================================================================
**     Method      :  HallC_Disable (component ExtInt)
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HallC_Disable() (ExtIntLdd3_Disable(ExtIntLdd3_DeviceData))

/*
** ===================================================================
**     Method      :  HallC_GetVal (component ExtInt)
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
#define HallC_GetVal() (ExtIntLdd3_GetVal(ExtIntLdd3_DeviceData))

/*
** ===================================================================
**     Method      :  HallC_SetEdge (component ExtInt)
**     Description :
**         Sets the edge type for this component that generates the
**         interrupt.
**     Parameters  :
**         NAME            - DESCRIPTION
**         edge            - Edge type:
**                           0 - falling edge
**                           1 - rising edge
**                           2 - both edges
**                           3 - low level
**                           4 - high level
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_RANGE - Value is out of range
** ===================================================================
*/
#define HallC_SetEdge(Edge) ((byte)ExtIntLdd3_SetEdge(ExtIntLdd3_DeviceData, (Edge)))

void ExtIntLdd3_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END HallC. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __HallC_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
