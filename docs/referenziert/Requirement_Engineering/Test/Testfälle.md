# 3. Testfälle – Modul-/Unit-Ebene (8 Stück)

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


# 4. Testfälle – Integrationsebene (8 Stück)

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
**Requirement:** 2.3  
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

# 5. Testergebnis-Dokumentation

| Testfall | Requirement | Ergebnis | Status |
|----------|--------------|---------------|--------|
| UT1 | 2.4 | Heizlogik EIN | ✔ |
| UT2 | 2.4 | Heizlogik AUS | ✔ |
| UT3 | 3.1 | kritische Temperatur erkannt | ✔ |
| UT4 | 3.2 | Heizung deaktiviert | ✔ |
| UT5 | 4.1 | Sensorwerte korrekt | ✔ |
| IT1 | 2.4 / 4.1 | Sensor → Controller logisch | ✔ |
| IT2 | 3.1 | Warnung ausgelöst | ✔ |
| IT3 | 3.2 | Heizung abgeschaltet | ✔ |
| IT4 | 3.4 | Warnmeldung angezeigt | ✔ |
| IT5 | 3.3 | Logging korrekt | ✔ |
