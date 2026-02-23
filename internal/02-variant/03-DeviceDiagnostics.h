#ifdef ARDUINO
#ifndef DEVICEDIAGNOSTICS_H
#define DEVICEDIAGNOSTICS_H

#include <StandardDefines.h>

#include <esp_system.h>

#include "../01-interface/01-IDeviceDiagnostics.h"

/* @Component */
class DeviceDiagnostics : public IDeviceDiagnostics {
    Public Virtual ~DeviceDiagnostics() = default;

    Public Virtual Bool HadPreviousCrash() const override {
        return (esp_reset_reason() == ESP_RST_PANIC);
    }
};

#endif // DEVICEDIAGNOSTICS_H
#endif // ARDUINO
