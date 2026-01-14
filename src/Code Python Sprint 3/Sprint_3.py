import time


# -------------------------------------------------
# Mock-Hardware
# -------------------------------------------------

class MockSensor:
    def __init__(self, initial_temp):
        self.temperature = initial_temp

    def read_temperature(self):
        return self.temperature

    def set_temperature(self, value):
        self.temperature = value


class MockHeater:
    def __init__(self):
        self.active = False

    def on(self):
        self.active = True
        print("Heizung EIN")

    def off(self):
        self.active = False
        print("Heizung AUS")


class MockDisplayDriver:
    def show_temperature(self, current, target):
        print(f"Anzeige: Ist={current:.1f}°C | Soll={target:.1f}°C")

    def show_warning(self, message):
        print(f"[WARNUNG] {message}")

    def show_timer(self, remaining):
        print(f"Timer: {remaining} Sekunden verbleibend")


# -------------------------------------------------
# Systemkomponenten
# -------------------------------------------------

class TemperatureController:
    def __init__(self, sensor, heater, display):
        self.sensor = sensor
        self.heater = heater
        self.display = display
        self.target_temperature = 0.0

    def set_target_temperature(self, temp):
        self.target_temperature = temp

    def get_current_temperature(self):
        return self.sensor.read_temperature()

    def update(self):
        current = self.get_current_temperature()

        if current < self.target_temperature:
            self.heater.on()
        else:
            self.heater.off()

        self.display.show_temperature(current, self.target_temperature)


class SafetyManager:
    def __init__(self, heater, display):
        self.heater = heater
        self.display = display
        self.max_temperature = 220.0

    def check_temperature(self, temperature):
        if temperature > self.max_temperature:
            self.heater.off()
            self.display.show_warning("Übertemperatur! System gestoppt.")


class TimerService:
    def __init__(self):
        self.remaining_time = 0
        self.running = False

    def start(self, seconds):
        self.remaining_time = seconds
        self.running = True

    def tick(self):
        if self.running and self.remaining_time > 0:
            self.remaining_time -= 1
            if self.remaining_time == 0:
                self.running = False
                print("Timer abgelaufen!")

    def get_remaining_time(self):
        return self.remaining_time


class UserInterface:
    def __init__(self, controller, timer):
        self.controller = controller
        self.timer = timer

    def set_temperature(self, temp):
        print(f"Benutzer setzt Solltemperatur auf {temp}°C")
        self.controller.set_target_temperature(temp)

    def start_cooking(self, duration_seconds):
        print(f"Garvorgang gestartet ({duration_seconds} Sekunden)")
        self.timer.start(duration_seconds)


# -------------------------------------------------
# MAIN – Sprint 3 Simulation
# -------------------------------------------------

def main():
    sensor = MockSensor(20.0)
    heater = MockHeater()
    display = MockDisplayDriver()

    controller = TemperatureController(sensor, heater, display)
    safety = SafetyManager(heater, display)
    timer = TimerService()

    ui = UserInterface(controller, timer)

    ui.set_temperature(180.0)
    ui.start_cooking(10)

    for cycle in range(15):
        print(f"\n--- Zyklus {cycle + 1} ---")

        # Temperatur steigt simuliert an
        sensor.set_temperature(sensor.read_temperature() + 20.0)

        controller.update()
        safety.check_temperature(controller.get_current_temperature())
        timer.tick()

        display.show_timer(timer.get_remaining_time())

        time.sleep(0.5)


if __name__ == "__main__":
    main()
