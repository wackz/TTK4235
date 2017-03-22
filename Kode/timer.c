#include "timer.h"
#include "systemReport.h"
#include <stdbool.h>


void tmr_startTimer(float duration)
{
	timerEnabled = true;
	timerStarted = clock();  //syncs start time to system clock
	dur = duration; //stores intended timer duration
	printSystemMessage("tmr", "Timer module has been reset",-1);
}


int tmr_getTimerDone(void)
{
	float deltaTime = (float)(clock() - timerStarted) / CLOCKS_PER_SEC; //get time difference
	if (deltaTime >= dur && timerEnabled)
	{
		printSystemMessage("tmr", "Timer module is done",-1);
		return true;
	}
	return false;
}

void tmr_stopTimer(void){
	timerEnabled = false;
}
