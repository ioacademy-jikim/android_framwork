
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>
#include <binder/MemoryHeapBase.h>
#include <binder/MemoryBase.h>
#include <string.h>

using namespace android;

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm(defaultServiceManager());
	sp<IMemoryHeap> heap = new MemoryHeapBase(4096);
	sp<IMemory> base = new MemoryBase( heap, 1024*3, 1024);
	sm->addService( String16("ashmem.service"), base->asBinder(base) );
	char *p;
	p = (char*)heap->base();
	strcpy( p + 3*1024, "Hello Android!!");
	IPCThreadState::self()->joinThreadPool();

	return 0;
}



