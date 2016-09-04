/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM_B.h
**     Project     : ProcessorExpert
**     Processor   : MK20DX128VLH5
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-15, 00:20, # CodeGen: 20
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       62            |  ADC0_SE6b/PTD5/SPI0_PCS2/UART0_CTS_b/UART0_COL_b/FTM0_CH5/EWM_OUT_b
**             ----------------------------------------------------
**
**         Timer name                  : FTM0_CNT [16-bit]
**         Counter                     : FTM0_CNT  [0x40038004]
**         Mode register               : FTM0_SC   [0x40038000]
**         Run register                : FTM0_SC   [0x40038000]
**         Prescaler                   : FTM0_SC   [0x40038000]
**         Compare register            : FTM0_C5V  [0x40038038]
**         Flip-flop register          : FTM0_C5SC [0x40038034]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTD
**         Bit number (in port)        : 5
**         Bit mask of the port        : 0x0020
**         Port data register          : GPIOD_PDOR [0x400FF0C0]
**         Port control register       : GPIOD_PDDR [0x400FF0D4]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-[driven by slave component]
**             Clock                   : [driven by slave component] Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : ---        ---
**             microseconds            : 3          3
**             milliseconds            : ---        ---
**             seconds                 : ---        ---
**             seconds (real)          : 3          3
**
**     Contents    :
**         SetRatio16 - byte PWM_B_SetRatio16(word Ratio);
**         SetDutyUS  - byte PWM_B_SetDutyUS(word Time);
**         SetDutyMS  - byte PWM_B_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PWM_B.h
** @version 01.01
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup PWM_B_module PWM_B module documentation
**  @{
*/         

#ifndef __PWM_B_H
#define __PWM_B_H

/* MODULE PWM_B. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd2.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define PWM_B_PERIOD_VALUE PwmLdd2_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define PWM_B_PERIOD_VALUE_HIGH PwmLdd2_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  PWM_B_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define PWM_B_SetRatio16(Ratio) (PwmLdd2_SetRatio16(PwmLdd2_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  PWM_B_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 3 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define PWM_B_SetDutyUS(Time) (PwmLdd2_SetDutyUS(PwmLdd2_DeviceData, Time))

/*
** ===================================================================
**     Method      :  PWM_B_SetDutyMS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to --- ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define PWM_B_SetDutyMS(Time) (PwmLdd2_SetDutyMS(PwmLdd2_DeviceData, Time))

/* END PWM_B. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PWM_B_H */
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
