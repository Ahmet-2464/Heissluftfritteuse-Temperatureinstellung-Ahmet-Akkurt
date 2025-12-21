# 3. Testfälle – Modul-/Unit-Ebene (16 Stück)

## UT1 – Temperaturuntergrenze wird korrekt behandelt  
**Requirement:** 1.1  
**Komponente/Klasse:** UserInterface / TouchInputHandler  
**Methode:** TemperaturEingabe()  

### Vorbedingung
- `TouchInputHandler` ist initialisiert.
- Keine Temperatur gesetzt (default = 0).

### Aktion
- Eingabe: `TemperaturEingabe(-20)` (unterhalb erlaubter Grenze 0°C).

### Erwartetes Ergebnis
- Wert wird auf **0°C** begrenzt.
- Keine Fehlermeldung.

### Nachbedingung
- interner Temperaturwert == 0°C.

### Status
✔ **Bestanden**  
Die Methode clampte den Wert korrekt auf 0.

---

## UT2 – Temperaturobergrenze wird korrekt behandelt  
**Requirement:** 1.1  
**Komponente/Klasse:** UserInterface / TouchInputHandler  
**Methode:** TemperaturEingabe()  

### Vorbedingung
- Standardzustand (`temp = 0`).

### Aktion
- Eingabe: `TemperaturEingabe(500)` (oberhalb max. 300°C).

### Erwartetes Ergebnis
- Temperatur wird auf **300°C** begrenzt.

### Nachbedingung
- interner Temperaturwert == 300°C.

### Status
✔ **Bestanden**

---

## UT3 – Temperaturanzeige formatiert korrekt  
**Requirement:** 1.2  
**Komponente/Klasse:** TouchInputHandler  
**Methode:** TemperaturAnzeige()  

### Vorbedingung
- Eingestellte Temperatur = 180°C.

### Aktion
- Aufruf von `TemperaturAnzeige()`.

### Erwartetes Ergebnis
- Rückgabe eines formatierten Strings, z. B.: `"Temperatur: 180°C"`.

### Nachbedingung
- Konsistente Ausgabe bei wiederholtem Aufruf.

### Status
✔ **Bestanden**

# 3. Testfälle – Modul-/Unit-Ebene

---

## **UT4 – Regelungslogik: Heizung EIN bei niedriger Ist-Temperatur**
**Requirement:** 2.4  
**Komponente/Klasse:** TemperatureController  
**Methode:** update()

### Vorbedingung
- Solltemperatur = 180°C  
- Isttemperatur = 140°C  
- Heizung ist AUS

### Aktion
- update() ausführen

### Erwartetes Ergebnis
- Heizung wird **EIN** geschaltet  
- Display zeigt „Heizung aktiv“

### Status
✔ Bestanden

---

## **UT5 – Regelungslogik: Heizung AUS bei Überschreiten der Solltemperatur**
**Requirement:** 2.4  
**Komponente/Klasse:** TemperatureController

### Vorbedingung
- Soll = 180°C  
- Ist = 185°C  
- Heizung EIN

### Aktion
- update()

### Erwartetes Ergebnis
- Heizung wird **AUS** geschaltet  
- Display aktualisiert den Status

### Status
✔ Bestanden

---

## **UT6 – SafetyManager erkennt kritische Temperatur**
**Requirement:** 3.1  
**Komponente:** SafetyManager  
**Methode:** checkSafetyConditions()

### Vorbedingung
- Isttemperatur = 250°C (kritischer Grenzwert überschritten)

### Aktion
- checkSafetyConditions() ausführen

### Erwartetes Ergebnis
- Sicherheitsflag gesetzt (`isCritical == true`)

### Status
✔ Bestanden

---

## **UT7 – SafetyManager deaktiviert Heizung bei kritischer Temperatur**
**Requirement:** 3.2

### Vorbedingung
- Heizung EIN  
- Isttemperatur = 260°C

### Aktion
- update()

### Erwartetes Ergebnis
- Heizung wird sofort auf **AUS** gesetzt  
- Log-Eintrag erstellt

### Status
✔ Bestanden

---

## **UT8 – SensorInterface liefert korrekte Temperaturwerte**
**Requirement:** 4.1  
**Komponente:** MockSensor / SensorInterface

### Vorbedingung
- Sensorwert simuliert = 150°C

### Aktion
- Temperatur auslesen

### Erwartetes Ergebnis
- Rückgabewert == 150°C

### Status
✔ Bestanden

---

