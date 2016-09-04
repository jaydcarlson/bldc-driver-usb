/*
 * BLDC.h
 *
 *  Created on: Sep 21, 2013
 *      Author: Jay
 */

#ifndef BLDC_H_
#define BLDC_H_

#include "PE_Types.h"

/**************************
 * PUBLIC VARIABLES
 *************************/
// Read this value to get the current position. Set it
// to 0 (or whatever) to "home" the motor.
extern int32_t BLDC_CurrentPosition;
// Change this value to set the workspace of the motor
extern int32_t BLDC_MaxPosition;
// Set to true to prevent the motor from commuting outside
// of the workspace. This is performed at the sequencer,
// not control, stage of the software, which makes this
// exceptionally safe.
extern bool BLDC_EnforceLimits;
// Modifying these should change the motor immediately,
// but it never hurts to call BLDC_Update(). 
extern uint16_t BLDC_Speed;
extern bool BLDC_Direction; // 0 = Forward, 1 = Reverse
// If needed, you can get the last angle of the shaft
// (probably not very useful)
extern uint8_t BLDC_LastPosition;
// We can correct for 1 sensor skip at most, but not 2. Increment
// the error counter if this condition happens; it may signify a 
// major problem
extern uint32_t BLDC_HallErrorCount;
/**************************
 * PUBLIC METHODS
 *************************/
void BLDC_Init(void);
void BLDC_Update(void);
void BLDC_Idle(void);

#endif /* BLDC_H_ */
