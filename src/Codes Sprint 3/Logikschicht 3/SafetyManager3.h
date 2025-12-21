#pragma once
#include "HeaterControl3.h"
#include "DisplayDriver3.h"

class SafetyManager {
private:
    HeaterControl* heater;
    DisplayDriver* display;
    bool critical;

public:
    SafetyManager(HeaterControl* h, DisplayDriver* d);

    void checkTemperature(float temp);
    bool isCritical() const;
};
