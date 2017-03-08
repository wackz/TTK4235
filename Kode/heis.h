#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "systemReport.h"
#include "requestHandler.h"
#include "elev.h"

// struct som definerer heisens nåværende situasjon
typedef struct{
	Etasje currentFloor;
	Etasje targetFloor;
	bool direction; // 1 for opp - 0 for ned
	bool doorOpen; // 1 for åpen - 0 for lukket
	bool emergencyButton; //1 for trykket - 0 ellers
	bool obstruction; //1 for obstruksjon på - 0 ellers
} ElevatorState;

static ElevatorState elevatorState = {etg1, 0, 0, 0, 0}; //heisens overordnede tilstand

void mainElevatorLoop(void);