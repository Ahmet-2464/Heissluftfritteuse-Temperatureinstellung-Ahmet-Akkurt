# 5. Testergebnisse 

# Unit-Tests

## UT1 – Temperaturuntergrenze

**Ziel:**  
Sicherstellen, dass Temperatureingaben unterhalb 0°C korrekt auf die erlaubte Untergrenze begrenzt werden.

**Ergebnis:**  
Die Methode `TemperaturEingabe(-20)` setzt den internen Wert wie erwartet auf 0°C und verhindert negative Temperaturen zuverlässig.

**Status:** Bestanden  
**Requirement:** 1.1

---

## UT2 – Temperaturobergrenze

**Ziel:**  
Prüfen, ob Temperatureingaben oberhalb 300°C zuverlässig auf 300°C begrenzt werden.

**Ergebnis:**  
Die Methode `TemperaturEingabe(500)` korrigiert den Wert korrekt auf 300°C.  
Das System akzeptiert keine überhöhten Eingaben.

**Status:** Bestanden  
**Requirement:** 1.1

---

## UT3 – Formatierte Temperaturanzeige

**Ziel:**  
Verifikation der korrekten String-Ausgabe bei gesetzter Temperatur.

**Ergebnis:**  
Bei gespeicherten 180°C liefert `TemperaturAnzeige()` den korrekt formatierten Anzeigetext `"Temperatur: 180°C"`.

**Status:** Bestanden  
**Requirement:** 1.2


---

## UT4 – Heizungsregelung: Heizung EIN bei niedriger Ist-Temperatur

**Ziel:**  
Überprüfen, dass der TemperatureController die Heizung aktiviert, wenn die Isttemperatur deutlich unter der Solltemperatur liegt.

**Ergebnis:**  
Bei Ist = 140°C und Soll = 180°C schaltet `update()` die Heizung korrekt EIN.

**Status:** Bestanden  
**Requirement:** 2.4

---

## UT5 – Heizungsregelung: Heizung AUS bei Überschreitung der Solltemperatur

**Ziel:**  
Sicherstellen, dass die Heizung deaktiviert wird, wenn die Isttemperatur über der Solltemperatur liegt.

**Ergebnis:**  
Bei Ist = 185°C schaltet `update()` die Heizung zuverlässig AUS.

**Status:** Bestanden  
**Requirement:** 2.4

---

## UT6 – SafetyManager erkennt kritische Temperatur

**Ziel:**  
Überprüfung, ob der SafetyManager einen kritischen Temperaturwert (z. B. > 250°C) korrekt erkennt.

**Ergebnis:**  
Der SafetyManager setzt das interne Sicherheitsflag und markiert den Zustand korrekt als kritisch.

**Status:** Bestanden  
**Requirement:** 3.1

---

## UT7 – SafetyManager deaktiviert Heizung im Gefahrenfall

**Ziel:**  
Sicherstellen, dass bei kritischer Temperatur automatisch die Heizleistung deaktiviert wird.

**Ergebnis:**  
Bei Ist = 260°C schaltet `update()` die Heizung zuverlässig AUS und trägt einen entsprechenden Log-Eintrag ein.

**Status:** Bestanden  
**Requirement:** 3.2

---

## UT8 – SensorInterface liefert korrekte Temperaturwerte

**Ziel:**  
Prüfen, ob Sensordaten korrekt ausgelesen und an die Steuerlogik weitergegeben werden.

**Ergebnis:**  
MockSensor gibt den simulierten Wert (150°C) präzise weiter.

**Status:** Bestanden  
**Requirement:** 4.1

---

# Integrations-Tests

## IT1 – Übergabe Temperatur UI → Display

**Ziel:**  
Sicherstellen, dass vom Benutzer eingegebene Temperaturen korrekt an den `DisplayController` weitergegeben werden und dort gerendert werden.

**Ergebnis:**  
Der vom UI gesetzte Wert 150°C wurde korrekt über die Schnittstelle `aktualisiereAnzeige()` übertragen und im Display-Modul dargestellt.

