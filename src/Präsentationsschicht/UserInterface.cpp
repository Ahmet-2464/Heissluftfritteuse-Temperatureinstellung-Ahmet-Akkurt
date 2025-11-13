#include "UserInterface.h"
#include "TemperatureController.h"

void UserInterface::TemperaturEingabe(TemperatureController& controller) {
    double zielTemp;
    std::cout << "Bitte Zieltemperatur eingeben: ";
    std::cin >> zielTemp;

    // Übergibt Zieltemperatur an den Controller
    controller.setSollTemperatur(zielTemp);
}

void UserInterface::TemperaturAnzeige(double aktuelleTemperatur) {
    std::cout << "Aktuelle Temperatur: " << aktuelleTemperatur << " °C\n";
}

void UserInterface::RueckmeldungAnNutzer(const std::string& nachricht) {
    std::cout << "Systemmeldung: " << nachricht << std::endl;
}
