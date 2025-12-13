#include "MainController.h"

MainController::MainController(
    TemperatureController* tempCtrl,
    SafetyManager* safety,
    UI* ui,
    EventSystem* events
) : tempCtrl(tempCtrl), safety(safety), ui(ui), events(events) {}

void MainController::loop() {
    int currentTemp = tempCtrl->getCurrentTemperature();
    int targetTemp = tempCtrl->getTargetTemperature();

    safety->checkTemperature(currentTemp);
    if (!safety->isSafe()) {
        ui->showWarning("Überhitzung!");
        return;  // Not-Aus aktiv – kein Regelbetrieb mehr
    }

    tempCtrl->updateRegulation();
    ui->showTemperature(currentTemp, targetTemp);
}
