#include "elev.h"
#include "driver.h"
#include "systemReport.h"
#include "fsm.h"
#include <stdbool.h>
#include "timer.h"

#define TIMER_SEC 3

static ElevatorState elevatorState;

void fsm_init(void)
{
	printSystemMessage("fsm-init", "initializing", -1);
	elevatorState = INIT;
	drv_setMotorDirection(DIRN_DOWN);

	while(drv_getCurrentFloor() != 0){}

	drv_setMotorDirection(DIRN_STOP);
	elevatorState = IDLE;
	printSystemMessage("fsm-init", "initializing - DONE", -1);
}


void fsm_stopButtonPressed(void)
{
	printSystemMessage("fsm", "EMERGENCY STOP - matrix reset", -1);

	switch(elevatorState){
		case INIT:
			break;
		case EMERGENCY:
			break;
		default:
			elevatorState = EMERGENCY;

			if (drv_getIsAtFloor()){
				printSystemMessage("STOP", "SETTING DOOR LAMP", -1);
				drv_setDoorLamp(true);
			}
			printSystemMessage("STOP", "SETTING MOTOR DIRECTION", -1);
			drv_setMotorDirection(DIRN_STOP);
			printSystemMessage("STOP", "WIPING FLOOR MATRIX", -1);
			drv_wipeFloorMatrix();
			printSystemMessage("STOP", "UPDATING FLOOR LAMPS", -1);
			drv_updateFloorLampsFromMatrix();
			printSystemMessage("STOP", "SETTING STOP LAMP", -1);
			drv_setStopLamp(true);
			break;

	}
}



void fsm_stopButtonReleased(void)
{
	drv_setMotorDirection(DIRN_STOP);
	elevatorState = IDLE;
	drv_setStopLamp(false);
	printSystemMessage("fsm", "EMERGENCY RELEASED - returning to idle", -1);
	drv_updateTargetFloor();
}



void fsm_timerDone(void)
{
	switch(elevatorState){
		case EMERGENCY:
			printSystemMessage("fsm", "timer complete after EMERGENCY", -1);
			break;
		case OPEN_DOORS:
			if(drv_isAtTargetFloor()){
				elevatorState=IDLE;
				drv_setDoorLamp(false);
				drv_setMotorDirection(DIRN_STOP);
			}
			else{
				elevatorState=MOVING;
				drv_setDoorLamp(false);
				drv_setMotorDirection(drv_dirToTargetFloor());
				printSystemMessage("fsm", "timer complete after doors have been open", -1);
			} 
			break;
		case IDLE:
			if(!drv_isAtTargetFloor()){
				elevatorState = MOVING;
				drv_setMotorDirection(drv_dirToTargetFloor());
				drv_setDoorLamp(false);
				printSystemMessage("fsm", "timer complete after idle period", -1);
			}
			break;
		case MOVING:
			break;
		default: break;
	}
	//drv_updateFloorLampsFromMatrix();
}




void fsm_entersFloor(int floor){
	printSystemMessage("fsm", "entering floor", floor);
	drv_setPreviousFloor();

	if(drv_isAtTargetFloor())
	{
		elevatorState = OPEN_DOORS;
		drv_setMotorDirection(DIRN_STOP);
		printSystemMessage("fsm", "reached target floor - going to idle", floor);
		tmr_startTimer(TIMER_SEC);
		drv_setFloorMatrix(floor,BUTTON_CALL_UP,0);
		drv_setFloorMatrix(floor,BUTTON_CALL_DOWN,0);
		drv_setFloorMatrix(floor,BUTTON_COMMAND,0);
		drv_updateTargetFloor();

	}
	else if(drv_passingFloorWithRequest(drv_getDirection(),floor))
	{
		printSystemMessage("fsm", "stopping to pick up passenger", floor);
		tmr_startTimer((long double)TIMER_SEC);
		
		elevatorState = OPEN_DOORS;
		drv_setDoorLamp(true);
		if(drv_getDirection() == DIRN_UP)
		{
			drv_setFloorMatrix(floor, BUTTON_CALL_UP, false);
			drv_setFloorMatrix(floor, BUTTON_COMMAND, false);
		}
		else if(drv_getDirection() == DIRN_DOWN)
		{
			drv_setFloorMatrix(floor, BUTTON_CALL_DOWN, false);
			drv_setFloorMatrix(floor, BUTTON_COMMAND, false);
		}

		drv_setMotorDirection(DIRN_STOP);
	}
	//drv_updateFloorLampsFromMatrix();


	switch(elevatorState){
		case INIT:
			break;
		case EMERGENCY:
			break;
		case OPEN_DOORS:
			break;
		case IDLE:
			break;
		case MOVING:
			break;
		default: break;
	}
}




void fsm_requestButtonPressed(int buttonType,int floor)
{
	if(elevatorState == EMERGENCY)
	{
		printSystemMessage("fsm", "EMERGENCY - request at floor denied", floor);
		return;
	}
	printSystemMessage("fsm", "request acquired at floor:", floor);
	drv_setFloorMatrix(floor, buttonType, true);
	
	
	

	switch(elevatorState){
		case IDLE: 
			printSystemMessage("fsm","idle",-1);
			if(floor==drv_getCurrentFloor()){
				printSystemMessage("fsm","Already at floor with request. Opening door",-1);
				elevatorState = OPEN_DOORS;
				drv_setDoorLamp(true);
				tmr_startTimer(TIMER_SEC);
				drv_setFloorMatrix(floor,buttonType,false);
			}
			else {
				drv_updateTargetFloor();
				elevatorState = MOVING;
				drv_setDoorLamp(false);
				drv_setMotorDirection(drv_dirToTargetFloor());
			}

			break;
		case OPEN_DOORS:
			printSystemMessage("fsm","open doors",-1);
			if(floor==drv_getCurrentFloor())
			{
				tmr_startTimer(TIMER_SEC);
				drv_setDoorLamp(true);
				drv_setFloorMatrix(floor,buttonType,false);
			}
			drv_updateTargetFloor();
			break; 
		case MOVING:
			break;
		default: 
			printSystemMessage("fsm","default case",-1);
			break;
	}
	//drv_updateFloorLampsFromMatrix();
	

}
