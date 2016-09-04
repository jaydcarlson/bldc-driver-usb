/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : HallB.h
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
**         User handling procedure     : HallB_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       28            |  PTA12/FTM1_CH0/I2S0_TXD0/FTM1_QD_PHA
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 12
**         Bit mask of the port        : 0x1000
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
**         Enable  - void HallB_Enable(void);
**         Disable - void HallB_Disable(void);
**         GetVal  - bool HallB_GetVal(void);
**         SetEdge - byte HallB_SetEdge(byte edge);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file HallB.h
** @version 01.00
** @brief
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup HallB_module HallB module documentation
**  @{
*/         

#ifndef __HallB_H
#define __HallB_H

/* MODULE HallB. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "ExtIntLdd2.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  HallB_Enable (component ExtInt)
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HallB_Enable() (ExtIntLdd2_Enable(ExtIntLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  HallB_Disable (component ExtInt)
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HallB_Disable() (ExtIntLdd2_Disable(ExtIntLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  HallB_GetVal (component ExtInt)
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
#define HallB_GetVal() (ExtIntLdd2_GetVal(ExtIntLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  HallB_SetEdge (component ExtInt)
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
#define HallB_SetEdge(Edge) ((byte)ExtIntLdd2_SetEdge(ExtIntLdd2_DeviceData, (Edge)))

void ExtIntLdd2_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END HallB. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __HallB_H */
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