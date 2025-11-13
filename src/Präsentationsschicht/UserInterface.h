#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>

class TemperatureController; // Vorwärtsdeklaration

class UserInterface {
public:
    // Methoden laut Diagramm
    void TemperaturEingabe(TemperatureController& controller);
    void TemperaturAnzeige(double aktuelleTemperatur);
    void RueckmeldungAnNutzer(const std::string& nachricht);
};

#endif
