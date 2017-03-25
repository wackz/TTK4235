#include "timer.h"
#include "systemReport.h"
#include <stdbool.h>
#include <stdio.h>

static clock_t timerStarted; 
static bool timerInit = false;
static long double dur; //permanent storage of parameter "duration"

void tmr_startTimer(long double duration)
{
	timerStarted = clock();  //syncs start time to system clock
	dur = duration; //stores intended timer duration
	printSystemMessage("tmr", "Timer module has been started",-1);
	timerInit = true;
}


int tmr_getTimerDone(void)
{
	long double deltaTime = (long double)(clock() - timerStarted) / (CLOCKS_PER_SEC); //get time difference
	if (deltaTime >= dur && timerInit)
	{
		//printSystemMessage("tmr", "Timer module is done",-1);
		return true;
	}
	return false;
}

