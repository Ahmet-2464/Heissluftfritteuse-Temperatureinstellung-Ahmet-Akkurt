#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "../Logikschicht 2/TemperatureController2.h"
#include "../Logikschicht 2/SafetyManager2.h"
#include "../Präsentationsschicht 2/UserInterface2.h"
#include "../events/EventSystem.h"

class MainController {
private:
    TemperatureController* tempCtrl;
    SafetyManager* safety;
    UI* ui;
    EventSystem* events;

public:
    MainController(
        TemperatureController* tempCtrl,
        SafetyManager* safety,
        UI* ui,
        EventSystem* events
    );

    void loop();  // Hauptzyklus
};

#endif
