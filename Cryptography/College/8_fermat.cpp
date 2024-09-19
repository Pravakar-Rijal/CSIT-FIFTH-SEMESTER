#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long power_mod(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent / 2;
        base = (base * base) % modulus;
    }
    return result;
}

int is_prime_fermat(long long n, int num_trials) {
    if (n <= 1) {
        return 0;  // Not prime
    } else if (n == 2 || n == 3) {
        return 1;  // Prime
    } else if (n % 2 == 0) {
        return 0;  // Not prime
    }

    srand(time(NULL));

    for (int i = 0; i < num_trials; ++i) {
        long long a = rand() % (n - 2) + 2;  // Random number between 2 and n-1
        if (power_mod(a, n - 1, n) != 1) {
            return 0;  // Not prime
        }
    }

    return 1;  // Likely prime
}

int main() {
    long long number_to_test;
    int num_trials = 5;

    printf("Enter a number to test for primality: ");
    scanf("%lld", &number_to_test);

    if (is_prime_fermat(number_to_test, num_trials)) {
        printf("%lld is likely to be prime.\n", number_to_test);
    } else {
        printf("%lld is composite.\n", number_to_test);
    }

    return 0;
}
