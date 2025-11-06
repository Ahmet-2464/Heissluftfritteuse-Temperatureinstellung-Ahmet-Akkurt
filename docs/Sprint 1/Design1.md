# Design

## Klassendiagramm

Das Klassendiagramm wurde in einem ersten Entwurf erstellt, um eine grundlegende Struktur der Systemarchitektur und die Interaktionen zwischen den zentralen Komponenten festzuhalten. Dieser erste Wurf diente vor allem dazu, die Hauptfunktionen des Systems – insbesondere Bedienung, Temperaturregelung und Sicherheitsüberwachung – konzeptionell zu erfassen.

Im Laufe der Implementierung hat sich das Klassendiagramm weiterentwickelt: Einige Klassen wurden in ihrer Funktion erweitert, andere zusammengefasst oder angepasst, um eine klarere Trennung zwischen Präsentations-, Logik- und Hardwareabstraktionsschicht (HAL) zu erreichen. Darüber hinaus wurden zusätzliche Attribute und Methoden ergänzt, um die Kommunikation zwischen den Komponenten sowie die interne Logik besser abzubilden.

Das finale Klassendiagramm zeigt sämtliche Klassen mit ihren Attributen und Methoden, jeweils mit der entsprechenden Sichtbarkeit gemäß gängiger Konventionen. Die Darstellung ermöglicht einen klaren Überblick über die Code-Struktur, die Abhängigkeiten zwischen den Modulen und die Datenflüsse im System. Nicht berücksichtigt sind in der Abbildung Enums und Hilfsklassen, die lediglich der internen Umsetzung bestimmter Designentscheidungen dienen.

![alt text](<../referenziert/Requirement_Engineering/design/Klassendiagramm für Sprint 1.png>)

## Sequenzdiagramm Eingabe einer neuen Solltemperatur über das Touch-Bedienfeld

**Ablaufbeschreibung:**

1. Benutzer tippt auf dem Touch-Bedienfeld die gewünschte Temperatur ein.

2. Der TouchInputHandler erfasst die Eingabe und übergibt sie an den      TemperatureController.

3. Der TemperatureController prüft, ob die Eingabe im gültigen Bereich (80–200 °C) liegt.

4. Bei gültiger Eingabe wird der Sollwert gespeichert und an den DisplayController weitergegeben.

5. Der DisplayController aktualisiert die Anzeige sofort, um die neue Solltemperatur zu zeigen.

6. Der Prozess stellt sicher, dass die Anzeige innerhalb von 200 ms aktualisiert wird (nicht-funktionales Requirement 2.4).

![alt text](<../referenziert/Requirement_Engineering/design/Sequenzdiagramm für Sprint 1.png>)


## Kommunikationsdiagramm für das Szenario „Temperaturwahl über Bedienfeld“

**Beschreibung des Diagramms**

| Nr. | Nachricht                             | Richtung                                  | Beschreibung                                                          |
| --- | ------------------------------------- | ----------------------------------------- | --------------------------------------------------------------------- |
| 1   | `tippt Solltemperatur (180 °C)`       | Benutzer → TouchInputHandler              | Der Benutzer gibt die gewünschte Temperatur über das Touch-Panel ein. |
| 2   | `sendTemperatureInput(180)`           | TouchInputHandler → TemperatureController | Das System überträgt den eingegebenen Wert an die Steuerung.          |
| 3   | `validateTemperatureRange(80–200 °C)` | intern in TemperatureController           | Der Wert wird überprüft, ob er im zulässigen Bereich liegt.           |
| 4   | `updateDisplay(180 °C)`               | TemperatureController → DisplayController | Die neue Solltemperatur wird zur Anzeige übermittelt.                 |
| 5   | `confirmUpdate()`                     | DisplayController → TemperatureController | Bestätigung, dass das Display aktualisiert wurde.                     |
| 6   | `Anzeige aktualisiert`                | DisplayController → Benutzer              | Der Benutzer sieht die geänderte Temperatur auf dem Display.          |


![alt text](<../referenziert/Requirement_Engineering/design/Kommunikationsdiagramm für Sprint 1.png>)

**Interpretation**

Dieses Kommunikationsdiagramm verdeutlicht:

- Welche Komponenten direkt interagieren (Punkt-zu-Punkt-Kommunikation),

- die Reihenfolge der Nachrichten (durch die Nummerierung),

- und wie logische Kontrolle (vom Benutzer bis zur Anzeige) fließt.

