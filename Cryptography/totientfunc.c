#include <stdio.h>

int isprime(int);
void primefactors(int, float[]);

int main() {
    int num;
    float totient=1.0;
    float primearr[10] = {0.0}; // Initialize the array with 0
    printf("\nEnter a number to find prime factors of: ");
    scanf("%d", &num);
   // printf("\nPrime factors are: ");
    primefactors(num, primearr);
    for (int i = 0; i < 10; i++) {
        if (primearr[i] != 0) {
            totient *= (1-(1/primearr[i]));
            //printf("%d ", primearr[i]);
        }
    }
    printf("\nTotient Value of %d is %.1f",num,num*totient);
    return 0;
}

void primefactors(int num, float arr[]) {
    int j = 0;
    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && isprime(i)) {
            arr[j] = i;
            j++;
        }
    }
}

int isprime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
