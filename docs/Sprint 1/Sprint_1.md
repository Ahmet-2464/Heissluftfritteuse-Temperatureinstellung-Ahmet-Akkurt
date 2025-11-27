## Sprint 1

Ziel: Einen durchgängigen Bedienablauf realisieren: Nutzer:innen können erstmals eine Temperatur am Touch-Feld eingeben, diese wird im korrekten Bereich und in Schritten verarbeitet und unmittelbar samt Anzeige-Feedback sichtbar gemacht. Es entsteht ein funktionsfähiges, testbares Basis-Inkrement für Bedienung und Anzeige. Damit steht eine erste Benutzungsstrecke und Feedbackkette bereit, auf der später alle weiteren Funktionen aufbauen können.


| Requirement-ID | Beschreibung                                                           | Begründung                                                         |
|:--------------:|:----------------------------------------------------------------------:|:------------------------------------------------------------------:|
| 1.1            | Temperaturwahl über Bedienfeld. Das System muss dem Nutzer ermöglichen, die gewünschte Temperatur über das Touch-Bedienfeld einzugeben. | Ermöglicht die zentrale Steuerung und bildet den Ausgangspunkt aller Funktionen. |
| 1.2            | Temperaturbereich & Schrittweite. Das System muss Eingaben in 5 °C-Schritten zwischen 80 °C und 200 °C verarbeiten. | Verhindert Fehleingaben, deckt den praxisrelevanten Nutzungsbereich ab.           |
| 2.1            | Temperaturanzeige auf Display. Das System muss die eingestellte Temperatur auf einem Display anzeigen. | Unmittelbares Feedback ist für die Bedienbarkeit essenziell.                      |
| 2.2            | Sofortige Aktualisierung der Anzeige. Die Anzeige soll sich bei jeder Änderung der Temperatur sofort aktualisieren. | Sorgt für eine flüssige, intuitive Bedienbarkeit ohne Verzögerung.                 |
| 1.3            | Reaktionsgeschwindigkeit Eingabe. Die Reaktionszeit auf eine Eingabe soll maximal 500 ms betragen. | Sicheres, zügiges Nutzererlebnis; beugt Unzufriedenheit vor.                      |
| 2.3            | Lesbarkeit der Anzeige. Die Displayhelligkeit soll aus einem Abstand von 1 m klar lesbar sein. | Praktisch relevant – stellt die Nutzbarkeit im Alltag sicher.                     |



Mit dieser Auswahl wird eine sofort nutzbare und testbare Bedien- und Anzeigegrundfunktionalität geschaffen. Sie ist die Basis für später folgende Regelungs- und Sicherheitsfeatures.

## 1. Vergleich von Architektur, Design und tatsächlicher Implementierung

Beim Abgleich der geplanten Software-Architektur und des Software-Designs mit der
tatsächlich implementierten Lösung aus Sprint 1 ergeben sich mehrere Abweichungen.
Diese Abweichungen sind typisch für frühe Projektphasen und spiegeln wider, dass die
Implementierung pragmatisch auf die erste nutzbare Funktionalität ausgerichtet war.

### 1.1 Abweichungen in der Architektur

**(A1) Reduzierte Umsetzung der HAL-Schicht**  
Im Architekturmodell existieren drei getrennte Hardware-Abstraktionsmodule
(*SensorInterface*, *HeaterControl*, *DisplayDriver*).  
In der Implementierung wurde jedoch nur der *DisplayDriver* in einer eigenen Klasse
umgesetzt. Der Sensorzugriff sowie die Heizlogik wurden noch nicht implementiert,
da Sprint 1 ausschließlich die Temperatureingabe und Anzeige umfasste.

**(A2) SafetyManager nicht implementiert**  
In der Architektur ist der *SafetyManager* eine getrennte Komponente für Überhitzungs-
schutz und Fehlerbehandlung.  
In der Implementierung wurde diese Komponente noch nicht benötigt und daher nicht
realisiert. Sicherheitsfunktionen sind für spätere Sprints vorgesehen.

**(A3) UserInterface-Architektur vs. Implementierung**  
Das Architekturmodell beschreibt die UI-Komponente als übergeordnete Einheit mit
mehreren Funktionen ("Temperatureingabe", "Anzeige", "Rückmeldung").  
In der Implementierung wurde dies zu einer **Konsoleingabe über `TouchInputHandler`**
vereinfacht, ohne visuelle oder Touch-Hardware-Ansteuerung.

---

### 1.2 Abweichungen im Design

