# Traceability-Matrix

| Requirement-ID | Jira-Issue | Komponente | Klasse(n) | Schnittstelle(n) | Testfall(e) |
|----------------|-------------|-------------|-------------|------------------|--------------|
| 1.1 | TEMP-1 | UserInterface | `TouchInputHandler` | `TemperaturEingabe()` | UT1, UT2 |
| 1.2 | TEMP-2 | UserInterface | `TouchInputHandler` | `TemperaturAnzeige()` | UT3 |
| 1.3 | TEMP-3 | UserInterface | `TouchInputHandler` | `RueckmeldungAnNutzer()` | IT3 |
| 2.1 | TEMP-5 | DisplayDriver | `DisplayController` | `aktiviereLED()` | IT2 |
| 2.2 | TEMP-6 | DisplayDriver | `DisplayController` | `aktualisiereAnzeige()` | IT1 |
| 2.3 | TEMP-7 | DisplayDriver | `DisplayController` | `spieleSignal()` | IT3 |
| 2.4 | TEMP-8 | DisplayDriver | `DisplayController` | `refreshAfterInput()` | - |
| 3.1 | TEMP-9 | TemperatureController, HeaterControl | `HeaterControl`, `TemperatureController` | `heatToTarget()` | - |
| 3.2 | TEMP-10 | TemperatureController, SensorInterface | `TemperatureController` | `maintainTemperature()` | - |
| 3.3 | TEMP-11 | SensorInterface | `SensorReader` | `measureTemperature()` | - |
| 3.4 | TEMP-12 | TemperatureController | `HeaterControl` | `calculateHeatingTime()` | - |
| 4.1 | TEMP-13 | SafetyManager, HeaterControl | `SafetyManager` | `shutdownOnOverTemp()` | - |
| 4.2 | TEMP-14 | SafetyManager, DisplayDriver | `SafetyManager`, `DisplayController` | `showOverheatWarning()` | - |
| 4.3 | TEMP-15 | SafetyManager | `SafetyManager` | `triggerSafetyShutdown()` | - |
| 4.4 | TEMP-16 | SafetyManager | `SafetyManager` | `checkPowerFluctuations()` | - |
| 5.1 | TEMP-17 | DisplayDriver | `AudioOutput` | `playSignalTone()` | - |
| 5.2 | TEMP-18 | DisplayDriver | `LEDController` | `activateLED()` | - |
| 5.3 | TEMP-19 | DisplayDriver | `AudioOutput` | `measureSignalVolume()` | - |
| 5.4 | TEMP-20 | DisplayDriver | `AudioOutput` | `signalAfterTargetTemp()` | - |
