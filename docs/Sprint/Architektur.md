# Architektur

## Komponentendiagramm

```md
+-------------------------------------------------------------+
|                 Präsentationsschicht                        |
|-------------------------------------------------------------|
|  UserInterface                                              |
|   - Temperatureingabe                                       |
|   - Temperaturanzeige                                       |
|   - Rückmeldung an Nutzer                                   |
+-------------------------------------------------------------+
                 │
                 │ Benutzerinteraktion (Eingabe / Anzeige)
                 ▼
+-------------------------------------------------------------+
|                    Logikschicht                             |
|-------------------------------------------------------------|
|  TemperatureController                                      |
|   - Soll-/Ist-Vergleich                                     |
|   - Regelung der Heizleistung                               |
|                                                             |
|  SafetyManager                                              |
|   - Übertemperaturschutz                                    |
|   - Sicherheitsabschaltung bei Überhitzung oder Fehler      |
+-------------------------------------------------------------+
                 │
                 │ Steuerung, Sensorabfrage, Sicherheitsprüfung
                 ▼
+-------------------------------------------------------------+
|            Hardwareabstraktionsschicht (HAL)                |
|-------------------------------------------------------------|
|  SensorInterface   → liest aktuelle Temperaturwerte         |
|  HeaterControl     → steuert das Heizelement                |
|  DisplayDriver     → steuert Anzeige / LEDs / Summer        |
+-------------------------------------------------------------+
```

| **Komponente**            | **Requirements**                                 |
| ------------------------- | ------------------------------------------------ |
| **UserInterface**         | Req. 1.1, Req. 1.2, Req. 1.3, Req. 3.1, Req. 5.1 |
| **TemperatureController** | Req. 2.1, Req. 2.2, Req. 2.3, Req. 3.1, Req. 4.1 |
| **SafetyManager**         | Req. 4.2, Req. 4.3, Req. 4.4                     |
| **SensorInterface**       | Req. 2.1, Req. 3.2, Req. 5.2                     |
| **HeaterControl**         | Req. 2.2, Req. 4.1, Req. 4.3                     |
| **DisplayDriver**         | Req. 1.3, Req. 3.1, Req. 5.3                     |


### Verantwortlichkeiten der Komponenten:

| **Komponente**            | **Rolle**                    | **Verantwortlichkeiten**                                                                                     |
| ------------------------- | ---------------------------- | ------------------------------------------------------------------------------------------------------------ |
| **UserInterface**         | Präsentationsschicht         | Aufnahme der Temperatureingabe, Anzeige der Soll-/Ist-Temperatur, Rückmeldung an Nutzer (Display, LED, Ton). |
| **TemperatureController** | Steuerungslogik              | Soll-/Ist-Vergleich, Regelung der Heizleistung, Kommunikation mit Sensoren und Aktoren.                      |
| **SafetyManager**         | Sicherheitslogik             | Überwachung der Temperaturgrenzen, Sicherheitsabschaltung bei Überhitzung oder Sensorfehler.                 |
| **SensorInterface**       | Hardware-Interface (Eingang) | Erfassen der aktuellen Temperatur über Sensoren und Bereitstellung an die Logik.                             |
| **HeaterControl**         | Hardware-Interface (Ausgang) | Steuerung des Heizelements gemäß Regelung und Sicherheitsvorgaben.                                           |
| **DisplayDriver**         | Anzeige-Interface            | Steuerung von Display, LEDs oder Summer zur Visualisierung von Temperatur, Status und Warnmeldungen.         |

