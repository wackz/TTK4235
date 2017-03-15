#include <stdio.h>
#include "timer.h"
#include <stdbool.h>
#include "systemReport.h"
#include "requestHandler.h"
#include "elev.h"

void mainElevatorLoop(void);

//update functions 
static void updateStopButton(void);
static void updateOrderButtons(void);
static void updateTimer(void);

typedef enum {
	IDLE, INIT, DOORS_OPEN, RUNNING, EMERGENCY
} ElevatorAction;


ElevatorAction elevatorAction = INIT;

