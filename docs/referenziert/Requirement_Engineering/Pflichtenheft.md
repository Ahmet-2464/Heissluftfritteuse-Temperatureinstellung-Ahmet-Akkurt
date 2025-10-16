# Pflichtenheft: Heißluftfritteuse – Temperatureinstellung

### 1. Temperatureingabe  
- Implementierung eines Touch-Bedienfelds mit numerischer Eingabe oder Drehregler.  
- Temperaturwahl in 5 °C-Schritten zwischen 80 °C und 200 °C.  
- Die Eingabe muss eine Reaktionszeit ≤ 500 ms aufweisen.  

### 2. Temperaturanzeige  
- Darstellung der eingestellten Temperatur auf einem kontrastreichen LCD-Display.  
- Anzeige muss aus 1 m Entfernung klar lesbar sein, auch bei schlechten Lichtverhältnissen.  
- Aktualisierung der Anzeige erfolgt unmittelbar (< 200 ms Verzögerung).  

### 3. Temperaturregelung  
- Die Heißluftfritteuse heizt die Kammer auf den Sollwert auf und hält diesen automatisch konstant (Regelgenauigkeit ±3 °C).  
- Bei Überschreitung von 210 °C erfolgt eine sofortige Abschaltung der Heizelemente (innerhalb von 2 Sekunden).  

### 4. Nutzer-Rückmeldung  
- Ein akustisches Signal ertönt, sobald die Zieltemperatur erreicht ist (mindestens 60 dB in 1 m Entfernung).  
- Eine LED leuchtet zusätzlich zur akustischen Rückmeldung auf.  
- Signalisierung erfolgt spätestens 1 Sekunde nach Erreichen der Temperatur.  

### 5. Sicherheitsmechanismen  
- Übertemperaturschutz mit Abschaltung bei Überschreitung von 210 °C.  
- Fehlererkennung und Anzeige (z. B. Überhitzung, Sensorfehler).  
- System arbeitet auch bei Netzspannungsschwankungen von ±10 % zuverlässig.  

### 6. Bedienkomfort und Barrierefreiheit  
- Die Temperatureinstellung ist durch große, gut beschriftete Bedienelemente auch für ältere Nutzer einfach bedienbar.  
- Die Anzeige nutzt kontrastreiche Farben und Symbole, die auch für Farbenblinde verständlich sind.  

### 7. Robustheit und Zuverlässigkeit  
- Temperatureinstellung und Anzeige funktionieren fehlerfrei bei Umgebungstemperaturen von 0 °C bis 40 °C und Luftfeuchtigkeit von 20 % bis 90 %.  
- Die Komponenten sind auf eine Lebensdauer von mindestens 1 Mio. Bedienzyklen ausgelegt.  

### 8. Design und Integration  
- Das Bedienfeld und Display sind ergonomisch in die Frontseite der Heißluftfritteuse integriert und nehmen maximal 15 % der Frontfläche ein.  
- Die Helligkeit des Displays ist automatisch dimmbar, um bei Nachtbetrieb nicht zu blenden.  