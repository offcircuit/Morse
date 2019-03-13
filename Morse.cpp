#include "Morse.h"

uint8_t Morse::encode(char c) {
  switch (c) {
    case 32: return 0b1;

    case 48: return 0b111111;
    case 49: return 0b111110;
    case 50: return 0b111100;
    case 51: return 0b111000;
    case 52: return 0b110000;
    case 53: return 0b100000;
    case 54: return 0b100001;
    case 55: return 0b100011;
    case 56: return 0b100111;
    case 57: return 0b101111;

    case 65: return 0b110;
    case 66: return 0b10001;
    case 67: return 0b10101;
    case 68: return 0b1001;
    case 69: return 0b10;
    case 70: return 0b10100;
    case 71: return 0b1011;
    case 72: return 0b10000;
    case 73: return 0b100;
    case 74: return 0b11110;
    case 75: return 0b1101;
    case 76: return 0b10010;
    case 77: return 0b111;
    case 78: return 0b101;
    case 79: return 0b1111;
    case 80: return 0b10110;
    case 81: return 0b11011;
    case 82: return 0b1010;
    case 83: return 0b1000;
    case 84: return 0b11;
    case 85: return 0b1100;
    case 86: return 0b11000;
    case 87: return 0b1110;
    case 88: return 0b11001;
    case 89: return 0b11101;
    case 90: return 0b10011;
  }
}
