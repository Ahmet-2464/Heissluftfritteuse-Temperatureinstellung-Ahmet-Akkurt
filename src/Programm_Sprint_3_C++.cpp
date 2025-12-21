#include <thread>
#include <chrono>

#include "MockSensor3.h"
#include "MockHeater3.h"
#include "MockDisplayDriver3.h"

#include "TemperatureController3.h"
#include "SafetyManager3.h"
#include "TimerService.h"
#include "UserInterface3.h"

int main() {
    MockSensor sensor(20.0f);
    MockHeater heater;
    MockDisplayDriver display;

    TemperatureController controller(&sensor, &heater, &display);
    SafetyManager safety(&heater, &display);
    TimerService timer;

    UserInterface ui(&controller, &timer);

    ui.setTemperature(180.0f);
    ui.startCooking(10);

    for (int i = 0; i < 15; ++i) {
        sensor.setTemperature(sensor.readTemperature() + 20.0f);

        controller.update();
        safety.checkTemperature(controller.getCurrentTemperature());
        timer.tick();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
