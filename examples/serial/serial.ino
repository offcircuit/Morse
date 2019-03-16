#include "Morse.h"

Morse morse;

String s;

void receiver(char e) {
  // receiving a message (letter by letter)

  Serial.print(e);
  delay(50);
}

void transmiter(uint8_t e) {
  // transmitting a message (tag by tag)

  s += String(e);
  if (e == MORSE_GAP) Serial.print("");
  if (e == MORSE_CHAR) Serial.print("/");
  else if (e == MORSE_SPACE) Serial.print("   ");
  else if (e == MORSE_EOL) Serial.println(" EOL ");
  else {
    if (e == MORSE_DI) Serial.print("_");
    else if (e == MORSE_DIT) Serial.print("-");
    else if (e == MORSE_DAH) Serial.print("¯");
    else {
      Serial.print("");
    }
  }
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  morse.begin(receiver, transmiter);

  Serial.println("-- PRINT MESSAGE WITHOUT EOL --");
  morse.print("se<n");

  Serial.println("");
  Serial.println("-- PRINT MESSAGE WITH EOL --");
  morse.println("ding morse code...<");

  Serial.println("");

  Serial.println("-- MESSAGE RECEIVED (ENCODED)--");
  Serial.println(s);
  Serial.println("");

  Serial.println("-- READ RECEIVED MESSAGE --");
  Serial.println(morse.read(s));
  Serial.println("");

  Serial.println("-- READ RECEIVED TAG BY TAG --");
  for (int i = 0; i < s.length(); i++) morse.listen(String(s[i]).toInt());

  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
}
