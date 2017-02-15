#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "systemReport.h"

void tmr_startTimer(float duration); // starts the timer with a duration of (duration)
bool tmr_getTimerDone(void); //returns true if the timer is done and HAS NOT BEEN READ after the timer is done

static clock_t timerStarted; 
static float dur; //permanent storage of parameter "duration"
static bool timerHasBeenRead = false;