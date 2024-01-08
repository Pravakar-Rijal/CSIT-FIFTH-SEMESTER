#include <stdio.h>
#include <stdlib.h>

#define q 19
#define alpha 13

int yA, yB;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

int userA_key_generation() {
    int xA;
    // Private Key for User A
    xA = (rand() % (q - 2)) + 2;
    // Public Key for User A
    yA = power(alpha, xA, q);
    return xA;
}

int userA_shared_key(int xA, int yB) {
    // Shared Key by User A
    int kA;
    kA = power(yB, xA, q);
    return kA;
}

int userB_key_generation() {
    int xB;
    // Private Key for User B
    xB = (rand() % (q - 2)) + 2;
    // Public Key for User B
    yB = power(alpha, xB, q);
    return xB;
}

int userB_shared_key(int xB, int yA) {
    // Shared Key by User B
    int kB;
    kB = power(yA, xB, q);
    return kB;
}

int main() {
    int kA, kB;
    srand(23);

    int xA = userA_key_generation();
    int xB = userB_key_generation();

    kA = userA_shared_key(xA, yB);
    kB = userB_shared_key(xB, yA);

    printf("\nSECRET KEY BY USER A: %d", kA);
    printf("\nSECRET KEY BY USER B: %d", kB);
    return 0;
}
