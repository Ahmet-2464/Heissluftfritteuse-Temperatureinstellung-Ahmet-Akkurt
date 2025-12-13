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

### 2.3 Black-Box/Systemtests (optional, nicht Teil von Sprint 1)

**Ziel:**  
Überprüfung des sichtbaren Systemverhaltens ohne Kenntnis der internen Implementierung.  
Beispiele (für spätere Sprints): Reaktion auf reale Nutzereingaben, Timing, Anzeigeverhalten.

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

### In-Scope (Sprint 1)

- Verarbeitung der Temperatureingabe  
- Begrenzung der Temperaturwerte  
- Weitergabe der Temperatur an die Anzeige  
- Aktivierung von LED und Signalton  
- Formatierte Temperaturanzeige  
- UI/Display-Kopplung  

### Out-of-Scope (Sprint 1)

- Echte Sensorhardware und Temperaturabnahme  
- Heizlogik oder Physik der Heißluftfritteuse  
- Zeitsteuerung / Timer / Heizprofil  
- Sicherheitsüberwachung (Übertemperatur etc.)  
- Black-Box-Systemtests am realen Gerät  




# Definition Testfälle inkl. betroffener Requirements



# Dokumentation der Ergebnisse


