//static values

//#ifndef __INCLUDE_DRV_H__
//#define __INCLUDE_DRV_H__

#include "elev.h"
#define N_FLOORS 4
#define N_BUTTONS 3

int targetFloor;
int currentFloor;
int IsAtFloor;
int motorDirection;

int floorMatrix[N_FLOORS][N_BUTTONS] = {{0}};


//target functions
void drv_setFloorMatrix(int floor, int buttonType, int value);
void drv_wipeFloorMatrix(void);
int drv_passingFloorWithRequest(int direction, int floor);
int drv_isAtTargetFloor(void);


//set functions
void drv_setMotorDirection(int direction);
void drv_setDoorLamp(int value);
void drv_setStopLamp(int value);
void drv_setCurrentFloor(void);
void drv_updateFloorLampsFromMatrix(void);


//get functions
int drv_getIsAtFloor(void);
int drv_getStopButton(void);
int  drv_getDirection(void);
int drv_getTargetFloor(void);
int drv_getCurrentFloor(void);


//priority handling code!!
int drv_dirToTargetFloor(void);
//#endif