#include "UserInterface.h"
#include "TemperatureController.h"
#include "SensorInterface.h"
#include "HeaterControl.h"
#include "SafetyManager.h"
#include "DisplayDriver.h"

int main() {
    SensorInterface sensor;
    HeaterControl heater;
    SafetyManager safety;
    DisplayDriver display;
    TemperatureController controller(&sensor, &heater, &safety, &display);
    UserInterface ui;

    ui.TemperaturEingabe(controller);

    for (int i = 0; i < 5; ++i) {
        controller.SollIstVergleich();
        controller.RegelungHeizleistung();
    }

    ui.RueckmeldungAnNutzer("Betrieb abgeschlossen.");
    return 0;
}
