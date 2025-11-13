#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <iostream>

class DisplayDriver {
public:
    void aktualisiereAnzeige(double temperatur);
    void aktiviereLED(bool status);
    void spieleSignal();
};

#endif
