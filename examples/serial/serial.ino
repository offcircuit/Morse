#include "Morse.h"

Morse morse;

String s;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("SEND MESSAGE ----------------------------------------------------------");

  morse.transmit = callback;
  morse.write("send<ing morse code ...<");

  Serial.println("");
  Serial.println("PRINT CODE ------------------------------------------------------------");
  Serial.println(s);

  Serial.println("");
  Serial.println("CONVERT CODE ----------------------------------------------------------");
  Serial.println(morse.read(s));

  Serial.println("");
  Serial.println("CONVERT CODE STEP BY STEP ---------------------------------------------");
  for (int i = 0; i < s.length(); i++) {
    Serial.print(morse.receive(String(s[i]).toInt()));
    delay(20);
  }

  Serial.println("");
  Serial.println("-----------------------------------------------------------------------");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void callback(int8_t e) {
  s += String(e);
  if (e == MORSE_GAP) Serial.print(" GAP ");
  if (e == MORSE_CHAR) Serial.println(" CHAR ");
  else if (e == MORSE_WORD) Serial.println(" WORD ");
  else if (e == MORSE_PHRASE) Serial.println(" PHRASE ");
  else {
    if (e == MORSE_DI) Serial.print(" DI ");
    else if (e == MORSE_DIT) Serial.print(" DIT ");
    else if (e == MORSE_DAH) Serial.print(" DAH ");
    else {
      Serial.print(" ");
    }
  }
}
