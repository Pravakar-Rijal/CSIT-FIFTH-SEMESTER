#include <iostream>

// Multiplication in Galois Field (GF)
unsigned char galois_multiplication(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    for (int i = 0; i < 8; ++i) {
        if ((b & 1) != 0) {
            p ^= a;
        }
        bool carry = (a & 0x80) != 0;
        a <<= 1;
        if (carry) {
            a ^= 0x1B; // XOR with irreducible polynomial x^8 + x^4 + x^3 + x + 1
        }
        b >>= 1;
    }
    return p;
}

// MixColumns operation
void mixColumns(unsigned char state[4][4]) {
    unsigned char tmp[4][4];
    for (int c = 0; c < 4; ++c) {
        tmp[0][c] = galois_multiplication(0x02, state[0][c]) ^ galois_multiplication(0x03, state[1][c]) ^ state[2][c] ^ state[3][c];
        tmp[1][c] = state[0][c] ^ galois_multiplication(0x02, state[1][c]) ^ galois_multiplication(0x03, state[2][c]) ^ state[3][c];
        tmp[2][c] = state[0][c] ^ state[1][c] ^ galois_multiplication(0x02, state[2][c]) ^ galois_multiplication(0x03, state[3][c]);
        tmp[3][c] = galois_multiplication(0x03, state[0][c]) ^ state[1][c] ^ state[2][c] ^ galois_multiplication(0x02, state[3][c]);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = tmp[i][j];
        }
    }
}

int main() {
    unsigned char state[4][4] = {
        {0xdb, 0xf2, 0x01, 0xc6},
        {0x13, 0x0a, 0xd2, 0x5f},
        {0x53, 0x23, 0xb4, 0x84},
        {0x5c, 0x3c, 0xe9, 0x61}
    };

    std::cout << "Original State:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << std::hex << static_cast<int>(state[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    mixColumns(state);

    std::cout << "\nAfter MixColumns:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << std::hex << static_cast<int>(state[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}