import tkinter as tk
import threading
import time

class MockSensor:
    def __init__(self):
        self.temp = 20

    def read(self):
        return self.temp

    def heat_up(self):
        self.temp += 5


class TemperatureController:
    def __init__(self, sensor):
        self.sensor = sensor
        self.target = 0
        self.heater_on = False

    def set_target(self, temp):
        self.target = temp

    def update(self):
        current = self.sensor.read()
        self.heater_on = current < self.target
        return current, self.heater_on


class App:
    def __init__(self, root):
        self.root = root
        root.title("Sprint 2 – Regelung")

        self.sensor = MockSensor()
        self.controller = TemperatureController(self.sensor)

        self.entry = tk.Entry(root)
        self.entry.pack()

        self.button = tk.Button(root, text="Solltemperatur setzen", command=self.start)
        self.button.pack()

        self.label = tk.Label(root, text="")
        self.label.pack(pady=10)

    def start(self):
        self.controller.set_target(int(self.entry.get()))
        threading.Thread(target=self.loop, daemon=True).start()

    def loop(self):
        while True:
            self.sensor.heat_up()
            current, heater = self.controller.update()
            self.label.config(
                text=f"Ist: {current}°C | Soll: {self.controller.target}°C | Heizung: {'EIN' if heater else 'AUS'}"
            )
            time.sleep(1)


if __name__ == "__main__":
    root = tk.Tk()
    App(root)
    root.mainloop()
