/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-21, 14:42, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "derivative.h" /* include peripheral declarations */
#include "USB.h"
#include "Clock.h"
#include "CmdProcessing.h"

#include "BLDC.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void initPorts(void) {
   // Enable all port clocks
   SIM_SCGC5 |=   SIM_SCGC5_PORTA_MASK
                | SIM_SCGC5_PORTB_MASK
                | SIM_SCGC5_PORTC_MASK
                | SIM_SCGC5_PORTD_MASK
                | SIM_SCGC5_PORTE_MASK;
//   ledInit();
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  initClock();
//   initPorts();

   initUSB();
//   initTimers();
   BLDC_Init();
   BLDC_Update(); // update the motor to the first position to trigger the interrupts.
   commandLoop();
  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
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
