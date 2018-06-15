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

    virtual void connect(sp<ILedClient>& client)
    {
		printf("BpLedService::ledOn()\n");
        Parcel data, reply;
		data.writeStrongBinder(ILedClient::asBinder(client));
        remote()->transact(CONNECT, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(LedService, "android.os.ILedService");

// ----------------------------------------------------------------------

status_t BnLedService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	switch (code) {
		case CONNECT: {
						 sp<ILedClient> client; 
						 data.readStrongBinder(&client);
						 connect(client);
						 return NO_ERROR;
					 } break;
		default:
					 return BBinder::onTransact(code, data, reply, flags);
	}
}
// ----------------------------------------------------------------------
}; // namespace android
