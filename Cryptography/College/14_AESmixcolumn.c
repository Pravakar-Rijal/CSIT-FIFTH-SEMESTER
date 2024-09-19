// WAP to demonstrate Mix-Column operation of AES algorithm
#include <stdio.h>

// Galois Multiplication of 8-bit numbers
unsigned char galoisMultiply(unsigned char a, unsigned char b) {
    unsigned char result = 0;
    unsigned char high_bit_set;

    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            result ^= a;
        }

        high_bit_set = (a & 0x80);
        a <<= 1;

        if (high_bit_set) {
            a ^= 0x1B; // XOR with the irreducible polynomial x^8 + x^4 + x^3 + x + 1
        }

        b >>= 1;
    }

    return result;
}

// MixColumns transformation for one column
void mixColumns(unsigned char *column) {
    unsigned char temp[4];

    temp[0] = galoisMultiply(0x02, column[0]) ^ galoisMultiply(0x03, column[1]) ^ column[2] ^ column[3];
    temp[1] = column[0] ^ galoisMultiply(0x02, column[1]) ^ galoisMultiply(0x03, column[2]) ^ column[3];
    temp[2] = column[0] ^ column[1] ^ galoisMultiply(0x02, column[2]) ^ galoisMultiply(0x03, column[3]);
    temp[3] = galoisMultiply(0x03, column[0]) ^ column[1] ^ column[2] ^ galoisMultiply(0x02, column[3]);

    for (int i = 0; i < 4; i++) {
        column[i] = temp[i];
    }
}

// Print a 4x4 matrix
void printMatrix(unsigned char matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%02X ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char stateMatrix[4][4] = {
        {0x32, 0x88, 0x31, 0xE0},
        {0x43, 0x5A, 0x31, 0x37},
        {0xF6, 0x30, 0x98, 0x07},
        {0xA8, 0x8D, 0xA2, 0x34}
    };

    printf("Original State Matrix:\n");
    printMatrix(stateMatrix);

    // Apply MixColumns operation on each column
    for (int i = 0; i < 4; i++) {
        mixColumns(stateMatrix[i]);
    }

    printf("\nAfter MixColumns Operation:\n");
    printMatrix(stateMatrix);

    return 0;
}
