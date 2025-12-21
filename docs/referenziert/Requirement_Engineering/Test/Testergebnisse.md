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

## UT9 – SafetyManager erkennt Übertemperatur

**Ziel:**  
Erkennung einer kritischen Temperatur über dem Grenzwert.

**Ergebnis:**  
`checkSafetyStatus()` erkennt Temperatur > Grenzwert und setzt Fehlerstatus.

**Status:** Bestanden  
**Requirement:** 4.2

---

## UT10 – SafetyManager deaktiviert Heizung

**Ziel:**  
Automatische Abschaltung der Heizung im Fehlerfall.

**Ergebnis:**  
`heater->off()` wird sofort ausgeführt.

**Status:** Bestanden  
**Requirement:** 4.3

---

## UT11 – Warnmeldung wird angezeigt

**Ziel:**  
Anzeige einer visuellen Warnmeldung.

**Ergebnis:**  
`showWarning()` wird mit korrektem Text aufgerufen.

**Status:** Bestanden  
**Requirement:** 4.2

---

## UT12 – UI wird im Fehlerfall gesperrt

**Ziel:**  
Verhindern weiterer Benutzereingaben.

**Ergebnis:**  
`lockInput()` blockiert Temperatureingaben zuverlässig.

**Status:** Bestanden  
**Requirement:** 4.4

---

## UT13 – Akustisches Warnsignal wird ausgelöst

**Ziel:**  
Akustische Rückmeldung bei Sicherheitsereignissen.

**Ergebnis:**  
`playSignal()` wird korrekt ausgelöst.

**Status:** Bestanden  
**Requirement:** 5.1

---

## UT14 – LED wird im Fehlerzustand aktiviert

**Ziel:**  
Visuelle Anzeige eines Fehlerzustands.

**Ergebnis:**  
`activateLED(ERROR)` wird ausgeführt.

**Status:** Bestanden  
**Requirement:** 5.2

---

## UT15 – Signal nach Zieltemperatur

**Ziel:**  
Akustische Rückmeldung nach Erreichen der Zieltemperatur.

**Ergebnis:**  
`signalAfterTargetTemp()` wird ausgelöst.

**Status:** Bestanden  
**Requirement:** 5.4

---

## UT16 – Signal-Lautstärke wird korrekt überwacht

**Ziel:**  
Sicherstellen, dass das akustische Signal die geforderte Lautstärke einhält.

**Ergebnis:**  
`measureSignalVolume()` liefert einen Wert innerhalb des definierten Grenzbereichs.

**Status:** Bestanden  
**Requirement:** 5.3

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

## IT9 – Temperaturüberschreitung löst Warnkette aus

**Ziel:**  
Überprüfung der vollständigen Reaktionskette.

**Ergebnis:**  
SafetyManager → Display → Audio → UI-Sperre.

**Status:** Bestanden  
**Requirement:** 4.2 / 4.4 / 5.1

---

## IT10 – Sicherheitsabschaltung der Heizung

**Ziel:**  
Abschaltung der Heizung bei kritischer Temperatur.

**Ergebnis:**  
Heizung wird deaktiviert, Status aktualisiert.

**Status:** Bestanden  
**Requirement:** 4.3

---

## IT11 – LED + Audio Synchronisation

**Ziel:**  
Gleichzeitige visuelle und akustische Rückmeldung.

**Ergebnis:**  
LED und Signal werden gemeinsam aktiviert.

**Status:** Bestanden  
**Requirement:** 5.1 / 5.2

---

## IT12 – Signal-Lautstärkeprüfung im Systemkontext

**Ziel:**  
Überprüfung der Signal-Lautstärke im Zusammenspiel mehrerer Komponenten.

**Ergebnis:**  
`measureSignalVolume()` bestätigt normgerechte Lautstärke nach Signalausgabe.

**Status:** Bestanden  
**Requirement:** 5.3

---

## IT13 – Zieltemperatur erreicht löst akustisches Signal aus

**Ziel:**  
Überprüfung, dass beim Erreichen der Solltemperatur automatisch ein akustisches Signal ausgelöst wird.

**Vorbedingung:**  
- Solltemperatur = 180°C  
- Isttemperatur steigt von 175°C auf 180°C  
- System befindet sich im aktiven Heizbetrieb

**Aktion:**  
- `TemperatureController.update()` verarbeitet neuen Sensorwert (180°C)

**Erwartetes Ergebnis:**  
- Zieltemperatur wird erkannt  
- `signalAfterTargetTemp()` wird aufgerufen  
- AudioOutput gibt Bestätigungssignal aus

**Status:** Bestanden  
**Requirement:** 5.4






