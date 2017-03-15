#include "heis.h"


void mainElevatorLoop(void){
	//initialisering skjer her!
	elev_set_motor_direction(DIRN_DOWN);	
	while(elev_get_floor_sensor_signal() != 0)
	{
		//busy wait
	}
	elev_set_motor_direction(DIRN_STOP);
	elevatorState.doorOpen = true;
	

	
	//hovedprogramloop
	while (true)
	{
		//update all elevatorStates
		updateStopButton(void);
		updateOrderButtons(void);
		updateTimer(void);
	}
}


//---------------------------------------------------
//update functions for state of elevator
//---------------------------------------------------

static void updateStopButton(void){
	static previousButtonState = false;
	
	if(previousButtonState && drv_getStopButton){
		//pressed stop button
		fsm_stopButtonPressed();
		previousButtonState = false;
	}
	if(!previousButtonState && !drv_getStopButton){
		//released stop button
		fsm_stopButtonReleased();
	}
}

static void updateOrderButtons(void){

}

static void updateTimer(void){

}

//---------------------------------------------------
//update function for elevator output
//---------------------------------------------------

//static void updateElevatorOutput(void){
	
	 
	 
	 /*
	//close door if timer is done
	if(tmr_getTimerDone()){
		elevatorState.doorOpen = false;
		tmr_stopTimer();
	}
	
	
	
	// handle emergency button press
	if(elevatorState.emergencyButton){
		printSystemMessage("heis", "emergency button pressed");
		elev_set_motor_direction(DIRN_STOP); 
		//åpne døra hvis heisen er ved en etasje
		if(elevatorState.isAtFloor == true){
			elevatorState.doorOpen = true;
		}
		req_wipeRequests();
		elevatorState.targetFloor = NONE;
	}
	
	
	
	//handle obstruction
	else if(elevatorState.obstruction && elevatorState.isAtFloor){
		printSystemMessage("heis", "door obstructed");
		tmr_startTimer(3);
		elevatorState.doorOpen = true;
		elev_set_motor_direction(DIRN_STOP); 
	}
	
	
	
	//handle arriving at target floor 
	else if(elevatorState.currentFloor == elevatorState.targetFloor && elevatorState.isAtFloor == true){
		printSystemMessage("heis", "elevator reached target floor");
		tmr_startTimer(3);
		elevatorState.doorOpen = true;
		elev_set_motor_direction(DIRN_STOP); 
	}
	
	
	
	//handle open door
	else if(elevatorState.doorOpen && !elevatorState.idle){
		printSystemMessage("heis", "elevator at floor - door open");
		elev_set_door_open_lamp(1);
	} 
	
	
	
	//handle NONE request
	else if(elevatorState.idle){
		printSystemMessage("heis", "elevator idle - waiting for new request");
		elevatorState.doorOpen = true;
		elev_set_door_open_lamp(1);
		elev_set_motor_direction(DIRN_STOP);
	}
	
	
	
	//handle other request
	else if(!elevatorState.idle){
		elevatorState.doorOpen = false;
		elev_set_door_open_lamp(0);
		if(elevatorState.targetFloor > elevatorState.currentFloor){
			elev_set_motor_direction(DIRN_UP);
			printSystemMessage("heis", "elevator active - moving up");
		}
		else if(elevatorState.targetFloor < elevatorState.currentFloor){
			elev_set_motor_direction(DIRN_DOWN);
			printSystemMessage("heis", "elevator active - moving down");
		}
	}
	*/
//}
