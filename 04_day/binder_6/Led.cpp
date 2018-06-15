#include "Led.h"
#include <stdio.h> 

namespace android 
{
	void Led::dataCallback(int ratio)
	{
		printf("Led::dataCallback(%d)\n", ratio);
	}
};
