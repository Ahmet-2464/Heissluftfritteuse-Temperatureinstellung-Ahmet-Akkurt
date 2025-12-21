# Test 

## 1. Ziel der Tests

Ziel dieser Testphase ist die Verifikation aller in Sprint 3 eingeführten
Sicherheits-, Anzeige- und Rückmeldefunktionen.

Der Fokus liegt auf:

- der korrekten Anzeige von Warn- und Statusmeldungen,
- der zuverlässigen Sicherheitsabschaltung bei kritischen Zuständen,
- der Sperrung von Benutzereingaben im Fehlerfall,
- der akustischen und visuellen Rückmeldung an den Benutzer.

Die Tests bauen auf der stabilen Regelungs- und Sensoriklogik aus Sprint 2 auf
und erweitern das System um benutzernahe Sicherheitsfunktionen.

---

## 2. Testarten und Abdeckung

### 2.1 Unit Tests (Modultests)

**Ziel:**  
Prüfung einzelner Methoden der Sprint-3-Module ohne Systemkontext.

**Getestete Klassen:**
- SafetyManager
- DisplayDriver
- UserInterface (Input-Locking)
- AudioOutput
- LEDController

**Abgedeckte Aspekte:**

- Erkennung kritischer Zustände (UT1)
- Abschaltung der Heizung (UT2)
- Logging von Sicherheitsereignissen (UT3)
- Anzeige von Warnmeldungen (UT4)
- UI-Sperrlogik (UT5)
- Signalausgabe (UT6–UT8)

---

### 2.2 Integration Tests

**Ziel:**  
Überprüfung des vollständigen Sicherheits- und Rückmeldepfades
über mehrere Komponenten hinweg.

**Abgedeckte Aspekte:**

- TemperatureController → SafetyManager
- SafetyManager → DisplayDriver
- SafetyManager → HeaterControl
- SafetyManager → UserInterface
- SafetyManager → Audio/LED

---

### 2.3 Black-Box/Systemtests (optional)

Diese Tests sind für Sprint 3 nicht Teil des formalen Umfangs,
bilden aber die Grundlage für spätere Geräte- und UI-Tests.

---

## 3. Teststrategie

Die Teststrategie kombiniert:

1. **Unit-Tests** für sicherheitskritische Methoden  
2. **Integrationstests** für komplette Reaktionsketten  
3. **Manuelle Sichtprüfung** der Display- und Konsolenausgaben  
4. **Regressionsprüfung**, um Sprint-2-Funktionen nicht zu beeinträchtigen  

---

### Testumgebung

- Programmiersprache: C++
- Compiler: g++
- Hardware: keine (Simulation)
- Mocks: MockHeater, MockDisplay, MockAudio
- Ausgabe: Konsole / Log
- Architektur gemäß Sprint-3-Design

---

## 4. Testumfang

### In-Scope (Sprint 3)

- Sicherheitswarnungen
- Heizungsabschaltung
- UI-Sperrmechanismus
- Akustische Signale
- LED-Statusanzeigen
- Sicherheitslogging

---

### Out-of-Scope (Sprint 3)

- Regelungsalgorithmen
- reale Sensorhardware
- zeitkritische Echtzeitanforderungen
- komplexe Zustandsautomaten

---

# Definition Testfälle inkl. betroffener Requirements
[Testfälle](/docs/referenziert/Requirement_Engineering/Test/Testfälle.md)


# Dokumentation der Ergebnisse
[Testergebnisse](/docs/referenziert/Requirement_Engineering/Test/Testergebnisse.md)