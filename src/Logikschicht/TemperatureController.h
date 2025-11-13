#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H

#include "SensorInterface.h"
#include "HeaterControl.h"
#include "SafetyManager.h"
#include "DisplayDriver.h"

class TemperatureController {
private:
    double sollTemperatur;
    double istTemperatur;

    SensorInterface* sensor;
    HeaterControl* heater;
    SafetyManager* safety;
    DisplayDriver* display;

public:
    TemperatureController(SensorInterface* s, HeaterControl* h, SafetyManager* sa, DisplayDriver* d);

    void SollIstVergleich();
    void RegelungHeizleistung();

    void setSollTemperatur(double temp) { sollTemperatur = temp; }
    double getIstTemperatur() const { return istTemperatur; }
};

#endif
