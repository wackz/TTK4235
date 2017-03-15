#include "timer.h"
#include "systemReport.h"


void tmr_startTimer(float duration)
{
	timerHasBeenRead = false;
	timerStarted = clock();  //syncs start time to system clock
	dur = duration; //stores intended timer duration
	printSystemMessage("tmr", "Timer module has been reset");
}


bool tmr_getTimerDone(void)
{
	float deltaTime = (float)(clock() - timerStarted) / CLOCKS_PER_SEC; //get time difference
	if (deltaTime >= dur)
	{
		printSystemMessage("tmr", "Timer module is done");
		return true;
	}
	return false;
}
