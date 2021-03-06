#ifndef ANDROID_ILED_SERVICE_H
#define ANDROID_ILED_SERVICE_H

#include <binder/IInterface.h>
#include <utils/String16.h>

namespace android {

// ----------------------------------------------------------------------

class ILedService : public IInterface
{
public:
    DECLARE_META_INTERFACE(LedService)

    virtual void   ledOn() = 0;

    enum {
        LED_ON = IBinder::FIRST_CALL_TRANSACTION
    };
};

}; // namespace android

#endif // ANDROID_ISERVICE_MANAGER_H

