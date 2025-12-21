# Architektur

## Komponentendiagramm

```md
+-------------------------------------------------------------+
|   Präsentationsschicht                                      |
|-------------------------------------------------------------|
| UserInterface                                               |
|  - Temperaturanzeige                                        |
|  - Warnmeldungen                                            |
|  - Statusanzeigen (Signal / LED)                            |
+-------------------------------------------------------------+
                 │
                 ▼
+-------------------------------------------------------------+
|   Logikschicht                                              |
|-------------------------------------------------------------|
| TemperatureController                                       |
|   - Koordination Regelung & Sicherheit                      |
|   - Zieltemperatur-Überwachung                              |
|                                                             |
| SafetyManager                                               |
|   - Übertemperatur-Erkennung                                |
|   - Zeitkritische Sicherheitsabschaltung                    |
|   - Spannungsüberwachung                                    |
|                                                             |
| NotificationManager                                         |
|   - Auslösen akustischer / optischer Signale                |
+-------------------------------------------------------------+
                 │
                 ▼
+-------------------------------------------------------------+
|   Hardware-Abstraktionsschicht (HAL)                        |
|-------------------------------------------------------------|
| SensorReader      → Temperaturmessung                       |
| HeaterControl     → Heizelement (Ein/Aus)                   |
| DisplayDriver     → Textanzeige                             |
| AudioOutput       → akustisches Signal                      |
| LEDController     → optische Rückmeldung                    |
+-------------------------------------------------------------+
```
| **Komponente**            | **Requirements**                                 |
| ------------------------- | ------------------------------------------------ |
| **UserInterface**         | Req. 1.1, Req. 1.2, Req. 1.3, Req. 4.2                  |
| **TemperatureController** | Req. 2.1, Req. 2.2, Req. 2.3, Req. 3.1, Req. 3.2, Req. 3.4, Req. 5.4                     |
| **SafetyManager**         |  Req. 4.1, Req. 4.2, Req. 4.3, Req. 4.4
| **NotificationManager**   |  Req. 5.1, Req. 5.2, Req. 5.3, Req. 5.4
| **AudioOutput**           |  Req. 5.1, Req. 5.3, Req. 5.4
| **LEDController**         |  Req. 5.2                        
| **SensorInterface**       | Req. 2.1, Req. 3.3                                       |
| **HeaterControl**         | Req. 2.2, Req. 4.1                                         |
| **DisplayDriver**         | Req. 1.3, Req. 4.2                                         |

## Schnittstellenbeschreibung – Sprint 3

| Schnittstelle | Methode | Beschreibung |
|---------------|--------|--------------|
| TemperatureController → SafetyManager | checkSafetyStatus() | Prüft Temperatur- und Systemzustand |
| SafetyManager → HeaterControl | shutdownHeater() | Sofortiges Abschalten |
| SafetyManager → DisplayDriver | showWarning() | Anzeige von Warnmeldungen |
| TemperatureController → AudioOutput | playSignalTone() | Akustisches Signal |
| TemperatureController → LEDController | activateLED() | Optische Rückmeldung |

## Erkenntnisse Sprint 3

### Erkenntnis 1 – Sicherheit ist nicht mehr nur reaktiv
In Sprint 1 und 2 wurden Sicherheitsmechanismen hauptsächlich
als Reaktion auf Fehler betrachtet.

In Sprint 3 zeigt sich:
Sicherheitslogik muss dauerhaft und parallel zur Regelung laufen.

➡ SafetyManager wird dauerhaft aktiv eingebunden.

---

### Erkenntnis 2 – Nutzerfeedback ist Teil der Logik
Akustische und optische Signale sind keine reinen UI-Funktionen mehr,
sondern Teil der Systemreaktion.

➡ Signalisierung wird logisch gesteuert, nicht nur angezeigt.

---

### Erkenntnis 3 – Zeitverhalten wird kritisch
Mehrere Requirements definieren explizite Zeitgrenzen.

➡ Vorbereitung auf Timer- und Event-System in Sprint 4.

---

### Erkenntnis 4 – Traceability muss sprintbezogen sein
Eine rein funktionale Traceability reicht nicht mehr aus.

➡ Erweiterung der Matrix um Sprint- und Modulbezug.
