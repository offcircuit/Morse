#ifndef MORSE_H
#define MORSE

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MORSE_DI 0 // SHORT MARK
#define MORSE_DAH 1 // LONG MARK
#define MORSE_DIT 2 // SHORT ENDING MARK
#define MORSE_CHAR 3 // BETWEEN CHARACTERS
#define MORSE_LETTER 4 // BETWEEN LETTERS
#define MORSE_WORD 5 // BETWEEN WORDS
#define MORSE_PHRASE 6 // END TRANSMITION

class Morse {
  private:
    typedef void (*morsePointer) (uint8_t *);
    
    uint8_t encode(char c);
    void pulse(int8_t e);

  public:
    morsePointer event;

    explicit Morse() {};
    explicit Morse(morsePointer pointer): event(pointer) {};

    void transmit(String data);
};

#endif
