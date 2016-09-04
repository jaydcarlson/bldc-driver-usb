/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ExtIntLdd3.h
**     Project     : ProcessorExpert
**     Processor   : MK20DX128VLH5
**     Component   : ExtInt_LDD
**     Version     : Component 02.156, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-15, 00:20, # CodeGen: 20
**     Abstract    :
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**          Component name                                 : ExtIntLdd3
**          Pin                                            : PTA13/LLWU_P4/FTM1_CH1/I2S0_TX_FS/FTM1_QD_PHB
**          Pin signal                                     : 
**          Generate interrupt on                          : both edges
**          Interrupt                                      : INT_PORTA
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**          Threshold level                                : 0
**     Contents    :
**         Init    - LDD_TDeviceData* ExtIntLdd3_Init(LDD_TUserData *UserDataPtr);
**         Enable  - void ExtIntLdd3_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - void ExtIntLdd3_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetVal  - bool ExtIntLdd3_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         SetEdge - LDD_TError ExtIntLdd3_SetEdge(LDD_TDeviceData *DeviceDataPtr, uint8_t Edge);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file ExtIntLdd3.h
** @version 01.02
** @brief
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup ExtIntLdd3_module ExtIntLdd3 module documentation
**  @{
*/         

#ifndef __ExtIntLdd3_H
#define __ExtIntLdd3_H

/* MODULE ExtIntLdd3. */

#include "Cpu.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "GPIO_PDD.h"
#include "PORT_PDD.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define ExtIntLdd3_PRPH_BASE_ADDRESS  0x400FF000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define ExtIntLdd3_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_ExtIntLdd3_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define ExtIntLdd3_Init_METHOD_ENABLED /*!< Init method of the component ExtIntLdd3 is enabled (generated) */
#define ExtIntLdd3_Enable_METHOD_ENABLED /*!< Enable method of the component ExtIntLdd3 is enabled (generated) */
#define ExtIntLdd3_Disable_METHOD_ENABLED /*!< Disable method of the component ExtIntLdd3 is enabled (generated) */
#define ExtIntLdd3_GetVal_METHOD_ENABLED /*!< GetVal method of the component ExtIntLdd3 is enabled (generated) */
#define ExtIntLdd3_SetEdge_METHOD_ENABLED /*!< SetEdge method of the component ExtIntLdd3 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define ExtIntLdd3_OnInterrupt_EVENT_ENABLED /*!< OnInterrupt event of the component ExtIntLdd3 is enabled (generated) */

/* Definition of implementation constants */
#define ExtIntLdd3_PIN_INDEX 0x0DU     /*!< Index of the used pin from the port */
#define ExtIntLdd3_PIN_MASK 0x2000U    /*!< Mask of the used pin from the port */

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Init (component ExtInt_LDD)
*/
/*!
**     @brief
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     @param
**         UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* ExtIntLdd3_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Enable (component ExtInt_LDD)
*/
/*!
**     @brief
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void ExtIntLdd3_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Disable (component ExtInt_LDD)
*/
/*!
**     @brief
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void ExtIntLdd3_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
void ExtIntLdd3_Interrupt(void);

/*
** ===================================================================
**     Method      :  ExtIntLdd3_GetVal (component ExtInt_LDD)
*/
/*!
**     @brief
**         Returns the actual value of the input pin of the component.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
*/
/* ===================================================================*/
bool ExtIntLdd3_GetVal(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  ExtIntLdd3_SetEdge (component ExtInt_LDD)
*/
/*!
**     @brief
**         Sets the edge type for this component that generates the
**         interrupt.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Edge            - Edge type:
**                           0 - falling edge
**                           1 - rising edge
**                           2 - both edges
**                           3 - low level
**                           4 - high level
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_RANGE - Value is out of range
*/
/* ===================================================================*/
LDD_TError ExtIntLdd3_SetEdge(LDD_TDeviceData *DeviceDataPtr, uint8_t Edge);

/* END ExtIntLdd3. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __ExtIntLdd3_H */
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
