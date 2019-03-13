#include "Morse.h"

char Morse::decode(String character) {
  uint8_t binary = 0, exponent = 1;

  for (size_t i = character.length(); i > 0; i--) {
    binary += exponent * (character[i - 1] == 49);
    exponent *= 2 ;
  }

  if (encode(13) == binary) return char(13);
  for (size_t i = 32; i <= 90; i++) if (encode(char(i)) == binary) return char(i);
}

uint8_t Morse::encode(char character) {
  switch (character) {
    case 13: return 0b1101100;    // EOL

    case 32: return 0b0;          // SPACE

    case 33: return 0b1110101;    // !
    case 34: return 0b1010010;    // "
    case 36: return 0b11001000;   // $

    case 38: return 0b100010;     // &
    case 39: return 0b1011110;    // '
    case 40: return 0b101101;     // (
    case 41: return 0b1101101;    // )
    case 44: return 0b1110011;    // ,
    case 45: return 0b1100001;    // -
    case 46: return 0b1101010;    // .
    case 47: return 0b101001;     // /

    case 48: return 0b111111;     // 0
    case 49: return 0b111110;     // 1
    case 50: return 0b111100;     // 2
    case 51: return 0b111000;     // 3
    case 52: return 0b110000;     // 4
    case 53: return 0b100000;     // 5
    case 54: return 0b100001;     // 6
    case 55: return 0b100011;     // 7
    case 56: return 0b100111;     // 8
    case 57: return 0b101111;     // 9

    case 58: return 0b1000111;    // :
    case 59: return 0b1010101;    // ;

    case 61: return 0b110001;     // =

    case 63: return 0b1001100;    // ?
    case 64: return 0b1010110;    // @

    case 65: return 0b110;        // A
    case 66: return 0b10001;      // B
    case 67: return 0b10101;      // C
    case 68: return 0b1001;       // D
    case 69: return 0b10;         // E
    case 70: return 0b10100;      // F
    case 71: return 0b1011;       // G
    case 72: return 0b10000;      // H
    case 73: return 0b100;        // I
    case 74: return 0b11110;      // J
    case 75: return 0b1101;       // K
    case 76: return 0b10010;      // L
    case 77: return 0b111;        // M
    case 78: return 0b101;        // N
    case 79: return 0b1111;       // O
    case 80: return 0b10110;      // P
    case 81: return 0b11011;      // Q
    case 82: return 0b1010;       // R
    case 83: return 0b1000;       // S
    case 84: return 0b11;         // T
    case 85: return 0b1100;       // U
    case 86: return 0b11000;      // V
    case 87: return 0b1110;       // W
    case 88: return 0b11001;      // X
    case 89: return 0b11101;      // Y
    case 90: return 0b10011;      // Z
  }
}

void Morse::pulse(int8_t e) {
  if (event) event(&e);
}

String Morse::receipt(String data) {
  String string, letter;
  for (size_t i = 0; i < data.length(); i++) {
    switch (String(data[i]).toInt()) {

      case MORSE_DI:
      case MORSE_DIT:
        letter = "0" + letter;
        break;

      case MORSE_DAH:
        letter = "1" + letter;
        break;

      case MORSE_GAP:
        break;

      case MORSE_CHAR:
        string += String(decode("1" + letter));
        letter = "";
        break;

      case MORSE_WORD:
        string += " ";
        letter = "";
        break;

      case MORSE_PHRASE: return string;
    }
  }
  return string;
}

void Morse::transmit(String data) {
  data.toUpperCase();
  for (size_t i = 0; i < data.length(); i++) {
    uint8_t code = encode(data[i]);

    if (code) {
      do {
        pulse((code % 2) + ((1 - (code % 2)) * (!((code >> 1) > 1) * 2)));
        if ((code >> 1) > 1) pulse(MORSE_GAP);
      } while ((code = code >> 1) > 1);

      pulse(MORSE_CHAR);
    } else if (i < data.length()) pulse(MORSE_WORD);
  }
  pulse(MORSE_PHRASE);
}
