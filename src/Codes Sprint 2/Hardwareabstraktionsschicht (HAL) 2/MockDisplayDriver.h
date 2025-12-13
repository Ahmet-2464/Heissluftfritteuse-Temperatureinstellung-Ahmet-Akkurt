#ifndef MOCK_DISPLAY_DRIVER_H
#define MOCK_DISPLAY_DRIVER_H

#include "DisplayDriver2.h"
#include <iostream>

class MockDisplayDriver : public DisplayDriver {
public:
    void displayText(const std::string& text) override {
        std::cout << "[DISPLAY] " << text << "\n";
    }

    void displayTemperature(int current, int target) override {
        std::cout << "[DISPLAY] Current: " << current
                  << "°C | Target: " << target << "°C\n";
    }
};

#endif
