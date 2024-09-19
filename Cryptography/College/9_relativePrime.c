#include <stdio.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to check if two numbers are relatively prime using Euler's theorem
int areRelativelyPrime(int a, int n) {
    return (gcd(a, n) == 1);
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check if the numbers are relatively prime (coprime)
    if (areRelativelyPrime(num1, num2)) {
        printf("%d and %d are relatively prime .\n", num1, num2);
    } else {
        printf("%d and %d are not relatively prime .\n", num1, num2);
    }

    return 0;
}
