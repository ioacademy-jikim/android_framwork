
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>

using namespace android;

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm(defaultServiceManager());
	sp<IBinder> binder = sm->getService( String16("led.service") );
	Parcel data, reply;
	binder->transact(1, data, &reply);

	return 0;
}



