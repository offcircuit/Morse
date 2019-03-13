#ifndef MORSE_H
#define MORSE

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MORSE_DIT
#define MORSE_DAH
#define MORSE_WORD
#define MORSE_SHORT
#define MORSE_
#define MORSE_LONG

class Morse {
  public:
    typedef void (*morsePointer) (bool*);

    morsePointer pulse;

    explicit Morse() {};
    uint8_t encode(char c);

    void send(String data) {
      data.toUpperCase();
      for (size_t i = 0; i < data.length(); i++) {
        uint8_t code = encode(data[i]);
        do if (pulse) pulse(code % 2);
        while ((code = code >> 1) > 1);
        pulse(0);
      }
    }
};

#endif
