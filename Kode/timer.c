#include "timer.h"
#include "systemReport.h"
#include <stdbool.h>


static clock_t timerStarted; 
static float dur; //permanent storage of parameter "duration"

void tmr_startTimer(float duration)
{
	timerStarted = clock();  //syncs start time to system clock
	dur = duration; //stores intended timer duration
	printSystemMessage("tmr", "Timer module has been reset",-1);
}


int tmr_getTimerDone(void)
{
	float deltaTime = (float)(clock() - timerStarted) / CLOCKS_PER_SEC; //get time difference
	if (deltaTime >= dur)
	{
		printSystemMessage("tmr", "Timer module is done",-1);
		return true;
	}
	return false;
}

