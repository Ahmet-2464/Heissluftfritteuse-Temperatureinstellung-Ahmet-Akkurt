#pragma once
#include "HeaterControl3.h"
#include <iostream>

class MockHeater : public HeaterControl {
private:
    bool active = false;

public:
    void on() override {
        active = true;
        std::cout << "[Heater] ON\n";
    }

    void off() override {
        active = false;
        std::cout << "[Heater] OFF\n";
    }

    bool isOn() const {
        return active;
    }
};
