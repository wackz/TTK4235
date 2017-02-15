#include "systemReport.h"

void printSystemMessage(char *moduleName, char *message)
{
	time_t rawTime;
	rawTime = time(NULL);
	struct tm* timeInfo;

	timeInfo = localtime(&rawTime);
	printf("%c%d%c%d%c%d%01c",'[' ,timeInfo->tm_hour,':',timeInfo->tm_min,':', timeInfo->tm_sec, ']' );
	fflush(stdout);
	printf("%s%s%s%s%c", "[", moduleName, "] -> ", message, '\n');
}