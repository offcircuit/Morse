#include "Morse.h"

Morse morse;

String s;

void receiver(char e) {
  Serial.print(e);
  delay(50);
}

void transmiter(int8_t e) {
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  morse.begin(transmiter, receiver);
  
  Serial.println("-- WRITE MESSAGE --");
  morse.write("sending ");
  morse.writeln("morse code...");
  Serial.println("");

  Serial.println("-- MESSAGE RECEIVED --");
  Serial.println(s);
  Serial.println("");
  
  Serial.println("-- READ RECEIVED --");
  Serial.println(morse.read(s));
  Serial.println("");
  
  Serial.println("-- READ RECEIVED STEP BY STEP --");
  for (int i = 0; i < s.length(); i++) morse.listen(String(s[i]).toInt());
}

void loop() {
  // put your main code here, to run repeatedly:

}
