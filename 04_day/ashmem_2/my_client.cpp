
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
	sp<IMemory> base = interface_cast<IMemory>( binder );
	ssize_t offset=0; 
	size_t size=0;
	sp<IMemoryHeap> heap = base->getMemory(&offset, &size);
	char *p = (char*)heap->getBase();
	printf("%s\n", p+offset );

	return 0;
}



