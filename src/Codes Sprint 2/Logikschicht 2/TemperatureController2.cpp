#include "TemperatureController2.h"

TemperatureController::TemperatureController(
    SensorInterface* sensor,
    HeaterControl* heater
) : targetTemperature(0), currentTemperature(0),
    sensor(sensor), heater(heater) {}

void TemperatureController::setTargetTemperature(int temperature) {
    // TODO: Temperaturbereich prüfen (50–200°C)
    targetTemperature = temperature;
}

int TemperatureController::getTargetTemperature() const {
    return targetTemperature;
}

int TemperatureController::getCurrentTemperature() {
    currentTemperature = sensor->readTemperature();
    return currentTemperature;
}

void TemperatureController::updateRegulation() {
    currentTemperature = sensor->readTemperature();

    // **Sehr einfache Steuerung** – in Sprint 3 ersetzt durch PID
    if (currentTemperature < targetTemperature)
        heater->setHeatingPower(100);
    else
        heater->setHeatingPower(0);

    // TODO Sprint 3:
    // - Glättung
    // - PID-Regelung
}
