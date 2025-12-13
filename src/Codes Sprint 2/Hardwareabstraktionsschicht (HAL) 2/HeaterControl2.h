#ifndef HEATER_CONTROL_H
#define HEATER_CONTROL_H

class HeaterControl {
public:
    virtual void setHeatingPower(int percent) = 0;
    virtual void shutdownHeater() = 0;

    virtual ~HeaterControl() {}
};

#endif
