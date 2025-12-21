# Design

## Klassendiagramm 

## Klassendiagramm – Beschreibung

Das Klassendiagramm stellt den erweiterten Systementwurf für Sprint 3 dar.

Im Vergleich zu Sprint 2 wurden folgende Klassen neu eingeführt oder erweitert:

- **SafetyManager**
  - erkennt Übertemperaturzustände (Req. 4.2)
  - führt sofortige Abschaltungen aus (Req. 4.3)
  - reagiert auf instabile Betriebsbedingungen (Req. 4.4)

- **AudioOutput**
  - erzeugt akustische Signale (Req. 5.1, 5.3, 5.4)

- **LEDController**
  - optische Rückmeldung für den Nutzer (Req. 5.2)

Der TemperatureController bleibt die zentrale Steuerinstanz,
koordiniert aber nun zusätzliche Rückmelde- und Sicherheitsmechanismen.

Das Diagramm verdeutlicht:
- klare Verantwortlichkeiten pro Klasse
- explizite Abhängigkeiten
- lose Kopplung zwischen Logik und Hardware



![alt text](<../referenziert/Requirement_Engineering/design/Klassendiagramm_für_Sprint_3.png>)


## Sequenzdiagramm – Beschreibung (Sprint 3)

Das Sequenzdiagramm für Sprint 3 beschreibt das **zeitliche Zusammenspiel**
zwischen Sensorik, Regelung, Sicherheitsüberwachung und Nutzer-Rückmeldung.

Im Vergleich zu Sprint 2 wurden folgende Aspekte erweitert:

- Sicherheitsprüfungen laufen nun **parallel zur Regelung**
- Nutzerfeedback (akustisch / optisch) ist **Teil des Systemablaufs**
- Kritische Ereignisse führen zu **sofortigen Systemreaktionen**
- Der Benutzer ist nicht mehr nur Auslöser, sondern auch Empfänger von Statusänderungen

Das Diagramm verdeutlicht insbesondere:

- die Reihenfolge der Nachrichten bei zeitkritischen Ereignissen
- wie Sicherheitslogik Regelungsprozesse unterbrechen kann
- dass Hardwareaktionen (Heizung, Signal, LED) ausschließlich
  über definierte Schnittstellen erfolgen

➡ Das Sequenzdiagramm zeigt damit erstmals ein **reaktives, sicherheitsorientiertes Systemverhalten**,  
wie es für Sprint 3 gefordert ist.

## Sequenzdiagramm – Übertemperatur – Beschreibung

Dieses Sequenzdiagramm fokussiert explizit einen sicherheitskritischen Ausnahmefall.

Im Mittelpunkt stehen:

- frühzeitige Erkennung einer Übertemperatur
- deterministisches Abschalten der Heizung
- sofortige und eindeutige Nutzerwarnung

Neu gegenüber früheren Sprints:

- Die Sicherheitsentscheidung liegt ausschließlich beim SafetyManager
- Der TemperatureController agiert nur noch als Vermittler
- Nutzerinteraktionen werden aktiv blockiert

Das Diagramm zeigt klar:

- dass Sicherheitslogik Vorrang vor Komfortfunktionen hat
- wie Fehlersituationen kontrolliert eskalieren
- dass jede sicherheitsrelevante Entscheidung nachvollziehbar ist

➡ Damit erfüllt das Diagramm die Anforderungen 4.2, 4.3 und 4.4 vollständig
und nachvollziehbar.


## Sequenzdiagramm – Übertemperatur

### Ablaufbeschreibung

1. Der Sensor meldet eine Temperatur oberhalb des kritischen Grenzwerts.
2. Der TemperatureController leitet den Wert an den SafetyManager weiter.
3. Der SafetyManager erkennt einen sicherheitskritischen Zustand.
4. Die Heizung wird sofort abgeschaltet (Req. 4.3).
5. Eine Warnmeldung wird auf dem Display angezeigt (Req. 4.2).
6. Zusätzlich wird ein akustisches Warnsignal ausgegeben.
7. Weitere Benutzereingaben werden gesperrt.

Dieses Szenario deckt die Requirements 4.2, 4.3 und 4.4 ab.

## Sequenzdiagramm – Zieltemperatur erreicht

### Ablaufbeschreibung

1. Der Benutzer gibt eine Zieltemperatur ein.
2. Der TemperatureController startet den Regelzyklus.
3. Der Sensor meldet zyklisch die aktuelle Temperatur.
4. Der SafetyManager überwacht parallel alle Grenzwerte.
5. Sobald die Zieltemperatur erreicht wird:
   - die Heizung wird deaktiviert
   - ein akustisches Signal wird ausgelöst (Req. 5.1)
   - eine LED wird aktiviert (Req. 5.2)
   - das Display zeigt den Status an
6. Die Rückmeldung erfolgt innerhalb von maximal 1 Sekunde (Req. 5.4).

Dieses Szenario erfüllt die Requirements 5.1–5.4 vollständig.

![alt text](<../referenziert/Requirement_Engineering/design/Sequenzdiagramm_für_Sprint_3.png>)

## Kommunikationsdiagramm – Beschreibung (Sprint 3)

Das Kommunikationsdiagramm stellt die **strukturelle Kommunikation**
zwischen den beteiligten Komponenten dar – unabhängig vom zeitlichen Ablauf.

Im Fokus von Sprint 3 stehen:

- klare Verantwortlichkeiten pro Komponente
- reduzierte Kopplung zwischen Logik und Hardware
- explizite Kommunikationswege für Sicherheits- und Signalisierungsfunktionen

Gegenüber Sprint 2 wurden folgende Änderungen vorgenommen:

- neue Kommunikationspfade zu AudioOutput und LEDController
- SafetyManager kommuniziert aktiv mit mehreren Komponenten
- DisplayDriver wird ausschließlich über Logikkomponenten angesprochen

Das Diagramm verdeutlicht:

- welche Komponenten miteinander sprechen dürfen
- dass Hardware nie direkt vom UI angesteuert wird
- dass Sicherheitslogik zentralisiert ist

➡ Das Kommunikationsdiagramm dient damit als **Strukturbeweis**
für die modulare und erweiterbare Architektur von Sprint 3.

## Kommunikationsdiagramm – Sicherheitskommunikation – Beschreibung

Dieses Kommunikationsdiagramm betrachtet ausschließlich
die Nachrichtenflüsse im Fehler- und Warnfall.

Besondere Merkmale:

- ereignisbasierte Kommunikation
- ein zentraler Entscheidungspunkt (SafetyManager)
- parallele Auslösung mehrerer Reaktionen (Abschaltung, Warnung, Signal)

Im Gegensatz zu Sprint 1 und 2:

- existiert kein direkter Pfad vom Sensor zur Hardware
- alle Entscheidungen werden logisch bewertet
- Nutzerfeedback ist verpflichtend und redundant (optisch + akustisch)

➡ Das Diagramm zeigt, dass Sicherheitsanforderungen
nicht nur implementiert, sondern **architektonisch abgesichert** sind.


## Kommunikationsdiagramm – Sicherheitsfall

Dieses Diagramm verdeutlicht:

- die lose Kopplung zwischen Controller und Signalisierung
- die zentrale Rolle des SafetyManager
- die klare Trennung von Entscheidung und Darstellung

Die Kommunikation erfolgt ereignisgetrieben und zeitkritisch,
um Sicherheitsanforderungen zuverlässig einzuhalten.

![alt text](<../referenziert/Requirement_Engineering/design/Kommunikationsdiagramm_für_Sprint_3.png>)