/* ###################################################################
**     Filename    : Events.h
**     Project     : ProcessorExpert
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-21, 14:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT0 - void Cpu_OnNMIINT0(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "TU1.h"
#include "PWM_B.h"
#include "PwmLdd1.h"
#include "PwmLdd3.h"
#include "RESET_A.h"
#include "BitIoLdd1.h"
#include "RESET_B.h"
#include "BitIoLdd2.h"
#include "RESET_C.h"
#include "BitIoLdd3.h"
#include "HallA.h"
#include "ExtIntLdd1.h"
#include "HallB.h"
#include "ExtIntLdd2.h"
#include "HallC.h"
#include "ExtIntLdd3.h"
#include "OTW.h"
#include "BitIoLdd4.h"
#include "FAULT.h"
#include "BitIoLdd5.h"
#include "M1.h"
#include "BitIoLdd6.h"
#include "M2.h"
#include "BitIoLdd7.h"
#include "M3.h"
#include "BitIoLdd8.h"
#include "POT1.h"
#include "AdcLdd1.h"
#include "PWM_A.h"
#include "PwmLdd2.h"
#include "PWM_C.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT0 (module Events)
**
**     Component   :  Cpu [MK20DX128EX5]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT0(void);


void HallC_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  HallC_OnInterrupt (module Events)
**
**     Component   :  HallC [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void HallB_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  HallB_OnInterrupt (module Events)
**
**     Component   :  HallB [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void HallA_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  HallA_OnInterrupt (module Events)
**
**     Component   :  HallA [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void POT1_OnEnd(void);
/*
** ===================================================================
**     Event       :  POT1_OnEnd (module Events)
**
**     Component   :  POT1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void POT1_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  POT1_OnCalibrationEnd (module Events)
**
**     Component   :  POT1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.07]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
