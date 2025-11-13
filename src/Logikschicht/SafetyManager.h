#ifndef SAFETY_MANAGER_H
#define SAFETY_MANAGER_H

#include <iostream>

class DisplayDriver;

class SafetyManager {
private:
    double maxTemperatur = 200.0; // Beispielgrenze

public:
    bool Uebertemperaturschutz(double aktuelleTemperatur);
    void Sicherheitsabschaltung();
};

#endif
