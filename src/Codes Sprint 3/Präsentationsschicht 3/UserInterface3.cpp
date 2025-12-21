#include "UserInterface3.h"

UserInterface::UserInterface(
    TemperatureController* c,
    TimerService* t
) : controller(c), timer(t) {}

void UserInterface::setTemperature(float temp) {
    controller->setTargetTemperature(temp);
}

void UserInterface::startCooking(int seconds) {
    timer->start(seconds);
}
