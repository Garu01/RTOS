#include "fsm_smart_irrigation.h"

int status = 0;

void fsm_irrigation_init(){
	//Turn on the first Valve
	Valve1fertilizeON();
	status = VALVE1;
	setTimer(0, 500);
}

void fsm_irrigation_run(){
		switch(status){
				case VALVE1:
					//Turn on the first Valve
					Valve1fertilizeON();
					if(isTimerExpired(0) == 1){
						status = VALVE2;
						setTimer(0, 500);
						//Turn of the first Valve
						Valve1fertilizeOFF();
					}
					break;
				case VALVE2:
					//Turn on the second Valve
					Valve2fertilizeON();
					if(isTimerExpired(0) == 1){
						status = VALVE3;
						setTimer(0, 500);
						//Turn of the second Valve
						Valve2fertilizeOFF();
					}
					break;
				case VALVE3:
					//Turn on the third Valve
					Valve3fertilizeON();
					if(isTimerExpired(0) == 1){
						status = PUMP1;
						setTimer(0, 500);
						//Turn off the third Vale
						Valve3fertilizeOFF();
					}
					break;
				case PUMP1 :
					//Turn on the first pump
					Pump1ON();
					if(isTimerExpired(0) == 1){
						status = PUMP2;
						setTimer(0,300);
						//Turn off the first pump
						Pump1OFF();
					}
					break;
				case PUMP2 :
					//Turn on the second pump
					Pump2ON();
					if(isTimerExpired(0) == 1){
						status = IDLE;
						setTimer(0,300);
						//Turn off the second pump
						Pump2OFF();
					}
					break;
				case IDLE :
					if(isTimerExpired(0) == 1){
						status = VALVE1;
						setTimer(0,300);
					}
					break;
				default:
					break;
}
}
