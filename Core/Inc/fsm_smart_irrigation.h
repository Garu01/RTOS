
#ifndef INC_FSM_SMART_IRRIGATION_H_
#define INC_FSM_SMART_IRRIGATION_H_
#include "software_timer.h"

#define INIT        0
#define VALVE1 		1
#define VALVE2 		2
#define VALVE3      3
#define PUMP1       4
#define PUMP2       5
#define IDLE 	    6


void fsm_irrigation_init();
void fsm_irrigation_run();


#endif /* INC_FSM_SMART_IRRIGATION_H_ */
