#include "SafetyManager3.h"

SafetyManager::SafetyManager(HeaterControl* h, DisplayDriver* d)
    : heater(h), display(d), critical(false) {}

void SafetyManager::checkTemperature(float temp) {
    if (temp >= 250.0f) {
        critical = true;
        heater->off();
        display->showWarning("Overtemperature!");
        display->playSignal();
    }
}

bool SafetyManager::isCritical() const {
    return critical;
}
