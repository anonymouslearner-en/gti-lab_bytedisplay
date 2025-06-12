/**
 * @file            Byte auf Display darstellen
 *
 * @brief           Praktikumsvorbereitung
 *                  Praktische Informatik 2 | TH Köln
 *
 * @author          Prof. Dr. Markus Stockmann
 * @version
 */

#include <Arduino.h>

/*
    ACHTUNG:

    Bitte nutzen Sie anstatt des bekannten int main(void) Aufbaus
    eine void setup() + void loop() Struktur, wie folgend dargestellt.

    Die Funktion setup() wird dabei bei der Abarbeitung einmal durchlaufen
    und die Funktion loop() anschließend permanent.
 */

// typ bool ist bereits deklariert
typedef unsigned char uint8_t;
typedef unsigned char BYTE;
typedef enum { PB, PC, PD } PORT;
typedef enum { K0 = 0, K1, K2, K3, K4, K5, K6, K7 } CHANNEL;

/** ------------------------------------------------------------------

                      Funktionsdeklarationen
                      *als vorwärtsdeklaration
                      (für Defintionen siehe unten)

------------------------------------------------------------------- */

/**
 * @fn        Pre Setup
 *
 * @brief     Pseudofunktion zum Testen, ob reservierte Bits geaendert
 *            wurden
 */
void preSetup(void);

/**
 * @fn        Input Byte
 * @note      HAS (Hardwareabstraktionsschicht)
 *
 * @brief     Takes formatted stream input & populates data into a struct object
 *
 * @param[out] PortName
 * @param[out] ReadValue
 * @return    bool [true = operation successful] [false = operation unsuccesful]
 */
BYTE InputByte(PORT PortName, BYTE* ReadValue);

/**
 * @fn        Input Byte
 * @note      HAS (Hardwareabstraktionsschicht)
 *
 * @brief     Takes formatted stream input & populates data into a struct object
 *
 * @param[out] PortName
 * @param[out] ReadValue
 * @return    bool [true = operation successful] [false = operation unsuccesful]
 */
BYTE OutputByte(PORT PortName, BYTE WriteValue);

/**
 * @fn        Input Byte
 *
 * @brief     Takes formatted stream input & populates data into a struct object
 *
 * @param[out] PortName
 * @param[out] ReadValue
 * @return    bool [true = operation successful] [false = operation unsuccesful]
 */
int readPoti(BYTE* valPoti);

/** ------------------------------------------------------------------

                      Hauptprogramm
                      (void setup() + void loop() Struktur)

------------------------------------------------------------------- */
/*
      Set Up
*/
void setup() {
  // Code, der nur einmal ausgeführt wird
}

/*
      Set Up
*/

void loop() {

  preSetup(); // Rote LED darf nicht leuchten, Gruene muss leuchten

  /** ------------------------------------------------------------------

                        Ab hier Ihr Code

------------------------------------------------------------------- */

  /*
      Do nothing more, wegen Umstrickung main() --> loop(), nach Fehler
      "Abbruch"
  */
  while (1) {
  }
}

/** ------------------------------------------------------------------

                      Funktionsdefinitionen
                      *Deklarationen siehe oben

------------------------------------------------------------------- */

//
void preSetup(void) {
  // Pseudo-Funktion soll testen, ob reservierte Bits geändert wurden
  BYTE PDval = 0b00000000;
  BYTE PBval = 0b00100000;

  DDRD = 0b00000010; // Output := 1, Input := 0
  DDRB = 0b00100100; // Output := 1, Input := 0

  OutputByte(PD, PDval);
  OutputByte(PB, PBval);
}

//
BYTE InputByte(PORT PortName, BYTE* ReadValue) {
  // Hardwareabstraktionsschicht, Einlesen und Abspeichern an Adresse ReadValue
  if (PortName == PB) {
    *ReadValue = PINB;
  } else if (PortName == PC) {
    *ReadValue = PINC;
  } else if (PortName == PD) {
    *ReadValue = PIND;
  }
  return 0;
}

//
BYTE OutputByte(PORT PortName, BYTE WriteValue) {
  // Hardwareabstraktionsschicht, Ausgabe des Bytes WriteValue am Port PortName
  if (PortName == PB) {
    PORTB = WriteValue;
  } else if (PortName == PC) {
    PORTC = WriteValue;
  } else if (PortName == PD) {
    PORTD = WriteValue;
  }
  return 0;
}

//
int readPoti(BYTE* valPoti) {
  // Funktion, die den PotiWert (0...1023) einlies und
  // in ein Byte umwandelt.
  // Rueckgabewert <> 0 --> Fehler
  // Ergebnis wird an die Adresse von valPoti geschrieben
  int returnVal = 0;
  int randNumber = random(100); // Random number for error code
  int valPoti10Bit = analogRead(A0);
  *valPoti = map(valPoti10Bit, 0, 1023, 0, 255);
  if (randNumber > 98)
    returnVal = randNumber; // Return Value depending on random number
  return (returnVal);
}