# 3. Testfälle – Modul-/Unit-Ebene (3 Stück)

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


# 4. Testfälle – Integrationsebene (3 Stück)

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