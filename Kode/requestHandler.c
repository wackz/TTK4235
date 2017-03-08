#include "requestHandler.h"
#include "elev.h"
#include "systemReport.h"

Etasje req_getPrioritizedRequest()
{

	// finn requesten med høyest prioritet (L->R)
	int i;
	for(i = 0 ; i < 10; i++)
	{
		if(requestList[i] == true)
		{
			break;
		}
	}
	
	
	//match request med riktig etasje og returner
	if(i == 10){
		return NONE;
	}
	Request currentRequest = (Request)i;
	requestList[i] = false;
	
	if(currentRequest == HEIS_1 || currentRequest == OPP_1){
		printSystemMessage("req", "request for ETG1 handed to heis.c");
		return ETG1;
	}
	else if(currentRequest == HEIS_2 || currentRequest == OPP_2 || currentRequest == NED_2){
		printSystemMessage("req", "request for ETG2 handed to heis.c");
		return ETG2;
	}
	else if(currentRequest == HEIS_3 || currentRequest == OPP_3 || currentRequest == NED_3){
		printSystemMessage("req", "request for ETG3 handed to heis.c");
		return ETG3;
	}
	else 
	{
		printSystemMessage("req", "request for ETG4 handed to heis.c");
		return ETG4;
	}
}



void req_updateRequestList()
{
	
	//oppdater requests ved å sjekke alle knappene og oppdatere requestList deretter
	int i;
	for(i = 0; i < 4; i++)
	{
		requestList[i] = elev_get_button_signal(BUTTON_COMMAND, int i);
	}
	for(i = 4; i < 7; i++)
	{
		requestList[i] = elev_get_button_signal(BUTTON_CALL_DOWN, int i);
	}
	for(i = 7; i < 10; i++)
	{
		requestList[i] = elev_get_button_signal(BUTTON_CALL_UP, int i);
	}
}