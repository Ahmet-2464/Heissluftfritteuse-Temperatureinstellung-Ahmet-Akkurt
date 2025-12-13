#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H

#include "../Hardwareabstraktionsschicht (HAL) 2/SensorInterface2.h"
#include "../Hardwareabstraktionsschicht (HAL) 2/HeaterControl2.h"

class TemperatureController {
private:
    int targetTemperature;
    int currentTemperature;

    SensorInterface* sensor;
    HeaterControl* heater;

public:
    TemperatureController(SensorInterface* sensor, HeaterControl* heater);

    void setTargetTemperature(int temperature);
    int getTargetTemperature() const;

    int getCurrentTemperature();
    void updateRegulation();  // Soll-Ist-Vergleich

    // Für Sprint 3:
    // TODO: PID-Regelung einbauen
};

#endif
