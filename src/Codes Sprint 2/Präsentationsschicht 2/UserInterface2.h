#ifndef UI_H
#define UI_H

#include "../Hardwareabstraktionsschicht (HAL) 2/DisplayDriver2.h"

class UI {
private:
    DisplayDriver* display;

public:
    UI(DisplayDriver* display);

    void showTemperature(int current, int target);
    void showWarning(const std::string& message);

    int readUserInput();  // z.B. Drehregler

    // TODO Sprint 3:
    // - Menülogik
    // - Timer-UI
};

#endif
