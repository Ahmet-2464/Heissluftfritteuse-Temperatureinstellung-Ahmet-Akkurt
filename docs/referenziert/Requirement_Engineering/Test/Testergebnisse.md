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