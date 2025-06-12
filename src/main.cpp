/**
 * @name            Byte auf Display darstellen
 *
 * @brief           Praktikumsaufgabe GTI
 *                  Grundlagen der technischen Informatik | TH Köln (SS2025)
 *
 * @author          Prof. Dr. Markus Stockmann
 * @version         v1
 */

#include <Arduino.h>

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
 * @fn          Pre Setup
 *
 * @brief       Pseudofunktion zum Testen, ob reservierte Bits geaendert
 *              wurden
 */
void preSetup(void);

/**
 * @fn          Input Byte
 * @note        HAS (Hardwareabstraktionsschicht)
 *
 * @brief       Einlesen und Abspeichern an Adresse ReadValue
 *
 * @param[in]   PortName The port to read from (PB, PC, or PD)
 * @param[out]  ReadValue Pointer to store the read byte value
 * @return      BYTE       Always returns 0
 */
BYTE InputByte(PORT PortName, BYTE* ReadValue);

/**
 * @fn          Output Byte
 * @note        HAS (Hardwareabstraktionsschicht)
 *
 * @brief       Ausgabe des Bytes WriteValue am Port PortName
 *
 * @param[in]   PortName  The port to write to (PB, PC, or PD)
 * @param[in]   WriteValue The byte value to write to the specified port
 * @return      BYTE        Always returns 0
 */
BYTE OutputByte(PORT PortName, BYTE WriteValue);

/**
 * @fn          Read Potentiometer
 *
 * @brief       Liest den Potentiometer-Wert (0...1023) ein und wandelt ihn in
 *              ein Byte (0...255) um.
 *
 * @param[out]  valPoti Pointer to store the converted potentiometer value
 *              (0-255)
 * @return      int 0 if successful, non-zero error code otherwise
 *              (Error occurs with ~2% probability as a simulation)
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
      Loop
*/

void loop() {

  preSetup(); // Rote LED darf nicht leuchten, Gruene muss leuchten

  /** ------------------------------------------------------------------

                        Ihr Code ⬇











                        Ihr Code ⬆

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

// Pre Setup Definition
void preSetup(void) {
  // Pseudo-Funktion soll testen, ob reservierte Bits geändert wurden
  BYTE PDval = 0b00000000;
  BYTE PBval = 0b00100000;

  DDRD = 0b00000010; // Output := 1, Input := 0
  DDRB = 0b00100100; // Output := 1, Input := 0

  OutputByte(PD, PDval);
  OutputByte(PB, PBval);
}

// Input Byte Definition
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

// Output Byte Definition
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

//  Read Potentiometer Definition
int readPoti(BYTE* valPoti) {
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