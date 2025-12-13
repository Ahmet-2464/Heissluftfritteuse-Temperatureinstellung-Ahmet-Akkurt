#ifndef MOCK_HEATER_H
#define MOCK_HEATER_H

#include "HeaterControl2.h"
#include <iostream>

class MockHeater : public HeaterControl {
private:
    int currentPower;

public:
    MockHeater() : currentPower(0) {}

    void setHeatingPower(int percent) override {
        currentPower = percent;
        std::cout << "Heater power set to: " << currentPower << "%\n";
    }

    void shutdownHeater() override {
        currentPower = 0;
        std::cout << "Heater EMERGENCY SHUTDOWN!\n";
    }
};

#endif
