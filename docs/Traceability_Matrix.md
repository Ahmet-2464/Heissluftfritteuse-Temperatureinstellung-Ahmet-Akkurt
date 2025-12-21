# Traceability-Matrix

| Requirement-ID | Sprint | Modul / Schicht | Klasse(n) | Schnittstelle(n) | Testfall(e) |
|----------------|--------|------------------|------------|------------------|--------------|
| 1.1 | Sprint 1 | UI | TouchInputHandler | onTemperatureInput() | UT1, UT2 |
| 1.2 | Sprint 1 | UI | DisplayController | updateDisplay() | UT3 |
| 1.3 | Sprint 1 | UI | DisplayController | showStatus() | IT3 |
| 2.1 | Sprint 1 / 2 | Anzeige | DisplayController | activateLED() | IT2 |
| 2.2 | Sprint 1 / 2 | Anzeige | DisplayController | updateDisplay() | IT1 |
| 2.3 | Sprint 1 / 2 | Anzeige | DisplayController | playSignal() | IT3 |
| 2.4 | Sprint 2 | Anzeige | DisplayController | render() | UT4, UT5, IT4 |
| 3.1 | Sprint 2 | Sicherheit | SafetyManager | checkSafetyStatus() | UT6, IT5 |
| 3.2 | Sprint 2 | Sicherheit | SafetyManager | triggerShutdown() | UT7, IT6 |
| 3.3 | Sprint 2 / 3 | Sicherheit | SafetyManager | logSafetyEvent() | IT8 |
| 3.4 | Sprint 2 / 3 | Sicherheit / Anzeige | SafetyManager, DisplayController | showWarning() | IT7 |
| 4.1 | Sprint 2 / 3 | Sensorik | SensorInterface | readTemperature() | UT8, IT4 |
| 4.2 | Sprint 3 | Sicherheit | SafetyManager | showOverheatWarning() | IT9 |
| 4.3 | Sprint 3 | Sicherheit | SafetyManager | triggerSafetyShutdown() | UT10, IT10 |
| 4.4 | Sprint 3 | Sicherheit / UI | SafetyManager, UserInterface | lockUserInput() | UT12, IT9, IT11 |
| 5.1 | Sprint 3 | Signalisierung | AudioOutput | playSignalTone() | UT13, IT11 |
| 5.2 | Sprint 3 | Signalisierung | LEDController | activateLED() | UT14, IT11 |
| 5.3 | Sprint 3 | Signalisierung | AudioOutput | measureSignalVolume() | UT16, IT12 |
| 5.4 | Sprint 3 | Signalisierung | AudioOutput | signalAfterTargetTemp() | UT15, IT13 |
