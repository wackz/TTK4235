#ifndef REQHANDLER_H_
#define REQHANDLER_H_

#include <stdbool.h>
#include "elev.h"
#include "systemReport.h"

#define N_FLOORS 4
#define N_BUTTONS 3
typedef enum {ETG1, ETG2, ETG3, ETG4, NONE} Etasje;  //enum for å beskrive etasje
typedef enum {HEIS_1, HEIS_2, HEIS_3, HEIS_4, NED_4, NED_3, NED_2, OPP_3, OPP_2, OPP_1} Request;  //enum for å beskrive alle mulig requests (prioritet går etter rekkefølge L->R)

static bool requestList[10] = {false};  //liste som inneholder alle tilgjengelige requests

Etasje req_getPrioritizedRequest();//returnerer neste etasje heisen skal til

void req_updateRequestList(); //henter hvilke heisknapper som er trykket og oppdaterer requestList (kjøres hver programsyklus)
void req_wipeRequests(void);
Etasje CheckAbove(Etasje);
Etasje CheckBelow(Etasje);

static int queue_matrix[N_FLOORS][N_BUTTONS] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
};

// struct som definerer heisens nåværende situasjon
typedef struct{
	Etasje currentFloor;
	Etasje targetFloor;
	bool isAtFloor;
	bool direction; // 1 for opp - 0 for ned
	bool doorOpen; // 1 for åpen - 0 for lukket
	bool emergencyButton; //1 for trykket - 0 ellers
	bool obstruction; //1 for obstruksjon på - 0 ellers
	bool idle;
} ElevatorState;

ElevatorState elevatorState;

void req_init(void);
void req_refreshMatrix(void);
bool CheckFloorRequests(int);

#endif
