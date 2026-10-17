/* A bitwise CRC-8 (polynomial 0x07). */
#include "test.h"

NOINLINE int crc8(const unsigned char *p, int n) {
    unsigned crc = 0;
    while (n--) { crc ^= *p++; for (int i = 0; i < 8; i++) crc = (crc & 0x80u) ? ((crc << 1) ^ 0x07u) & 0xFFu : (crc << 1) & 0xFFu; }
    return (int)crc;
}
int test_call(void) { const unsigned char msg[4] = { '1', '2', '3', '4' }; return crc8(msg, 4); }

// RUN: test_call = 194
