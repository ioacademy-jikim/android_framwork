
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include <binder/IMemory.h>
#include <utils/String16.h>

using namespace android;

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm(defaultServiceManager());
	sp<IBinder> binder = sm->getService( String16("ashmem.service") );
	sp<IMemoryHeap> ashmem = interface_cast<IMemoryHeap>( binder );
	char *p = (char*)ashmem->getBase();
	printf("%s\n", p );

	return 0;
}



