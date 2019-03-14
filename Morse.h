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

    uint16_t _buffer = 1;

    uint8_t clear(uint8_t tag);
    uint8_t count(uint8_t value);
    uint8_t decode();
    uint16_t encode(uint16_t character);

    void pulse(int8_t signal);
    uint8_t tag(uint8_t signal);

  public:
    morsePointer transmit;

    explicit Morse() {};
    explicit Morse(morsePointer pointer): transmit(pointer) {};

    void clear();
    String read(String data);
    char receive(uint8_t signal);
    void write(String data);
};

#endif
