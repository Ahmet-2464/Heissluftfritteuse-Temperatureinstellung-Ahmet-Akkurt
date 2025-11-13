#include "HeaterControl.h"

void HeaterControl::steuereHeizelement(double leistung) {
    std::cout << "Heizelement auf " << leistung << "% Leistung eingestellt.\n";
    // In echter Hardware würde hier die Heizleistung gesetzt werden.
}
