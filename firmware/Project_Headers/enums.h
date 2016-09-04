#ifndef _ENUMS_H_
#define _ENUMS_H_

typedef enum {
	/**
	 * CMD_NOP
	 * Description: Do nothing.
	 * Parameters: none
	 */
   CMD_NOP  = 0,
   
   /**
    * CMD_IDLE, CMD_IDLE
    * Description: CMD_IDLE shuts down the PID controller, theBLDC Sequencer, 
    * and the H-bridge. Motors should move freely. Equivalent to a 
    * software E-stop. Motors will only run again once a CMD_RUN is sent.
    * Parameters: none
    */
   CMD_IDLE,
   CMD_RUN,
   /**
    * CMD_STATUSREQ
    * Description: When the status changes (motor starts/stops moving, etc),
    * a status report is sent to the host. This command manually requests
    * this report to be sent immediately.
    * Parameters: none
    */
   CMD_STATUSREQ, 

   /**
    * CMD_VELOCITY
    * Free-run the motor at the specified velocity
    * Parameter0 (bool): direction -- 0 for forward, 1 for reverse
    * Parameter1 (U16): speed, from 0 to 65,535
    */
   CMD_VELOCITY,
   
   /**
    * CMD_POSITION
    * Move to the specified position as quickly as possible.
    * Paramter0 (S32): Shaft position. Valid range is
    * -2,147,483,648 to 2,147,483,647
    */
   CMD_POSITION, 
   
   /**
    * CMD_HOME
    * Start a homing sequence.
    * Paramter0 (U8 Enum): Op code taking on the following values:
    * 	0: Just set the shaft counter to 0. 
    * 	1: Home using limit switch #1
    * 	2: Home using limit switch #2
    * 	3: Home using LS #1, and set workspace to LS #2
    * 	4: Home using LS #2, and set workspace to LS #1
    */
   CMD_HOME, 
} Commands;

typedef enum {
	STATE_IDLE = 0, // H bridge de-energized; motor free to move
	STATE_HOLDING,
	STATE_MOVING,
	STATE_HOMING
} State;

#endif
