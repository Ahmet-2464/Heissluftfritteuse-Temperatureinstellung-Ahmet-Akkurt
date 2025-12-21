#include "TemperatureController3.h"

TemperatureController::TemperatureController(
    SensorInterface* s,
    HeaterControl* h,
    DisplayDriver* d
) : sensor(s), heater(h), display(d), targetTemp(0.0f) {}

void TemperatureController::setTargetTemperature(float temp) {
    targetTemp = temp;
}

float TemperatureController::getCurrentTemperature() const {
    return sensor->readTemperature();
}

void TemperatureController::update() {
    float current = sensor->readTemperature();
    display->showTemperature(current);

    if (current < targetTemp) {
        heater->on();
        display->showStatus("Heating");
    } else {
        heater->off();
        display->showStatus("Target reached");
    }
}
