/**
 * @file 01-DeviceIdentityThread.h
 * @brief IRunnable for device identity (placeholder; call Run() from main loop if needed).
 */

#ifndef DEVICE_IDENTITY_DEVICE_IDENTITY_THREAD_H
#define DEVICE_IDENTITY_DEVICE_IDENTITY_THREAD_H

#include <IRunnable.h>
#include "../01-interface/01-IDeviceIdentityProvider.h"

class DeviceIdentityThread final : public IRunnable {

    /* @Autowired */
    Private IDeviceIdentityProviderPtr deviceIdentityProvider;

    Public Void Run() override {
        (void)deviceIdentityProvider;
    }
};

#endif // DEVICE_IDENTITY_DEVICE_IDENTITY_THREAD_H
