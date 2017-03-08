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
		
		//update emergency states
		elevatorState.obstruction = (bool)elev_get_obstruction_signal();
		elevatorState.emergencyButton = (bool)elev_get_stop_signal();
		
		//update currentFloor
		if(elev_get_floor_sensor_signal() != -1){
			elevatorState.currentFloor = elev_get_floor_sensor_signal()
		}
	}
}