**(D1) Sequenzdiagramm vs. tatsächlicher Datenfluss**  
Das Sequenzdiagramm definiert mehrere Schritte: Eingabe → Validierung → Anzeige → Bestätigung.  
In der Implementierung erfolgt die Anzeige direkt nach Zuweisung des Sollwerts –
eine gesonderte Bestätigung vom DisplayDriver ist nicht vorhanden.

**(D2) Kommunikationsdiagramm sagt Callbacks voraus**  
Das Design beschreibt asynchrone Ereignisse wie `onTemperatureUpdate()`.  
Die Implementierung nutzt ausschließlich **synchrone Funktionsaufrufe** ohne Event-Mechanismus.

**(D3) Keine Temperature-Range-Validierung in einer eigenen Methode**  
Das Design sieht eine Validierungsfunktion vor (`validateTemperatureRange`).  
In der Implementierung ist die Prüfung direkt in `setTargetTemperature()` integriert.

---

### 1.3 Abweichungen in der Traceability zu Anforderungen

**(T1) Einige Requirements in Sprint 1 nicht implementiert**  
Folgende Anforderungen wurden bewusst NOCH NICHT umgesetzt:

- Req 4.x (Sicherheitslogik)  
- Req 5.x (erweiterte Interaktionen, komplexere Displays)  
- Req 2.3 (Lesbarkeit aus 1 m → hardwareabhängig)

Dadurch fehlen diese Komponenten im Code, obwohl sie im Architekturmodell existieren.

---

### **1.4 Zusammenfassung**

Die wesentlichen Abweichungen ergeben sich daraus, dass Sprint 1 bewusst nur eine
**minimal funktionsfähige Bedienkette** („Eingabe → Validierung → Anzeige“)
implementieren sollte.  
Die Architektur beschreibt das komplette System, die Implementierung dagegen nur den
ersten funktionalen Teilbereich.

Diese Abweichungen sind dokumentiert und dienen der Planung der Folge-Sprints.

## 2. Abweichungsanalyse Sprint 1

Im Zuge des Vergleichs von Architektur, Design und Implementierung konnten folgende Abweichungen festgestellt werden:

### 2.1 Präsentationsschicht (UserInterface)
Die Architektur sieht eine vollständige UserInterface-Komponente vor, welche sowohl Temperatureingaben verarbeitet als auch Rückmeldungen an Nutzer (LED, Signalton) ausgibt. In der Implementierung wird die Temperatureingabe bereits korrekt umgesetzt, jedoch existiert noch keine separate UI-Klasse für visuelle und akustische Rückmeldungen. Stattdessen übernimmt der DisplayController Teile dieser Aufgabe.

### 2.2 TemperatureController
Laut Architektur soll der TemperatureController Soll- und Ist-Werte vergleichen, die Heizleistung steuern und Sensorwerte verarbeiten. In Sprint 1 wurden ausschließlich Funktionen zur Verarbeitung der Solltemperatur implementiert. Regelungslogik und Sensorverarbeitung folgen in Sprint 2.

### 2.3 SafetyManager
Der SafetyManager ist Bestandteil der Architektur, wurde jedoch im Rahmen der Sprint-1-Implementierung noch nicht umgesetzt, da sicherheitsrelevante Temperaturüberwachung erst in Sprint 2 vorgesehen ist.

### 2.4 Hardwareabstraktionsschicht (HAL)
Die Architektur umfasst drei getrennte Hardwaremodule: SensorInterface, HeaterControl und DisplayDriver. Im aktuellen Implementierungsstand existiert nur der DisplayController. SensorInterface und HeaterControl folgen in kommenden Sprints.

### 2.5 Schnittstellenverhalten
Architektur und Schnittstellenbeschreibung sehen teilweise asynchrone Ereignisse vor (Callbacks, Interrupts). In der Implementierung werden in Sprint 1 ausschließlich synchrone Funktionsaufrufe genutzt. Diese Abweichung ist geplant und wird in Sprint 2 korrigiert, sobald Sensoren integriert werden.

Alle Abweichungen sind konsistent mit dem in Sprint 1 definierten Umfang und daher nicht kritisch.

## 3. Erkenntnisse für kommende Sprints und notwendige Anpassungen

Während und nach Abschluss von Sprint 1 wurden mehrere wichtige Erkenntnisse gewonnen,
die Einfluss auf die zukünftige Architektur, das Design und die Implementierung haben
werden.

### 3.1 Erkenntnis: Die UI-Komponente muss stärker modularisiert werden
Die momentane Implementierung verwendet eine Konsoleneingabe als Platzhalter für das
Touch-Bedienfeld. Für reale Hardware oder eine GUI wird eine klare Trennung von:

- Eingabelogik  
- Anzeige-Logik  
- Fehler-/Statusmeldungen  

notwendig.  
Damit wird das System testbarer und portabler.

