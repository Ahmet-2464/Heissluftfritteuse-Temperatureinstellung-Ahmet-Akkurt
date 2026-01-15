import tkinter as tk
import threading
import time

class MockSensor:
    def __init__(self):
        self.temp = 20

    def read(self):
        return self.temp

    def increase(self):
        self.temp += 15


class SafetyManager:
    def check(self, temp):
        return temp < 220


class App:
    def __init__(self, root):
        self.root = root
        root.title("Sprint 3 – Sicherheit & Timer")

        self.sensor = MockSensor()
        self.safety = SafetyManager()
        self.running = False

        self.start_btn = tk.Button(root, text="Starten (180°C)", command=self.start)
        self.start_btn.pack(pady=5)

        self.label = tk.Label(root, text="System bereit")
        self.label.pack(pady=10)

    def start(self):
        self.running = True
        self.start_btn.config(state="disabled")
        threading.Thread(target=self.loop, daemon=True).start()

    def loop(self):
        while self.running:
            self.sensor.increase()
            temp = self.sensor.read()

            if not self.safety.check(temp):
                self.label.config(text=f"❌ ÜBERHITZUNG bei {temp}°C")
                self.running = False
                return

            self.label.config(text=f"Temperatur: {temp}°C")
            time.sleep(1)


if __name__ == "__main__":
    root = tk.Tk()
    App(root)
    root.mainloop()