## UT9 – Übertemperatur wird erkannt und gemeldet  
**Requirement:** 4.2  
**Komponente/Klasse:** SafetyManager  
**Methode:** checkSafetyStatus()  

### Vorbedingung
- SafetyManager ist initialisiert.
- Kritischer Grenzwert = 250°C.
- Kein Fehlerzustand aktiv.

### Aktion
- Isttemperatur = 255°C an SafetyManager übergeben.

### Erwartetes Ergebnis
- Übertemperatur wird erkannt.
- Sicherheitsstatus wird auf *kritisch* gesetzt.

### Nachbedingung
- `isCritical == true`.

### Status
✔ **Bestanden**  
Die Übertemperatur wurde korrekt erkannt.

---

## UT10 – Sicherheitsabschaltung der Heizung bei Übertemperatur  
**Requirement:** 4.3  
**Komponente/Klasse:** SafetyManager  
**Methode:** update()  

### Vorbedingung
- Heizung ist EIN.
- Kritische Temperatur liegt an (z. B. 260°C).

### Aktion
- Aufruf von `update()`.

### Erwartetes Ergebnis
- Heizung wird sofort abgeschaltet.

### Nachbedingung
- Heizstatus == AUS.

### Status
✔ **Bestanden**

---


## UT11 – Warnmeldung wird auf dem Display angezeigt  
**Requirement:** 4.2  
**Komponente/Klasse:** DisplayDriver  
**Methode:** showWarning()  

### Vorbedingung
- DisplayDriver ist initialisiert.
- Kein aktiver Warnhinweis.

### Aktion
- `showWarning("Überhitzung!")` aufrufen.

### Erwartetes Ergebnis
- Warntext wird angezeigt.

### Nachbedingung
- Display befindet sich im Warnzustand.

### Status
✔ **Bestanden**

---

## UT12 – Benutzereingaben werden im Fehlerfall gesperrt  
**Requirement:** 4.4  
**Komponente/Klasse:** UserInterface  
**Methode:** lockInput()  

### Vorbedingung
- Fehlerzustand aktiv.
- UI ist initialisiert.

### Aktion
- Benutzer versucht Temperatureingabe.

### Erwartetes Ergebnis
- Eingabe wird blockiert.

### Nachbedingung
- Keine Änderung der Solltemperatur.

### Status
✔ **Bestanden**

---

## UT13 – Akustisches Warnsignal wird ausgelöst  
**Requirement:** 5.1  
**Komponente/Klasse:** AudioOutput  
**Methode:** playSignal()  

### Vorbedingung
- Audiosystem ist bereit.
- Kein aktives Signal.

### Aktion
- Sicherheitsereignis auslösen.

### Erwartetes Ergebnis
- Akustisches Warnsignal wird abgespielt.

### Nachbedingung
- Signalstatus = aktiv.

### Status
✔ **Bestanden**

---

## UT14 – LED zeigt Fehlerzustand an  
**Requirement:** 5.2  
**Komponente/Klasse:** LEDController  
**Methode:** activateLED()  

### Vorbedingung
- LED ist AUS.

### Aktion
- Fehlerzustand aktivieren.

### Erwartetes Ergebnis
- Fehler-LED wird eingeschaltet.

### Nachbedingung
- LED-Zustand = ERROR / ON.

### Status
✔ **Bestanden**

---

## UT15 – Signal nach Erreichen der Zieltemperatur  
**Requirement:** 5.4  
**Komponente/Klasse:** AudioOutput  
**Methode:** signalAfterTargetTemp()  

### Vorbedingung
- Solltemperatur = 180°C.
- Isttemperatur = 180°C.

### Aktion
- Zieltemperatur erreicht.

### Erwartetes Ergebnis
- Bestätigungssignal wird abgespielt.

### Nachbedingung
- Signal wurde genau einmal ausgelöst.

### Status
✔ **Bestanden**

---

## UT16 – Lautstärke des akustischen Signals wird überprüft  
**Requirement:** 5.3  
**Komponente/Klasse:** AudioOutput  
**Methode:** measureSignalVolume()  

### Vorbedingung
- Audiosystem ist initialisiert.
- Signal wurde abgespielt.

### Aktion
- `measureSignalVolume()` ausführen.

### Erwartetes Ergebnis
- Gemessene Lautstärke liegt innerhalb des definierten Bereichs (z. B. 70–90 dB).

### Nachbedingung
- Lautstärkewert ist gültig und dokumentiert.

### Status
✔ **Bestanden**

# 4. Testfälle – Integrationsebene (13 Stück)

