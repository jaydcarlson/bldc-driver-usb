#ifndef _USB_H_
#define _USB_H_

#include "Common.h"

extern void initUSB(void);

extern void receiveUSBCommand( U8 size, U8 *buffer);
extern void sendUSBResponse( U8 size, const U8 *buffer);
void USB0_IRQHandler( void );
#endif  // _USB_H_
