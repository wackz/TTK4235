#include "elev.h"
#include "driver.h"
#include "timer.h"
#include <stdbool.h>

typedef enum{
	INIT,
	EMERGENCY,
	IDLE,
	MOVING,
	OPEN_DOORS,
}ElevatorState

ElevatorState elevatorState = INIT;


void fsm_entersFloor(int floor);
void fsm_leavesFloor(void);
void fsm_stopButtonReleased(void);
void fsm_requestButtonPressed(int floor, int buttonType);
void fsm_timerDone(void);