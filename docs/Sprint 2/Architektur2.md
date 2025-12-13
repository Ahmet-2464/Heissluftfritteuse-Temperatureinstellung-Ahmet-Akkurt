# Architektur

## Komponentendiagramm

```md

+-------------------------------------------------------------+
|   Präsentationsschicht                                      |
|-------------------------------------------------------------|
| UserInterface                                               |
|  - Temperatureingabe                                        |
|  - Temperaturanzeige                                        |
|  - Rückmeldung an Nutzer                                    |
+-------------------------------------------------------------+
                 │
                 ▼
+-------------------------------------------------------------+
|   Logikschicht                                              |
|-------------------------------------------------------------|
| TemperatureController                                       |
|   - Koordiniert Regelung, Messung, Safety, Anzeige          |
|                                                             |
| RegulationEngine                                            |
|   - Soll-Ist-Vergleich                                      |
|   - Regelung Heizleistung                                   |
|                                                             |
| SafetyChecker                                               |
|   - Prüft Temperaturbereich (min/max)                       |
|                                                             |
| HeatingCalculator                                           |
|   - Berechnung Heizzeit                                     |
+-------------------------------------------------------------+
                 │
                 ▼
+-------------------------------------------------------------+
|   Sensor / Hardware-Abstraktion                             |
|-------------------------------------------------------------|
| SensorReader      → liest Temperatur (geglättet)            |
| HeaterControl     → steuert Heizelement                     |
| DisplayDriver     → Ausgabe (Text/LED/Ton)                  |
| DisplayRefresher  → aktualisiert Anzeige ≤ 200 ms           |
+-------------------------------------------------------------+
```
| **Komponente**            | **Requirements**                                 |
| ------------------------- | ------------------------------------------------ |
| **UserInterface**         | Req. 1.1, Req. 1.2, Req. 1.3                   |
| **TemperatureController** | Req. 2.1, Req. 2.2, Req. 2.3, Req. 3.1, Req. 3.2, Req. 3.4                     |
| **SafetyManager**         |  Req. 4.1                                                |
| **SensorInterface**       | Req. 2.1, Req. 3.3                                       |
| **HeaterControl**         | Req. 2.2, Req. 4.1                                         |
| **DisplayDriver**         | Req. 1.3                                         |


# Schnittstellenbeschreibung 

Dieses Dokument beschreibt die zentralen Schnittstellen zwischen den Softwarekomponenten der Heißluftfritteuse entsprechend der geplanten Architektur nach Sprint 1 (mit Erkenntnissen eingearbeitet).

---

## 1. TemperatureController

Der TemperatureController regelt die Temperatur, verarbeitet Soll- und Ist-Werte, steuert die Heizleistung und nutzt sensorische Eingaben.

### Öffentliche Methoden

#### `void setTargetTemperature(int temperature)`
- **Beschreibung:** Setzt die gewünschte Solltemperatur.
- **Vorbedingung:** Temperatur liegt im gültigen Bereich (z. B. 50–200 °C).
- **Nachbedingung:** Interner Regler wird aktualisiert.
- **Aufrufer:** UI, MainController

#### `int getTargetTemperature()`
- **Beschreibung:** Liefert aktuell gesetzte Solltemperatur.
- **Aufrufer:** UI, Logging

#### `int getCurrentTemperature()`
- **Beschreibung:** Liefert aktuell gemessene Ist-Temperatur.
- **Datenquelle:** SensorInterface
- **Aufrufer:** UI, SafetyManager

#### `void updateRegulation()`
- **Beschreibung:** Führt Soll-Ist-Vergleich durch und passt Heizleistung an.
- **Aufrufer:** MainController (zyklisch)
- **Seit Sprint 2:** Sensoranbindung integriert.

---

## 2. SafetyManager

Der SafetyManager überwacht sicherheitskritische Parameter (Überhitzung, Fehlmessungen, Hardwarefehler).

### Öffentliche Methoden

#### `void checkTemperature(int currentTemperature)`
- **Beschreibung:** Prüft, ob Ist-Temperatur sicher ist.
- **Reaktion:** Deaktiviert Heizelement bei Überhitzung.
- **Seit Sprint 2:** Pflichtintegration laut Erkenntnissen.

#### `bool isSafe()`
- **Beschreibung:** Gibt an, ob System sich in sicherem Zustand befindet.
- **Aufrufer:** MainController, UI

#### `void resetSafetyState()`
- **Beschreibung:** Setzt Sicherheitsflags nach Fehler zurück.

---

## 3. UI (UserInterface)

Neu in Sprint 2 als eigene Klasse (Entkopplung vom DisplayController).

### Öffentliche Methoden

#### `void showTemperature(int current, int target)`
- **Beschreibung:** Zeigt Ist- und Solltemperatur an.
- **Nutzt:** DisplayDriver (HAL)

#### `void showWarning(string message)`
- **Beschreibung:** Gibt Warnungen aus (z. B. Überhitzung).
- **Nutzt:** DisplayDriver + optional Signalton/LED

#### `int readUserInput()`
- **Beschreibung:** Liest Nutzereingaben (Tasten, Drehregler).
- **Aufrufer:** MainController

---

## 4. HAL – Hardware Abstraction Layer

HAL kapselt Hardwaredetails in klar getrennten Modulen.

### 4.1 SensorInterface (neu in Sprint 2)

#### `int readTemperature()`
- **Beschreibung:** Liefert gemessene Temperatur in °C.
- **Aufrufer:** TemperatureController

#### `bool sensorOK()`
- **Beschreibung:** Prüft Sensorfunktionalität.

---

### 4.2 HeaterControl (neu in Sprint 2)

#### `void setHeatingPower(int powerPercent)`
- **Beschreibung:** Setzt Heizleistung (0–100 %).
- **Aufrufer:** TemperatureController

#### `void shutdownHeater()`
- **Beschreibung:** Schaltet Heizelement sofort ab.
- **Aufrufer:** SafetyManager

---

### 4.3 DisplayDriver (bestehend)

#### `void displayText(string text)`
- **Beschreibung:** Gibt Text auf dem Display aus.

#### `void displayTemperature(int current, int target)`
- **Beschreibung:** Optimierte Temperaturanzeige für UI.

---

## 5. Eventsystem / Asynchrone Events

### Hintergrund
Laut Architektur müssen Sensor- (Temperaturänderung), UI- und Safety-Events unterstützt werden.

### Schnittstellen

#### `void registerCallback(EventType type, function callback)`
- **Beschreibung:** Registriert Callbacks für Events (z. B. Überhitzung, Tastendruck).

#### `void triggerEvent(EventType type)`
- **Beschreibung:** Löst Ereignis aus, ruft registrierte Handler auf.

### Eventtypen
- `TEMP_CHANGED`
- `OVERHEAT`
- `BUTTON_PRESS`
- `SYSTEM_ERROR`

---

# Zusammenfassung der Änderungen durch Erkenntnisse aus Sprint 1

Die folgenden Anpassungen wurden in diese Schnittstellenbeschreibung eingearbeitet:

- **SafetyManager früh integrieren** → vollständige Schnittstelle vorhanden  
- **TemperatureController benötigt Sensoranbindung** → Methoden reflektieren SensorInterface  
- **HAL muss erweitert werden** → SensorInterface & HeaterControl ergänzt  
- **Asynchrone Events notwendig** → Eventsystem beschrieben  
- **UI aus DisplayController herauslösen** → eigene Klasse definiert

---
