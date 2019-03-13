#include "Morse.h"

Morse morse;

String s;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  morse.event = callback;
  morse.transmit("sending morse code...");
  Serial.println(s);
  Serial.println(morse.receipt(s));
}

void callback(int8_t *e) {
  s += String(*e);

  if (*e == MORSE_CHAR) Serial.print(" CHAR ");
  if (*e == MORSE_LETTER) Serial.println(" LETTER ");
  else if (*e == MORSE_WORD) Serial.println(" WORD ");
  else if (*e == MORSE_PHRASE) Serial.println(" PHRASE ");
  else {
    if (*e == MORSE_DI) Serial.print(" DI ");
    else if (*e == MORSE_DIT) Serial.print(" DIT ");
    else if (*e == MORSE_DAH) Serial.print(" DAH ");
    else {
      Serial.print(" ");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
