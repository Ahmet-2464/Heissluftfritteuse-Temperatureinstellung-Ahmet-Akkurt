#include "TemperatureController.h"
#include <iostream>

TemperatureController::TemperatureController(SensorInterface* s, HeaterControl* h, SafetyManager* sa, DisplayDriver* d)
    : sensor(s), heater(h), safety(sa), display(d), sollTemperatur(0.0), istTemperatur(0.0) {}

void TemperatureController::SollIstVergleich() {
    istTemperatur = sensor->leseTemperatur();
    display->aktualisiereAnzeige(istTemperatur);

    // Überprüft auf Sicherheitsgrenzen
    if (safety->Uebertemperaturschutz(istTemperatur)) {
        heater->steuereHeizelement(0); // Heizung ausschalten
        safety->Sicherheitsabschaltung();
    }
}

void TemperatureController::RegelungHeizleistung() {
    double differenz = sollTemperatur - istTemperatur;

    // Einfache Regelung (Proportional)
    double leistung = differenz * 10; // P-Regler, Faktor 10 = Verstärkung

    if (leistung < 0) leistung = 0;
    if (leistung > 100) leistung = 100; // Maximalleistung

    heater->steuereHeizelement(leistung);
}
