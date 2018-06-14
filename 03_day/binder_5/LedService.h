#ifndef ANDROID_LED_SERVICE_H
#define ANDROID_LED_SERVICE_H
#include "ILedService.h"

namespace android {
	class LedService : public BnLedService
	{
		public : 
			void ledOn(void);
	};
};

#endif
