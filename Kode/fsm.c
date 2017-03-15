void fsm_stopButtonPressed(void){
	if (drv_isAtFloor())
	{
		tmr_startTimer();
		drv_setDoors(true);
	}
	else
	{
		
	}
	drv_setMotorDirection(DIRN_STOP);
	elevatorState = EMERGENCY;
}



void fsm_timerDone(void){
	
	switch(elevatorState){
		case EMERGENCY:
			elevatorState = IDLE;
			break;
		case OPEN_DOORS: 
			elevatorState = IDLE;
			drv_setDoors(false);
			break;
	}
}