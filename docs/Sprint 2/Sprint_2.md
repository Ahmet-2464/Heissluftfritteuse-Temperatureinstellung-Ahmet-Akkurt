# Retrospective – Sprint 2

## Sprint 2 – Ziel
Ziel von Sprint 2 war es, aufbauend auf der Bedien- und Anzeigegrundfunktionalität aus Sprint 1 erstmals **Regelungs-, Sicherheits- und Hardware-nahe Logik** zu implementieren.  
Das System sollte in der Lage sein, eine eingestellte Solltemperatur aktiv zu erreichen, diese automatisch zu regeln und bei kritischen Zuständen (Übertemperatur) sicher einzugreifen. Zusätzlich wurden nicht-funktionale Anforderungen wie Anzeige-Aktualisierungszeiten und Aufheizzeiten berücksichtigt.

Damit entsteht erstmals ein **funktional geschlossenes Regelungssystem** (Sensor → Controller → Heizung → Sicherheit → Anzeige), welches als Grundlage für reale Hardwareintegration dient.

---

## 1. Übersicht der Sprint-2-Requirements

| Requirement-ID | Beschreibung | Begründung |
|----------------|--------------|------------|
| 2.4 | Aktualisierungszeit der Anzeige | Schnelles Feedback ist entscheidend für Bedienkomfort und Systemtransparenz |
| 3.1 | Aufheizen auf Solltemperatur | Kernfunktion einer Heißluftfritteuse |
| 3.2 | Automatische Temperaturregelung | Konstante Garqualität erfordert kontinuierliche Regelung |
| 3.3 | Temperaturgenauigkeit ±3 °C | Verhindert Über- oder Untergaren |
| 3.4 | Maximale Aufheizzeit (200 °C ≤ 5 min) | Energieeffizienz und Nutzererwartung |
| 4.1 | Automatische Abschaltung bei Übertemperatur | Zentrale Sicherheitsanforderung |

Diese Auswahl stellt sicher, dass Sprint 2 nicht nur neue Funktionen ergänzt, sondern **Systemverantwortung (Regelung & Sicherheit)** übernimmt.

---

## 2. Vergleich von Architektur, Design und Implementierung (Sprint 2)

### 2.1 Architekturabgleich

**(A1) Einführung der vollständigen HAL-Schicht**  
Die Architektur sieht klar getrennte Hardware-Abstraktionen vor:
- SensorInterface
- HeaterControl
- DisplayDriver

➡ In Sprint 2 wurden alle drei Komponenten als klar definierte Schnittstellen implementiert.  
Die reale Hardware wird durch Mock-Klassen simuliert, womit die Architektur vollständig eingehalten wird.

**Status:** Architekturkonform

---

**(A2) SafetyManager nun umgesetzt**  
Der SafetyManager war in Sprint 1 nur konzeptionell vorhanden.

➡ In Sprint 2 wurde er implementiert und überwacht:
- Kritische Temperaturgrenzen
- Abschaltung der Heizung
- Ausgabe von Warnmeldungen

**Status:** Architektur erfüllt

---

### 2.2 Designabgleich

**(D1) Sequenzdiagramm vs. Implementierung**  
Das Design beschreibt einen zyklischen Ablauf:
Sensor → Controller → Heizung → Safety → Anzeige

➡ In der Implementierung wird dieser Ablauf synchron innerhalb einer `update()`-Routine umgesetzt.  
Asynchrone Events (Callbacks) sind vorbereitet, aber noch nicht umgesetzt.

**Status:** Design weitgehend umgesetzt, Asynchronität folgt in Sprint 3

---

**(D2) Kommunikationsdiagramm – Datenfluss klarer als in Sprint 1**  
Im Vergleich zu Sprint 1 sind die Verantwortlichkeiten klar getrennt:
- Controller entscheidet
- SafetyManager überwacht
- HAL führt aus

➡ Die Kommunikationspfade entsprechen dem Design.

**Status:** Designkonform

---

### 2.3 Abweichungen zur Architektur

**(AB1) Zeitverhalten nur simuliert**  
Requirements 2.4 und 3.4 betreffen zeitliche Eigenschaften (ms / Minuten).

➡ Diese werden in Sprint 2 **logisch simuliert**, nicht real gemessen.

**Bewertung:**  
Geplant und akzeptabel – reale Zeitmessung erfolgt erst mit Hardware oder RTOS.

---

## 3. Abweichungsanalyse Sprint 2

### 3.1 Regelungslogik (TemperatureController)

Die Architektur sieht eine vollständige Regelung inkl. Genauigkeit ±3 °C vor.

➡ Implementiert wurde:
- Soll-/Ist-Vergleich
- Heizung EIN/AUS
- einfache Hysterese

➡ Feingranulare Regelung (PID) ist **noch nicht Bestandteil von Sprint 2**.

**Bewertung:**  
Requirement 3.2 erfüllt, 3.3 funktional vorbereitet.

---

### 3.2 Sicherheitslogik (SafetyManager)

Die Sicherheitsabschaltung bei >210 °C ist vollständig umgesetzt.

➡ Abschaltung erfolgt deterministisch und sofort.

**Bewertung:**  
Requirement 4.1 vollständig erfüllt.

---

### 3.3 Anzeigeverhalten

Die Anzeige wird bei Zustandsänderungen unmittelbar aktualisiert.

➡ Die 200-ms-Grenze wird logisch eingehalten (keine Blockaden).

**Bewertung:**  
Requirement 2.4 erfüllt (softwareseitig).

---

## 4. Erkenntnisse aus Sprint 2

### 4.1 Regelung und Sicherheit müssen getrennt bleiben
Die Trennung von TemperatureController und SafetyManager hat sich bewährt:
- klare Verantwortlichkeiten
- einfachere Tests
- bessere Wartbarkeit

➡ Beibehalten für Sprint 3

---

### 4.2 HAL-Schnittstellen sind entscheidend für Testbarkeit
Durch MockSensor und MockHeater konnte das komplette System ohne Hardware getestet werden.

➡ Dieses Konzept wird in Sprint 3 für weitere Komponenten fortgeführt.

---

### 4.3 Zeitabhängige Requirements benötigen Messkonzepte
Nicht-funktionale Anforderungen (ms, Minuten) können softwareseitig nur begrenzt geprüft werden.

➡ In Sprint 3:
- Definition von Messmethoden
- ggf. Simulationszeit oder Echtzeitframework

---

### 4.4 Vorbereitung auf asynchrone Architektur notwendig
Der zyklische `update()`-Ansatz funktioniert, skaliert aber nur begrenzt.

➡ Sprint 3:
- Callbacks / Observer
- Event-getriebene Sensorupdates

---

## 5. Zusammenfassung Sprint 2

Sprint 2 stellt einen **entscheidenden Entwicklungsschritt** dar:

- Das System regelt aktiv eine Temperatur
- Sicherheitsabschaltung funktioniert zuverlässig
- Hardware-Abstraktion ist vollständig vorhanden
- Architektur und Design werden weitgehend eingehalten
- Abweichungen sind bewusst geplant und dokumentiert

Damit ist das System **bereit für reale Hardwareanbindung, präzisere Regelung und asynchrone Erweiterungen in Sprint 3**.