➡ **Geplante Änderung in Sprint 2:**  
Einführung eines „UIService“, der zwischen Controller und DisplayDriver vermittelt.

---

### 3.2 Erkenntnis: Die Logikschicht muss erweiterbar bleiben
Der TemperatureController erfüllt aktuell nur Basisfunktionen (Sollwert setzen, Anzeige aktualisieren).  
Für die weitere Entwicklung ist eine flexible Architektur notwendig, die:

- Sensorwerte fortlaufend einliest  
- Heizleistung dynamisch regelt  
- Sicherheitslogik integriert  

➡ **Geplante Änderung in Sprint 2:**  
Erweiterung des Controllers um eine periodische Aktualisierungsroutine (z. B. `update()`).

➡ **Geplante Änderung in Sprint 3:**  
Einführung eines asynchronen Event-Systems (Callbacks/Observer Pattern).

---

### 3.3 Erkenntnis: SafetyManager wird ein kritischer Teil des Gesamtentwurfs
Der SafetyManager wurde im Architekturmodell vorgesehen, aber noch nicht implementiert.  
Er wird später benötigen:

- Sensorüberwachung  
- Grenzwertkontrollen  
- Heizabschaltung bei Übertemperatur  
- Anzeige von Warnungen  

➡ **Geplante Änderung in Sprint 3:**  
Implementierung des SafetyManager + Ankopplung an DisplayDriver und Controller.

---

### 3.4 Erkenntnis: HAL-Schicht benötigt klare Schnittstellen
Die geplanten HAL-Komponenten (`SensorInterface`, `HeaterControl`) existieren bereits
als Architekturkonzept, aber noch nicht im Code.

Um Fehler zu vermeiden, werden die Schnittstellen strikt definiert, bevor Hardware simuliert wird.

➡ **Geplante Änderung in Sprint 2:**  
Implementieren von Hardware-Simulationen („Mock-Sensor“, „Mock-Heater“)  
für Testbarkeit ohne echte Geräte.

---

### 3.5 Erkenntnis: Einige Requirements müssen für Testbarkeit präzisiert werden
Requirements wie „Anzeige soll aus 1 m lesbar sein“ oder „Reaktionszeit ≤ 500 ms“
benötigen:

- Messmethoden  
- Testkriterien  
- Mock-Umgebungen  

➡ **Geplante Änderung in Sprint 2:**  
Erstellung eines Testkonzepts für nicht-funktionale Anforderungen.

---

### **3.6 Zusammenfassung**
Die Erkenntnisse führen zu folgenden Kernanpassungen:

- Bessere Modularisierung der UI  
- Erweiterung der Logik um kontinuierliche Temperaturregelung  
- Implementierung einer echten Sicherheitslogik  
- Präzise definierte HAL-Schnittstellen  
- Einrichtung einer Hardware-Simulationsumgebung  
- Vorbereitung für asynchrone Kommunikation (Events/Observer)

Diese geplanten Änderungen sichern die
*Wartbarkeit*, *Erweiterbarkeit* und *Zuverlässigkeit* der Software im weiteren Projektverlauf.

## 4. Erkenntnisse für Sprint 2 und Sprint 3

Im Rahmen von Sprint 1 wurden verschiedene technische und konzeptionelle Erkenntnisse gewonnen, die Änderungen in der Architektur, dem Design und der Implementierung nach sich ziehen:

### 4.1 Einführung des SafetyManagers in Sprint 2
Die Überwachung der Temperaturgrenzen ist für die sichere Steuerung einer Heißluftfritteuse essenziell. Daher wird der SafetyManager ab Sprint 2 implementiert.

### 4.2 Integration eines SensorInterface
Für die Regelung der Heizleistung wird die Erfassung der Ist-Temperatur benötigt. Dies erfordert die Einführung der Klasse SensorInterface in Sprint 2.

### 4.3 Einführung von HeaterControl
Die Architektur sieht vor, dass die Heizleistung separat über ein Hardwareinterface gesteuert wird. Diese Klasse wird in Sprint 2 implementiert.

### 4.4 Übergang zu asynchronen Schnittstellen
In Sprint 1 wurden ausschließlich synchrone Aufrufe genutzt. Die Architektur sieht jedoch asynchrone Schnittstellen (Callbacks, Events) vor. Diese werden ab Sprint 2 teilweise umgesetzt.

### 4.5 Separation of Concerns im UI
Der DisplayController übernimmt aktuell auch Teile der UserInterface-Aufgaben. Das UI wird in Sprint 2 als eigene Klasse umgesetzt, um eine saubere Logiktrennung sicherzustellen.

Diese Erkenntnisse bilden die Grundlage für die Planung von Sprint 2 und 3.




