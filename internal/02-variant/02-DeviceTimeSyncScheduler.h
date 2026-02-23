/**
 * @file 02-DeviceTimeSyncScheduler.h
 * @brief Triggers IDeviceTime::SyncTimeFromNetwork() after checks (interval, internet).
 */

#ifndef DEVICE_IDENTITY_DEVICE_TIME_SYNC_SCHEDULER_H
#define DEVICE_IDENTITY_DEVICE_TIME_SYNC_SCHEDULER_H

#include <IInternetConnectionStatusProvider.h>
#include <StandardDefines.h>
#include <Arduino.h>
#include <ILogger.h>

#include "../01-interface/01-IDeviceTime.h"
#include "../01-interface/02-IDeviceTimeSyncScheduler.h"

/* @Component */
class DeviceTimeSyncScheduler final : public IDeviceTimeSyncScheduler {

    /* @Autowired */
    Private IDeviceTimePtr deviceTime;
    /* @Autowired */
    Private IInternetConnectionStatusProviderPtr internetStatusProvider;
    /* @Autowired */
    Private ILoggerPtr logger;

    Private ULong lastSyncMs_{0};

    Public Bool TrySync() override {
        if (!internetStatusProvider->IsInternetConnected())
            return false;
        Bool ok = deviceTime->SyncTimeFromNetwork();
        if (ok) {
            logger->Info(Tag::Untagged, StdString("[DeviceTimeSyncScheduler] Time synced"));
        }
        return ok;
    }
};

#endif // DEVICE_IDENTITY_DEVICE_TIME_SYNC_SCHEDULER_H
