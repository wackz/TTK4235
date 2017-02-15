#include "timer.h"
#include "systemReport.h"

int main(void)
{
	printSystemMessage("main", "MAIN STARTED SUCCESSFULLY");
	while (true)
	{
		tmr_startTimer(3);
		while (!tmr_getTimerDone())
		{

		}
	}
	getchar();
}