#include "Morse.h"

Morse m;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m.pulse = mm;
  m.send("abcd");
}

void mm(bool pulse) {
  Serial.println(pulse);
}

void loop() {
  // put your main code here, to run repeatedly:

}
