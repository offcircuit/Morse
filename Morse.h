#ifndef MORSE_H
#define MORSE

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MORSE_DI 0
#define MORSE_DAH 1
#define MORSE_DIT 2
#define MORSE_CHAR 3
#define MORSE_LETTER 4
#define MORSE_WORD 5
#define MORSE_PHRASE 6

class Morse {
  public:
    typedef void (*morsePointer) (uint8_t *);
    morsePointer pointer;

    explicit Morse() {};
    
    uint8_t encode(char c);
    void pulse(int8_t e);
    void send(String data);
};

#endif
