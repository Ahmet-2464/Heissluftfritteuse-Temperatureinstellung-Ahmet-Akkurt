# Retrospective – Sprint 3

## Sprint 3 – Ziel
Ziel von Sprint 3 war es, das bestehende Regelungs- und Sicherheitssystem aus Sprint 2 um
**aktive Benutzerbenachrichtigung, Fehlerbehandlung und Systemreaktionen auf kritische Zustände**
zu erweitern.

Der Fokus lag dabei auf:
- erweiterter Sicherheitsreaktion (Warnung, Abschaltung, UI-Sperre),
- synchroner visueller und akustischer Rückmeldung,
- klarer Nachvollziehbarkeit sicherheitskritischer Ereignisse,
- sowie vollständiger Testabdeckung der neuen Anforderungen.

Sprint 3 stellt damit den Übergang von einer rein funktionalen Regelung hin zu
einem **benutzer- und sicherheitsorientierten Systemverhalten** dar.

---

## 1. Übersicht der Sprint-3-Requirements

| Requirement-ID | Beschreibung | Begründung |
|----------------|--------------|------------|
| 4.2 | Warnmeldung bei Übertemperatur | Nutzer muss unmittelbar über Gefahr informiert werden |
| 4.3 | Sicherheitsabschaltung der Heizung | Schutz vor Schäden und Gefährdung |
| 4.4 | Sperrung der Benutzereingabe im Fehlerfall | Vermeidung fehlerhafter Bedienung |
| 5.1 | Akustisches Warnsignal | Zusätzliche Wahrnehmung neben visueller Anzeige |
| 5.2 | LED-Anzeige im Fehlerzustand | Schnelle visuelle Statusinformation |
| 5.3 | Überwachung der Signallautstärke | Sicherstellen wahrnehmbarer Signale |
| 5.4 | Signal nach Erreichen der Zieltemperatur | Benutzerfeedback bei abgeschlossenem Vorgang |

Diese Requirements erweitern das System von einer reinen Regelung hin zu
einer **interaktiven und fehlertoleranten Benutzerführung**.

---

## 2. Vergleich von Architektur, Design und Implementierung (Sprint 3)

### 2.1 Architekturabgleich

**(A1) Erweiterung der Sicherheitsarchitektur**
Die Architektur sieht vor, dass sicherheitskritische Ereignisse:
- erkannt,
- behandelt,
- kommuniziert
werden.

➡ In Sprint 3 übernimmt der `SafetyManager` zusätzlich:
- aktive Warnmeldung,
- UI-Sperrung,
- Ansteuerung visueller und akustischer Ausgabekanäle.

**Status:** Architektur erweitert und eingehalten

---

**(A2) Anzeige- und Signalkomponenten klar getrennt**
Die Architektur trennt:
- logische Sicherheitsentscheidungen
- von der konkreten Ausgabe (LED, Audio, Display).

➡ Diese Trennung wurde durch spezialisierte Anzeige- und Audio-Schnittstellen umgesetzt.

**Status:** Architekturkonform

---

### 2.2 Designabgleich

**(D1) Klassendiagramm – Erweiterung ohne Bruch**
Das Design aus Sprint 2 wurde erweitert, nicht ersetzt:
- keine Auflösung bestehender Verantwortlichkeiten,
- stattdessen Ergänzung um Benachrichtigungslogik.

➡ Bestehende Klassen bleiben stabil, neue Methoden ergänzen Verhalten.

**Status:** Design konsistent erweitert

---

**(D2) Sequenz- und Kommunikationsdiagramme**
Die entworfenen Abläufe für Übertemperatur und Zieltemperatur-Erreichung
entsprechen der implementierten Aufrufreihenfolge:

TemperatureController → SafetyManager → Anzeige / Audio / UI

➡ Die Implementierung folgt exakt dem entworfenen Ablauf.

**Status:** Designkonform

---

### 2.3 Abweichungen zur Architektur

**(AB1) Ereignisse weiterhin synchron**
Die Architektur lässt asynchrone Ereignisse zu (Timer, Interrupts).

➡ In Sprint 3 werden Sicherheitsereignisse weiterhin synchron verarbeitet.

**Bewertung:**  
Akzeptabel, da Fokus auf korrektem Verhalten liegt, nicht auf Echtzeitfähigkeit.

---

## 3. Abweichungsanalyse Sprint 3

### 3.1 Sicherheitsreaktionen (Requirements 4.2–4.4)

Die Architektur fordert:
- Warnung,
- Abschaltung,
- Sperrung der Benutzereingabe.

➡ Alle drei Reaktionen werden deterministisch ausgelöst.

**Bewertung:**  
Requirements 4.2, 4.3 und 4.4 vollständig erfüllt.

---

### 3.2 Benutzerfeedback (Requirements 5.1–5.4)

Sprint 3 erweitert die Ausgabeebene erheblich:
- Audio-Feedback,
- LED-Status,
- Abschluss-Signale.

➡ Die Ausgaben erfolgen synchron und konsistent.

**Bewertung:**  
Requirements 5.1, 5.2, 5.4 erfüllt.  
Requirement 5.3 softwareseitig umgesetzt (Messung simuliert).

---

### 3.3 Signallautstärke (Requirement 5.3)

Die Architektur sieht eine Überwachung der Signallautstärke vor.

➡ In Sprint 3 wird dies logisch simuliert (Mock-Werte).

**Bewertung:**  
Funktional umgesetzt, physikalische Messung folgt erst mit Hardware.

---

## 4. Erkenntnisse aus Sprint 3

### 4.1 Sicherheit ist mehr als Abschaltung
Reine Abschaltung reicht nicht aus – Nutzer müssen informiert werden.

➡ Sicherheitsreaktionen müssen immer:
- sichtbar,
- hörbar,
- nachvollziehbar
sein.

---

### 4.2 Benutzerinteraktion muss im Fehlerfall kontrolliert werden
Freie Bedienung im Fehlerzustand birgt Risiken.

➡ UI-Sperrung ist zwingend notwendig (Requirement 4.4).

---

### 4.3 Konsistenz der Rückmeldungen ist entscheidend
Visuelle und akustische Signale müssen synchron auftreten.

➡ Getrennte Ausgabe-Klassen mit gemeinsamer Steuerung haben sich bewährt.

---

### 4.4 Testaufwand steigt mit Systemverhalten
Systemweite Reaktionen benötigen:
- Unit-Tests,
- Integrationstests,
- klare Traceability.

➡ Teststrategie aus Sprint 2 wurde erfolgreich erweitert.

---

## 5. Zusammenfassung Sprint 3

Sprint 3 erweitert das System signifikant:

- Sicherheitsereignisse werden aktiv kommuniziert
- Benutzer wird geführt und geschützt
- Anzeige-, Audio- und Logikschichten arbeiten konsistent zusammen
- Alle Sprint-3-Requirements sind umgesetzt und getestet
- Architektur und Design bleiben stabil und erweiterbar


