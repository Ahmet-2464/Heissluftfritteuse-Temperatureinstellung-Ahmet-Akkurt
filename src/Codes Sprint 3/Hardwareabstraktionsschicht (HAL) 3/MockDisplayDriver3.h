#pragma once
#include "DisplayDriver3.h"
#include <iostream>

class MockDisplayDriver : public DisplayDriver {
public:
    void showTemperature(float temp) override {
        std::cout << "[Display] Temperature: " << temp << " °C\n";
    }

    void showStatus(const std::string& text) override {
        std::cout << "[Display] Status: " << text << "\n";
    }

    void showWarning(const std::string& text) override {
        std::cout << "[Display] WARNING: " << text << "\n";
    }

    void playSignal() override {
        std::cout << "[Display] *Signal*\n";
    }
};

