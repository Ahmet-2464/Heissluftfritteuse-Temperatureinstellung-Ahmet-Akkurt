#include "DisplayDriver.h"

void DisplayDriver::aktualisiereAnzeige(double temperatur) {
    std::cout << "Anzeige aktualisiert: " << temperatur << " °C\n";
}

void DisplayDriver::aktiviereLED(bool status) {
    std::cout << (status ? "LED AN\n" : "LED AUS\n");
}

void DisplayDriver::spieleSignal() {
    std::cout << "Signalton ausgegeben!\n";
}
