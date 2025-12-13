#include "SafetyManager2.h"

SafetyManager::SafetyManager() : safeState(true) {}

void SafetyManager::checkTemperature(int currentTemperature) {
    if (currentTemperature > maxTemperature) {
        safeState = false;
        // Heater wird extern deaktiviert (MainController reagiert)
    }
}

bool SafetyManager::isSafe() const {
    return safeState;
}

void SafetyManager::resetSafetyState() {
    safeState = true;
}
