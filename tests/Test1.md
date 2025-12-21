# Test 

## 1. Ziel der Tests

Ziel der Tests ist die Verifikation der korrekten Temperatureingabe, -anzeige und -rückmeldung in der Software der Heißluftfritteuse.  
Die Tests stellen sicher, dass:

- Temperatureingaben korrekt verarbeitet werden (Range-Check / algorithmische Korrektheit).
- Die Anzeige den gesetzten Temperaturwert richtig übernimmt.
- Benutzerfeedback (LED + Akustik) zuverlässig ausgelöst wird.
- UI-Komponente und Display-Komponente korrekt zusammenarbeiten.

## 2. Testarten und Abdeckung

### 2.1 Unit Tests (Modultests)

**Ziel:**  
Prüfung der kleinstmöglichen Testeinheiten im System, insbesondere der Methoden der Klasse `TouchInputHandler`.  
Damit soll sichergestellt werden, dass algorithmische Logik wie Temperaturbegrenzung, Wertevalidierung und Formatierung fehlerfrei arbeitet.

**Abgedeckte Aspekte:**  
- Prüfung der unteren und oberen Temperaturgrenzen (UT1, UT2)  
- Prüfung der korrekten Anzeigeformatierung (UT3)

Diese Tests fokussieren ausschließlich auf die Logik innerhalb einer einzelnen Klasse ohne Interaktion mit externen Komponenten.

---

### 2.2 Integration Tests

**Ziel:**  
Sicherstellung, dass UI-Komponente (TouchInputHandler) und Display-Komponente (DisplayController) technisch korrekt zusammenarbeiten, d. h.:

- Aufrufsyntax der öffentlichen Methoden stimmt.  
- Temperaturwerte werden richtig weitergegeben.  
- LEDs und Signale werden zuverlässig ausgelöst.

**Abgedeckte Aspekte:**  
- UI übergibt Temperatur korrekt an Display (IT1)  
- LED wird korrekt aktiviert (IT2)  
- Signalton wird korrekt ausgelöst (IT3)

---

## 3. Teststrategie

Die Teststrategie kombiniert automatisierte und manuelle Tests, um die Funktionsfähigkeit aller UI- und Display-relevanten Funktionen sicherzustellen.

### Vorgehen:

1. **Unit-Tests** für alle temperaturbezogenen Operationen:  
   - Grenzwerteingabe  
   - Formatierung  
   - Validierung  

2. **Integrationstests** nach jedem Sprint-Build:  
   - UI → Display → LED  
   - UI → Display → Signal  

3. **Regressionslauf** nach Änderungen am Temperaturmodell.

4. **Manuelle UI-Sichtprüfungen** für Anzeige- und Rückmeldetests.

---

### Testumgebung

- Entwicklungsumgebung: C++ (g++ / clang++)  
- Testframework: manueller Test + optional GTest  
- Hardware-Emulation: Software-Mock des Displays  
- Log-Ausgabe zur Verifikation von Signalen  
- Konsolen-Simulation der Kontrolllogik  
- Keine reale Heißluftfritteuse notwendig (Software-only in Sprint 1)

---

## 4. Testumfang

### In-Scope 

- Verarbeitung der Temperatureingabe  
- Begrenzung der Temperaturwerte  
- Weitergabe der Temperatur an die Anzeige  
- Aktivierung von LED und Signalton  
- Formatierte Temperaturanzeige  
- UI/Display-Kopplung  

### Out-of-Scope 

- Echte Sensorhardware und Temperaturabnahme  
- Heizlogik oder Physik der Heißluftfritteuse  
- Zeitsteuerung / Timer / Heizprofil  
- Sicherheitsüberwachung (Übertemperatur etc.)  
- Black-Box-Systemtests am realen Gerät  



# Definition Testfälle inkl. betroffener Requirements
[Testfälle](/docs/referenziert/Requirement_Engineering/Test/Testfälle.md)


# Dokumentation der Ergebnisse
[Testergebnisse](/docs/referenziert/Requirement_Engineering/Test/Testergebnisse.md)

