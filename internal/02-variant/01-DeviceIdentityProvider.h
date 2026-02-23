/**
 * @file 01-DeviceIdentityProvider.h
 * @brief Default device identity provider (placeholder implementation).
 */

#ifndef DEVICE_IDENTITY_DEVICE_IDENTITY_PROVIDER_H
#define DEVICE_IDENTITY_DEVICE_IDENTITY_PROVIDER_H

#include "../01-interface/01-IDeviceIdentityProvider.h"
#include <StandardDefines.h>

/* @Component */
class DeviceIdentityProvider final : public IDeviceIdentityProvider {

    Public DeviceIdentityProvider() = default;

    Public ~DeviceIdentityProvider() override = default;

    Public StdString GetSerialNumber() const override {
        return StdString("");
    }
};

#endif // DEVICE_IDENTITY_DEVICE_IDENTITY_PROVIDER_H
