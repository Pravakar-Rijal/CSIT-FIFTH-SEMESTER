// WAP to find Euler’s Totient function of a given number.
#include <stdio.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate Euler's Totient function
int eulerTotient(int n) {
    int result = 1;

    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }

    return result;
}

int main() {
    int number;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Check if the input is valid
    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;  // Exit with an error code
    }

    // Calculate and display Euler's Totient function
    int totient = eulerTotient(number);
    printf("Euler's Totient function of %d is: %d\n", number, totient);

    return 0;
}
