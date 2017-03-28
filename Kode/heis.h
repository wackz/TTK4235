#ifndef __INCLUDE_HEIS_H__
#define __INCLUDE_HEIS_H__

void mainElevatorLoop(void);

//update functions 
static void updateFloorSignals(void);
static void updateStopButton(void);
static void updateOrderButtons(void);
static void updateTimer(void);
static void updateLamps(void);

#endif