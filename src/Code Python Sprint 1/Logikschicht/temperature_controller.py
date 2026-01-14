class TemperatureController:
    def __init__(self, sensor, heater, safety, display):
        self.sensor = sensor
        self.heater = heater
        self.safety = safety
        self.display = display
        self.target_temp = 0

    def set_target_temperature(self, temp):
        self.target_temp = temp

    def soll_ist_vergleich(self):
        self.current_temp = self.sensor.read_temperature()

    def regelung_heizleistung(self):
        if self.current_temp < self.target_temp:
            self.heater.on()
        else:
            self.heater.off()
