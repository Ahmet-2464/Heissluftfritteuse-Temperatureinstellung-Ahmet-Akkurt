import tkinter as tk
from Präsentationsschicht.user_interface import UserInterface
from Logikschicht.temperature_controller import TemperatureController
from Hardwareabstraktionsschichtpy.sensor_interface import SensorInterface
from Hardwareabstraktionsschichtpy.heater_control import HeaterControl
from Logikschicht.safety_manager import SafetyManager
from Hardwareabstraktionsschichtpy.display_driver import DisplayDriver

class UserInterface:
    def __init__(self, root):
        self.root = root
        self.root.title("Sprint 1 – Heißluftfritteuse")

        self.label = tk.Label(root, text="Solltemperatur eingeben (°C):")
        self.label.pack(pady=5)

        self.entry = tk.Entry(root)
        self.entry.pack(pady=5)

        self.button = tk.Button(root, text="Bestätigen", command=self.set_temperature)
        self.button.pack(pady=5)

        self.output = tk.Label(root, text="Keine Temperatur gesetzt")
        self.output.pack(pady=10)

    def set_temperature(self):
        temp = self.entry.get()
        self.output.config(text=f"Solltemperatur: {temp}°C")


if __name__ == "__main__":
    root = tk.Tk()
    ui = UserInterface(root)
    root.mainloop()
