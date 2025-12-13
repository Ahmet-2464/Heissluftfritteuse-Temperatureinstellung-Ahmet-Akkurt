#include "UserInterface2.h"

UI::UI(DisplayDriver* display) : display(display) {}

void UI::showTemperature(int current, int target) {
    display->displayTemperature(current, target);
}

void UI::showWarning(const std::string& message) {
    display->displayText("WARNUNG: " + message);
}

int UI::readUserInput() {
    // TODO: Hardware-Eingabe auslesen
    // Platzhalter:
    return 0;
}
