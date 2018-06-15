#define LOG_TAG "LedClient"

#include "ILedClient.h"

#include <binder/IPCThreadState.h>
#include <binder/Parcel.h>
#include <unistd.h>

namespace android {

// ----------------------------------------------------------------------

class BpLedClient : public BpInterface<ILedClient>
{
public:
    explicit BpLedClient(const sp<IBinder>& impl)
        : BpInterface<ILedClient>(impl)
    {
    }

    virtual void dataCallback(int ratio)
    {
		printf("BpLedClient::dataCallback()\n");
        Parcel data, reply;
		data.writeInt32(ratio);
        remote()->transact(DATA_CALLBACK, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(LedClient, "android.os.ILedClient");

// ----------------------------------------------------------------------

status_t BnLedClient::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	switch (code) {
		case DATA_CALLBACK: {
					     int temp;
						 temp = data.readInt32();
						 dataCallback(temp);
						 return NO_ERROR;
					 } break;
		default:
					 return BBinder::onTransact(code, data, reply, flags);
	}
}
// ----------------------------------------------------------------------
}; // namespace android
