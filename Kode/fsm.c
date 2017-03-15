
void fsm_stopButtonPressed(void)
{
	if (drv_isAtFloor())
	{
		drv_setDoors(true);
	}
	drv_setMotorDirection(DIRN_STOP);
	elevatorState = EMERGENCY;
	drv_wipeFloorMatrix(void);
	drv_updateFloorLampsFromMatrix(void);
	printSystemMessage("fsm", "EMERGENCY STOP - matrix reset", -1);
}



void fsm_timerDone(void)
{
	switch(elevatorState){
		case EMERGENCY:
			elevatorState = IDLE;
			printSystemMessage("fsm", "timer complete after EMERGENCY", -1);
			break;
		case OPEN_DOORS:
			if(!drv_getObstruction())
			{
				elevatorState = MOVING;
				drv_setDoors(false);
				drv_setMotorDirection(drv_dirToTargetFloor());
				printSystemMessage("fsm", "timer complete after doors have been open", -1);
				break;
			}
			tmr_startTimer();
			printSystemMessage("fsm", "door obstructed", -1);
			break;
		case IDLE: 
			elevatorState = MOVING;
			drv_setDoors(false);
			drv_setMotorDirection(drv_dirToTargetFloor());
			printSystemMessage("fsm", "timer complete after idle period", -1);
			break;
	}
}



void fsm_entersFloor(int floor){
	printSystemMessage("fsm", "entering floor", floor);
	drv_setCurrentFloor();
	if(drv_isAtTargetFloor())
	{
		if(drv_dirToTargetFloor() == DIRN_STOP)
		{
			elevatorState = IDLE;
			drv_setMotorDirection(DIRN_STOP);
			drv_setDoors(true);
			printSystemMessage("fsm", "reached target floor - going to idle", floor);
		}
	}
	else if(drv_passingFloorWithRequest(floor))
	{
		printSystemMessage("fsm", "stopping to pick up passenger", floor);
		tmr_startTimer();
		drv_setMotorDirection(DIRN_STOP);
		elevatorState = DOOR_OPEN;
		drv_setDoors(true);
		if(drv_getDirection() == DIRN_UP)
		{
			drv_setFloorMatrix(floor, BUTTON_CALL_UP, false);
		}
		else if(drv_getDirection() == DIRN_DOWN)
		{
			drv_setFloorMatrix(floor, BUTTON_CALL_DOWN, false);
		}
	}
	drv_updateFloorLampsFromMatrix(void);
}



void fsm_requestButtonPressed(int floor, int buttonType)
{
	printSystemMessage("fsm", "request acquired at floor:", floor);
	drv_setFloorMatrix(floor, buttonType, true);
	drv_updateFloorLampsFromMatrix(void);
	
	switch(elevatorState){
		case EMERGENCY:
			elevatorState = MOVING;
			drv_setDoors(false);
			drv_setMotorDirection(drv_dirToTargetFloor());
			break;
		case IDLE: 
			elevatorState = MOVING;
			drv_setDoors(false);
			drv_setMotorDirection(drv_dirToTargetFloor());
			break;
	}
}