#pragma once
#include <string>

class DisplayDriver {
public:
    virtual ~DisplayDriver() = default;

    virtual void showTemperature(float temp) = 0;
    virtual void showStatus(const std::string& text) = 0;
    virtual void showWarning(const std::string& text) = 0;
    virtual void playSignal() = 0;
};
