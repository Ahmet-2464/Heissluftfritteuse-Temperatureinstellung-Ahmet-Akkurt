# Traceability-Matrix

| Requirement-ID | Jira-Issue | Komponente | Klasse(n) | Schnittstelle(n) | Testfall(e) |
|----------------|-------------|-------------|-------------|------------------|--------------|
| 1.1 | TEMP-1 | UserInterface | `TouchInputHandler` | `readUserTemperature()` | UI1 |
| 1.2 | TEMP-2 | UserInterface | `TouchInputHandler` | `validateTemperatureRange()` | UI2 |
| 1.3 | TEMP-3 | UserInterface | `TouchInputHandler` | `processInput()` | NF1 |
| 1.4 | TEMP-4 | UserInterface | `TouchPanel` | `checkDurability()` | NF2 |
| 2.1 | TEMP-5 | DisplayDriver | `DisplayController` | `showSetTemperature()` | UI3 |
| 2.2 | TEMP-6 | DisplayDriver | `DisplayController` | `updateDisplay()` | UI4 |
| 2.3 | TEMP-7 | DisplayDriver | `DisplayController` | `adjustBrightness()` | NF3 |
| 2.4 | TEMP-8 | DisplayDriver | `DisplayController` | `refreshAfterInput()` | NF4 |
| 3.1 | TEMP-9 | TemperatureController, HeaterControl | `HeaterControl`, `TemperatureController` | `heatToTarget()` | TC1 |
| 3.2 | TEMP-10 | TemperatureController, SensorInterface | `TemperatureController` | `maintainTemperature()` | TC2 |
| 3.3 | TEMP-11 | SensorInterface | `SensorReader` | `measureTemperature()` | NF5 |
| 3.4 | TEMP-12 | TemperatureController | `HeaterControl` | `calculateHeatingTime()` | NF6 |
| 4.1 | TEMP-13 | SafetyManager, HeaterControl | `SafetyManager` | `shutdownOnOverTemp()` | SF1 |
| 4.2 | TEMP-14 | SafetyManager, DisplayDriver | `SafetyManager`, `DisplayController` | `showOverheatWarning()` | SF2 |
| 4.3 | TEMP-15 | SafetyManager | `SafetyManager` | `triggerSafetyShutdown()` | NF7 |
| 4.4 | TEMP-16 | SafetyManager | `SafetyManager` | `checkPowerFluctuations()` | NF8 |
| 5.1 | TEMP-17 | DisplayDriver | `AudioOutput` | `playSignalTone()` | UX1 |
| 5.2 | TEMP-18 | DisplayDriver | `LEDController` | `activateLED()` | UX2 |
| 5.3 | TEMP-19 | DisplayDriver | `AudioOutput` | `measureSignalVolume()` | NF9 |
| 5.4 | TEMP-20 | DisplayDriver | `AudioOutput` | `signalAfterTargetTemp()` | NF10 |
