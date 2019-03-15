#ifndef MORSE_H
#define MORSE_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MORSE_NULL 0    // NULL
#define MORSE_DI 1      // SHORT MARK
#define MORSE_DAH 2     // LONG MARK
#define MORSE_DIT 3     // SHORT ENDING MARK
#define MORSE_GAP 4     // BETWEEN CHARACTERS
#define MORSE_CHAR 5    // BETWEEN LETTERS
#define MORSE_WORD 6    // BETWEEN WORDS
#define MORSE_PHRASE 7  // END TRANSMITION

#define MORSE_INVALID_CHAR 0x7C

class Morse {
  private:
    typedef void (*morsePointer) (uint8_t *);

    uint16_t _buffer = 1;

    morsePointer _transmiter;
    morsePointer _receiver;

    uint8_t clear(uint8_t label);
    uint8_t count(uint8_t value);
    uint16_t decode();
    uint16_t encode(uint8_t character);

    uint8_t label(uint8_t tag);
    void send(uint8_t tag);

  public:
    explicit Morse() {};

    void begin(morsePointer tx, morsePointer rx);
    void clear();
    void listen(uint8_t tag = MORSE_NULL);
    String read(String data);
    void receiver(morsePointer pointer);
    void transmiter(morsePointer pointer);
    void write(String data);
    void writeln(String data);
};

#endif
