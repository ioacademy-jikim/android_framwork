
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>

using namespace android;

class LedService : public BBinder
{
	public:
		status_t onTransact(
				uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
		{
			switch (code) {
				case 1:
					printf("LedService::LED_ON\n");
					return NO_ERROR;

				default:
					return BBinder::onTransact(code, data, reply, flags);
			}
		}
};

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm(defaultServiceManager());
	sm->addService( String16("led.service"), new LedService );
	IPCThreadState::self()->joinThreadPool();

	return 0;
}



