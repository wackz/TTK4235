//#ifndef __INCLUDE_FSM_H__
//#define __INCLUDE_FSM_H__

typedef enum{
	INIT,
	EMERGENCY,
	IDLE,
	MOVING,
	OPEN_DOORS,
}ElevatorState;

//holds current elevator state 


//functions responding to any possible button press
void fsm_init(void);
void fsm_entersFloor(int floor);
void fsm_stopButtonPressed(void);
void fsm_stopButtonReleased(void);
void fsm_requestButtonPressed(int buttonType,int floor);
void fsm_timerDone(void);

//#endif