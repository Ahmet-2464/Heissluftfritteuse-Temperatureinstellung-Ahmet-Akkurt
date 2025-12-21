#pragma once
#include "SensorInterface3.h"
#include "HeaterControl3.h"
#include "DisplayDriver3.h"

class TemperatureController {
private:
    SensorInterface* sensor;
    HeaterControl* heater;
    DisplayDriver* display;

    float targetTemp;

public:
    TemperatureController(
        SensorInterface* s,
        HeaterControl* h,
        DisplayDriver* d
    );

    void setTargetTemperature(float temp);
    float getCurrentTemperature() const;
    void update();
};
