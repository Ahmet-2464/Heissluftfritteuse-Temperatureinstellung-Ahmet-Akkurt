# Test 

## 1. Ziel der Tests

Ziel dieser Testphase ist die vollständige Verifikation der neuen Regelungs- und Sicherheitsfunktionen aus Sprint 2.  
Es soll überprüft werden, dass:

- der TemperatureController Soll- und Istwerte richtig verarbeitet (Regelungslogik),
- der SafetyManager Übertemperatur erkennt und korrekt reagiert,
- Warnmeldungen und Displayanzeigen wie gefordert funktionieren,
- die Heizleistung automatisch deaktiviert wird,
- Sensorwerte korrekt eingelesen und weiterverarbeitet werden.

---

## 2. Testarten und Abdeckung

### 2.1 Unit Tests (Modultests)

**Ziel:**  
Sicherstellen der Funktionsfähigkeit der einzelnen Softwaremodule (TemperatureController, SafetyManager, SensorInterface).  
Es wird überprüft, ob zentrale Logikmodule ohne externe Abhängigkeiten korrekt arbeiten.

**Abgedeckte Aspekte:**  
- Heizungsregelung basierend auf Soll/Ist (UT1, UT2)  
- Sicherheitslogik (Warnung + Abschaltung) (UT3, UT4)  
- korrekte Sensordatenverarbeitung (UT5)

Diese Tests stellen sicher, dass jedes Modul isoliert korrekt funktioniert.

---

### 2.2 Integration Tests

**Ziel:**  
Verifikation der Zusammenarbeit zwischen Controller, Sensor, SafetyManager und Display.  
Dabei wird geprüft:

- ob Temperaturdaten korrekt vom Sensor in den Controller gelangen,
- ob die Logik des SafetyManagers in der gesamten Kette korrekt greift,
- ob Display und Logging auf sicherheitskritische Ereignisse reagieren,
- ob die Heizungsabschaltung korrekt durch die Safety-Schicht erfolgt.

**Abgedeckte Aspekte:**  
- Sensor → TemperatureController (IT1)  
- TemperatureController → SafetyManager (IT2)  
- SafetyManager → HeaterControl (IT3)  
- SafetyManager → Display (IT4)  
- SafetyManager → Logging (IT5)

---

### 2.3 Black-Box/Systemtests (optional)

**Ziel:**  
Überprüfung des Gesamtsystems aus Benutzersicht.  
Diese Tests sind für Sprint 2 noch nicht Teil des Umfangs, aber Basis für spätere Sprints.

---

## 3. Teststrategie

Die Teststrategie kombiniert modulare und integrative Tests, um Sicherheits- und Regelungslogik zuverlässig zu prüfen.

### Vorgehen:

1. **Unit-Tests** aller sicherheitskritischen Methoden  
   - Temperaturregelung  
   - Grenzwertüberwachung  
   - Logging  

2. **Integrationstests** für den gesamten Temperaturfluss  
   Sensor → Controller → Safety → Display/Heizung  

3. **Manuelle Sichtprüfung**  
   - Display-Warnmeldungen  
   - Konsolenlogs  

4. **Regressionslauf**  
   Nach Anpassung der Safety- und Regelungslogik.

---

### Testumgebung

- Entwicklungsumgebung: C++ (g++, Clang)  
- Testhardware: Software-only, MockSensor, MockHeater, MockDisplay  
- Werkzeuge: Terminal-Log, Konsolenausgabe  
- Keine physische Heißluftfritteuse erforderlich  
- Testframework (optional): GoogleTest  
- Umgebung entspricht den Architekturentscheidungen von Sprint 2

---

## 4. Testumfang

### In-Scope (Sprint 2)

- Soll-/Ist-Regelungslogik  
- Sensor-Datenverarbeitung  
- Übertemperaturerkennung  
- Sicherheitsabschaltung der Heizung  
- Warnmeldungen im Display  
- Safety-Logging  
- SafetyManager/TemperatureController Integration

### Out-of-Scope (Sprint 2)

- reale Hardware-Sensoren  
- physikalisches Heizverhalten  
- Black-Box-Systemtests  
- UI-Interaktionen (Touch, Buttons)  
- Timer-/Zeitsteuerung  
- vollständige Heizzustandsmodelle

---

# Definition Testfälle inkl. betroffener Requirements
[Testfälle](/docs/referenziert/Requirement_Engineering/Test/Testfälle.md)


# Dokumentation der Ergebnisse
[Testergebnisse](/docs/referenziert/Requirement_Engineering/Test/Testergebnisse.md)