**Status:** Bestanden  
**Requirement:** 2.2

---

## IT2 – LED-Aktivierung durch UI

**Ziel:**  
Überprüfung, ob bei Temperatureinstellung die LED über den DisplayController korrekt aktiviert wird.

**Ergebnis:**  
Beim Setzen einer Temperatur von 200°C wurde `aktiviereLED()` wie vorgesehen ausgelöst und die LED korrekt auf ON geschaltet.

**Status:** Bestanden  
**Requirement:** 2.1

---

## IT3 – Signalton bei Eingabebestätigung

**Ziel:**  
Prüfen, ob das UI beim Bestätigen der Temperatureingabe das akustische Signal über den DisplayController korrekt auslöst.

**Ergebnis:**  
Die Methode `spieleSignal()` wurde wie erwartet aufgerufen.  
Das System erzeugte den vorgesehenen Benachrichtigungston (Simulation/Log).

**Status:** Bestanden  
**Requirement:** 2.3

## IT4 – Sensor → TemperatureController

**Ziel:**  
Verifikation, dass Sensordaten korrekt in den TemperatureController übernommen werden und die Heizlogik richtig reagiert.

**Ergebnis:**  
Der Controller übernimmt den Sensorwert (130°C) korrekt und aktiviert die Heizung wie erwartet.

**Status:** Bestanden  
**Requirement:** 2.4 / 4.1

---

## IT5 – TemperatureController → SafetyManager (Warnung)

**Ziel:**  
Sicherstellen, dass der SafetyManager bei überkritischen Temperaturen eine Warnung auslöst.

**Ergebnis:**  
Bei Sensordaten > 250°C wird der SafetyManager ausgelöst und die Warnlogik aktiviert.

**Status:** Bestanden  
**Requirement:** 3.1

---

## IT6 – SafetyManager → HeaterControl (Abschaltung)

**Ziel:**  
Überprüfen, ob die Heizung zuverlässig deaktiviert wird, wenn der SafetyManager einen kritischen Zustand erkennt.

**Ergebnis:**  
Der SafetyManager ruft korrekt die Abschaltfunktion des Heizers auf.

**Status:** Bestanden  
**Requirement:** 3.2

---

## IT7 – SafetyManager → DisplayDriver (Warnmeldung)

**Ziel:**  
Verifikation, dass sicherheitskritische Zustände im Display angezeigt werden.

**Ergebnis:**  
`showWarning("Überhitzung!")` wurde korrekt aufgerufen und im Display-Mock sichtbar gemacht.

**Status:** Bestanden  
**Requirement:** 3.4

---

## IT8 – Logging eines Sicherheitsereignisses

**Ziel:**  
Sicherstellen, dass kritische Temperaturereignisse zuverlässig im Systemlog protokolliert werden.

**Ergebnis:**  
Beim Erreichen von 250°C wurde der Logeintrag korrekt erzeugt.

**Status:** Bestanden  
**Requirement:** 3.3

---







# 6. Traceability-Matrix – Sprint 2

| Requirement-ID | Jira | Komponente | Klasse | Schnittstelle | Testfall(e) |
|----------------|------|------------|--------|----------------|-------------|
| 2.4 | TEMP-8 | Regelung | TemperatureController | update() | UT1, UT2, IT1 |
| 3.1 | SAFE-1 | Safety | SafetyManager | checkSafetyConditions() | UT3, IT2 |
| 3.2 | SAFE-2 | Safety | SafetyManager | update(), heater->off() | UT4, IT3 |
| 3.3 | SAFE-3 | Safety | SafetyManager | logEvent() | IT5 |
| 3.4 | SAFE-4 | Safety/UI | SafetyManager + DisplayDriver | showWarning() | IT4 |
| 4.1 | TEMP-9 | Sensorik | SensorInterface | readTemperature() | UT5, IT1 |

