/*! \file
    \brief Main command procedure for executing BDM commands received over the USB.
*/    
#ifndef _CMDPROCESSING_H_
#define _CMDPROCESSING_H_

#include "Common.h"

extern void commandLoop(void);
void SetStatus(U8 status);
extern U8  commandBuffer[]; // Buffer for USB command in, result out

#endif
