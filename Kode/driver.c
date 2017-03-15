//------------------------
//target functions
//------------------------
void drv_setFloorMatrix(int floor, tag_elev_lamp_type buttonType)
{
	floorMatrix[floor][buttonType] = 1;
}

void drv_wipeFloorMatrix(void)
{
	floorMatrix = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
	}
}


bool drv_passingFloorWithRequest(elev_motor_direction_t direction, int floor)
{
	if(direction == DIRN_UP)
	{
		return (bool)floorMatrix[floor][BUTTON_CALL_UP];
	}
	if(direction == DIRN_DOWN)
	{
		return (bool)floorMatrix[floor][BUTTON_CALL_DOWN];
	}
}

/*
int drv_getTargetFloor(void)
{
	
}
*/

bool drv_isAtTargetFloor(void)
{
	if(currentFloor == targetFloor){
		return true;
	}
	return false;
}





//------------------------
//set functions
//------------------------
void drv_setMotorDirection(elev_motor_direction_t direction)
{
	elev_set_motor_direction(direction);
}

void drv_doorLamp(bool doorOpen)
{
	void elev_set_door_open_lamp((int)doorOpen);
}

void drv_setStopLamp(bool lampOn)
{
	void elev_set_stop_lamp((bool)lampOn);
}

void drv_setCurrentFloor()
{
	currentFloor = elev_get_floor_sensor_signal();
}

void drv_updateFloorLampsFromMatrix(void)
{
	for(int i = 0; i < 4; i++){
		elev_set_button_lamp(BUTTON_COMMAND, i, int floorMatrix[i][BUTTON_COMMAND]);
	}
	for(int i = 1; i < 4; i++){
		elev_set_button_lamp(BUTTON_CALL_DOWN, i, int floorMatrix[i][BUTTON_CALL_DOWN]);
	}
	for(int i = 0; i < 3; i++){
		elev_set_button_lamp(BUTTON_CALL_UP, i, int floorMatrix[i][BUTTON_CALL_UP]);
	}
}


//------------------------
//get functions
//------------------------

bool drv_GetIsAtFloor(void)
{
	int floor = elev_get_floor_sensor_signal(void);
	if(floor != -1)
	{
		return true;
	}
	return false
}

bool drv_getStopButton(void)
{
	if((bool)elev_get_stop_signal(void))
	{
		return true;
	}
	return false
}

bool drv_getObstruction(void)
{
	return (bool)elev_get_obstruction_signal(void);
}

elev_motor_direction_t drv_getDirecction(void)
{
	return motorDirection;
}



//------------------------
//priority handling code
//------------------------
elev_motor_direction_t drv_dirToTargetFloor(void)
{
	//check down-buttons
	for(int i = 3; i == 0; i--)
	{
		if(floorMatrix[i][BUTTON_CALL_DOWN] == 1)
		{
			return i;
		}
	}
	//check up-buttons
	for(int i = 0; i < 3; i++)
	{
		if(floorMatrix[i][BUTTON_CALL_UP] == 1)
		{
			return i;
		}
	}
	//checks command buttons
	for(int i = 0; i < 4; i++)
	{
		if(floorMatrix[i][BUTTON_COMMAND] == 1)
		{
			targetFloor = i
		}
	}

	//sets direction
	if(targetFloor > currentFloor)
	{
		return DIRN_UP;
	}
	else if(targetFloor < currentFloor)
	{
		return DIRN_DOWN;
	}
	return DIRN_STOP;
}