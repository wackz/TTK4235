#include "heis.h"


void mainElevatorLoop(void){
	elev_set_motor_direction(DIRN_UP);

	while (true)
	{
		if (elev_get_floor_sensor_signal() == 3)
		{
			elev_set_motor_direction(DIRN_DOWN);
		}
		if (elev_get_floor_sensor_signal() == 0)
		{
			elev_set_motor_direction(DIRN_UP);
		}
	}
}
