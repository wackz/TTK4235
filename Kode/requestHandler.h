#include <stdbool.h>

typedef enum {ETG1, ETG2, ETG3, ETG4, NONE} Etasje;  //enum for � beskrive etasje
typedef enum {HEIS_1, HEIS_2, HEIS_3, HEIS_4, NED_4, NED_3, NED_2, OPP_3, OPP_2, OPP_1} Request;  //enum for � beskrive alle mulig requests (prioritet g�r etter rekkef�lge L->R)

static bool requestList[10] = {false};  //liste som inneholder alle tilgjengelige requests

Etasje req_getPrioritizedRequest();//returnerer neste etasje heisen skal til

void req_updateRequestList(); //henter hvilke heisknapper som er trykket og oppdaterer requestList (kj�res hver programsyklus)
