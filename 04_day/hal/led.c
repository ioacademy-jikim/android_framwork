#include <stdio.h>

typedef struct module
{
	void (*on)();
	void (*off)();
} module_t;

void ledOn()
{
	printf("ledOn()\n");
}

void ledOff()
{
	printf("ledOff()\n");
}

module_t  HMI = { ledOn, ledOff };
