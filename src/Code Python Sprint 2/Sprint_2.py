import time

# -------------------------------------------------------
# Mock-Hardware
# -------------------------------------------------------

class MockSensor:
    def __init__(self):
        self.temperature = 25  # Starttemperatur

    def read_temperature(self):
        return self.temperature

    def set_simulated_value(self, value):
        self.temperature = value


class MockHeater:
    def __init__(self):
        self.is_on = False

    def turn_on(self):
        self.is_on = True
        print("Heizung EIN")

    def turn_off(self):
        self.is_on = False
        print("Heizung AUS")

    def shutdown_heater(self):
        self.turn_off()
        print("[HEATER] Notabschaltung")


# -------------------------------------------------------
# Safety Manager
# -------------------------------------------------------

class SafetyManager:
    def __init__(self):
        self.safe = True
        self.max_temperature = 210

    def check_temperature(self, temperature):
        if temperature > self.max_temperature:
            self.safe = False

    def is_safe(self):
        return self.safe


# -------------------------------------------------------
# User Interface (Mock)
# -------------------------------------------------------

class UI:
    def show_temperature(self, current, target):
        print(f"[DISPLAY] Ist: {current}°C | Soll: {target}°C")

    def show_warning(self, message):
        print(f"[WARNUNG] {message}")


# -------------------------------------------------------
# Temperature Controller
# -------------------------------------------------------

class TemperatureController:
    def __init__(self, sensor, heater):
        self.sensor = sensor
        self.heater = heater
        self.target_temperature = 180

    def get_current_temperature(self):
        return self.sensor.read_temperature()

    def get_target_temperature(self):
        return self.target_temperature

    def set_target_temperature(self, value):
        self.target_temperature = value

    def update_regulation(self):
        current = self.sensor.read_temperature()

        if current < self.target_temperature:
            self.heater.turn_on()
        else:
            self.heater.turn_off()


# -------------------------------------------------------
# MAIN PROGRAMM
# -------------------------------------------------------

def main():
    print("=== Heissluftfritteuse – Sprint 2 Systemstart ===")

    # Hardware-Mocks
    sensor = MockSensor()
    heater = MockHeater()

    # Safety-System
    safety = SafetyManager()

    # UI
    ui = UI()

    # Controller
    controller = TemperatureController(sensor, heater)

    # Systemstartanzeige
    ui.show_temperature(
        controller.get_current_temperature(),
        controller.get_target_temperature()
    )

    # Benutzer gibt Solltemperatur ein
    print("\nBenutzer gibt neue Solltemperatur ein...")
    user_input = 180
    controller.set_target_temperature(user_input)

    ui.show_temperature(
        controller.get_current_temperature(),
        controller.get_target_temperature()
    )

    # Regelzyklus
    for cycle in range(8):
        print(f"\n--- Regelzyklus {cycle + 1} ---")

        current = sensor.read_temperature()
        print(f"Sensor meldet: {current}°C")

        safety.check_temperature(current)

        if not safety.is_safe():
            print("[!] Sicherheitsfehler — System wird abgeschaltet!")
            heater.shutdown_heater()
            ui.show_warning("Überhitzung! System stoppt.")
            break

        controller.update_regulation()

        ui.show_temperature(
            controller.get_current_temperature(),
            controller.get_target_temperature()
        )

        # Simulierte Aufheizung
        sensor.set_simulated_value(sensor.read_temperature() + 10)

        time.sleep(0.5)

    print("\n=== Ende der Simulation ===")


if __name__ == "__main__":
    main()
