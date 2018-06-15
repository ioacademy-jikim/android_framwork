#include <dlfcn.h>

typedef struct module
{
	void (*on)();
	void (*off)();
} module_t;

int main()
{
    void *handle;
	module_t *module;
	handle = dlopen("libled.so", RTLD_NOW);
	module = dlsym( handle, "HMI" );
	module->on();
	module->off();
	dlclose(handle);
	return 0;
}
