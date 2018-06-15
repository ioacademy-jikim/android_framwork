#ifndef ANDROID_LED_H
#define ANDROID_LED_H
#include "ILedClient.h"

namespace android {
	class Led : public BnLedClient
	{
		public : 
    		void dataCallback(int ratio);
	};
};

#endif
