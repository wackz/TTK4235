#include "elev.h"
#include "driver.h"
#include <stdbool.h>
#include <stdio.h>
#include "systemReport.h"
//------------------------
//target functions
//------------------------
static int targetFloor = 0;
static int previousFloor = 0;
static int IsAtFloor = true;
static int motorDirection = DIRN_UP;
static int previousMotorDirection = DIRN_UP;
static int floorMatrix[N_FLOORS][N_BUTTONS] = {{0}};



void drv_setFloorMatrix(int floor, int buttonType, int value)
{
	floorMatrix[floor][buttonType] = value;
}

void drv_wipeFloorMatrix(void)
{
	for(int i = 0; i < N_FLOORS; i++)
		for(int j = 0; j < N_BUTTONS; j++)
			floorMatrix[i][j] = 0;
}


int drv_passingFloorWithRequest(int direction, int floor)
{
	if (floorMatrix[floor][BUTTON_COMMAND])
	{
		return floorMatrix[floor][BUTTON_COMMAND];
	}
	if(direction == DIRN_UP)
	{	
		return floorMatrix[floor][BUTTON_CALL_UP];
	}
	if(direction == DIRN_DOWN)
	{
		return floorMatrix[floor][BUTTON_CALL_DOWN];
	}
	return false;
}





int drv_isAtTargetFloor(void)
{
	if(drv_getCurrentFloor() == targetFloor){
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

	if(motorDirection)
		previousMotorDirection = motorDirection;
}

void drv_setDoorLamp(int value)
{
	elev_set_door_open_lamp(value);
}

void drv_setStopLamp(int value)
{
	elev_set_stop_lamp(value);
}

void drv_setPreviousFloor()
{
	previousFloor = elev_get_floor_sensor_signal();
}

void drv_setTargetFloor(int floor)
{
	targetFloor = floor;
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

void drv_updateFloorIndicator(void){
	elev_set_floor_indicator(previousFloor);
}

void drv_printFloorMatrix(void)
{
	for(int i = 0; i < N_FLOORS; i++){
		for(int j = 0; j < N_BUTTONS; j++){
			printf("%d",floorMatrix[i][j]);
		}
		printf("\n");
	}
	
}


//------------------------
//get functions
//------------------------

int drv_getIsAtFloor(void)
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

int drv_getDirection(void)
{
	return motorDirection;
}

int drv_getPreviousDirection(void)
{
	return previousMotorDirection;
}

int drv_getTargetFloor(void)
{
	return targetFloor;
}

int drv_getPreviousFloor(void)
{
	return previousFloor;
}

int drv_getCurrentFloor(void){
	return elev_get_floor_sensor_signal();
}

//------------------------
//priority handling code
//------------------------
int drv_dirToTargetFloor(void)
{
	if(targetFloor - previousFloor > 0)
		return 1;
	else if (targetFloor - previousFloor < 0)
		return -1;
	else return 0;
}

void drv_updateTargetFloor(void)
{
	switch(drv_getPreviousDirection()){
		case DIRN_UP:
			for(int i = N_FLOORS-1; i>drv_getPreviousFloor(); i--)
			{
				if(floorMatrix[i][0] || floorMatrix[i][1] || floorMatrix[i][2]){
					targetFloor = i;
					break;	
				}
			}
			for(int i = 0; i < drv_getPreviousFloor(); i++)
			{
				if(floorMatrix[i][0] || floorMatrix[i][1] || floorMatrix[i][2]){
					targetFloor = i;
					break;	
				}
			}
			break;
		case DIRN_DOWN:
			for(int i = 0; i < drv_getPreviousFloor(); i++)
			{
				if(floorMatrix[i][0] || floorMatrix[i][1] || floorMatrix[i][2]){
					targetFloor = i;
					break;	
				}
			}
			for(int i = N_FLOORS-1; i>drv_getPreviousFloor(); i--)
			{
				if(floorMatrix[i][0] || floorMatrix[i][1] || floorMatrix[i][2]){
					targetFloor = i;
					break;	
				}
			}
			
			break;
		default: break;
	}
	printSystemMessage("drv","Target floor set to ",targetFloor);
}