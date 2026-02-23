/**
 * @file 01-DeviceTimeSyncThread.h
 * @brief IRunnable that calls IDeviceTimeSyncScheduler::TrySync() periodically.
 *        Call Run() every loop from main thread; throttled so sync runs at most every 10 mins.
 */

#ifndef DEVICE_IDENTITY_DEVICE_TIME_SYNC_THREAD_H
#define DEVICE_IDENTITY_DEVICE_TIME_SYNC_THREAD_H

#include <StandardDefines.h>
#include <IRunnable.h>

#include "../01-interface/02-IDeviceTimeSyncScheduler.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

/** Interval between scheduler TrySync() calls (ms). */
static constexpr ULong kDeviceTimeSyncThreadIntervalMs = 10 * 60 * 1000;  // 10 minutes

class DeviceTimeSyncThread final : public IRunnable {

    /* @Autowired */
    Private IDeviceTimeSyncSchedulerPtr deviceTimeSyncScheduler;

    Private ULong lastRunMs_{0};

    Public Void Run() override {
        while (true) {
            Val synced =deviceTimeSyncScheduler->TrySync();
            if(synced) {
                logger->Info(Tag::Untagged, StdString("[DeviceTimeSyncThread] Time synced"));
                Thread::Sleep(6 * 60 * 60 * 1000); // 6 hours
            }
        }
    }
};

#endif // DEVICE_IDENTITY_DEVICE_TIME_SYNC_THREAD_H
