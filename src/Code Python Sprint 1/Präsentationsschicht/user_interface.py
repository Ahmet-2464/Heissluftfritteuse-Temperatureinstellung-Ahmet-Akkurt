class UserInterface:
    def temperatur_eingabe(self, controller):
        controller.set_target_temperature(180)

    def rueckmeldung_an_nutzer(self, message):
        print(message)
