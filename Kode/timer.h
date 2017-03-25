#ifndef __INCLUDE_TIMER_H__
#define __INCLUDE_TIMER_H__

#include <time.h>

void tmr_startTimer(long double duration); // starts the timer with a duration of (duration)
int tmr_getTimerDone(void); //returns true if the timer is done and HAS NOT BEEN READ after the timer is done

#endif