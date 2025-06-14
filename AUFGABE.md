# Aufgabenbeschreibung:

Es soll eine Steuerung aufgebaut werden, welche ein eingelesenes
Byte auf einer vierstelligen 7 Segmentanzeige als
Dezimaläquivalent darstellt.
Das eingelesene Byte wird hier durch die Veränderung eines Potis
vorgegeben. Die Steuerung soll auf einem µC (AT-Mega 328, Arduino Uno)
realisiert werden.

> [!WARNING]
> Bitte nutzen Sie anstatt des bekannten int main(void) Aufbaus eine void setup() + void loop() Struktur, wie folgend dargestellt. Die Funktion setup() wird dabei bei der Abarbeitung einmal durchlaufen und die Funktion loop() anschließend permanent.

Folgende Pin Belegung ist zu beachten
Port B
Bit 0/1/2/3/4/5/6/7
Bez yG/yDig1/yDig2/yDig3/yDig4/Res/Res/Res

Port D
Bit 0/1/2/3/4/5/6/7
Bez Res/Res/yA/yB/yC/yD/yE/yF

- [ ] R1: Das eingelesene Byte soll als Dezimaläquivalent auf der
      Siebensegmentanzeige fortwährend dargestellt werden.
- [ ] R2: Die hier verwendete Anzeige verfügt über vier 7
      Segmentanzeigen. Jede 7Segmentanzeige wiederum aus sieben
      LEDs (A,B,C,...,G), s. https://docs.wokwi.com/parts/wokwi-7segment
      Die einzelnen 7Segmentanzeigen lassen sich durch ein Löschen der Bits
      yDig1, ..., yDig4 ansteuern --> yDig1 = 0 und yDig 2 = 0
      --> yA,yB, ..., yG Anzeige wird an erster Stelle (yDig1, ganze rechts)
      und an zweiter Stelle (yDig2) dargestellt.
      Die einzelnen LEDs (yA,..., yG) werden zum Leuchten gebracht, indem
      die Bits yA, yB, ... gesetzt werden.

- [ ] R3: Der Mikrocontroller soll fortlaufend die Funktion readPoti aufrufen,
      um das Byte einzulesen.
      Diese Funktion liefert als Rückgabewert eine Null, wenn das Einlesen
      des Potis funktioniert hat. Die Funktion wird über
      call by reference aufgerufen, s. Funktionssignatur.

- [ ] R4: Die Datenrichtungen sollen in einer InitIO() Funktion eingestellt werden.

- [ ] R5: Alle Ausgänge sollen zu Beginn auf 1 initialisiert werden.

- [ ] R6: Nutzen Sie zum Lesen und Schreiben der digitalen Ein- und
      Ausgänge die Funktionen InputByte und OutputByte der HAS.

- [ ] R7: Wird entweder in der HAS oder beim Einlesen des Poti Bytes
      ein Fehlerwert zurückgegeben, soll auf allen 7Segmentanzeigen
      eine 1 dargestellt werden.

- [ ] R8: Reservierte Bits dürfen nicht in Wert oder Datenrichtung geändert werden.
      Ausgänge sind rücklesbar.
