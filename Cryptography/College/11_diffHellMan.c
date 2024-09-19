// WAP to implement Diffie Helman key exchange algorithm:

#include <stdio.h>
#include <math.h>

// Function to calculate (base ^ exponent) % modulus
long long int mod_pow(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    long long int prime, base, private_key_A, private_key_B, public_key_A, public_key_B, secret_key_A, secret_key_B;

    // Input prime number and primitive root
    printf("Enter prime number (p): ");
    scanf("%lld", &prime);

    printf("Enter primitive root (g): ");
    scanf("%lld", &base);

    // Input private keys for users A and B
    printf("Enter private key for user A: ");
    scanf("%lld", &private_key_A);

    printf("Enter private key for user B: ");
    scanf("%lld", &private_key_B);

    // Calculate public keys for users A and B
    public_key_A = mod_pow(base, private_key_A, prime);
    public_key_B = mod_pow(base, private_key_B, prime);

    printf("\nPublic Key for user A: %lld\n", public_key_A);
    printf("Public Key for user B: %lld\n", public_key_B);

    // Calculate secret keys for users A and B
    secret_key_A = mod_pow(public_key_B, private_key_A, prime);
    secret_key_B = mod_pow(public_key_A, private_key_B, prime);

    printf("\nSecret Key for user A: %lld\n", secret_key_A);
    printf("Secret Key for user B: %lld\n", secret_key_B);

    return 0;
}

