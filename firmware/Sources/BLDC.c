/*
 * BLDC.c
 *
 *  Created on: Sep 21, 2013
 *      Author: Jay
 */

#include "BLDC.h"
#include "U_EN.h"
#include "V_EN.h"
#include "W_EN.h"

#include "U_DIR.h"
#include "V_DIR.h"
#include "W_DIR.h"

#include "HallA.h"
#include "HallB.h"
#include "HallC.h"

int32_t BLDC_CurrentPosition = 0;
// Change this value to set the workspace of the motor
int32_t BLDC_MaxPosition = 0;
// Set to true to prevent the motor from commuting outside
// of the workspace. This is performed at the sequencer,
// not control, stage of the software, which makes this
// exceptionally safe.
bool BLDC_EnforceLimits = 0;
// Modifying these should change the motor immediately,
// but it never hurts to call BLDC_Update(). 
uint16_t BLDC_Speed = 0;
bool BLDC_Direction = 0; // 0 = Forward, 1 = Reverse
// If needed, you can get the last angle of the shaft
// (probably not very useful)
uint8_t BLDC_LastPosition = 0;
// We can correct for 1 sensor skip at most, but not 2. Increment
// the error counter if this condition happens; it may signify a 
// major problem
uint32_t BLDC_HallErrorCount = 0;

uint8_t SequenceTable[] = {
		0, // 0b000
		3, // 0b001
		5, // 0b010
		4, // 0b011
		1, // 0b100
		2, // 0b101
		6, // 0b110
		0, // 0b111
};

void UpdatePosition(uint8_t val);

void BLDC_Init(void)
{
	HallA_Enable();
	HallB_Enable();
	HallC_Enable();
	
	U_EN_SetRatio16(1);
	V_EN_SetRatio16(1);
	W_EN_SetRatio16(1);
	
	U_DIR_PutVal(1);
	V_DIR_PutVal(1);
	W_DIR_PutVal(1);
}

/**
 * This can be called periodically, or on Hall sensor interrupts
 */
void BLDC_Update(void)
{
	uint8_t val = (HallC_GetVal()<<2) | (HallB_GetVal()<<1) | HallA_GetVal();
	UpdatePosition(val);
	if(BLDC_Direction == 1) // Clockwise
	{
		switch(val)
		{
		case 0b100:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(1);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(1);
			W_DIR_PutVal(0);
			break;
		
		case 0b101:
			U_EN_SetRatio16(1);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(1);
			W_DIR_PutVal(0);
			break;
			
		case 0b001:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(1);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(1);
			V_DIR_PutVal(0);
			W_DIR_PutVal(0);
			break;
			
		case 0b011:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(1);
			
			U_DIR_PutVal(1);
			V_DIR_PutVal(0);
			W_DIR_PutVal(0);
			break;
			
		case 0b010:
			U_EN_SetRatio16(1);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(0);
			W_DIR_PutVal(1);
			break;
			
		case 0b110:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(1);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(0);
			W_DIR_PutVal(1);
			break;
		}
	} else {
		switch(val)
		{
		case 0b100:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(1);
			
			U_DIR_PutVal(1);
			V_DIR_PutVal(0);
			W_DIR_PutVal(0);
			break;
		
		case 0b110:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(1);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(1);
			V_DIR_PutVal(0);
			W_DIR_PutVal(0);
			break;
			
		case 0b010:
			U_EN_SetRatio16(1);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(1);
			W_DIR_PutVal(0);
			break;
			
		case 0b011:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(1);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(1);
			W_DIR_PutVal(0);
			break;
			
		case 0b001:
			U_EN_SetRatio16(BLDC_Speed);
			V_EN_SetRatio16(0);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(0);
			W_DIR_PutVal(1);
			break;
			
		case 0b101:
			U_EN_SetRatio16(1);
			V_EN_SetRatio16(BLDC_Speed);
			W_EN_SetRatio16(BLDC_Speed);
			
			U_DIR_PutVal(0);
			V_DIR_PutVal(0);
			W_DIR_PutVal(1);
			break;
		}
	}
	BLDC_LastPosition = val;
}

void BLDC_Idle(void)
{
	HallA_Disable();
	HallB_Disable();
	HallC_Disable();
	
	U_EN_SetRatio16(1);
	V_EN_SetRatio16(1);
	W_EN_SetRatio16(1);
	U_DIR_PutVal(0);
	V_DIR_PutVal(0);
	W_DIR_PutVal(0);
}

// We could just look at the direction and naïvely increment/decrement the 
// counter whenever we get a new sensor reading, but since we're running
// absolute control off this, we really need it to be more robust to loads
// back-driving the shaft (which will make it move opposite of its current
// direction), as well as Hall sensor skips.
void UpdatePosition(uint8_t val)
{
	uint8_t cur = SequenceTable[val];
	uint8_t last = SequenceTable[BLDC_LastPosition];
	
		 if(last == 1 && cur == 2)
		BLDC_CurrentPosition++;
	else if(last == 1 && cur == 3)
		BLDC_CurrentPosition += 2;
	else if(last == 1 && cur == 4)
		BLDC_HallErrorCount++;
	else if(last == 1 && cur == 5)
		BLDC_CurrentPosition -= 2;
	else if(last == 1 && cur == 6)
		BLDC_CurrentPosition-- ;
	
	else if (last == 2 && cur == 1)
		BLDC_CurrentPosition-- ;
	else if (last == 2 && cur == 3)
		BLDC_CurrentPosition++ ;
	else if(last == 2 && cur == 4)
		BLDC_CurrentPosition += 2;
	else if(last == 2 && cur == 5)
		BLDC_HallErrorCount++;
	else if(last == 2 && cur == 6)
		BLDC_CurrentPosition += 2;
	
	else if(last == 3 && cur == 1)
		BLDC_CurrentPosition -= 2;
	else if(last == 3 && cur == 2)
		BLDC_CurrentPosition-- ;
	else if(last == 3 && cur == 4)
		BLDC_CurrentPosition++ ;
	else if(last == 3 && cur == 5)
		BLDC_CurrentPosition += 2;
	else if(last == 3 && cur == 6)
		BLDC_HallErrorCount++;
	
	else if(last == 4 && cur == 1)
		BLDC_HallErrorCount++;
	else if(last == 4 && cur == 2)
		BLDC_CurrentPosition -= 2;
	else if(last == 4 && cur == 3)
		BLDC_CurrentPosition-- ;
	else if(last == 4 && cur == 5)
		BLDC_CurrentPosition++;
	else if(last == 4 && cur == 6)
		BLDC_CurrentPosition += 2;
	
	else if (last == 5 && cur == 1)
		BLDC_CurrentPosition += 2;
	else if (last == 5 && cur == 2)
		BLDC_HallErrorCount++;
	else if(last == 5 && cur == 3)
		BLDC_CurrentPosition -= 2;
	else if(last == 5 && cur == 4)
		BLDC_CurrentPosition--;
	else if(last == 5 && cur == 6)
		BLDC_CurrentPosition++;
	
	else if(last == 6 && cur == 1)
		BLDC_CurrentPosition++;
	else if(last == 6 && cur == 2)
		BLDC_CurrentPosition += 2;
	else if(last == 6 && cur == 3) 
		BLDC_HallErrorCount++;
	else if(last == 6 && cur == 4)
		BLDC_CurrentPosition -= 2;
	else if(last == 6 && cur == 5)
		BLDC_CurrentPosition--;
	
	else // We got some wacky sensor reading
		BLDC_HallErrorCount++;	
}