## IT1 – UI übergibt Temperatur korrekt an Displaykomponente  
**Requirement:** 2.2  
**Komponenten:** UserInterface ↔ DisplayDriver  
**Klassen:** TouchInputHandler ↔ DisplayController  
**Schnittstelle:** aktualisiereAnzeige()  

### Vorbedingung
- DisplayController initialisiert.
- UI hat Temperatur = 150°C gespeichert.

### Aktion
- `TouchInputHandler::TemperaturAnzeige()` löst Update an DisplayController aus.

### Erwartetes Ergebnis
- DisplayController erhält Wert 150°C und rendert Text korrekt.

### Nachbedingung
- Displaywert entspricht UI-Wert.

### Status
✔ **Bestanden**

---

## IT2 – UI aktiviert LED korrekt beim Setzen der Temperatur  
**Requirement:** 2.1  
**Schnittstelle:** aktiviereLED()  
**Komponenten:** UserInterface ↔ DisplayDriver  

### Vorbedingung
- Display-LED ist AUS.
- Temperatureingabe = 0°C.

### Aktion
- Benutzer setzt Temperatur auf 200°C.

### Erwartetes Ergebnis
- `DisplayController::aktiviereLED()` wird aufgerufen.
- LED wechselt auf "ACTIVE".

### Nachbedingung
- LED = ON.

### Status
✔ **Bestanden**

---

## IT3 – UI löst Signalton korrekt aus  
**Requirement:** 1.3 + 2.3  
**Schnittstelle:** spieleSignal()  
**Komponenten:** TouchInputHandler ↔ DisplayController  

### Vorbedingung
- Keinerlei Sounds aktiv.
- Temperatur = 0°C.

### Aktion
- Benutzer bestätigt Eingabe 180°C → UI ruft `spieleSignal()` auf.

### Erwartetes Ergebnis
- DisplayController spielt kurzen Benachrichtigungston.

### Nachbedingung
- Soundflag/Logfile zeigt „Signal abgespielt“.

### Status
✔ **Bestanden**


## **IT4 – Sensor → TemperatureController verarbeitet Sensordaten korrekt**
**Requirement:** 4.1 + 2.4  
**Komponenten:** SensorInterface → TemperatureController

### Vorbedingung
- Sensor meldet 130°C  
- Solltemperatur = 200°C

### Aktion
- controller.update()

### Erwartetes Ergebnis
- Controller übernimmt Isttemperatur  
- Heizlogik aktiviert Heizung

### Status
✔ Bestanden

---

## **IT5 – TemperatureController → SafetyManager löst Warnung aus**
**Requirement:** 3.1  
**Komponenten:** TemperatureController → SafetyManager

### Vorbedingung
- Sensor = 255°C (außerhalb sicherer Zone)  
- Solltemperatur = 180°C

### Aktion
- Controller erkennt Temperatur  
- SafetyManager wird in update() aktiv

### Erwartetes Ergebnis
- SafetyManager setzt Warnflag  
- DisplayDriver erhält Warnhinweis

### Status
✔ Bestanden

---

## **IT6 – SafetyManager → HeaterControl: Heizung wird deaktiviert**
**Requirement:** 3.2

### Vorbedingung
- Controller hat Heizung EIN  
- Temperatur = 260°C

### Aktion
- SafetyManager.update()

### Erwartetes Ergebnis
- SafetyManager ruft `heater->off()`  
- Heizstatus = AUS

### Status
✔ Bestanden

---

## **IT7 – SafetyManager → DisplayDriver gibt Warnmeldung aus**
**Requirement:** 3.4

### Vorbedingung
- Kritische Temperatur aktiv

### Aktion
- SafetyManager.update()

### Erwartetes Ergebnis
- `display.showWarning("Überhitzung!")` wird ausgeführt  
- Display zeigt Warnsymbol/Text

### Status
✔ Bestanden

---

## **IT8 – Loggingfunktion beim Sicherheitsereignis**
**Requirement:** 3.3

### Vorbedingung
- Temperatur = 250°C

### Aktion
- SafetyManager.update()

### Erwartetes Ergebnis
- Logeintrag: „Critical Temperature – Heater disabled“

### Status
✔ Bestanden

---

# 4. Testfälle – Integrationsebene (8 Stück)

---

## IT9 – SafetyManager löst vollständige Warnkette aus  
**Requirement:** 4.2, 4.4, 5.1  
**Komponenten:** SafetyManager ↔ DisplayDriver ↔ UserInterface ↔ AudioOutput  

