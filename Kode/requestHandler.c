#include "requestHandler.h"



void req_init(void){
	elevatorState = (ElevatorState){ETG1, NONE, 1, 1, 1, 0, 0, 1}; //heisens overordnede tilstand
}

Etasje req_getPrioritizedRequest()
{
	req_refreshMatrix();
	req_updateRequestList();
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

void req_updateRequestList(void)
{
	
	//oppdater requests ved å sjekke alle knappene og oppdatere requestList deretter
	for(int i = 0; i <= 3; i++)
	{
		if(!queue_matrix[i][0]) //passer på at knappen lyser etter at den har blitt aktivert
			queue_matrix[i][0] = elev_get_button_signal(BUTTON_COMMAND,i);
		if(!queue_matrix[i][1] && i!=0) //passer på at knappen lyser etter at den har blitt aktivert
			queue_matrix[i][1] = elev_get_button_signal(BUTTON_CALL_DOWN,i);
		if(!queue_matrix[i][2] && i!=3) //passer på at knappen lyser etter at den har blitt aktivert
			queue_matrix[i][2] = elev_get_button_signal(BUTTON_CALL_UP,i);	
		
	}
	
	//aktiverer lys - må flyttes til heis.c
	for(int i = 0; i < 4; i++){
		elev_set_button_lamp(BUTTON_COMMAND,i,queue_matrix[i][0]);
	}


}

void req_wipeRequests(void){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 3; j++)
			queue_matrix[i][j] = 0;
}
Etasje CheckAbove(Etasje currentFloor){
	for(int i = currentFloor - 1; i < N_FLOORS; i++){
		if(CheckFloorRequests(i))return (Etasje)(i);
	}
	return NONE;
}

Etasje CheckBelow(Etasje currentFloor){
	for(int i = currentFloor - 1; i >= 0; i--){
		if(CheckFloorRequests(i)) return (Etasje)(i);
	}
	return NONE;
}

bool CheckFloorRequests(int floor){
	for(int i = 0; i<3; i++){
		if(queue_matrix[floor][i])
			return true;
	}
	return false;
}
void req_refreshMatrix(){

	queue_matrix[elevatorState.currentFloor][0] = 0;
	for(int i = 0; i < 4; i++){
		elev_set_button_lamp(BUTTON_COMMAND,i,queue_matrix[i][0]);
	}

}




