# Modulstruktur

## Beschreibung

Die Git-Projektstruktur für das Software-System „Heißluftfritteuse – Temperatureinstellung“ orientiert sich direkt an der im Klassendiagramm definierten Architektur und folgt einer modularen Trennung nach Verantwortlichkeiten und Software-Layern.
Jedes Modul entspricht einem logischen Teil des MVC-Designs (Model, View, Controller) und enthält den zugehörigen Code, Dokumentation und Testkomponenten.


![alt text](<../referenziert/Requirement_Engineering/design/Modulstruktur_anhand_des_Codes.png>)




## Begründung der Modulstruktur

1. Klare Trennung nach Verantwortlichkeiten (Separation of Concerns):

    - Jede Komponente ist einem Paket zugeordnet (UserInterface, ControlLogic, HardwareAbstraction, PersistenceManager).

    - Dies entspricht dem im Klassendiagramm verwendeten MVC-Designpattern.

2. Einfache Wartung und Erweiterung:

    - Änderungen an der Benutzeroberfläche (z. B. Display oder Eingabe) beeinflussen nicht die Steuerlogik oder
      Hardware-Ansteuerung.

    - Neue Hardwarekomponenten (z. B. Temperatursensoren anderer Hersteller) können leicht integriert werden, indem man
      nur das hardwareabstraction-Modul erweitert.

3. Nachvollziehbare Verbindung zum UML-Design:

    - Jede Klasse aus dem Klassendiagramm ist im Quellcode-Verzeichnis src/ logisch angeordnet.

    - Diese Struktur spiegelt direkt die Schichten des Diagramms wider.

4. Erweiterte Projektorganisation:

    - Der Ordner docs/ dient der Nachvollziehbarkeit der Entwicklungsphasen (Requirements, Design, Sprint-Artefakte).

    - Der Ordner lib/ enthält externe Abhängigkeiten.

    - Die Verzeichnisstruktur ermöglicht eine einfache Integration in CI/CD-Systeme und Versionsverwaltung (GitHub
      GitLab).


## Zusammenhang mit dem Design Pattern

**Die Modulstruktur wurde auf Basis des MVC-Musters erstellt:**

    - Model: hardwareabstraction & persistencemanager

    - View: userinterface

    - Controller: controllogic

Diese Aufteilung unterstützt zusätzlich das Observer Pattern, da Ereignisse (z. B. Übertemperatur) von der ControlLogic automatisch an die UserInterface-Schicht weitergegeben werden können.

# Fazit

Die Git-Modulstruktur bildet das im UML-Design definierte Softwarekonzept vollständig ab.
Durch die klare Schichtung nach MVC und die modulare Unterteilung in Quellcode, Dokumentation und Bibliotheken ist das Projekt wartbar, erweiterbar und übersichtlich organisiert.