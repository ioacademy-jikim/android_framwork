#define LOG_TAG "LedService"

#include "ILedService.h"

#include <binder/IPCThreadState.h>
#include <binder/Parcel.h>
#include <unistd.h>

namespace android {

// ----------------------------------------------------------------------

class BpLedService : public BpInterface<ILedService>
{
public:
    explicit BpLedService(const sp<IBinder>& impl)
        : BpInterface<ILedService>(impl)
    {
    }

    virtual void ledOn(void)
    {
		printf("BpLedService::ledOn()\n");
        Parcel data, reply;
        remote()->transact(LED_ON, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(LedService, "android.os.ILedService");

}; // namespace android
