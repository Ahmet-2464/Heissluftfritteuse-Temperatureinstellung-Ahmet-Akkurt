<style>
  .muss {
    background-color: rgba(51, 170, 51, .4)
  }
</style>
<style>
  .soll {
    background-color: rgba(255, 174, 0, 0.4);
  }
</style>
<style>
  .kann {
    background-color: rgba(170, 51, 51, 0.4);
  }
</style>

# Requirements: Heißluftfritteuse - Temperatureinstellung

**Legende:** <p class="muss">Muss-Requirement<p> <p class="soll">Soll-Requirement<p> <p class="kann">Kann-Requirement<p>

### 1. Funktionale Requirements

<table>
  <thead>
    <tr>
      <th>Nr.</th>
      <th>Titel</th>
      <th>Beschreibung</th>
    </tr>
  </thead>
  <tbody>
    <tr class="muss">
      <td>1.1</td>
      <td>Temperaturwahl über Bedienfeld</td>
      <td>Das System muss dem Nutzer ermöglichen, die gewünschte Temperatur über ein Touch-Bedienfeld einzugeben.</td>
    </tr>
    <tr class="muss">
      <td>1.2</td>
      <td>Temperaturbereich & Schrittweite</td>
      <td>Das System muss Eingaben in 5 °C-Schritten zwischen 80 °C und 200 °C verarbeiten.</td>
    </tr>
    <tr class="muss">
      <td>2.1</td>
      <td>Temperaturanzeige auf Display</td>
      <td>Das System muss die eingestellte Temperatur auf einem Display anzeigen.</td>
    </tr>
    <tr class="soll">
      <td>2.2</td>
      <td>Sofortige Aktualisierung der Anzeige</td>
      <td>Die Anzeige soll sich bei jeder Änderung der Temperatur sofort aktualisieren.</td>
    </tr>
    <tr class="muss">
      <td>3.1</td>
      <td>Aufheizen auf Solltemperatur</td>
      <td>Das System muss die Temperatur auf den eingestellten Sollwert aufheizen.</td>
    </tr>
    <tr class="muss">
      <td>3.2</td>
      <td>Automatische Temperaturregelung</td>
      <td>Das System muss die eingestellte Temperatur während des Garvorgangs automatisch regeln.</td>
    </tr>
    <tr class="muss">
      <td>4.1</td>
      <td>Automatische Abschaltung bei Übertemperatur</td>
      <td>Das System muss die Heizung automatisch abschalten, wenn 210 °C überschritten werden.</td>
    </tr>
    <tr class="soll">
      <td>4.2</td>
      <td>Warnmeldung bei Übertemperatur</td>
      <td>Das System soll eine Warnmeldung auf dem Display anzeigen, wenn die Temperatur über dem Grenzwert liegt.</td>
    </tr>
    <tr class="soll">
      <td>5.1</td>
      <td>Akustisches Signal bei Zieltemperatur</td>
      <td>Das System soll ein akustisches Signal ausgeben, wenn die Zieltemperatur erreicht ist.</td>
    </tr>
    <tr class="kann">
      <td>5.2</td>
      <td>LED-Anzeige bei Zieltemperatur</td>
      <td>Das System kann zusätzlich eine LED-Anzeige aktivieren, wenn die Zieltemperatur erreicht ist.</td>
    </tr>
  </tbody>
</table>




### 2. Nicht-funktionale Requirements

<table>
  <thead>
    <tr>
      <th>Nr.</th>
      <th>Titel</th>
      <th>Beschreibung</th>
    </tr>
  </thead>
  <tbody>
    <tr class="soll">
      <td>1.3</td>
      <td>Reaktionsgeschwindigkeit der Eingabe</td>
      <td>Die Reaktionszeit auf eine Eingabe soll maximal 500 ms betragen.</td>
    </tr>
    <tr class="soll">
      <td>2.3</td>
      <td>Lesbarkeit der Anzeige</td>
      <td>Die Displayhelligkeit soll aus einem Abstand von 1 m klar lesbar sein.</td>
    </tr>
    <tr class="kann">
      <td>2.4</td>
      <td>Aktualisierungszeit der Anzeige</td>
      <td>Die Aktualisierung der Anzeige kann innerhalb von 200 ms nach einer Eingabe erfolgen.</td>
    </tr>
    <tr class="muss">
      <td>3.3</td>
      <td>Temperaturgenauigkeit</td>
      <td>Die Temperaturabweichung muss ±3 °C nicht überschreiten.</td>
    </tr>
    <tr class="soll">
      <td>3.4</td>
      <td>Maximale Aufheizzeit</td>
      <td>Die Aufheizzeit auf 200 °C soll maximal 5 Minuten betragen.</td>
    </tr>
    <tr class="muss">
      <td>4.3</td>
      <td>Reaktionszeit Sicherheitsabschaltung</td>
      <td>Die Sicherheitsabschaltung muss innerhalb von maximal 2 Sekunden nach Erreichen des Grenzwerts erfolgen.</td>
    </tr>
    <tr class="soll">
      <td>4.4</td>
      <td>Zuverlässigkeit bei Spannungsschwankungen</td>
      <td>Die Sicherheitsfunktion soll auch bei Netzspannungsschwankungen von ±10 % zuverlässig arbeiten.</td>
    </tr>
    <tr class="soll">
      <td>5.3</td>
      <td>Lautstärke des Signals</td>
      <td>Das akustische Signal soll eine Lautstärke von mindestens 60 dB in 1 m Entfernung haben.</td>
    </tr>
    <tr class="muss">
      <td>5.4</td>
      <td>Signalisierungszeit</td>
      <td>Die Rückmeldung muss spätestens 1 Sekunde nach Erreichen der Zieltemperatur erfolgen.</td>
  </tbody>
</table>


