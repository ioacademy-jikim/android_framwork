#include "LedService.h"
#include <stdio.h> 

namespace android 
{
	void LedService::connect(sp<ILedClient>& client)
	{
		printf("LedService::ledOn()\n");
		client->dataCallback(222);
	}
};
