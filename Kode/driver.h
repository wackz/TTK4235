//static values

//#ifndef __INCLUDE_DRV_H__
//#define __INCLUDE_DRV_H__


#define N_FLOORS 4
#define N_BUTTONS 3


//target functions
void drv_setFloorMatrix(int floor, int buttonType, int value);
void drv_wipeFloorMatrix(void);
int drv_passingFloorWithRequest(int direction, int floor);
int drv_isAtTargetFloor(void);
void drv_printFloorMatrix(void);


//set functions
void drv_setMotorDirection(int direction);
void drv_setDoorLamp(int value);
void drv_setStopLamp(int value);
void drv_setPreviousFloor(void);
void drv_setTargetFloor(int floor);
void drv_updateFloorLampsFromMatrix(void);
void drv_updateFloorIndicator(void);

//get functions
int drv_getIsAtFloor(void);
int drv_getStopButton(void);
int drv_getDirection(void);
int drv_getTargetFloor(void);
int drv_getCurrentFloor(void);
int drv_getPreviousFloor(void);
int drv_getPreviousDirection(void);

//priority handling code!!
void drv_updateTargetFloor(void);
int drv_dirToTargetFloor(void);
//#endif