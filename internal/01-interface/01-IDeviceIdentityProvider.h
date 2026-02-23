/**
 * @file 01-IDeviceIdentityProvider.h
 * @brief Interface for device identity (serial number, device details).
 */

#ifndef DEVICE_IDENTITY_IDEVICE_IDENTITY_PROVIDER_H
#define DEVICE_IDENTITY_IDEVICE_IDENTITY_PROVIDER_H

#include <StandardDefines.h>

DefineStandardPointers(IDeviceIdentityProvider)

class IDeviceIdentityProvider {
    Public Virtual ~IDeviceIdentityProvider() = default;

    /** Returns the device serial number (e.g. from MAC or configured value). */
    Public Virtual StdString GetSerialNumber() const = 0;
};

#endif // DEVICE_IDENTITY_IDEVICE_IDENTITY_PROVIDER_H
