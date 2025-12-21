#pragma once
#include "TemperatureController3.h"
#include "TimerService.h"

class UserInterface {
private:
    TemperatureController* controller;
    TimerService* timer;

public:
    UserInterface(
        TemperatureController* c,
        TimerService* t
    );

    void setTemperature(float temp);
    void startCooking(int seconds);
};
