
#include <string.h>
#include "Common.h"
#include "enums.h"

//#include "ARM.h"
#include "USB.h"
#include "CmdProcessing.h"
#include "BLDC.h"
#include "PE_Types.h"
uint8_t pressed = 0;
bool runMotor = 0;

uint8_t statusBuffer[300];

void SendStatus(void);

void commandLoop(void) {
// Define to discard commands at random for command retry testing
//#define TESTDISCARD

   for(;;) {
//	   BLDC_Update();
      (void)receiveUSBCommand( 64, commandBuffer ); // this may take a *long* time...
      
      switch(commandBuffer[0])
      {
      case CMD_NOP: // do nothing
    	  break;
      case CMD_IDLE: // shut everything down
    	  BLDC_Idle(); // this disables the Hall interrupts and the H-bridge
    	  break;
      case CMD_RUN:
    	  BLDC_Init();
    	  break;
    	  
      case CMD_VELOCITY:
    	  if(commandBuffer[1] == 0 || commandBuffer[1]==1)
    	  {
    		  BLDC_Direction = commandBuffer[1];
    		  memcpy(&BLDC_Speed, &commandBuffer[2], sizeof(U16));
    	  }
    	  break;
      case CMD_STATUSREQ:
    	  SendStatus();
      }

   }
}

void SetStatus(U8 status)
{
	
}

void SendStatus(void)
{
	  commandBuffer[0] = 0x81;
	  memcpy(&commandBuffer[1], &BLDC_CurrentPosition, sizeof(int32_t));
	  sendUSBResponse( sizeof(int32_t)+1, commandBuffer );
	  pressed ^= 1;
}

