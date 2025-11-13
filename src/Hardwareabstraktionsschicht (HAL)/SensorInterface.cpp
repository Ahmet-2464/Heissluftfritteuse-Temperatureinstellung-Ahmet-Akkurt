#include "SensorInterface.h"

// Simulierte Temperaturmessung
double SensorInterface::leseTemperatur() {
    // Zufälliger Wert für Simulation
    return 150.0 + (std::rand() % 100) / 10.0; 
}
