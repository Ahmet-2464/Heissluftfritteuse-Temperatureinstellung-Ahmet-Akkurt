# Design

## Klassendiagramm 

Das Klassendiagramm wurde ausgehend vom ursprünglichen Entwurf aus Sprint 1 erweitert und überarbeitet. 
Ziel war es, die neu gewonnenen Erkenntnisse aus Sprint 1 sowie den geplanten Funktionsumfang von Sprint 2 
vollständig abzubilden.

Dabei wurden folgende wesentliche Anpassungen vorgenommen:

- **Einführung des SafetyManager**, da sicherheitskritische Funktionen wie Überhitzungsschutz 
  frühzeitig berücksichtigt werden müssen.
- **Erweiterung des TemperatureController**, der nun neben der Eingabeverarbeitung auch 
  Sensorwertverarbeitung, Soll-Ist-Vergleich und Heizungssteuerung übernimmt.
- **Integration der Hardwareabstraktionsschicht (HAL)** durch die Klassen `SensorInterface` und 
  `HeaterControl`, um die Interaktion mit physischer Hardware zu ermöglichen.
- **Trennung der UI-Logik** in `TouchInputHandler`, `DisplayController` und eine optionale `UI`-Klasse, 
  um eine sauberere Schichtung zu erreichen.
- **Einführung asynchroner Ereignisse**, die später durch Callbacks oder Interrupts realisiert werden.

Das finale Klassendiagramm zeigt die gesamte Struktur des Systems, inklusive aller wesentlichen Attribute, 
Methoden und Beziehungen. Hilfsklassen oder Enums, die nur intern verwendet werden, wurden bewusst nicht 
aufgeführt, um die Übersichtlichkeit zu behalten.

![alt text](<../referenziert/Requirement_Engineering/design/Klassendiagramm für Sprint 2.png>)

## Sequenzdiagramm – Eingabe einer neuen Solltemperatur

Das Sequenzdiagramm beschreibt den vollständigen Ablauf, wenn eine neue Solltemperatur über das 
Touch-Bedienfeld eingegeben wird. Der Ablauf umfasst die Verarbeitung der Nutzereingabe, die Validierung, 
die Abfrage der aktuellen Sensordaten sowie die Aktualisierung der Anzeige.

Der Ablauf deckt folgende Anforderungen ab:

- **3.1 – Eingabe der Solltemperatur**
- **3.2 – Temperaturbereich 80–200 °C**
- **2.4 – Anzeige muss innerhalb von 200 ms aktualisiert werden**
- **3.4 – Validierungslogik**
- **4.1 – Sicherheitsprüfung auf Überhitzung**

### Ablaufbeschreibung:

1. Der Benutzer gibt über das Touchfeld eine neue Temperatur ein.
2. Der TouchInputHandler validiert die Eingabe und übermittelt sie an den TemperatureController.
3. Der TemperatureController prüft, ob die Temperatur im gültigen Bereich (80–200 °C) liegt.
4. Anschließend wird über den SensorInterface die aktuelle Temperatur abgefragt.
5. Der SafetyManager prüft anhand des neuen Ist-Wertes mögliche Gefahren (z. B. Überhitzung).
6. Der TemperatureController führt seinen Regelalgorithmus aus.
7. Über den DisplayController wird die Anzeige aktualisiert.
8. Der Benutzer erhält sofortiges Feedback über das Display.

Dieser Ablauf stellt sicher, dass das System sowohl funktionale als auch nicht-funktionale Anforderungen 
einheitlich erfüllt und eventuelle Sicherheitsrisiken berücksichtigt.

![alt text](<../referenziert/Requirement_Engineering/design/Sequenzdiagramm für Sprint 2.png>)

## Kommunikationsdiagramm – Temperaturwahl über das Bedienfeld

Das Kommunikationsdiagramm zeigt die strukturierte Interaktion zwischen den Systemkomponenten, wenn der 
Benutzer eine neue Temperatur eingibt. Im Gegensatz zum Sequenzdiagramm liegt der Fokus hier stärker auf 
den beteiligten Komponenten und der Reihenfolge nummerierter Nachrichten.

### Beschreibung der Nachrichten:

| Nr. | Nachricht                         | Richtung                                  | Beschreibung |
|----:|-----------------------------------|--------------------------------------------|--------------|
| 1   | Temperatur eingeben               | Benutzer → TouchInputHandler               | Benutzer gibt die neue Solltemperatur ein. |
| 2   | sendTemperatureInput(value)       | TouchInputHandler → TemperatureController  | System überträgt die Eingabe zur Steuerlogik. |
| 3   | validateTemperatureRange          | intern in TemperatureController            | Temperatur wird auf 80–200 °C geprüft. |
| 4   | readTemperature()                 | TemperatureController → SensorInterface    | Der aktuelle Ist-Wert wird abgefragt. |
| 5   | currentTemp                       | SensorInterface → TemperatureController    | Rückgabe der gemessenen Temperatur. |
| 6   | checkSafetyStatus                 | TemperatureController → SafetyManager      | Prüfung auf Überhitzung oder Sensorfehler. |
| 7   | status OK                          | SafetyManager → TemperatureController      | Meldung, dass keine Gefahr besteht. |
| 8   | updateDisplay                     | TemperatureController → DisplayController  | Anzeige wird aktualisiert. |
| 9   | Anzeige aktualisiert              | DisplayController → Benutzer               | Benutzer erhält direkt visuelles Feedback. |

![alt text](<../referenziert/Requirement_Engineering/design/Kommunikationsdiagramm für Sprint 2.png>)

### Interpretation:

Das Diagramm verdeutlicht:

- Wie Benutzerinteraktion in eine Kette technischer Prozesse mündet.
- Die unmittelbare Verknüpfung von Regelung, Sicherheit und UI-Feedback.
- Die klare Trennung der Verantwortlichkeiten zwischen UI, Logik und Hardwareabstraktion.
- Die konsistente Reihenfolge aller gesendeten Nachrichten innerhalb des Systems.