### Vorbedingung
- System im Normalbetrieb.
- Heizung EIN.

### Aktion
- Übertemperatur (260°C) tritt auf.

### Erwartetes Ergebnis
- Warnmeldung im Display  
- Akustisches Signal  
- UI gesperrt

### Status
✔ **Bestanden**

---

## IT10 – SafetyManager schaltet Heizung systemweit ab  
**Requirement:** 4.3  
**Komponenten:** SafetyManager ↔ HeaterControl  

### Vorbedingung
- Heizung EIN.
- Kritische Temperatur aktiv.

### Aktion
- SafetyManager.update()

### Erwartetes Ergebnis
- Heizung wird deaktiviert.

### Status
✔ **Bestanden**

---

## IT11 – LED und Signal werden synchron ausgelöst  
**Requirement:** 5.1, 5.2  
**Komponenten:** SafetyManager ↔ AudioOutput ↔ LEDController  

### Vorbedingung
- Fehlerzustand erkannt.

### Aktion
- SafetyManager.update()

### Erwartetes Ergebnis
- LED EIN  
- Signal abgespielt

### Status
✔ **Bestanden**

---

## IT12 – Akustisches Signal erfüllt Lautstärkeanforderung  
**Requirement:** 5.3  
**Komponenten:** SafetyManager ↔ AudioOutput  

### Vorbedingung
- Sicherheitsereignis aktiv.
- Akustisches Signal wird ausgelöst.

### Aktion
- Lautstärkeprüfung nach Signalausgabe durchführen.

### Erwartetes Ergebnis
- Signal ist für den Benutzer eindeutig hörbar.
- Lautstärke liegt im spezifizierten Bereich.

### Status
✔ **Bestanden**

---

## IT13 – Signal nach Zieltemperatur im Gesamtsystem  
**Requirement:** 5.4  
**Komponenten:** TemperatureController ↔ AudioOutput  

### Vorbedingung
- Soll = 160°C
- Ist = 160°C

### Aktion
- Regelzyklus abschließen.

### Erwartetes Ergebnis
- Bestätigungssignal wird abgespielt.

### Status
✔ **Bestanden**

---

# 5. Testergebnis-Dokumentation

| Testfall | Requirement | Ergebnis | Status |
|----------|--------------|---------------|--------|
| UT1 | 1.1 | Untergrenze korrekt begrenzt | ✔  |
| UT2 | 1.1 | Obergrenze korrekt begrenzt | ✔ |
| UT3 | 1.2 | Formatierte Ausgabe korrekt | ✔ |
| UT4 | 2.4 | Heizlogik EIN | ✔ |
| UT5 | 2.4 | Heizlogik AUS | ✔ |
| UT6 | 3.1 | kritische Temperatur erkannt | ✔ |
| UT7 | 3.2 | Heizung deaktiviert | ✔ |
| UT8 | 4.1 | Sensorwerte korrekt | ✔ |
| UT9 | 4.2 | Übertemperatur erkannt | ✔ |
| UT10 | 4.3 | Heizung abgeschaltet | ✔ |
| UT11 | 4.2 | Warnmeldung angezeigt | ✔ |
| UT12 | 4.4 | UI gesperrt | ✔ |
| UT13 | 5.1 | Signal ausgelöst | ✔ |
| UT14 | 5.2 | LED aktiviert | ✔ |
| UT15 | 5.4 | Zieltemperatursignal | ✔ |
| UT16 | 5.3 | Lautstärke geprüft | ✔ |
| IT1 | 2.2 | UI → Display Übertragung korrekt | ✔ |
| IT2 | 2.1 | LED-Reaktion korrekt | ✔ |
| IT3 | 1.3 / 2.3 | Signalton korrekt | ✔ |
| IT4 | 2.4 / 4.1 | Sensor → Controller logisch | ✔ |
| IT5 | 3.1 | Warnung ausgelöst | ✔ |
| IT6 | 3.2 | Heizung abgeschaltet | ✔ |
| IT7 | 3.4 | Warnmeldung angezeigt | ✔ |
| IT8 | 3.3 | Logging korrekt | ✔ |
| IT9 | 4.2 / 4.4 / 5.1 | Warnkette vollständig | ✔ |
| IT10 | 4.3 | Abschaltung erfolgreich | ✔ |
| IT11 | 5.1 / 5.2 | Signal + LED | ✔ |
| IT12 | 5.3 | Lautstärkeanforderung erfüllt | ✔ |
| IT13 | 5.4 | Endsignal korrekt | ✔ |

