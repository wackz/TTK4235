#include <stdio.h>
#include "timer.h"
#include <stdbool.h>
#include "systemReport.h"
#include "requestHandler.h"
#include "elev.h"


void mainElevatorLoop(void);

//update functions 
static void updateEmergencyStates(void);
static void updateCurrentFloor(void);
static void updateTargetFloor(void);
static void updateElevatorOutput(void);

