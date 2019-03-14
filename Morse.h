#ifndef MORSE_H
#define MORSE

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MORSE_DI 0      // SHORT MARK
#define MORSE_DAH 1     // LONG MARK
#define MORSE_DIT 2     // SHORT ENDING MARK
#define MORSE_GAP 3     // BETWEEN CHARACTERS
#define MORSE_CHAR 4    // BETWEEN LETTERS
#define MORSE_WORD 5    // BETWEEN WORDS
#define MORSE_PHRASE 6  // END TRANSMITION

#define MORSE_INVALID_CHAR 0x7C

class Morse {
  private:
    typedef void (*morsePointer) (uint8_t *);

    String _buffer = "";

    char decode();
    uint16_t encode(char character);
    void pulse(int8_t sign);

  public:
    morsePointer event;

    explicit Morse() {};
    explicit Morse(morsePointer pointer): event(pointer) {};

    String receipt(String data);
    String signal(uint8_t sign);
    void transmit(String data);
};

#endif
