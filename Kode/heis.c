#include "heis.h"


void mainElevatorLoop(void){
	//initialisering skjer her!
	elev_set_motor_direction(DIRN_DOWN);
	while(elev_get_floor_sensor_signal() != 0)
	{
		//busy wait
	}
	elev_set_motor_direction(DIRN_STOP);
	elevatorState.doorOpen == true;

	
	//hovedprogramloop
	while (true)
	{
		//update all elevatorStates
		updateEmergencyStates();
		updateCurrentFloor();
		updateTargetFloor();
		updateTimerInProgress();
		
		//update elevator output
		updateElevatorOutput();

	}
}


//---------------------------------------------------
//update functions for state of elevator
//---------------------------------------------------

static void updateEmergencyStates(void){
		elevatorState.obstruction = (bool)elev_get_obstruction_signal();
		elevatorState.emergencyButton = (bool)elev_get_stop_signal();
}

static void updateCurrentFloor(void){
		if(elev_get_floor_sensor_signal() != -1){
			elevatorState.currentFloor = elev_get_floor_sensor_signal()
			elevatorState.isAtFloor = true;
		}
		else{
			elevatorState.isAtFloor = false;
		}
}

static void updateTargetFloor(void){
			elevatorState.targetFloor = req_getPrioritizedRequest();
			if(elevatorState.targetFloor == NONE){
				elevatorState.idle == true;
			}
			else{
				elevatorState.idle == false;
			}
}

//---------------------------------------------------
//update function for elevator output
//---------------------------------------------------

static void updateElevatorOutput(void){
	
	//close door if timer is done
	if(tmr_getTimerDone()){
		elevatorState.doorOpen = false;
		elev_set_door_open_lamp(0);
	}
	
	
	
	// handle emergency button press
	if(elevatorState.emergencyButton){
		elev_set_motor_direction(DIRN_STOP); 
		//åpne døra hvis heisen er ved en etasje
		if(isAtFloor == true){
			elevatorState.doorOpen = 1;
		}
		req_wipeRequests();
		elevatorState.targetFloor = NONE;
	}
	
	
	
	//handle obstruction
	else if(elevatorState.obstruction && isAtFloor){
		tmr_startTimer(3);
		elevatorState.doorOpen = 1;
		elev_set_motor_direction(DIRN_STOP); 
	}
	
	
	
	//handle open door
	else if(elevatorState.doorOpen && !elevatorState.idle){
		elev_set_door_open_lamp(1);
	} 
	
	
	//handle NONE request
	else if(elevatorState.idle){
		elevatorState.doorOpen = 1;
		elev_set_door_open_lamp(1);
		elev_set_motor_direction(DIRN_STOP);
	}
	
	
	//handle other request
	else if(!elevatorState.idle){
		elevatorState.doorOpen = 0;
		elev_set_door_open_lamp(0);
		if(elevatorState.targetFloor > elevatorState.currentFloor){
			elev_set_motor_direction(DIRN_UP);
		}
		else if(elevatorState.targetFloor < elevatorState.currentFloor){
			elev_set_motor_direction(DIRN_DOWN);
		}
	}
}