#include "elev.h"
#include "driver.h"
#include "timer.h"
#include <stdbool.h>
#include "systemReport.h"
typedef enum{
	INIT,
	EMERGENCY,
	IDLE,
	MOVING,
	OPEN_DOORS,
}ElevatorState

//holds current elevator state 
ElevatorState elevatorState = INIT;

//functions responding to any possible button press
void fsm_init(void);
void fsm_entersFloor(int floor);
void fsm_stopButtonPressed(void);
void fsm_stopButtonReleased(void);
void fsm_requestButtonPressed(int floor, int buttonType);
void fsm_timerDone(void);