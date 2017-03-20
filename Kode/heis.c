#include "heis.h"


void mainElevatorLoop(void){
	//initialisering skjer her!
	elev_set_motor_direction(DIRN_DOWN);	
	while(elev_get_floor_sensor_signal() != 0)
	{
		//busy wait
	}
	elev_set_motor_direction(DIRN_STOP);
	

	
	//hovedprogramloop
	while (true)
	{
		//update all elevatorStates
		updateFloorSignals();
		updateStopButton();
		updateOrderButtons();
		updateTimer();
	}
	
	return 0;
}


//---------------------------------------------------
//update functions for state of elevator
//---------------------------------------------------

static void updateStopButton(void){
	static previousButtonState = false;
	
	if(!previousButtonState && drv_getStopButton()){
		//pressed stop button
		fsm_stopButtonPressed();
		previousButtonState = true;
	}
	if(previousButtonState && !drv_getStopButton()){
		//released stop button
		previousButtonState = false;
	}
}

static void updateOrderButtons(void){
	static int buttonStates[N_BUTTONS][N_FLOORS] = {{0}};
	
	for (int i = 0; i < N_BUTTONS; i++)
    {
        for (int j = 0; j < N_FLOORS; j++)
        {
			//needs exception handling for floor 1 and floor 4
			//elev api calls needs to be moved to driver
			//need to change fsm_OrderBtnClicked to fsm_requestButtonPressed
			if (buttonStates[i][j]==0 && elev_get_button_signal(i,j))
            {
                buttonStates[i][j]=true;
                fsm_OrderBtnClicked(i,j);
            }
            else if (buttonStates[i][j]==1 && !elev_get_button_signal(i,j))
                buttonStates[i][j]=false;
			
}

static void updateTimer(void){

}

static void updateFloorSignals(void){
	static bool previousFloorStates = {0,0,0,0};
	
	for(int i = 0; i < N_FLOORS; i++){
		if(previousFloorState[i] && drv_getCurrentFloor()==i){
			fsm_entersFloor();
			previousButtonState[i] = false;
		}
	}
	
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
