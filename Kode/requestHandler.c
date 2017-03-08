#include "requestHandler.h"
Etasje req_getPrioritizedRequest()
{
	if(elevatorState.direction){
		if(CheckAbove(elevatorState.currentFloor) == NONE)
			return CheckBelow(elevatorState.currentFloor);
		else return CheckAbove(elevatorState.currentFloor);
	}	
	else{
		if(CheckBelow(elevatorState.currentFloor) == NONE)
			return CheckAbove(elevatorState.currentFloor);
		else return CheckBelow(elevatorState.currentFloor);
	}	
}

void req_updateRequestList()
{
	
	//oppdater requests ved � sjekke alle knappene og oppdatere requestList deretter
	for(int i = 0; i <= 3; i++)
	{
		if(!queue_matrix[i][0]) //passer p� at knappen lyser etter at den har blitt aktivert
			queue_matrix[i][0] = elev_get_button_signal(BUTTON_COMMAND,i);
		//queue_matrix[i][1] = elev_get_button_signal(BUTTON_CALL_DOWN,i);
		//queue_matrix[i][2] = elev_get_button_signal(BUTTON_CALL_UP,i);	
		
	}
	
	//aktiverer lys - m� flyttes til heis.c
	for(int i = 0; i < 4; i++){
		elev_set_button_lamp(BUTTON_COMMAND,i,queue_matrix[i][0]);
	}


}

void req_init(ElevatorState* elev){
	elevatorState = elev;
}

void req_wipeRequests(){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 3; j++)
			queue_matrix[i][j] = 0;

Etasje CheckAbove(Etasje currentFloor){
	for(int i = currentFloor - 1; i < N_FLOORS; i++){
		if(i) return (Etasje)(i);
	}
	return NONE;
}

Etasje CheckBelow(Etasje currentFloor){
	for(int i = currentFloor - 1; i >= 0; i--){
		if(i) return (Etasje)(i);
	}
	return NONE;
}



