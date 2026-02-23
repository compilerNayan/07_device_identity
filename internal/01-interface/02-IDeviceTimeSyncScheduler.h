/**
 * @file 02-IDeviceTimeSyncScheduler.h
 * @brief Interface for triggering device time sync after certain checks (e.g. interval, network).
 */

#ifndef DEVICE_IDENTITY_IDEVICE_TIME_SYNC_SCHEDULER_H
#define DEVICE_IDENTITY_IDEVICE_TIME_SYNC_SCHEDULER_H

#include <StandardDefines.h>

DefineStandardPointers(IDeviceTimeSyncScheduler)

class IDeviceTimeSyncScheduler {
    Public Virtual ~IDeviceTimeSyncScheduler() = default;

    /**
     * Runs the scheduler: performs checks and triggers time sync if conditions are met.
     * Call periodically (e.g. from main loop or a thread).
     * @return true if a sync was attempted (and may have succeeded), false if skipped (e.g. interval not elapsed, checks failed).
     */
    Public Virtual Bool TrySync() = 0;
};

#endif // DEVICE_IDENTITY_IDEVICE_TIME_SYNC_SCHEDULER_H
