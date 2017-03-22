#ifndef __INCLUDE_TIMER_H__
#define __INCLUDE_TIMER_H__

#include <time.h>

void tmr_startTimer(float duration); // starts the timer with a duration of (duration)
int tmr_getTimerDone(void); //returns true if the timer is done and HAS NOT BEEN READ after the timer is done
void tmr_stopTimer(void); //stops timer

static clock_t timerStarted; 
static float dur; //permanent storage of parameter "duration"
static int timerEnabled;


#endif