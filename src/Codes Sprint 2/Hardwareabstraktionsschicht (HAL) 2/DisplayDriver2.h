#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <string>

class DisplayDriver {
public:
    virtual void displayText(const std::string& text) = 0;
    virtual void displayTemperature(int current, int target) = 0;

    virtual ~DisplayDriver() {}
};

#endif
