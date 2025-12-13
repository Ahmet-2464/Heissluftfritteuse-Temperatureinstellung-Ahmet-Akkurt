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
| **UserInterface**         | Req. 1.1, Req. 1.2, Req. 1.3                     |
| **TemperatureController** | Req. 2.1, Req. 2.2, Req. 2.3                     |
| **SafetyManager**         |                                                  |
| **SensorInterface**       | Req. 2.1                                         |
| **HeaterControl**         | Req. 2.2                                         |
| **DisplayDriver**         | Req. 1.3                                         |


### Verantwortlichkeiten der Komponenten:

| **Komponente**            | **Rolle**                    | **Verantwortlichkeiten**                                                                                     |
| ------------------------- | ---------------------------- | ------------------------------------------------------------------------------------------------------------ |
| **UserInterface**         | Präsentationsschicht         | Aufnahme der Temperatureingabe, Anzeige der Soll-/Ist-Temperatur, Rückmeldung an Nutzer (Display, LED, Ton). |
| **TemperatureController** | Steuerungslogik              | Soll-/Ist-Vergleich, Regelung der Heizleistung, Kommunikation mit Sensoren und Aktoren.                      |
| **SafetyManager**         | Sicherheitslogik             | Überwachung der Temperaturgrenzen, Sicherheitsabschaltung bei Überhitzung oder Sensorfehler.                 |
| **SensorInterface**       | Hardware-Interface (Eingang) | Erfassen der aktuellen Temperatur über Sensoren und Bereitstellung an die Logik.                             |
| **HeaterControl**         | Hardware-Interface (Ausgang) | Steuerung des Heizelements gemäß Regelung und Sicherheitsvorgaben.                                           |
| **DisplayDriver**         | Anzeige-Interface            | Steuerung von Display, LEDs oder Summer zur Visualisierung von Temperatur, Status und Warnmeldungen.         |



---

## Schnittstellenbeschreibung

| Schnittstelle | Richtung | Syntax (Art der Kommunikation) | Semantik (Daten / Bedeutung) |
|----------------|-----------|-------------------------------|-------------------------------|
| **UI → TemperatureController** | synchron | Methodenaufruf `setTargetTemperature(value)` | Übergibt Solltemperatur vom Benutzer an die Steuerung |
| **TemperatureController → DisplayDriver** | asynchron | Ereignisgesteuert, Callback `updateDisplay(temp)` | Anzeige der neuen Soll-/Ist-Temperatur |
| **TemperatureController → HeaterControl** | synchron | Direkter Funktionsaufruf `setHeatingPower(level)` | Anpassung der Heizleistung in Abhängigkeit vom Soll-/Ist-Vergleich |
| **TemperatureController → SensorInterface** | synchron | Funktionsaufruf `readCurrentTemperature()` | Abfrage des aktuellen Temperaturwerts vom Sensor |
| **SensorInterface → TemperatureController** | asynchron | Interrupt / Callback `onTemperatureUpdate(value)` | Meldet neue Messwerte an die Regelungslogik |
| **SafetyManager → HeaterControl** | synchron | Funktionsaufruf `shutdownHeater()` | Sofortige Abschaltung bei Übertemperatur |
| **SafetyManager → DisplayDriver** | asynchron | Ereignis `showWarning(message)` | Anzeige einer Warnmeldung bei Überhitzung |
| **DisplayDriver → UserInterface** | asynchron | Signalübertragung (z. B. LED oder Ton) | Rückmeldung über Statusänderungen oder Warnungen |
| **TemperatureController → SafetyManager** | synchron | Methodenaufruf `checkTemperatureLimits(value)` | Übergibt aktuelle Temperatur zur Grenzprüfung |


## Zusammenfassung
Dieses Komponentendiagramm bildet die funktionale Struktur der Systemarchitektur ab.  
Die **Schnittstellenbeschreibung** stellt sicher, dass die Kommunikation zwischen den Komponenten eindeutig definiert ist — sowohl auf **technischer Ebene (Syntax)** als auch **inhaltlicher Ebene (Semantik)**.  
Damit wird eine klare Trennung zwischen Benutzerinteraktion, Steuerungslogik und Hardwarezugriff erreicht, was die **Wartbarkeit**, **Testbarkeit** und **Zuverlässigkeit** des Gesamtsystems wesentlich verbessert.

