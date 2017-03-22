#include "elev.h"
#include "driver.h"
#include <stdbool.h>
//------------------------
//target functions
//------------------------
static int targetFloor;
static int currentFloor;
static int IsAtFloor;
static int motorDirection;
static int floorMatrix[N_FLOORS][N_BUTTONS] = {{0}};



void drv_setFloorMatrix(int floor, int buttonType, int value)
{
	floorMatrix[floor][buttonType] = value;
}

void drv_wipeFloorMatrix(void)
{
	for(int i = 0; i < N_FLOORS; i++)
		for(int j = 0; j < N_BUTTONS; i++)
			floorMatrix[i][j] = 0;
}


int drv_passingFloorWithRequest(int direction, int floor)
{
	if(direction == DIRN_UP)
	{
		return floorMatrix[floor][BUTTON_CALL_UP];
	}
	if(direction == DIRN_DOWN)
	{
		return floorMatrix[floor][BUTTON_CALL_DOWN];
	}
}

/*
int drv_getTargetFloor(void)
{
	
}
*/

int drv_isAtTargetFloor(void)
{
	if(currentFloor == targetFloor){
		return true;
	}
	return false;
}





//------------------------
//set functions
//------------------------
void drv_setMotorDirection(int direction)
{
	elev_set_motor_direction(direction);
	motorDirection = direction;
}

void drv_doorLamp(int value)
{
	elev_set_door_open_lamp(value);
}

void drv_setStopLamp(int value)
{
	elev_set_stop_lamp(value);
}

void drv_setCurrentFloor()
{
	currentFloor = elev_get_floor_sensor_signal();
}

void drv_updateFloorLampsFromMatrix(void)
{
	for(int i = 0; i < 4; i++){
		elev_set_button_lamp(BUTTON_COMMAND, i, floorMatrix[i][BUTTON_COMMAND]);
	}
	for(int i = 1; i < 4; i++){
		elev_set_button_lamp(BUTTON_CALL_DOWN, i,floorMatrix[i][BUTTON_CALL_DOWN]);
	}
	for(int i = 0; i < 3; i++){
		elev_set_button_lamp(BUTTON_CALL_UP, i, floorMatrix[i][BUTTON_CALL_UP]);
	}
}


//------------------------
//get functions
//------------------------

int drv_GetIsAtFloor(void)
{
	int floor = elev_get_floor_sensor_signal();
	if(floor != -1)
	{
		return true;
	}
	return false;
}

int drv_getStopButton(void)
{
	return elev_get_stop_signal();
}

int drv_getDirecction(void)
{
	return motorDirection;
}



//------------------------
//priority handling code
//------------------------
int drv_dirToTargetFloor(void)
{
	//prioritetskode!!!
}