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
