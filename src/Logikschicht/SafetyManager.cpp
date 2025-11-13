#include "SafetyManager.h"

bool SafetyManager::Uebertemperaturschutz(double aktuelleTemperatur) {
    return aktuelleTemperatur > maxTemperatur;
}

void SafetyManager::Sicherheitsabschaltung() {
    std::cout << "WARNUNG: Sicherheitsabschaltung wegen Übertemperatur!\n";
    // Hier könnte eine Hardwareabschaltung erfolgen
}
