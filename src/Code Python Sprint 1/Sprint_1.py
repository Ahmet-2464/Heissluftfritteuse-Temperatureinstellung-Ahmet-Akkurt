from Präsentationsschicht.user_interface import UserInterface
from Logikschicht.temperature_controller import TemperatureController
from Hardwareabstraktionsschichtpy.sensor_interface import SensorInterface
from Hardwareabstraktionsschichtpy.heater_control import HeaterControl
from Logikschicht.safety_manager import SafetyManager
from Hardwareabstraktionsschichtpy.display_driver import DisplayDriver


def main():
    # Hardware / HAL
    sensor = SensorInterface()
    heater = HeaterControl()
    safety = SafetyManager()
    display = DisplayDriver()

    # Controller
    controller = TemperatureController(
        sensor=sensor,
        heater=heater,
        safety=safety,
        display=display
    )

    # UI
    ui = UserInterface()

    # Benutzereingabe
    ui.temperatur_eingabe(controller)

    # Regelungszyklus
    for _ in range(5):
        controller.soll_ist_vergleich()
        controller.regelung_heizleistung()

    # Rückmeldung an Nutzer
    ui.rueckmeldung_an_nutzer("Betrieb abgeschlossen.")


if __name__ == "__main__":
    main()
