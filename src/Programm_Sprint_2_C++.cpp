#include <iostream>
#include <thread>
#include <chrono>

// Eigene Header
#include "TemperatureController2.h"
#include "SafetyManager2.h"
#include "UserInterface2.h"
#include "SensorInterface2.h"
#include "HeaterControl2.h"

// Mock-Hardware
#include "MockSensor.h"
#include "MockHeater.h"

int main() {
    std::cout << "=== Heissluftfritteuse – Sprint 2 Systemstart ===\n";

    // -------------------------------------------------------
    // Hardware-Mocks (später echte Hardwaretreiber)
    // -------------------------------------------------------
    MockSensor sensor;        // Liefert simulierte Temperaturwerte
    MockHeater heater;        // Simuliert Heizleistung

    // -------------------------------------------------------
    // Safety-System
    // -------------------------------------------------------
    SafetyManager safety;

    // -------------------------------------------------------
    // User Interface (zeigt Soll/Ist-Temperatur an)
    // -------------------------------------------------------
    UI ui;

    // -------------------------------------------------------
    // Zentrale Steuerung
    // -------------------------------------------------------
    TemperatureController controller(&sensor, &heater);

    // -------------------------------------------------------
    // Systemstartanzeige
    // -------------------------------------------------------
    ui.showTemperature(controller.getCurrentTemperature(),
                       controller.getTargetTemperature());

    // -------------------------------------------------------
    // Beispiel: Benutzer gibt Solltemperatur ein
    // -------------------------------------------------------
    std::cout << "\nBenutzer gibt neue Solltemperatur ein...\n";
    int userInput = 180;   // Simulierter UI-Wert
    controller.setTargetTemperature(userInput);

    // UI aktualisieren
    ui.showTemperature(controller.getCurrentTemperature(),
                       controller.getTargetTemperature());

    // -------------------------------------------------------
    // Regelzyklus (simuliert z. B. alle 500 ms)
    // Simuliert, wie das echte Gerät später arbeitet!
    // -------------------------------------------------------
    for (int cycle = 0; cycle < 8; ++cycle) {
        std::cout << "\n--- Regelzyklus " << cycle+1 << " ---\n";

        // Temperatur vom Sensor einlesen
        int current = sensor.readTemperature();
        std::cout << "Sensor meldet: " << current << "°C\n";

        // Safety prüfen
        safety.checkTemperature(current);

        if (!safety.isSafe()) {
            std::cout << "[!] Sicherheitsfehler — System wird abgeschaltet!\n";
            heater.shutdownHeater();
            ui.showWarning("Überhitzung! System stoppt.");
            break;
        }

        // Regler aktualisiert Heizleistung
        controller.updateRegulation();

        // UI aktualisiert Ist-/Solltemperatur
        ui.showTemperature(controller.getCurrentTemperature(),
                           controller.getTargetTemperature());

        // Temperatur steigt simuliert an (Mock)
        // ------------------------------------------------------
        // WICHTIG: Dies simuliert die reale Aufheizung —
        // Im echten Gerät liefert der Sensor automatisch neue Werte.
        // ------------------------------------------------------
        sensor.setSimulatedValue(sensor.readTemperature() + 10);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\n=== Ende der Simulation ===\n";
    return 0;
}
